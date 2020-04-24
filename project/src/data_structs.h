 /**
 * @file data_structs.h
 *
 * @copyright 2019 3081 Staff and D. Kunkler, All rights reserved.
 */
#ifndef SRC_DATA_STRUCTS_H_
#define SRC_DATA_STRUCTS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include <vector>

/*******************************************************************************
 * Struct Definitions
 ******************************************************************************/

/**
 * @brief A position struct that holds two floats x and y.
 *
 * Calls to \ref Position create a struct instance with x and y set to 0.
 */
struct Position {
/*
 * @brief Generator for a Position struct.
 *
 * @param[in] x float.
 * @param[in] y float.
 * @return Position object.
 */
  Position(int x, int y): x(x), y(y) { }
  Position() : x(0), y(0) {}
  float x;
  float y;
};
/**
 * @brief A Color data struct holds colr info for the vissim
 *
 * Calls to \ref Color create a struct with rgb at 0 and alpha at 255.
 */
struct Color {
  Color(int r = 158, int g = 32, int b = 32, int a = 120):
      red(r), green(g), blue(b), alpha(a) { }
  int red;
  int green;
  int blue;
  int alpha;
};
/**
 * @brief A BusData struct that holds the bus id, its position, the number of
 * passengers, and its maximum capacity.
 *
 * Calls to \ref BusData create a struct with a blank id, default Position
 * object, 0 passengers, and capacity of 0.
 */
struct BusData {
/*
 * @brief Generator for a BusData struct.
 *
 * @param[in] id string.
 * @param[in] Color color
 * @param[in] position Position struct.
 * @param[in] num_passengers int.
 * @param[in] capacity int.
 * @return BusData object.
 */
 BusData(std::string id, Color color, Position pos, int n_pass, int cap):
     id(id), position(pos), num_passengers(n_pass), capacity(cap), color(color) { }
 BusData() : id(""), position(Position()), num_passengers(0), capacity(0), color() {}
 std::string id;
 Position position;
 int num_passengers;
 int capacity;
 Color color;
};

/**
 * @brief A StopData struct that holds the stop id, its position, the number of
 * people at the stop.
 *
 * Calls to \ref StopData create a struct with empty id, default Position object
 * , and 0 passengers.
 */
struct StopData {
/*
 * @brief Generator for a StopData struct.
 *
 * @param[in] id string.
 * @param[in] position Position struct.
 * @param[in] num_people int.
 * @return StopData object.
 */
  StopData(std::string id, Position pos , int n_peeps):
      id(id), position(pos), num_people(n_peeps) { }
  StopData() : id(""), position(Position()), num_people(0) {}
  std::string id;
  Position position;
  int num_people;
};

/**
 * @brief A RouteData struct that holds the route id, and a vector of StopData.
 *
 * Calls to \ref RouteData create a struct with empty id and a vector of
 * StopData objects.
 */
struct RouteData {
/*
 * @brief Generator for a RouteData object.
 *
 * @param[in] id string.
 * @param[in] stops StopData vector.
 * @return RouteData object.
 */
  RouteData(std::string id) :
     id(id), stops(std::vector<StopData>(0)) { }
  RouteData() : id(""), stops(std::vector<StopData>(0)) {}
  std::string id;
  std::vector<StopData> stops;
};

#endif  // SRC_DATA_STRUCTS_H_
