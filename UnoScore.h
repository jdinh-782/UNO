//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_UNOSCORE_H
#define UNO_UNOSCORE_H

#include "CardHand.h"

//template <class T>
class UnoScore
{
private:

public:
    UnoScore();

    bool checkCard(CardHand& ch, CardHand& middleCard, int index); //earlier version of "cardToUse" function
    int cardToUse(CardHand& ch, CardHand& middleCard, int index); //checks if card can be used
};


//#include "UnoScore.cpp"


#endif //UNO_UNOSCORE_H
