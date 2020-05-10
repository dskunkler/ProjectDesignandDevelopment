### Iteration 3 - Style-And-Git Partial Assessment (Graded By: Pallavi Mitra)

Run on May 10, 01:15:37 AM.

<hr>

This Partial Assessment indicates a TA has begun grading your Iteration 3 Design. However, design will be graded using a Canvas rubric and grades will only be posted on Canvas once every student's program design has been graded. We ask for your patience at this time.

<hr>

+ Pass: Checkout iteration 3 final submission.




#### Style Compliance Tests

+ Pass: Change into directory "project/src".

+ Pass: Linting main src files...



+ Pass: Change into directory "../web_code/web".

+ Pass: Linting web code...




#### Git Tests

+  _2_ / _2_ : Pass: Counting Iteration 3 branches...

Sufficient branches found (found=7, required=6):

docs/07-doxygen

feat/23-logfiler

feat/26-decorator

feat25-stopobserver

fix/02-style-errors

fix/24-pausebutton

fix28/stickyobserver

+  _2.0_ / _2_ : Pass: Run ghi for total number of issues in Github repo (Found: 6, Expected: 4) 

 [OPEN issue #27] :  Segfault on specific refresh.

[CLOSED issue #28] :  Observers not clearing?

[CLOSED issue #26] :  Decorator

[CLOSED issue #25] :  Add a stop observer [enhancement]

[CLOSED issue #24] :  Pause Button broken

[CLOSED issue #23] :  Singleton Logwriter

 




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history







including a UML jpg for easy reading.







changing intensity along the route.
I changed it back so it wraps the bus every update with a new intensity and the problem is no longer there.
I'm not sure this is the best solution, but I've had too many issues with this and since it's working, I'm leaving it.


After I observed 1000, I couldn't get back to my other busses to observer.
I spoke with Sukhail and he observed I needed to make my register/notify/clear in my BusDecorator.
This was seg faulting and we realized it was because my constructor for ColorDec and IntensityDec were
only writing to their BusToDecorate and not to the one in BusDecorator where the functions were defined.
I changed the construtor and that solved the issue. I also changed it so the Intensity only wraps once at instantiation.


after observing a smaller number. I had a feeling it was related to notify
being called from the bus when it needed to be called from the wrapper.
My solution which worked to let me check out different buses was to have
the wrapper call update bye calling BTD(BusToDecorate)->Move, BTD->UpdateBusData
NotifyObservers.


the old listeners when I'm adding a new one from the decorator.



and that allowed both of them to be observable.


a bool decorated to bus and BusDecorator which represents whether it is
decorated or not. In busses its false, in BusDecorator it returns true.
I also added a functions OutboundComplete which is a bool wheter outroute
IsAtEnd. I used these in Vis Sim's update so that when the outbound is complete
and the bus isn't decorated, we decorate it. I made BusColorDecorator
that inherits from busDecorator and it's GetBusData command gets first
sets the .color aspect to gold before sending it.


pure virtual functions. I then added a IBus BusToDecorate pointer
as a protected member of Decorator. I defined all the functions within
the header to simply call the BusToDecorate->FunctionName().











 Bus decorator is empty but will store an ibus object.






I noticed that I never was actually notifying. I managed to find a StopData struct in the RouteUpdate.
This is useful because stops isn't really used in vis_sim at all. I added an update when its creating its
stopdata vector in Route, UpdateRouteData.




and I need to get the decorator working right too.




I've got a addbus/stop clearbus/stop and I added a StopWebObserver.



show any differences.




to include it.


I created a StopWebCommand that is pretty empty. I will fill it in more
when I get the provided sketch.js files for the lab.


to ClearBusListeners and I made listen to BusListen


bus listen. I also changed clearlisteners to clear bus listeners









code from iteration 1 because the code provided in iteration 2 from the
TA's prevented the pause button from operating effectively.



if a bus's trip is complete. Only if it's complete will I write it to the csv.



what I wrote. I do think the codes pretty clear though.




I'm at least able to compile. Added a section to bus so that its unloader
has a destination file.


file writer function.


and a vector string. Open the file and write to it then close it.


need to create the definitions for them all.


I have yet to define it though.




I also added a line into LoadPassenger that will increment it every
time it's called. This should now track total passengers that get
onto the bus.




















+  _1_ / _1_ : Pass: Check git commit history
Sufficient commits (found=92,required=10)

+ Pass: Opening Iter_03_Style-And-Git_Assessment.md using firefox

