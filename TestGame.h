//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_TESTGAME_H
#define UNO_TESTGAME_H

#include <iostream>
#include <ctime>
#include "UnoScore.h"
#include "Stack.h"
#include "unistd.h"

using namespace std;


template <class T>
class TestGame
{
private:
    Deck d;
    bool skip;

public:
    TestGame();

    bool saidUno; //checks if user said 'uno'

    UnoScore u;
    Stack<T> chS, userS, botS, deckS;
    CardHand ch, userCh, botCh, deckCh;

    Card returnMiddleCard();

    int playCard(int n, int cardIndex, CardHand& temp, Stack<T>& s, const string& player); //plays a card determined by the user
    int botAction(); //bot functions

    void setDeck(); //sets the game deck
    void setHands(); //sets the hands for each player
    void chooseOption(); //asks user to either place/draw a card or skip their turn
    void drawCard(); //draws a card
    void actionCardFunctions(int actionNum, const string& player); //function for action cards
    void chooseColor(int actionNum, const string& player); //gets user input for which color they want to select
    void chooseColorInGame(int index, int cardType, const string& player);
    void botDrawCard();
    void noMoreCards(); //if a specific user has no cards left
    void runGame(); //runs the game in the console
};

#include "TestGame.cpp"


#endif //UNO_TESTGAME_H
