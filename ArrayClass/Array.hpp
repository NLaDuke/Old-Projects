#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include<iostream>

//File: Array.hpp
//////////////////////////////////////////
// Header file for                      //
//          Dynamic Array class         //
// Written by: Nolan LaDuke             //
// Last Edited: 11/2/2019               //
// For personal use only                //
//////////////////////////////////////////
// Class Requirements:                  //
// - Every element of the array should  //
//   be defined at all times            //
// - Don't run out of heap space        //
//////////////////////////////////////////

template<typename T>
class Array{
public:
    //Constructors
  Array  ()                ;  //Default Constructor
  Array  (int)             ;  //Capacity Constructor
  ~Array ()                ;  //Destructor
  Array  (const Array<T>&) ;  //Copy Constructor

    //Functions
  //Operations
  int       getSize   ()     const {return size;}     ; //Gets the Array size
  void      printOut  (char) const                    ; //Prints out the Array separated by a given character
  Array<T>  reverse   ()     const                    ; //Returns a copy of the Array reversed
  Array<T>  bubbleSort()     const                    ; //Returns a copy of the Array sorted using Bubble Sort
  Array<T>  selectSort()     const                    ; //Returns a copy of the Array sorted using Selection Sort
  bool      isEmpty   ()     const {return size==0;}  ; //Returns whether or not the Array is empty
  bool      isSorted  ()     const                    ; //Returns whether or not the Array is sorted smallest -> greatest
  //Modifications
  void      swap      (Array<T>&)                     ; //Swap function
  void      pushOn    (const T&)                      ; //Adds an item to the end of the Array, incrementing the size of the Array
  T         popOff    ()                              ; //Removes an item from the end of the Array and returns it
  T         pluckOut  (int)                           ; //Removes an item from a space in the Array and returns it
  void      placeIn   (int, const T&)                 ; //Adds an item into a space in the Array and increments its size
  void      empty     ()                  {resize(0);}; //Removes all elements from the Array and resets 'size' to 0
  void      readIn    (std::istream&, int)            ; //Reads in from an input stream a given number of times

    //Operators
  Array<T>& operator= (Array<T>)              ; //Overloaded Assignment Operator
  T         operator[](int)              const; //Overloaded Copy Subscript Operator
  T&        operator[](int)                   ; //Overloaded Reference Subscript Operator
  Array<T>  operator+ (const Array<T>&)       ; //Overloaded Addition Operator
  Array<T>& operator+=(const Array<T>&)       ; //Overloaded Shorthand Addition Operator
  bool      operator==(const Array<T>&)  const; //Overloaded Equals Operator
  bool      operator< (const Array<T>&)  const; //Overloaded Less-Than Operator

    //Friend Functions
  template<typename t>  //Overloaded Output Operator
  friend std::ostream& operator<<(std::ostream&, const Array<t>&);
  template<typename t>  //Overloaded Input Operator
  friend std::istream& operator>>(std::istream&, const Array<t>&);

private:
    //Private Functions
  void resize     (int)     ; //Resizes the Array
  void swapAround (int, int); //Swaps two spaces in the Array
    //Private Elements
  int size;
  T * ptr;
};

  //Free Functions
template<typename T>
bool operator<=(const Array<T>& lhs, const Array<T>& rhs) {return ((lhs == rhs) || (lhs < rhs));};
template<typename T>
bool operator> (const Array<T>& lhs, const Array<T>& rhs) {return (rhs < lhs);};
template<typename T>
bool operator>=(const Array<T>& lhs, const Array<T>& rhs) {return ((rhs == lhs) || (rhs < lhs));};

#include "Array.tpp"
#endif
