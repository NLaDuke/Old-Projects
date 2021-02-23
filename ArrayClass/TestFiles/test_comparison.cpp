#include "Array.hpp"
#include <cassert>
#include <iostream>

//File: test_comparison.cpp
///////////////////////////////////////////
// Testing file for Dynamic Array class  //
// Written by: Nolan LaDuke              //
// Last Edited: 11/__/2019               //
// For personal use only                 //
///////////////////////////////////////////

//Tests: Comparison Operators (<, <=, >, >=, ==)
int main(){
  std::cout << "==============================\n";
  std::cout << "Testing: Comparison Operators\n\n";
    //Case: Tests all operators on Empty Arrays
  {
    //Declaration
    Array<int> test1;
    Array<int> test2;
    //Verification
    assert(!(test1 < test2));
    assert(!(test1 > test2));
    assert(test1 <= test2);
    assert(test1 >= test2);
    assert(test1 == test2);
  }
    //Case: Tests all operators on Generic Arrays
  {
    //Declaration
    Array<int> test1(25);
    Array<int> test2(25);
    for(int i = 0; i < 25; i++){
      test1[i] = i;
      test2[i] = i % 3;
    }
    //Verification
    assert(!(test1 < test2));
    assert(test1 > test2);
    assert(!(test1 <= test2));
    assert(test1 >= test2);
    assert(!(test1 == test2));
  }
    //Case: Tests all operators on Generic Arrays of unequal size
  {
    //Declaration
    Array<char> test1(20);
    Array<char> test2(25);
    for(int i = 0; i < 25; i++){
      test1[i % 20] = i;
      test2[i] = i;
    }
    //Verification
    assert(test1 < test2);
    assert(!(test1 > test2));
    assert(test1 <= test2);
    assert(!(test1 >= test2));
    assert(!(test1 == test2));
  }
    //Case: Tests all operators on Large Arrays
  {
    //Declaration
    Array<char> test1(1000);
    Array<char> test2(1000);
    for(int i = 0; i < 1000; i++){
      test1[i] = test2[i] = i;
    }
    test2[999] = 0;
    //Verification
    assert(!(test1 < test2));
    assert(test1 > test2);
    assert(!(test1 <= test2));
    assert(test1 >= test2);
    assert(!(test1 == test2));
  }
    //Case: Tests all operators on Large, Equal Arrays
  {
    //Declaration
    Array<char> test1(1000);
    Array<char> test2(1000);
    for(int i = 0; i < 1000; i++){
      test1[i] = test2[i] = i;
    }
    //Verification
    assert(!(test1 < test2));
    assert(!(test1 > test2));
    assert(test1 <= test2);
    assert(test1 >= test2);
    assert(test1 == test2);
  }
  std::cout << "\nFinished Test\n";
  std::cout << "==============================\n";
  return 0;
}
