#ifndef BASIC_STACK_TPP
#define BASIC_STACK_TPP

#include<iostream>
#include "Node.hpp"

//File: Stack.tpp
////////////////////////////////
// Implementation file for    //
//  Basic Stack class         //
// Written By: Nolan LaDuke   //
// Last Edited: 12/7/2019     //
// For Personal use only      //
////////////////////////////////

  //Constructors:
//==============================================================================

//------------------------------------------------------------------------------
//Destructor
template<typename T>
Stack<T>::~Stack(){
  while(tos != 0){
    Node<T> *temp = tos;
    tos = tos->next;
    delete temp;
  }
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Copy Constructor
template<typename T>
Stack<T>::Stack(const Stack<T>& actual) : Stack() {
  Node<T>* pointRhs = actual.tos;
  Node<T>* pointThis;

  while(pointRhs != 0){
    if(tos == 0){
      tos = new Node<T>(pointRhs->data);
      pointThis = tos;
    }
    else{
      //Create a new Node that's a copy of actual's Node
      pointThis->next = new Node<T>(pointRhs->data);
      //Increment the pointers
      pointThis       = pointThis->next;
    }
    pointRhs        = pointRhs->next;
  }
}
//______________________________________________________________________________

//==============================================================================

  //Functions:
//==============================================================================

//------------------------------------------------------------------------------
//Top Function
//Returns a copy of the element at the top of the Stack
//If the stack is empty, returns a default-constructed T
//Requires: The Stack is not empty
template<typename T>
T Stack<T>::top() const{
  if(!isEmpty())
    return tos->data;
  std::cerr << "ERROR: Attempted to pull from an empty Stack in Stack: Top\n";
  T temp;
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Is Empty Function
//Returns whether or not the Stack is empty
template<typename T>
bool Stack<T>::isEmpty() const{
  return(tos == 0);
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Is Full Function
//Returns whether or not the Stack is full
template<typename T>
bool Stack<T>::isFull() const{
  Node<T> *ptr = new(std::nothrow) Node<T>();
	//ptr = 0 if no memory available
	if(ptr == 0){
		return true;
	}
	delete ptr;
	return false;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Size Function
//Returns the number of elements in the Stack
template<typename T>
int Stack<T>::size() const{
  if(tos == 0){return 0;}
  int ret = 1;
  Node<T>* currentNode = tos;
  while(currentNode->next != 0){
    currentNode = currentNode->next;
    ret++;
  }
  return ret;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Swap Function
template<typename T>
void Stack<T>::swap(Stack<T>& rhs){
  Node<T> *temp = rhs.tos;
  rhs.tos = tos;
  tos = temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Push Function
//Pushes an element onto the top of the Stack
//Requires: The Stack is not full
template<typename T>
void Stack<T>::push(const T& item){
  if(!isFull()){
    Node<T>* temp = new Node<T>(item);
    temp->next = tos;
    tos = temp;
    return;
  }
  std::cerr << "ERROR: Attempted to push an item onto a full Stack in Stack: Push\n";
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Pop Function
//Pops an item off of the top of the Stack
//If the Stack is empty, returns a default-constructed T
//Requires: The Stack is not empty
template<typename T>
T Stack<T>::pop(){
  if(!isEmpty()){
    T item = tos->data;
    Node<T>* temp = tos;
    tos = tos->next;
    delete temp;
    return item;
  }
  std::cerr << "ERROR: Attempted to pop an item off an empty Stack in Stack: Pop\n";
  T temp;
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Remove Function
//Removes an element from inside of the Stack and returns it
//Indexes from [1 - Stack.size()]
template<typename T>
T Stack<T>::remove(const int place){
  int stackSize = size();

  if(place < 1 || place > stackSize){ //Checking for invalid call
    std::cerr << "ERROR: OOB Value passed in Stack::remove" << std::endl;
    return T();
  }

  if(place == 1){ //Case for removing the top of the Stack
    T ret = tos->data;  //Returned Value (Data in tos)
    Node<T>* ptr = tos; //Pointer to delete the removed Node
    tos = tos->next;    //Shift tos down one
    delete ptr;         //Delete the removed Node
    return ret;         //Return
  }

  Node<T>* currentNode = tos;     //Current space in the Stack
  for(int i = 2; i < place; i++){
    //Loop until reaching one before 'place'
    currentNode = currentNode->next;
  }
  Node<T>* temp = currentNode->next; //Pointer to removed Node
  currentNode->next = currentNode->next->next; //Set the Stack to "skip" the removed Node
  T ret = temp->data; //Returned Value
  delete temp;        //Delete the removed Node
  return ret;         //Return

}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Combine Function
//Combines two Stacks, stacking the current one on top of the one passed
template<typename T>
void Stack<T>::combine(Stack<T>& bottomStack){
  Node<T>* currentNode = tos; //Current space in the Stack
  while(currentNode->next != 0){
    currentNode = currentNode->next; //Loop through Stack until reaching the bottom
  }
  currentNode->next = bottomStack.tos; //Set the bottom of the current Stack to point to the top of 'bottomStack'
  bottomStack.tos = 0; //Disassociate bottomStack.tos to avoid pointer inconsistency
}
//______________________________________________________________________________

//==============================================================================

  //Overloaded Operators
//==============================================================================

//------------------------------------------------------------------------------
//Overloaded Assignment Operator
template<typename T>
Stack<T>& Stack<T>::operator=(Stack<T> rhs){
  swap(rhs);
  return *this;
}
//______________________________________________________________________________

//==============================================================================

#endif
