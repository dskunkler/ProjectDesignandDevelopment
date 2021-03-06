/**
 * @file bus.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

 /*******************************************************************************
   * Includes
 ******************************************************************************/
#include "src/bus.h"
#include "src/i_observer.h"
#include "web_code/web/my_web_server_command.h"

/*******************************************************************************
  * Member Functions
******************************************************************************/

Bus::Bus(std::string name, Route * out, Route * in,
                         int capacity, double speed) {
  name_ = name;
  outgoing_route_ = out;
  incoming_route_ = in;
  passenger_max_capacity_ = capacity;
  speed_ = speed;
  distance_remaining_ = 0;
  next_stop_ = out->GetDestinationStop();
  unloader_ = new PassengerUnloader;
  unloader_->SetOutputFile("PassData.csv");
  loader_ = new PassengerLoader;
  total_passengers = 0;  // We start with no passengers on the bus.
}

bool Bus::IsTripComplete() {
  bool is_complete = false;

  // short-circuit: outgoing has to be completed first
  if (outgoing_route_->IsAtEnd() && incoming_route_->IsAtEnd()) {
    is_complete = true;
  }
  return is_complete;
}


bool Bus::LoadPassenger(Passenger * new_passenger) {
  bool added_passenger = false;
  if (loader_->LoadPassenger(new_passenger, passenger_max_capacity_,
      &passengers_)) {
    added_passenger = true;
    total_passengers++;  // increase total passengers by 1.
    // revenue_ += 0; //No revenue tracking at this time.
  }
  return added_passenger;
}


bool Bus::Move() {
  // update all passengers FIRST
  // new passengers will get "updated" when getting on the bus
  for (std::list<Passenger *>::iterator it = passengers_.begin();
                                  it != passengers_.end(); it++) {
    (*it)->Update();
  }
  bool did_move = true;
  // travel (happens in all cases, neg distance indicates ready to unload/load)

  if (speed_ > 0) {
    distance_remaining_ -= speed_;
  } else {
    did_move = false;
  }
    int passengers_handled = 0;  // counts those on or off bus at this location

    // if there's no more distance
    // (OFF BY ONE ERROR ISSUE - do we unload if exactly zero after a move?
    // or only if there was time remaining?)

    if (distance_remaining_ <= 0) {
        did_move = false;

        // Determine which route we are on
        Route * current_route = outgoing_route_;
        if (outgoing_route_->IsAtEnd()) {
            current_route = incoming_route_;
            if (!incoming_route_->IsAtEnd()) {
                // Only get here if we are on our incoming route

              // if A passenger wants off or if there are people at the stop
              // we must handle the passengers.
       if (PassengerRequestOff() || next_stop_->GetNumPassengersPresent() > 0) {
                passengers_handled += UnloadPassengers();  // unload
                passengers_handled += next_stop_->LoadPassengers(this);  // load

              // if any passengers on or off, all distance to next stop is left
              // but, if we didn't handle any passengers here, any negative will
              // affect the distance remaining (see addition below)

                if (passengers_handled != 0) {
                    distance_remaining_ = 0;
                    did_move = true;  // We move if we have gotten passengers?
                }
              } else {
                std::cout << "Bus: "<< name_
                  << "\nStop skipped: "
                    << (current_route->GetDestinationStop())->GetId()
                     << std::endl;
                did_move = true;
              }

                current_route->ToNextStop();
                next_stop_ = current_route->GetDestinationStop();
                distance_remaining_ += current_route->GetNextStopDistance();
                return did_move;

            } else {
                speed_ = 0;
                distance_remaining_ = 999;
                return did_move;
            }
        }


        // Only get here if we are on outgoing route

       if (PassengerRequestOff() || next_stop_->GetNumPassengersPresent() > 0) {
          passengers_handled += UnloadPassengers();  // unload
          passengers_handled += next_stop_->LoadPassengers(this);  // load

          // if any passengers on or off, all distance to next stop is left
          // but, if we didn't handle any passengers here, any negative will
          // affect the distance remaining (see addition below)

          if (passengers_handled != 0) {
              distance_remaining_ = 0;
              did_move = true;
          }
        } else {
          std::cout << "Bus: "<< name_
            << "\nStop skipped: "
              << (current_route->GetDestinationStop())->GetId()
               << std::endl;
          did_move = true;
        }
        current_route->ToNextStop();

        // If we have incremented past the end of the outgoing route, set our
        // next stop to actually be the first stpo in incoming
        if (current_route->IsAtEnd()) {
            next_stop_ = incoming_route_->GetDestinationStop();
            distance_remaining_ += incoming_route_->GetNextStopDistance();
        } else {
            next_stop_ = current_route->GetDestinationStop();

            // adding here in case negative time still remains
            // // (see passengers_handled above)
            distance_remaining_ += current_route->GetNextStopDistance();
        }
    }
  return did_move;
}


// bool Refuel() {
// This may become more complex in the future
// fuel_ = max_fuel_;
// }

void Bus::Update() {  // using common Update format
  std::cout << "Bus Update\n";
  Move();
  UpdateBusData();
  BusData to_send = GetBusData();  // could just use bus_data_.
  NotifyObservers(&to_send);  // notifying observers
}

// print a report of all the information of the bus.
void Bus::Report(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Size: " << passenger_max_capacity_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
                                        it != passengers_.end(); it++) {
    (*it)->Report(out);
  }
}

// modified version for our csv report. No need to show individual passenger
// info as we are more concerned with total passengers.
void Bus::StatReport(std::ostream& out) {
  out << "Name: " << name_ << std::endl;
  out << "Speed: " << speed_ << std::endl;
  out << "Size: " << passenger_max_capacity_ << std::endl;
  out << "Distance to next stop: " << distance_remaining_ << std::endl;
  out << "\tPassengers (" << passengers_.size() << "): " << std::endl;
  out << "Total num of passengers " << total_passengers << std::endl;
}


int Bus::UnloadPassengers() {
  int passengers_unloaded = 0;
  unloader_->UnloadPassengers(&passengers_, next_stop_);
  return passengers_unloaded;
}


void Bus::UpdateBusData() {
    bus_data_.id = name_;

    // Get the correct route and early exit
    Route * current_route = outgoing_route_;
    if (outgoing_route_->IsAtEnd()) {
        if (incoming_route_->IsAtEnd()) { return; }
        current_route = incoming_route_;
    }

    Stop * prevStop = current_route->PrevStop();
    Stop * nextStop = current_route->GetDestinationStop();

    double distanceBetween = current_route->GetNextStopDistance();
    double ratio;

    // Need to check if we are at the first stop
    if (distanceBetween - 0.00001 < 0) {
        ratio = 1;
    } else {
        ratio = distance_remaining_ / distanceBetween;
        if (ratio < 0) {
            ratio = 0;
            distance_remaining_ = 0;
        }
    }

    // This ratio shows us how far from the previous stop are we in a ratio
    // from 0 to 1
    Position p;

    p.x = (nextStop->GetLongitude() * (1 - ratio) + prevStop->GetLongitude()
      * ratio);
    p.y = (nextStop->GetLatitude() * (1 - ratio) + prevStop->GetLatitude()
      * ratio);
    bus_data_.position = p;

    bus_data_.num_passengers = static_cast<int>(passengers_.size());
    bus_data_.capacity = passenger_max_capacity_;
}

BusData Bus::GetBusData() const {
    return bus_data_;
}

// This returns a bool if there are passengers that need off of the bus
bool Bus::PassengerRequestOff() {
  bool wantsOff = false;
  for (std::list<Passenger *>::iterator it = passengers_.begin();
      it != passengers_.end();
      it++) {
    if ((*it)->GetDestination() == next_stop_->GetId()) {
      // Passenger wants to get off!
      wantsOff = true;
    }
  }
  return wantsOff;
}


// This returns a bool that says whether the outbound leg of the trip is
// complete. It allows us to Decorate it at the appropriate time.
bool Bus::OutboundComplete() {
  return outgoing_route_->IsAtEnd();
}
