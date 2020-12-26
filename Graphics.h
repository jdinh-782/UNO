//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_GRAPHICS_H
#define UNO_GRAPHICS_H

#include <SFML/Graphics.hpp>
#include "CardHand.h"

using namespace std;


class Graphics : public sf::Drawable, sf::Transformable
{
private:
    sf::Texture cardTexture, texture, cardDeckTexture;
    sf::Sprite cardImage, image, cardDeckImage;
    sf::Font font, buttonFont;
    sf::Text gameName, info, buttonText;
    sf::RectangleShape button;

    sf::Sprite popUpDisplay, unoButton;
    sf::Texture colorMenuTexture, unoButtonTexture;
    sf::Text pressUnoText, botDecidingText, botSaysUnoText;
    sf::Font colorFont;

public:
    Graphics();

    bool switchWindow = false;
    bool oneCardLeft = false;
    bool botTurnDisplay = false;
    bool botSaysUno = false;

    vector<sf::Sprite> spriteVector;
    vector<sf::Texture> textureVector;

    sf::Sprite setDeckImage();

    void setCardImage(vector<Card> hand, int index, int posX, int posY); //sets up the card sprites for every card in each player's hand (with position)
    void setGameName();
    void setInfo(); //sets the course name, crn, and my name for the splash screen
    void setButtonText(); //sets the play button text
    void setImage(); //sets the image for the splash screen
    void setButton(); //sets the play button
    //void moveCard(float x, float y);
    void hoverCard(sf::Vector2f mousePos, int index); //changes position of card when user hovers over
    void setPopUpDisplay();
    void setUnoButton(); //set the UNO button
    void setBotDisplay(); //sets up bot displays (what the bot is deciding to do...)

    bool clickedUnoButton(sf::Vector2f mousePos); //detects and returns a bool if user clicks on the UNO button
    bool useCard(sf::RenderWindow& window, const sf::Sprite& s); //checks to see which card the user wants to use based on left click and cursor position
    bool pressPlay(sf::RenderWindow& window); //checks if user clicks the play button

    virtual void draw (sf::RenderTarget &window, sf::RenderStates state) const;
};


#endif //UNO_GRAPHICS_H
