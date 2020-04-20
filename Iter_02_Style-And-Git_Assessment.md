### Iteration 2 - Style-And-Git Partial Assessment (Graded By: Pallavi Mitra)

Run on April 19, 19:28:53 PM.

<hr>

This Partial Assessment indicates a TA has begun grading your Iteration 2 Design. However, design will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's program design has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 2 final submission.




#### Style Compliance Tests

+ Pass: Change into directory "project/src".

+ Pass: Linting main src files...



+ Pass: Change into directory "../web_code/web".

+ Pass: Linting web code...




#### Git Tests

+  _2_ / _2_ : Pass: Counting Iteration 2 branches...

Sufficient branches found (found=10, required=4):

docs/07-doxygen

feat/16-bus-depot

fix/02-style-errors

fix/14-regression-test

fix/15-observer-pattern

fix/22-noonstrat-print-error

refactor/21-isubject

refactor/isubjectcc

style/17-maincpp-indent

style/18-ifelse-indent

+  _2.0_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 14, Expected: 4) 

 [OPEN issue #19] :  Buses going off Route [bug]

[OPEN issue #2] :  Style error according to cpplint [enhancement]

[CLOSED issue #22] :  Strategy 2 (noonstrategy) is outptting size 0 for a large bus

[CLOSED issue #21] :  Refactor ISubject so its template takes the BusData, not the Iobserver

[CLOSED issue #20] :  Put the ISubject definitions into the header file

[CLOSED issue #18] :  Indent if else statements so else is indented.

[CLOSED issue #17] :  Indentation in main.cpp

[CLOSED issue #16] :  BusDepot [enhancement]

[CLOSED issue #15] :  Observer pattern [enhancement]

[CLOSED issue #14] :  Regression Tests [enhancement]

[CLOSED issue #12] :  Skip stops [enhancement]

[CLOSED issue #11] :  Simulation seems to skip stop 13 from default config file

[CLOSED issue #8] :  Time runs out when paused [bug] 1

[CLOSED issue #7] :  Doxygen [enhancement]

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history

provided to us through lab 14.


added and image and found out how to resize it.




the implementation of the Observer pattern.





code blocks so I indented it to make it clearer.



I also made NotifyObservers purely virtual and have it overridden in bus. I removed the old definitions from Bus for the other functions.


I think this makes more since since we can always have something
inherit from IObserver and be added, but we don't always want our subject to be
sending bus data. What it sends should be dependend ont he type that inherits it.



simulator I made.






/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 box to all new code as well as the code provided in web_code/web and in src.



files the TA's provided. Woops!



as per the project specifications.




the bus that the strategy was returning to the depot.
After I fixed that I ran the instance and saw I was only producing small busses.
I realized I was incrementing the state AFTER teh return so it wasn't chaning.
I fixed that and the issue persisted and realized that when I initialize
the state to 0 in the individual strategy it was resetting it evertime so I only
produced small busses. I fixed it and it seems to be working perfectly.


DeployStrat which is purely virtual.  I created 4 strategies that inherit
from BusStrat. Morning/noon/afternoon/alternative that deploy the
appropriate type of busses sequentially as per the specificitions.








wasn't actually displaying the observer information. I added print statements throughout
and noticed that Notify wasn't displaying anything. I put a print statement
into the IObservable and noticed that WAS printing. This showed me that
the function was calling Notify from the parent class. I made the function
purely virtual and that solved the issues.





IObserver to be a template too so it aligned with the provided code.
I made some changes to the visualization_simulator so that my template would
be used correctly.



I'm not sure why this isn't working. I'm now getting an undefined reference to


correctly named so that the program compiles and runs. I still need
to actually implements the functions AddListener and ClearListeners.


I made it doxystyle compliant. Note that the UML we were provided does not align with
my header implementation but I made it that way because that it show it gets called from
my_web_server_command that was provided to us to use.


in the NotifyObservers functions


into the correct files. I changed visualization_simulator's Pause command
to TogglePause so it aligned with those files.













































+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=76,required=10)

+ Pass: Opening Iter_02_Style-And-Git_Assessment.md using firefox

