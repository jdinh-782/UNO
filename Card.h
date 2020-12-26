//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_CARD_H
#define UNO_CARD_H

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;


//enum to hold the colors
enum colors
{
    Red = 0, Yellow, Green, Blue, Black, NullColor
};


//enum to hold the values for each uno card
enum values
{
    Zero = 0, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    Skip = 10, Reverse, PlusTwo, PlusFour, WildCard, NullValue
};


//template <class T>
class Card
{
private:
    colors color;
    values value;
    string name, cardColor;
    int score;

public:
    Card();
    Card(colors colorInput, values valueInput);

    void setColor(int n);
    void setValue(int n);
    void setCardName(string s);
    void setCardValue(int num);
    void setCardColor(string str);

    string getColor() const;
    string getValue() const;
    string returnName();

    int returnValue();
    string returnColor();

    //template <class S>
    friend ostream& operator << (ostream& outs, const Card& c);
};


//#include "Card.cpp"


#endif //UNO_CARD_H
