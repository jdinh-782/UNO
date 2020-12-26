//
// Created by jdinh on 12/5/2020.
//
//#ifndef UNO_CARDHAND_H
//#define UNO_CARDHAND_H

#include "CardHand.h"


//template <class T>
CardHand::CardHand()
= default;


//template <class T>
Card& CardHand::addCard(Deck& d)
{
    hand.push_back(d.giveCard());
    d.cardIndex++;
    handSize++;
    return hand[handSize-1];
}


//template <class T>
void CardHand::removeCard(int index)
{
    hand.erase(hand.begin() + index);
    handSize--;
}


//template <class S>
ostream& operator << (ostream& outs, const CardHand& ch)
{
    for (int i = 0; i < ch.handSize; i++)
    {
        outs << ch.hand[i] << endl;
    }
    return outs;
}