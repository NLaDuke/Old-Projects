
#include<iostream>
#include<string>
#include "Card.hpp"

//File: card.cpp
////////////////////////////////////////
// Implementation file for card class //
// Written by: Nolan LaDuke           //
// Last Edited: 2/11/2020             //
////////////////////////////////////////

  //Constructors:
//==============================================================================

//------------------------------------------------------------------------------
//Default Constructor:
//Creates a generic, invalid Card
Card::Card(){
  value = 0;
  suit = 0;
  color = 0;
  symbol = '*';
  joker = false;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Destructor:
//Deletes nothing
Card::~Card(){
  //May need to change this
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Copy Constructor:
Card::Card(const Card& rhs){
  value = rhs.value;
  suit = rhs.suit;
  color = rhs.color;
  joker = rhs.isJoker();
  symbol = rhs.symbol;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Generic Constructor:
//Creates a complete Card based on a passed suit & value
//Used for traditional 52 - 54 card decks
Card::Card(int val, int sui){
  value = val;
  suit = sui;
  (sui < 5) ? (color = 0) : (color = 1);

  switch(value){
    case 1: symbol = "A"; break;
    case 11: symbol = "J"; break;
    case 12: symbol = "Q"; break;
    case 13: symbol = "K"; break;
    default: symbol = char(value + 48);
  }

  joker = false;

  if(value == -1){
    joker = true;
    symbol = "Jkr";
  }
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Modular Constructor:
//Creates a complete Card based on a passed suit, value, & symbol
//Used for decks with non-traditional values / symbols / sizes
Card::Card(int val, int sui, std::string sym){
  value = val;
  suit = sui;
  symbol = sym;
  (sui < 5) ? (color = 0) : (color = 1);
  joker = false;
  if(value == -1){
    joker = true;
  }
}
//______________________________________________________________________________

//==============================================================================

  //Public Functions
//==============================================================================

//------------------------------------------------------------------------------
//Swap function
void Card::swap(Card& rhs){
  int temp = value;
  value = rhs.value;
  rhs.value = temp;

  temp = suit;
  suit = rhs.suit;
  rhs.suit = temp;

  temp = color;
  color = rhs.color;
  rhs.color = temp;

  std::string tempStr = symbol;
  symbol = rhs.symbol;
  rhs.symbol = tempStr;

  bool tempBool = joker;
  joker = rhs.joker;
  rhs.joker = tempBool;
}
//______________________________________________________________________________

//==============================================================================

  //Overloaded Operators
//==============================================================================

//------------------------------------------------------------------------------
//Assignment Operator
Card& Card::operator=(Card rhs){
  swap(rhs);
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Less Than Operator
//Compares the two cards based on their 'value'
bool Card::operator<(const Card& rhs) const{
  return value < rhs.value;
}
//______________________________________________________________________________

//------------------------------------------------------------------------------
//Equals Operator
//Returns 'true' if the two cards have the same 'value'
//Does not worry about suit/color/symbol
bool Card::operator==(const Card& rhs) const{
  return value == rhs.value;
}
//______________________________________________________________________________

//==============================================================================

  //Friend Functions
//==============================================================================

//------------------------------------------------------------------------------
//Overloaded Output Operator
//Prints out in the following format:
//  "| SymSuit |"
std::ostream& operator<<(std::ostream& out, const Card& card){
  out << "| ";
  if(card.isJoker()){
    out << card.symbol << " |";
    return out;
  }
  else if(card.value == 10){
    out << card.symbol;
  }
  else{
    out << card.symbol << " ";
  }
  switch(card.suit){
    case 1: out << "♥"; break;
    case 2: out << "♦"; break;
    case 3: out << "♣"; break;
    case 4: out << "♠"; break;
    default: out << char(card.suit);
  }
  out << " |";
  return out;
}
//______________________________________________________________________________

//==============================================================================
