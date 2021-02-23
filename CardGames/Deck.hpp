#ifndef DECK_HPP
#define DECK_HPP

#include "../StackClass/Stack.hpp"
#include "Card.hpp"
#include <iostream>
#include <ifstream>
#include <string>

//File: Deck.hpp
////////////////////////////////
// Header file for Deck class //
// Written by: Nolan LaDuke   //
// Last Edited: 2/17/2020     //
////////////////////////////////////////////////
// Class Requirements:
//  Must have initialized the discard pile to
//  call discard-oriented functions
////////////////////////////////////////////////

class Deck{
public:
    //Constructors:
  Deck()           ; //Default Constructor
  ~Deck()          ; //Destructor
  Deck(const Deck&); //Copy Constructor
  Deck(std::string); //File Constructor

    //Public Functions:
  //Operations:
  bool isEmpty() const {return pile.isEmpty();}; //Returns whether or not 'pile' is empty
  Card scryTop      () const; //Returns a copy of the top Card of the Deck
  void revealTop    () const; //Prints out the top Card of the Deck
  void printDiscard () const; //Prints out the contents of the discard pile

  //Modifiers:
  void swap           (Deck&) ; //Swap Function
  void shuffle        ()      ; //Shuffles the Deck
  void shuffleDiscard ()      ; //Shuffles the discard pile into the deck
  void discardTop     ()      ; //Discards the top card of the deck
  Card drawTop        ()      ; //Removes and returns the top Card of the deck

    //Overloaded Operators:
  Deck& operator=(Deck); //Overloaded Assignment Operator
private:
  Stack<Card> pile;     //Deck
  Stack<Card> discard;  //Discard Pile (Need not always be initialized)
}

//May need to implement a function in the Stack class that prints out the Stack
//in order to make printDiscard() happen without some real fuckery
//Don't love the idea (because it becomes much harder to implement w/ graphics)
//Maybe there's something with a friend class or some shit I can do... not sure
//Test first → if issues then fix (don't assume it won't work)





#endif
