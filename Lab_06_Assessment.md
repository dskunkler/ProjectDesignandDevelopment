### Assessment for Lab 06

#### Total score: _10_ / _100_

Run on February 18, 13:44:11 PM.


#### System Files and Directory Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab06_gdb" exists.

+ Pass: Change into directory "labs/lab06_gdb".

+  _10_ / _10_ : Pass: Replace doInterestingThing(1999); with doInterestingThing(1999);doInterestingThing(2018); in main.cc.




#### Test that code compiles and creates the exectuable

+  _0_ / _30_ : Fail: Check that make compiles.

    Make compile fails with errors:.
<pre>g++ -Wall -g -c -o Date.o Date.cc
g++ -Wall -g -o date main.cc Date.o Exceptions.o
Date.o: In function `Date::before(Date const&) const':
/project/grades/Spring-2020/csci3081/ghosh117/grading-environment/grading-scripts/grading/Lab_06_Assessment_section20/repo-kunkl007/labs/lab06_gdb/Date.cc:127: undefined reference to `InvalidData::InvalidData(std::string)'
Date.o: In function `mkDate(int, int, int)':
/project/grades/Spring-2020/csci3081/ghosh117/grading-environment/grading-scripts/grading/Lab_06_Assessment_section20/repo-kunkl007/labs/lab06_gdb/Date.cc:157: undefined reference to `InvalidData::InvalidData(std::string)'
Date.o: In function `mkDate_ptr(int, int, int)':
/project/grades/Spring-2020/csci3081/ghosh117/grading-environment/grading-scripts/grading/Lab_06_Assessment_section20/repo-kunkl007/labs/lab06_gdb/Date.cc:169: undefined reference to `InvalidData::InvalidData(std::string)'
Exceptions.o: In function `InvalidData::InvalidData(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)':
/home/kunkl007/3081_s20/repo-kunkl007/labs/lab06_gdb/Exceptions.cc:17: undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string()'
/home/kunkl007/3081_s20/repo-kunkl007/labs/lab06_gdb/Exceptions.cc:18: undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::operator=(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
/home/kunkl007/3081_s20/repo-kunkl007/labs/lab06_gdb/Exceptions.cc:17: undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string()'
Exceptions.o: In function `InvalidData::~InvalidData()':
/home/kunkl007/3081_s20/repo-kunkl007/labs/lab06_gdb/Exceptions.cc:21: undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::~basic_string()'
Exceptions.o: In function `InvalidData::get_msg[abi:cxx11]()':
/home/kunkl007/3081_s20/repo-kunkl007/labs/lab06_gdb/Exceptions.cc:25: undefined reference to `std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)'
collect2: error: ld returned 1 exit status
Makefile:6: recipe for target 'date' failed
make: *** [date] Error 1
</pre>



+  _0_ / _10_ : Skip: Check that file "date" exists.

  This test was not run because of an earlier failing test.


#### Test Output Execution

+  _0_ / _10_ : Skip: Program executes flawlessly.

  This test was not run because of an earlier failing test.

+  _0_ / _5_ : Skip: Check for correct output.

  This test was not run because of an earlier failing test.

+ Skip: Replace i <= with i < in main.cc.

  This test was not run because of an earlier failing test.

+ Skip: Check that make compiles.

  This test was not run because of an earlier failing test.

+  _0_ / _20_ : Skip: Most of the program works.

  This test was not run because of an earlier failing test.

+  _0_ / _15_ : Skip: Check for correct output.

  This test was not run because of an earlier failing test.

#### Total score: _10_ / _100_

