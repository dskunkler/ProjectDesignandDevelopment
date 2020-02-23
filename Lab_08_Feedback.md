### Fuller Feedback for Lab 08

Run on February 23, 14:47:45 PM.


#### System Files and Lab Directory Structure

+ Pass: Check that directory "googletest" exists.

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab08_google_tests" exists.

+ Pass: Make directory "Lab08_Testing".

+ Pass: Change into directory "Lab08_Testing".


#### Essential Files Exist

+ Pass: Check that file "../labs/lab08_google_tests/date_unittest.cc" exists.


### Testing correct implementation

+ Pass: Copy directory "Lab08 files.".



+ Pass: Copy directory "Files for correct version".



+ Pass: Change into directory "correct".

+ Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>g++ -isystem ../../googletest/include -g -Wall -Wextra -pthread -c ./date.cc
g++ -isystem ../../googletest/include -g -Wall -Wextra -pthread -c ./date_unittest.cc
./date_unittest.cc:14:10: fatal error: lab08_google_tests/date.h: No such file or directory
 #include "lab08_google_tests/date.h"
          ^~~~~~~~~~~~~~~~~~~~~~~~~~~
compilation terminated.
Makefile:85: recipe for target 'date_unittest.o' failed
make: *** [date_unittest.o] Error 1
</pre>



+ Skip: Check that file "date_unittest" exists.

  This test was not run because of an earlier failing test.

+ Skip: Get all google tests.

  This test was not run because of an earlier failing test.


#### Results

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.

+ Skip: Check that a GoogleTest test passes.

  This test was not run because of an earlier failing test.


### Testing Mutants


#### Testing Mutant 1 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 2 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 3 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 4 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 5 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 6 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 7 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 8 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.


#### Testing Mutant 9 for failure

+ Skip: Abstract test class.

  This test was not run because of an earlier failing test.

