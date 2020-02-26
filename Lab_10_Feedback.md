### Feedback for Lab 10

Run on February 25, 22:28:30 PM.


### Necessary Files and Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab10_advanced_git" exists.


### Git Usage

+ Pass: Run git ls-remote to check for existence of specific branch- Branch devel found

+ Pass: Checkout devel branch.



+ Pass: Run git ls-remote gather all branches in repo

		0af28c39b827e8d4616a200e0254e0663444d5ad	refs/heads/devel

		94343bc82982c5a2c8b1e75ce455b1b70f5287f8	refs/heads/fix/01-compilation-errors

		ca64e54e715904923d3f9934f4d604521c3bab1c	refs/heads/fix/02-style-errors

		7020b1c179fb67be45b8dc3f41754e6c7df6ab0f	refs/heads/master

		d5335a0ab4637887f51807b93c4bd2c05ada3db1	refs/heads/support-code



+ Pass: Checking for the correct number of branches

Insufficient branches found (found=-2, required=2):




#### Counting commits on devel

+ Pass: Checkout devel branch.



+ Pass: Gather commit history





+ Fail: Check git commit history
Insufficient commits (found=0,required=4)


### Git Issue Usage

+ Pass: Configuring GHI

+ Pass: Run ghi for total number of open issues in Github repo (Found: 0)

+ Pass: Run ghi for total number of closed issues in Github repo (Found: 0)

+ Fail: Run ghi for total number of issues in Github repo (Found: 0, Expected: 2) 

 [OPEN issue #] : 

[CLOSED issue #] : 

 




### Test that code on  devel compiles

+ Pass: Checkout devel branch.



+ Pass: Check that directory "project" exists.

+ Pass: Change into directory "project".

+ Fail: Check that file "makefile" exists.

     "makefile" not found.

+ Skip: Check that make compiles.

  This test was not run because of an earlier failing test.

