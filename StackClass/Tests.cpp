#include <iostream>
#include "Stack.hpp"

int main(){
  std::cout << "Testing Stack Class (Poorly)" << std::endl;
  Stack<int> test;
  Stack<char> testSize;
  for(int i = 0; i < 10; i++){
    test.push(i);
  }
  for(int i = 0; i < 1000; i++){
    testSize.push('A');
  }
  std::cout << test.size() << std::endl;
  std::cout << testSize.size() << std::endl;
  std::cout << test.top() << test.top() << "\n";
  Stack<int> test2(test);
  std::cout << test.pop() << std::endl;
  Stack<int> test3 = test2;
  std::cout << test2.pop();
  std::cout << test3.pop();
  std::cout << test2.top();
  std::cout << test3.pop();
  std::cout << test2.pop();
  std::cout << std::endl;

  std::cout << "Testing Remove Function" << std::endl;
  Stack<int> testRemove;
  for(int i = 100; i > 0; i--){
    testRemove.push(i);
  }
  std::cout << testRemove.remove(5);
  std::cout << testRemove.remove(5);
  std::cout << testRemove.remove(5);
  std::cout << testRemove.remove(100) << std::endl;
  std::cout << testRemove.remove(97) << std::endl;
  while(!testRemove.isEmpty()){
    std::cout << testRemove.remove(1);
  }
  std::cout << std::endl;

  std::cout << "Testing Combine Function" << std::endl;
  Stack<int> testC1;
  Stack<int> testC2;
  for(int i = 0; i < 15; i++){
    testC1.push(i);
    testC2.push(i);
  }
  testC1.combine(testC2);
  while(!testC1.isEmpty()){
    std::cout << testC1.pop() << std::endl;
  }
  std::cout << "Break" << std::endl;
  while(!testC2.isEmpty()){
    std::cout << testC2.pop() << std::endl;
  }
  return 0;
}
