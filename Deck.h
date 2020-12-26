//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_DECK_H
#define UNO_DECK_H

#include "Card.h"
#include <ctime>


//template <class T>
class Deck
{
private:
    Card deck[108];

public:
    int deckSize = 108;
    string cardNames[108];
    Deck();

    Card giveCard(); //gives one card at a time

    int cardIndex = 0;

    void setDeck(); //sets the uno deck of 108
    void shuffle(); //shuffles the deck
    void setCardNamesAndValues(); //set the card names for each card
    void setValues(); //set the values for each card

    string returnCardName(int index); //returns the card name by index

    bool empty() const; //checks if deck is empty

    //template <class S>
    friend ostream& operator << (ostream& outs, const Deck& d);
};


//#include "Deck.cpp"


#endif //UNO_DECK_H
