//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_GAME_H
#define UNO_GAME_H

#include "TestGame.h"
#include "Graphics.h"
#include "Displays.h"

using namespace std;


template <class T>
class Game
{
private:
    TestGame<T> t;
    Graphics gr, cardMiddleSprite, userCardHandSprite, botCardHandSprite, botDisplay, pressUno;
    Displays d, colorsDisplay, endDisplay;
    sf::RenderWindow window;
    sf::Sprite deckImage;
    sf::Vector2f pos;
    sf::FloatRect deckImageBounds;

    int posX = 15;
    int posY = 750;
    int botPosX = 15;
    int botPosY = 10;
    int index = 7;
    int botIndex = 7;
    int colorIndex,  colorCardType;
    int counter = 0;
    bool gameScreen = false;
    bool botTurn = false;

public:
    Game();

    bool playerPressedUnoButton(bool temp);

    void botInGameAction(); //AI functions (use a card or draw)
    void drawCardInGame(const string& player); //drawing a card in the game
    void userActionInGame(); //checks if user can use a specific card or if they have to draw
    void confirmCardUsedInGame(int num); //confirm the card that can be used
    void chooseColorInGame(); //if wildcard or plusfour, popup a display to let the user choose a color
    void drawPlusFour(const string& player); //draws 4 cards from the deck based on which player
    void drawPlusTwo(const string& player); //draws 2 cards from the deck based on which player
    void userClickDrawCard(); //checks if user is left clicking AND hovering over and on the deck
    void changeMiddleCard(const string& player); //change the card in the middle
    void shiftCardsOver(const string& player); //shifts all the cards to the left after a card is used
    void checkHandSize(); //check the hand size of the user (to see if the user is able to press UNO)
    void pressUNOInGame(); //checks if user clicks on the UNO button
    void splashScreen(); //sets up splashscreen by calling functions from Graphics class
    void setup(); //setup the deck, hands, and graphics
    void run(); //runs the entire game
};


#include "Game.cpp"


#endif //UNO_GAME_H
