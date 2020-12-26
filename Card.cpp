//
// Created by jdinh on 12/5/2020.
//

//#ifndef UNO_CARD_CPP
//#define UNO_CARD_CPP
#include "Card.h"


//template <class T>
Card::Card()
{
    color = Red;
    value = Zero;
    score = 0;
}


//template <class T>
Card::Card(colors colorInput, values valueInput)
{
    color = colorInput;
    value = valueInput;
    score = 0;
}


//template <class T>
void Card::setColor(int n)
{
    switch(n)
    {
        case 0:
            color = Red;
            break;
        case 1:
            color = Yellow;
            break;
        case 2:
            color = Green;
            break;
        case 3:
            color = Blue;
            break;
        case 4:
            color = Black; //for WildCard and PlusFour
            break;
        default:
            color = NullColor;
    }
}


//template <class T>
void Card::setValue(int n)
{
    switch(n)
    {
        case 0:
            value = Zero;
            break;
        case 1:
            value = One;
            break;
        case 2:
            value = Two;
            break;
        case 3:
            value = Three;
            break;
        case 4:
            value = Four;
            break;
        case 5:
            value = Five;
            break;
        case 6:
            value = Six;
            break;
        case 7:
            value = Seven;
            break;
        case 8:
            value = Eight;
            break;
        case 9:
            value = Nine;
            break;
        case 10:
            value = Skip;
            break;
        case 11:
            value = Reverse;
            break;
        case 12:
            value = PlusTwo;
            break;
        case 13:
            value = PlusFour;
            break;
        case 14:
            value = WildCard;
            break;
        default:
            value = NullValue;
    }
}


//template <class T>
string Card::getColor() const
{
    switch(color)
    {
        case 0:
            return "Red";
        case 1:
            return "Yellow";
        case 2:
            return "Green";
        case 3:
            return "Blue";
        case 4:
            return "Black"; //for WildCard and PlusFour
        default:
            return "NULL";
    }
}


//template <class T>
string Card::getValue() const
{
    switch(value)
    {
        case 0:
            return "Zero";
        case 1:
            return "One";
        case 2:
            return "Two";
        case 3:
            return "Three";
        case 4:
            return "Four";
        case 5:
            return "Five";
        case 6:
            return "Six";
        case 7:
            return "Seven";
        case 8:
            return "Eight";
        case 9:
            return "Nine";
        case 10:
            return "Skip";
        case 11:
            return "Reverse";
        case 12:
            return "PlusTwo";
        case 13:
            return "PlusFour";
        case 14:
            return "WildCard";
        default:
            return "NULL";
    }
}


//template <class T>
void Card::setCardName(string s)
{
    name = s;
}


//template <class T>
void Card::setCardValue(int num)
{
    score = num;
}


//template <class T>
void Card::setCardColor(string str)
{
    cardColor = str;
}


//template <class T>
string Card::returnName()
{
    return name;
}


//template <class T>
string Card::returnColor()
{
    return cardColor;
}


//template <class T>
int Card::returnValue()
{
    return score;
}


//template <class S>
ostream& operator << (ostream& outs, const Card& c)
{
    outs << c.getColor() << " " << c.getValue();
    return outs;
}


//#endif //UNO_CARD_CPP