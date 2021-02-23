#include "Array.hpp"
#include <cassert>
#include <iostream>

//File: test_addition.cpp
///////////////////////////////////////////
// Testing file for Dynamic Array class  //
// Written by: Nolan LaDuke              //
// Last Edited: 11/__/2019               //
// For personal use only                 //
///////////////////////////////////////////

//Tests: Addition and Shorthand Operators
int main(){
  std::cout << "==============================\n";
  std::cout << "Testing: Addition Operators\n\n";
    //Case: Adding Empty Arrays
  {
    //Declaration
    Array<char> test1;
    Array<char> test2;
    //Test
    Array<char> test3 = test1 + test2;
    //Verification
    assert(test3 == test1);
    assert(test3.isEmpty())
  }
    //Case: Adding a Non-Empty Array to an Empty Array using shorthand
  {
    //Declaration
    Array<int> test1(5);
    Array<int> test2;
    for(int i = 0; i < 5; i++){
      test1[i] = i;
    }
    //Test
    test2 += test1;
    //Verification
    assert(test2 == test1);
    assert(test2.getSize() == 5);
    assert(!test2.isEmpty());
  }
    //Case: Adding several Non-Empty Arrays using long and shorthand
  {
    //Declaration
    Array<char> test1(15);
    Array<char> test2(15);
    Array<char> test3(15);
    Array<char> test4;
    for(int i = 0; i < 15; i++){
      test1[i] = char(i);
      test2[i] = char(i);
      test3[i] = char(i);
    }
    //Test
    test1 += test2;
    test3 = test2 + test3;
    test4 = test3 + test1;
    //Verification
    assert(test3 == test1);
    assert(test4.getSize() == 60);
  }
    //Case: Adding with Large Arrays
  {
    //Declaration
    Array<int> test1(1000);
    Array<int> test2(457);
    Array<int> test3;
    for(int i = 0; i < 1000; i++){
      test1[i] = i % 5;
    }
    for(int i = 0; i < 457; i++){
      test2[i] = i;
    }
    //Test
    test3 += test1 + test2;
    test1 = test1 + test2;
    //Verification
    assert(test3.getSize() == 1457);
    assert(test2.getSize() == 457);
    assert(test1.getSize() == 1457);
  }
    //Case: Adding an Empty Array to an Empty Array through shorthand
  {
    //Declaration
    Array<bool> test1;
    Array<bool> test2;
    //Test
    for(int i = 0; i < 25; i++){
      test1 += test2;
    }
    //Verification
    assert(test1 == test2);
    assert(test1.isEmpty());
    assert(test2.isEmpty());
  }

  std::cout << "\nFinished Test\n";
  std::cout << "==============================\n";
  return 0;
}
