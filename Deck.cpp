//
// Created by jdinh on 12/5/2020.
//
//#ifndef UNO_DECK_CPP
//#define UNO_DECK_CPP
#include "Deck.h"


//template <class T>
Deck::Deck()
{
    cardIndex = 0;
    srand(time(nullptr));
}


//template <class T>
void Deck::setDeck()
{
    int count = 0;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deck[count].setValue(i);
            deck[count].setColor(j);
            count++;
        }
    }

    //continues the filling in of the deck (check for memory error)
    for (int i = 1; i < 13; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            deck[count].setValue(i);
            deck[count].setColor(j);
            count++;
        }
    }
}


//template <class T>
void Deck::shuffle()
{
    for (int i = 0; i < deckSize; i++)
    {
        int randCard = i + (rand() % 108 - i);

        swap (deck[i], deck[randCard]);
    }
}


//template <class T>
Card Deck::giveCard()
{
    if (empty())
    {
        cout << "\nThere are no more cards left in the deck. The game is over! ";
        exit(1);
    }

    deckSize--;
    return deck[cardIndex];
}


//template <class T>
bool Deck::empty() const
{
    bool emptyDeck;

    if (deckSize <= 0)
    {
        emptyDeck = true;
    }

    else
    {
        emptyDeck = false;
    }
    return emptyDeck;
}


//template <class T>
void Deck::setCardNamesAndValues()
{
    int count = 0;
    for (int i = 0; i < deckSize; i += 4)
    {
        string stringCount = to_string(count);
        string s = "Red" + stringCount;
        deck[i].setCardName(s);
        deck[i].setCardValue(count);
        deck[i].setCardColor("Red");
        //cout << i + 1 << ": " << deck[i].returnName() << endl;
        //cout << i + 1 << ": " << deck[i].returnScore() << endl;
        count += 1;
        if (count == 15)
        {
            count = 1;
        }
    }

    count = 0;
    for (int i = 1; i < deckSize; i += 4)
    {
        string stringCount = to_string(count);
        string s = "Yellow" + stringCount;
        deck[i].setCardName(s);
        deck[i].setCardValue(count);
        deck[i].setCardColor("Yellow");
        //cout << i + 1 << ": " << deck[i].returnName() << endl;
        //cout << i + 1 << ": " << deck[i].returnScore() << endl;
        count += 1;
        if (count == 15)
        {
            count = 1;
        }
    }

    count = 0;
    for (int i = 2; i < deckSize; i += 4)
    {
        string stringCount = to_string(count);
        string s = "Green" + stringCount;
        deck[i].setCardName(s);
        deck[i].setCardValue(count);
        deck[i].setCardColor("Green");
        //cout << i + 1 << ": " << deck[i].returnName() << endl;
        //cout << i + 1 << ": " << deck[i].returnScore() << endl;
        count += 1;
        if (count == 15)
        {
            count = 1;
        }
    }

    count = 0;
    for (int i = 3; i < deckSize; i += 4)
    {
        string stringCount = to_string(count);
        string s = "Blue" + stringCount;
        deck[i].setCardName(s);
        deck[i].setCardValue(count);
        deck[i].setCardColor("Blue");
        //cout << i + 1 << ": " << deck[i].returnName() << endl;
        //cout << i + 1 << ": " << deck[i].returnScore() << endl;
        count += 1;
        if (count == 15)
        {
            count = 1;
        }
    }
}


//template <class T>
void Deck::setValues()
{

}


//template <class T>
string Deck::returnCardName(int index)
{
    //cout << deck[index] << endl;
    return deck[index].returnName();
}


//template <class S>
ostream& operator << (ostream& outs, const Deck& d)
{
    for (int i = 0; i < d.deckSize; i++)
    {
        outs << i + 1 << ": " << d.deck[i] << endl;
    }
    return outs;
}

//#endif //UNO_DECK_CPP