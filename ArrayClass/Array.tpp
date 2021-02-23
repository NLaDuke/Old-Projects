#ifndef DYNAMIC_ARRAY_TPP
#define DYNAMIC_ARRAY_TPP

#include<iostream>
#include<cassert>

//File: Array.tpp
///////////////////////////////////
// Implementation file for       //
//  Dynamic Array class          //
// Written by: Nolan LaDuke      //
// Last Edited: 11/2/2019        //
// For personal use only         //
///////////////////////////////////

  //Constructors:
//==============================================================================

//------------------------------------------------------------------------------
//Default Constructor:
//Creates an Array of size 0
template<typename T>
Array<T>::Array(){
  size = 0;
  ptr = new T[size];
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Capacity Constructor
//Creates an Array of size 'cap'
//Requires: 'cap' is a non-negative number
template<typename T>
Array<T>::Array(int cap){
  if(cap < 0){
    std::cerr << "ERROR: OOB value passed in Array: Capacity Constructor\n";
  }
  size = cap;
  ptr = new T[size];
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Destructor
template<typename T>
Array<T>::~Array(){
  delete[] ptr;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Copy Constructor
template<typename T>
Array<T>::Array(const Array<T>& actual){
  size = actual.size;
  ptr = new T[size];
  for(int i = 0; i < size; i++){
    ptr[i] = actual.ptr[i];
  }
}
//______________________________________________________________________________

//==============================================================================

  //Functions
//==============================================================================

//------------------------------------------------------------------------------
//Printout Function
//Prints out each element of the Array separated by a given character
//Includes a space between each element if 'split' is not '\n'
//Requires: 'T' has a valid output operator
template<typename T>
void Array<T>::printOut(char split) const{
  for(int i = 0; i < size-1; i++){
    std::cout << ptr[i] << split;
    if(split != '\n') std::cout << " ";
  }
  if(size != 0) std::cout << ptr[size-1];
  std::cout << std::endl;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Reverse Function
//Returns a copy of the Array reversed (last -> first)
template<typename T>
Array<T> Array<T>::reverse() const{
  Array<T> temp = Array<T>(size);
  int point = 0;
  for(int i = size-1; i >= 0; i--){
    temp[point] = ptr[i];
    point++;
  }
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Bubble-Sort function
//Returns a copy of the Array sorted using the Bubble algorithm
template<typename T>
Array<T> Array<T>::bubbleSort() const{
  Array<T> temp = Array<T>(*this);
  while(!temp.isSorted()){
    for(int i = 0; i < temp.getSize()-1; i++){
      if(temp.ptr[i] > temp.ptr[i+1]){
        temp.swapAround(i, i+1);
      }
    }
  }
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Selection-Sort Function
//Returns a copy of the Array sorted using the Selection algorithm
template<typename T>
Array<T> Array<T>::selectSort() const{
  Array<T> temp = Array<T>(*this);
  int tempSize = temp.getSize();
  while(!temp.isSorted()){
    int biggestLoc = 0;
    for(int i = 0; i < tempSize; i++){
      if(temp[i] > temp[biggestLoc]) biggestLoc = i;
    }
    temp.swapAround(biggestLoc, tempSize-1);
    tempSize--;
  }
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Is-Sorted Function
//Returns whether or not the Array is sorted from smallest -> greatest
//Requires: 'T' has valid Comparison Operators
template<typename T>
bool Array<T>::isSorted() const{
  for(int i = 0; i < size-1; i++){
    if(ptr[i] > ptr[i+1]) return false;
  }
  return true;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Swap Function
//Swaps around the components of two Arrays
template<typename T>
void Array<T>::swap(Array<T>& rhs){
  //Swap around pointers
    T * temp = ptr;
    ptr = rhs.ptr;
    rhs.ptr = temp;
  //Swap around sizes
    int tmp = size;
    size = rhs.size;
    rhs.size = tmp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Push Function
//Increments the size of the Array and adds a given element to the end
template<typename T>
void Array<T>::pushOn(const T& add){
  resize(size+1);
  ptr[size-1] = add;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Pop Function
//Decrements the size of the Array, and returns the element at the end
//Requires: The Array contains an item
template<typename T>
T Array<T>::popOff(){
  assert(size > 0);
  T temp = ptr[size-1];
  resize(size-1);
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Pluck Function
//Removes an item from a given space in the Array and returns it
//Returns ptr[0] if an error occurs
//Requires: 'space' is between 0 and size-1, the Array contains an item
template<typename T>
T Array<T>::pluckOut(int space){
  if((space < 0) || (space >= size)){
    std::cerr << "ERROR: OOB value passed in Array::pluckOut\n";
    return ptr[0];
  }
  T temp = ptr[space];
  for(int i = space; i < size-1; i++){
    ptr[i] = ptr[i+1];
  }
  resize(size-1);
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Place Function
//Inserts an item into a given space in the Array, shiftind down other elements
//Requires: 'space' is between 0 and size
template<typename T>
void Array<T>::placeIn(int space, const T& item){
  if((space < 0) || (space >= size)){
    std::cerr << "ERROR: OOB value passed in Array::placeIn\n";
    return;
  }
  if(space == size-1){
    pushOn(item);
    return;
  }
  resize(size+1);
  T temp = ptr[space];
  T hold;
  ptr[space] = item;
  for(int i = space+1; i < size-1; i++){
    hold = ptr[i];
    ptr[i] = temp;
    temp = hold;
  }
  ptr[size-1] = temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Read In Function
//Reads in from an input a given number of times
//If it reaches the end of the file, it will return the original Array unmodified
//Requires: 'T' has a valid input operator
template<typename T>
void Array<T>::readIn(std::istream& in, int run){
  int count = 0;
  int space = size;
  T temp;
  Array<T> temp = Array<T>(*this);
  resize(size + run);
  while(count < run){
    if(in.eof()){
      swap(temp);
      std::cerr << "ERROR: End of File reached when looping in Array::readIn\n";
      return;
    }
    in >> temp;
    ptr[space] = temp;
    space++; count++;
  }
}
//______________________________________________________________________________

//==============================================================================

  //Overloaded Operators
//==============================================================================

//------------------------------------------------------------------------------
//Overloaded Assignment Operator
//Takes in an Array and copies it into this Array
template<typename T>
Array<T>& Array<T>::operator=(Array<T> rhs){
  swap(rhs);
  return *this;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Subscript Operator
//Returns a copy of a space in the Array
//Requires: 'loc' is between 0 and size
template<typename T>
T Array<T>::operator[](int loc) const{
  if((loc >= size) || (loc < 0)){
    std::cerr << "ERROR: OOB input in Array: operator[]\n";
    return ptr[0];
  }
  return ptr[loc];
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Subscript Operator
//Returns a reference to a space in the Array
//Requires: 'loc' is between 0 and size
template<typename T>
T& Array<T>::operator[](int loc){
  if((loc >= size) || (loc < 0)){
    std::cerr << "ERROR: OOB input in Array: operator[]\n";
    return ptr[0];
  };
  return ptr[loc];
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Addition Operator
//Returns two Arrays added together
//Format: end of the first starts the beginning of the second
template<typename T>
Array<T> Array<T>::operator+(const Array<T>& rhs){
  Array<T> temp = Array<T>(*this);   //Returned object
  temp.resize(size + rhs.size);
  int pntr = 0;                      //Current space in 'rhs'
  for(int i = size; i < temp.size; i++){
    temp[i] = rhs[pntr];
    pntr++;
  }
  return temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Shorthand Addition Operator
//Adds an Array to 'this' and returns a reference to it
//Format: end of the first starts the beginning of the second
template<typename T>
Array<T>& Array<T>::operator+=(const Array<T> & rhs){
  int tempSize = size;   //Initial size of Array
  resize(size + rhs.size);
  int pntr = 0;
  for(int i = tempSize; i < size; i++){
    ptr[i] = rhs[pntr];
    pntr++;
  }
  return *this;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Equals Operator
//Returns a boolean for if two Arrays are equal in length and contents
//Requires: 'T' has a valid Equals Operator
template<typename T>
bool Array<T>::operator==(const Array<T>& rhs) const{
  if(rhs.size != size) return false;
  for(int i = 0; i < size; i++){
    if(ptr[i] != rhs[i]) return false;
  }
  return true;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Less-Than Operator
//Returns a boolean for if one Array is less than another
//Requires: 'T' has a valid Less-Than Operator
template<typename T>
bool Array<T>::operator<(const Array<T>& rhs) const{
  if(rhs.size  > size) return true;
  for(int i = 0; i < size; i++){
    if(ptr[i] < rhs[i]) return true;
  }
  return false;
}
//______________________________________________________________________________

//==============================================================================

  //Friend Functions
//==============================================================================

//------------------------------------------------------------------------------
//Overloaded Output Operator
//Prints out each element of the Array, separated by a space
//Requires: 'T' has a valid Output Operator
template<typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& rhs){
  for(int i = 0; i < rhs.size; i++){
    out << rhs.ptr[i] << " ";
  }
  return out;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Overloaded Input Operator
//Reads in an element and pushes it onto the end of the Array
//Requires: 'T' has a valid Input Operator
template<typename T>
std::istream& operator>>(std::istream& in, const Array<T>& rhs){
  if(in.eof()){
    std::cerr << "ERROR: Attempted to call Array::operator>> when 'in' is empty\n";
  }
  T temp;
  in >> temp;
  rhs.pushOn(temp);
  return in;
}
//______________________________________________________________________________

//==============================================================================

  //Private Functions
//==============================================================================

//------------------------------------------------------------------------------
//Resize Function
//Changes the size of an Array, truncating if the new size is smaller
//Requires: 'newSize' is a non-negative number
template<typename T>
void Array<T>::resize(int newSize){
  if(newSize < 0){
    std::cerr << "ERROR: OOB value passed in Array::resize\n";
    return;
  }
  int smaller = (size < newSize) ? size : newSize;
  size = newSize;
  T *temp = new T[size];
  for(int i = 0; i < smaller; i++){
    temp[i] = ptr[i];
  }
  delete[] ptr;
  ptr = temp;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Switch function
//Swaps two spaces in the Array
//Requires: 'space1' and 'space2' are both between 0 and size-1
template<typename T>
void Array<T>::swapAround(int space1, int space2){
  if(((space1 < 0) || (space1 >= size)) || ((space2 < 0) || (space2 >= size))){
    std::cout << "ERROR: OOB value passed in Array::switch\n";
    return;
  }
  T temp = ptr[space1];
  ptr[space1] = ptr[space2];
  ptr[space2] = temp;
}
//______________________________________________________________________________

//==============================================================================

  //Free Functions
//==============================================================================

//==============================================================================

#endif
