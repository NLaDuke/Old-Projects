#include "Card.cpp"
#include <iostream>
#include <cassert>

int main(){
  std::cout << "Testing Constructors:\n";
  Card test1(1,4);
  Card test2(-1,0);
  Card test3(5,3);
  Card test4(13,3);
  Card test5 = test3;
  Card test6(test5);
  test6 = Card(1,1);
  std::cout << test1 << std::endl;
  std::cout << test2 << std::endl;
  std::cout << test3 << std::endl;
  std::cout << test4 << std::endl;
  std::cout << test5 << std::endl;
  std::cout << test6 << std::endl;
  std::cout << "Testing Destructor" << std::endl;
  Card* testPtr = new Card(1,1);
  std::cout << *testPtr << std::endl;
  delete testPtr;
  std::cout << "Testing Comparison Operators:" << std::endl;
  test1 = Card(1,1);
  test2 = Card(1,2);
  test3 = Card(2,1);
  assert(test1 < test3);
  assert(!(test1 > test2));
  assert(test1 == test2);
  assert(test1 <= test3);
  assert(test1 >= test2);
  assert(test1 != test3);
  std::cout << "Finished Tests" << std::endl;
  return 0;
}
