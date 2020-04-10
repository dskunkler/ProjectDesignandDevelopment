/**
 * @file mainpage.h
 *
 * @copyright 2020 Daniel Kunkler
 * , All rights reserved.
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage Index page for Project: Bus System Simulator
 *
 * \section intro_sec Introduction
 *
 * The following pages contain UML documentation for Bus System Simulator
 *
 * \section obtaining_code How to obtain the code:
 * 	To obtain the code navigate to the website
 * http://github.umn.edu/umn-csci-3081-s20/repo-kunkl007
 * From here you have a few options of how you can obtain the project. You can
 * either download the files and unzip them, then navigate to project.
 * Alternatively, create a folder and navigate to it through the command line
 * and type "git clone http://github.umn.edu/umn-csci-3081-s20/repo-kunkl007.git".
 * This will create a copy of the entire file structure and you will have to
 * navigate to the "project" folder to see the project we will be referring to
 * for the rest of this document.
 * \subsection compile How To compile
 * To compile the code, further navigate to the
 * src folder by type "cd src/" in the command line. Here you will want to type
 * and enter "make clean" then "make". This should compile the project for you
 * to be able to run.
 * \subsection running Running the Code
 * Type "cd .." to navigate back to the "project" folder
 * project. From here you will want to type "./build/bin/vis_sim 8123". The
 * command line should print "starting server...". At this point you'll want to
 * open your internet browser and enter
 * "http://127.0.0.1:8123/web_graphics/project.html" At this point the command
 * line should say "Connection established". From the webpage you can choose how
 * many steps you want to run of the simulation with the top scroll bar. The
 * bottom bars let you choose how many steps you want to wait in between
 * spawning new busses. The final step is to click "Start" button to get the
 * simulation to start executing. If at any time you want to pause the
 * simulation simply click the "Pause" putton and the simulation will stop
 * running. Please note that you should be generating a report of all the
 * passengers who are at the stops as well as the bus details of the busses
 * operating.
 * \section Outline
 * A very general outline of what is happening in our code and the major players.
 * We have
 * <br>1) Passenger
 * <br>2) Stop
 * <br>3) Route
 * <br>4) Bus
 * <br>5) Visualization simulator
 * <br>6) Bus Factory
 * <br>Passengers are created with a random name and a random legal stop
 * destination. The location they are generated is at the Stop. Stops have an
 * integer id and two doubles that represent their longitude and latitude that
 * are both instantiated at a Stop’s construction. Stops also have a list
 * of passengers. Routes have a name, a list of stops, a list of distances
 * between stops, an integer representing the number of stops and a
 * PassengerGenerator which adds the passengers to the stops. Two Routes are
 * added to a Bus which also has name, a capacity and a speed. The passengers
 * are unloaded and loaded onto and off the bus when it visits each stop. Bus
 * is an abstract class and currently has three classes that inherit from it,
 * SmallBus, RegularBus, and LargeBus. We did this so we could use our first
 * design pattern the Factory Pattern.
 * \section bus_fact Bus Factory
![UML of Concrete Factory](Concrete.png)
 * Factories can come in two forms, Concrete
 * or Abstract. The one I chose was the Concrete factory. There were a few
 * considerations I considered when choosing this Factory type.
 * <br>
 * 1) How long would it take to implement?<br>
 * 2) What will it be used for?<br>
 * 3) How much will we need to modify and how much will this affect our Factory?
 * <br>
 * At this point you may be asking yourself, how does concrete factory
 * satisfy these questions? Concrete factories are the simplest factory to
 * implement. The tradeoff of this is that they are more rigid then abstract
 * factory. With a concrete class we must provide all the information required
 * for the generation of the busses within the factory itself. This can be an
 * issue. However, our busses are only ever generated within the VisualSimulator
 * class and they’re only ever spawned with a random chance of generating each
 * bus. The solution for in this situation then is to simply allow the Factory
 * to randomly generate one of the three bus types. If we ever decide that there
 * should be something else passed into, we will need to make new modifications
 * and will need to make changes anywhere the factory is used.. If say we want to say generate
 * busses from a different class and use them differently, then we would want an
 * Abstract Factory. For example, if we decide we want to deploy busses
 * differently for different times of day, we would need to pass or frequency to
 * the factory and allow the factory to spawn a larger bus or smaller bus when
 * needed. This would be impossible with our current version of the factory.
 * Right now, we would need visual simulator to somehow know which bus to
 * generate, and then pass that size into the factory. We don’t want that
 * because it increases the coupling of visual simulator and bus factory.
 * We only implement design patterns because we want to be effective
 * programmers. Another property of effective programming is “Open to extension,
 * closed to modification”. In my opinion, Abstract factories follow this
 * property more closely. With an Abstract Factory, the factory itself is
 * abstract meaning you can create different types of factories which can create
 * different types of busses. However, the trade-off for this is that we’re
 * increasing the coupling of Visual Simulator and the Bus Factory since Visual
 * Simulator must know which type of Factory to create. I imagine we will have
 * to create and abstract factory later, but I haven’t yet been convinced of its
 * usefulness for our current situation. I do see however, if we decide to
 * change the busses, we can simply change them within their individual classes.
 * This does violate our Open to Extension, closed to modification principle
 * though. Either way, the trade-off of simplicity for functionality took place
 * with out tight time frame.
 * \section Observer Designing and Implementing the Observer Pattern
 * The Observer Pattern was a fun and informative experience overall. I named my
 * abstract classes ISubject which I was refer to as the subject and IObserver
 * which I will refer to as the observer. I ended up making both of them
 * Templates which means they have to have a type passed to them to use. I
 * made it so the type passed was a BusData pointer. I think this makes the
 * most sense because we will always be able to inherit an observer from our
 * IObserver class so our ISubject class will be able to use any time which
 * is an IObserver. However, we may want to use the subject and observer
 * relationship for something besides a Bus and BusData object so we want
 * to let the compiler know what we want to observer. For example we could
 * have Bus inherit from ISubject and pass all of it's passengers to an observer
 * or any other aspect of it we want. We would simply need to pass that in
 * as the bracket for our ISubject in the inheritance. I had to add a function
 * NotifyObservers to the Bus class because I wanted ISubject to be an abstract
 * type. I also had to add AddListener and ClearListeners to the
 * visualization_simulator class. The hardest part for me was definitely getting
 * the syntax for the templates correct. It can be a little confusing when youre
 * passing in a bunch of different types all over the place and passing a
 * template type as an argument to something too. I had an issue where the
 * compiler was telling me I had an undefined type because I didn't know
 * I had to have the definitions in the header file for the templates until
 * Brandon Voigt helped me figure it out during a TA session.
 * I would say the things which helped me understand the Observer pattern the
 * most is Chapter 2 in Head First Design Patterns as well as the image provided
 * in the lab.
 * ![Observer Pattern](Observer_UML.jpg) width=600px
 * I'm a very visual learner so it was nice to have something translated into
 * C++ which is the language I'm probably most comfortable with at this point.
 * My tip for understanding the pattern would be to read the chapter, then
 * look at an example in your best language. In english I would describe it as
 * this.<br>1 ) You have a subject which is being witnessed.
 * <br> 2 ) You have an observer who wants to watch the subject.
 * <br> 3 ) You want to subject to hold a reference of the observers watching it
 * so that it can alert them whenever it wants.
 * <br> This is a VERY BASIC understanding of the Observer pattern. Somethings
 * watching and somethings being watched and the subject being watched alerts
 * the observer to its changes.
 */
#endif  // SRC_MAINPAGE_H_
