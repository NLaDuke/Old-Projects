#ifndef LL_NODE_HPP
#define LL_NODE_HPP

//File: Node.hpp
//////////////////////////////
// Node Class               //
//   For Single Linked List //
// By: Nolan LaDuke         //
// Last Edited: 12/7/2019   //
//////////////////////////////

template<typename T>
class Node{
public:
    //Constructors
  Node() : next(0)                          {} ;
  Node(const T& item) : data(item), next(0) {} ;
    //Public Elements
  T        data; //Object that the Node contains
  Node<T> *next; //Pointer to the next Node
};

#endif
