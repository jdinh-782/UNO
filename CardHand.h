//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_CARDHAND_H
#define UNO_CARDHAND_H

#include "Deck.h"
#include <vector>


//template <class T>
class CardHand
{
public:
    int handSize = 0;
    vector<Card> hand; //vector to store the cards in the user's hand

    CardHand();

    Card& addCard(Deck& d); //adds one card to the user's hand
    void removeCard(int index); //deletes the card based off the index from the user's hand

    //template <class S>
    friend ostream& operator << (ostream& outs, const CardHand& ch);
};


//#include "CardHand.cpp"


#endif //UNO_CARDHAND_H
