#ifndef BASIC_STACK_HPP
#define BASIC_STACK_HPP

#include<iostream>
#include "Node.hpp"

//File: Stack.hpp
//////////////////////////////////////////
// Header file for                      //
//          Basic Stack class           //
// Written by: Nolan LaDuke             //
// Last Edited: 12/5/2019               //
// For personal use only                //
//////////////////////////////////////////
// Class Requirements:                  //
// -                                    //
// - Don't run out of heap space        //
//////////////////////////////////////////

template<typename T>
class Stack{
public:
    //Constructors:
  Stack () : tos(0)                 {} ; //Default Constructor
  ~Stack()                             ; //Destructor
  Stack (const Stack<T>&)              ; //Copy Constructor

    //Functions:
  //Operations
  T    top     ()  const; //Returns a copy of the item at the top of the Stack
  bool isEmpty ()  const; //Returns whether or not the Stack is empty
  bool isFull  ()  const; //Returns whether or not the Stack is full
  int  size    ()  const; //Returns the number of elements in the Stack

  //Modifications
  void swap    (Stack<T>&) ; //Swap Function
  void push    (const T&)  ; //Pushes an item on the Stack
  T    pop     ()          ; //Pops an item off the Stack and returns it
  T    remove  (const int ); //Removes an item from inside of the Stack and returns it [Indexed 1-size()]
  void combine (Stack<T>& ); //Combines two stacks ('this' Stack on top of the one passed)

    //Operators:
  Stack<T>& operator=(Stack<T>); //Overloaded Assignment Operator

private:
    //Private Functions:

    //Private Elements:
    Node<T> *tos;
};

#include "Stack.tpp"

#endif
