//
// Created by jdinh on 12/8/2020.
//

#ifndef UNO_DISPLAYS_H
#define UNO_DISPLAYS_H
#include <SFML/Graphics.hpp>
#include "CardHand.h"


class Displays : public sf::Drawable, sf::Transformable
{
private:
    sf::Texture backgroundTexture, popUpDisplayTexture;
    sf::Sprite gameBackground, popUpDisplay;
    sf::RectangleShape scoreTable, cardDeckDisplayBackground, redBox, greenBox, yellowBox, blueBox;
    sf::Text playerName, botName, playerScore, botScore, deckSizeText, deckCounterText, cardText, cardInMiddleText, colorMenuText, redBoxText, greenBoxText, yellowBoxText, blueBoxText, endingDisplayText;
    sf::Font scoreDisplayFont, cardDeckDisplayFont, colorFont;

public:
    Displays();

    int scoreNum = 7;
    int botScoreNum = 7;
    int deckSizeCounter = 92;
    bool showColorOptions = false;
    bool showEndingDisplay = false;
    vector<sf::RectangleShape> colorsVector;

    int chooseColor(sf::Vector2f mousePos, int index);

    void setGameBackground(); //setup the game background
    void setScoreTable(); //sets the scoretable
    void changeScore(bool increase, const string& player); //change score based on amount of cards in hand
    void setCardAndDeckCounterDisplay(); //set the display for the card in the middle and the deck size
    void changeDeckSize(); //change deck size every time a card is drawn
    void changeCardText(const Card& c); //change the text for the card in the middle every time a card is used
    void setPopUpDisplay(); //sets up pop-up displays
    void setColorMenu(); //sets the color menu for color options
    void setEndingDisplay(const string& whatToDisplay); //sets ending display based on who wins or if there are no more cards in the deck

    virtual void draw (sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //UNO_DISPLAYS_H
