#ifndef CARD_HPP
#define CARD_HPP

#include<iostream>
#include<string>

//File: Card.hpp
//////////////////////////////////
// Header file for Card class  //
// Written by: Nolan LaDuke    //
// Last Edited: 2/11/2020      //
//////////////////////////////////////////
// Class Requirements:                  //
//'value' range: -1, 1-13               //
//'suit' range: 0-4                     //
//'color' range: 0-1                    //
//All variables must be declared for    //
// functions to be called               //
//////////////////////////////////////////////////////
//General Notes:                                    //
//  Comparison operators are based only on 'value'  //
//  not on 'suit' / 'color' / 'symbol'              //
//////////////////////////////////////////////////////
class Card{
public:
    //Public Elements:
  int value;  //Value of the card (-1, 1-13) | (Jack, A - K)
  int suit ;  //Suit of the card  (0-4)      | (Jkr,♥,♦,♣,♠)
  int color;  //Color of the card (0-1)      | (0 = Red, 1 = Black)

    //Constructors:
  Card  ()                     ; //Default Constructor
  ~Card ()                     ; //Destructor
  Card  (const Card&)          ; //Copy Constructor
  Card  (int, int)             ; //Generic Deck Constructor
  Card  (int, int, std::string); //Modular Deck Constructor

    //Public Functions:
  bool isJoker() const {return joker;}; //Returns whether or not the card is a Joker
  void swap(Card&)                    ; //Swap Function


    //Overlaoded Operators:
  Card& operator= (Card)             ; //Overloaded Assignment Operator
  bool  operator< (const Card&) const; //Overloaded '<' Comparison Operator
  bool  operator==(const Card&) const; //Overloaded Equals Operator

    //Friend Functions:
  friend std::ostream& operator<<(std::ostream&, const Card&);

private:
    //Private Elements:
  std::string symbol;  //Symbol of the Card (A, 2-10, J, Q, K)
  bool joker;          //Boolean for whether or not the card is a Joker
};

  //Free Functions:
//Comparison Operators:
bool operator> (const Card& lhs, const Card& rhs) {return (rhs<lhs);};
bool operator>=(const Card& lhs, const Card& rhs) {return ((lhs>rhs) || (lhs==rhs));};
bool operator<=(const Card& lhs, const Card& rhs) {return ((rhs>lhs) || (lhs==rhs));};
bool operator!=(const Card& lhs, const Card& rhs) {return !(lhs==rhs);};

#endif
