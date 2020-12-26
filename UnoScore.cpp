//
// Created by jdinh on 12/5/2020.
//
//#ifndef UNO_UNOSCORE_CPP
//#define UNO_UNOSCORE_CPP
#include "UnoScore.h"



//template <class T>
UnoScore::UnoScore()
= default;


//template <class T>
bool UnoScore::checkCard(CardHand& ch, CardHand& middleCard, int index)
{
    if (ch.hand[index].returnValue() >= 13 && ch.hand[index].returnValue() <= 14) //check for plusTwo, plusFour, and wildCard
    {
        return true;
    }
    if (ch.hand[index].returnValue() == middleCard.hand[0].returnValue() ||
        ch.hand[index].returnColor() == middleCard.hand[0].returnColor())
    {
        return true;
    }
    return false;
}


int UnoScore::cardToUse(CardHand& ch, CardHand& middleCard, int index)
{
    //check for skip card (color and value)
    if (ch.hand[index].returnValue() == 10 && ch.hand[index].returnColor() == middleCard.hand[0].returnColor()
        || ch.hand[index].returnValue() == 10 && middleCard.hand[0].returnValue() == 10)
    {
        return 0;
    }

    //check for reverse card (color and value)
    if (ch.hand[index].returnValue() == 11 && ch.hand[index].returnColor() == middleCard.hand[0].returnColor()
        || ch.hand[index].returnValue() == 11 && middleCard.hand[0].returnValue() == 11)
    {
        return 1;
    }

    //check for plus two card (color and value)
    if (ch.hand[index].returnValue() == 12 && ch.hand[index].returnColor() == middleCard.hand[0].returnColor()
        || ch.hand[index].returnValue() == 12 && middleCard.hand[0].returnValue() == 12)
    {
        return 2;
    }

    //check for plus four card (color and value)
    if (ch.hand[index].returnValue() == 13)
    {
        return 3;
    }

    //check for wildcard
    if (ch.hand[index].returnValue() == 14)
    {
        return 4;
    }

    //check for values and colors of any card
    if (ch.hand[index].returnValue() == middleCard.hand[0].returnValue() ||
        ch.hand[index].returnColor() == middleCard.hand[0].returnColor())
    {
        return 5;
    }
    return 6; //card cannot be used
}


//#endif //UNO_UNOSCORE_CPP