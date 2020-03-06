### Assessment for Lab 10

#### Total score: _100.0_ / _100_

Run on March 03, 15:44:37 PM.


### Necessary Files and Structure

+  _10_ / _10_ : Pass: Check that directory "labs" exists.

+  _10_ / _10_ : Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+  _10_ / _10_ : Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		220b762ea70c0b78899e82018b50bb6955b822c1	refs/heads/devel

		94343bc82982c5a2c8b1e75ce455b1b70f5287f8	refs/heads/fix/01-compilation-errors

		ca64e54e715904923d3f9934f4d604521c3bab1c	refs/heads/fix/02-style-errors

		e2798cb98f4cc6e9a44bfc0b91f23761b1736c32	refs/heads/master

		d5335a0ab4637887f51807b93c4bd2c05ada3db1	refs/heads/support-code



+  _10_ / _10_ : Pass: Checking for the correct number of branches

Sufficient branches found (found=2, required=2):

fix/01-compilation-errors

fix/02-style-errors


#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history














However, that didn't seem right to me so I posted to piazza and was told to run with root=..
This told me to add them all back in so I did.





passenger_factory.h, passenger_generator.h, passenger_loader.h, passenger_unloader.h,
random_passenger_generator.h, route.cc/h and stop.h Google style compliant.
I left one warning.
/export/scratch/cpplint-kunkl007/./passenger_unloader.h:18:  Is this a non-const reference? If so, make const or use a pointer: std::list<Passenger*>& passengers  [runtime/references] [2]
Done processing /export/scratch/cpplint-kunkl007/./passenger_unloader.h
I'm not sure what it actually wants me to do there because I think that's
vital to the code. I will discuss this with a TA on friday.




undid commenting in passenger.cc and random_passenger_generator that was blocking required methods.
These changes were all neccessary to allow compilation.











































































































+  _5_ / _5_ : Pass: Check git commit history
Sufficient commits (found=30,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 3)

[CLOSED issue #3] :  missing files 1

[CLOSED issue #2] :  Style error according to cpplint [enhancement]

[CLOSED issue #1] :  compilation error [bug] 1





+  _10.0_ / _10_ : Pass: Run ghi for total number of issues in Github repo (Found: 3, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #3] :  missing files 1

[CLOSED issue #2] :  Style error according to cpplint [enhancement]

[CLOSED issue #1] :  compilation error [bug] 1

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+  _10_ / _10_ : Pass: Check that directory "project/src" exists.

+ Pass: Change into directory "project/src".

+  _5_ / _5_ : Pass: Check that file "makefile" exists.

+  _30_ / _30_ : Pass: Check that make compiles.



#### Total score: _100.0_ / _100_
