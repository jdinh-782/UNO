//
// Created by jdinh on 12/5/2020.
//

#include "Graphics.h"

Graphics::Graphics()
{
    textureVector.reserve(108); //make sure this is up to date with number of cards (set to 108)
}


//sets the card sprites
void Graphics::setCardImage(vector<Card> h, int index, int posX, int posY)
{
    spriteVector.push_back(cardImage);
    textureVector.push_back(cardTexture);
    string s;
    s = "backside.png";
    if (posX == 900 || posY == 600 || posY == 750)
    {
        s = h[index].returnName() + ".png";
    }
    //cout << s << endl;
    if (!cardTexture.loadFromFile(s))
    {
        exit(1);
    }
    textureVector[index] = cardTexture;
    cardImage.setTexture(textureVector[index]);
    cardImage.setPosition(sf::Vector2f(posX, posY));
    cardImage.setScale(0.25, 0.25);
    spriteVector[index] = cardImage;

    //    v.reserve(2);
    //    t.reserve(2);
    //    for (int i = 0; i < 2; i++)
    //    {
    //        v.push_back(c1);
    //        t.push_back(t1);
    //        string s;
    //        s = "Blue" + to_string(i) + ".png";
    //        t1.loadFromFile(s);
    //        t[i] = t1;
    //        c1.setTexture(t[i]);
    //        c1.setPosition(sf::Vector2f(posX, 750));
    //        c1.setScale(0.25, 0.25);
    //        v[i] = c1;
    //        posX += 105;
    //    }
}


void Graphics::setGameName()
{
    if (!font.loadFromFile("segoescb.ttf"))
    {
        exit(0);
    }
    gameName.setString("BIG UNO");
    gameName.setFont(font);
    gameName.setCharacterSize(75);
    gameName.setPosition(625, 25);
}


void Graphics::setInfo()
{
    if (!font.loadFromFile("segoescb.ttf"))
    {
        exit(0);
    }
    info.setString("Johnson Dinh // CS 3A (CRN: 77058) // Fall 2020");
    info.setFont(font);
    info.setCharacterSize(50);
    info.setPosition(100, 150);
}


void Graphics::setButtonText()
{
    if (!buttonFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }
    buttonText.setString("Play");
    buttonText.setFont(buttonFont);
    buttonText.setCharacterSize(50);
    buttonText.setPosition(725, 750);
}


void Graphics::setImage()
{
    if (!texture.loadFromFile("meme.png"))
    {
        exit(0);
    }
    image.setTexture(texture);
    image.setPosition(550, 250);
    image.setScale({0.50, 0.50});
}


void Graphics::setButton()
{
    button.setFillColor(sf::Color::Red);
    button.setSize({150, 75});
    button.setPosition(705, 745);
}


sf::Sprite Graphics::setDeckImage()
{
    //deck graphics
    if (!cardDeckTexture.loadFromFile("backside.png"))
    {
        exit(0);
    }
    cardDeckImage.setTexture(cardDeckTexture);
    cardDeckImage.setPosition({750, 380});
    cardDeckImage.setScale(0.25, 0.25);

    return cardDeckImage;
}


//void Graphics::moveCard(float x, float y)
//{
//    cardImage.setPosition(sf::Vector2f(x - 50, y - 100));
//}


//simply move up the position of the card by 25 units and bring back down when the mousse cursor is not on it
void Graphics::hoverCard(sf::Vector2f mousePos, int index)
{
    sf::FloatRect bounds = spriteVector[index].getGlobalBounds();
    int cardPosX = spriteVector[index].getPosition().x;
    int cardPosY = 750;

    if (index >= 15)
    {
        cardPosY = 600;
        if (index == 15)
        {
            if (mousePos.x < spriteVector[index].getGlobalBounds().width && bounds.contains(mousePos))
            {
                spriteVector[index].setPosition(sf::Vector2f(cardPosX, cardPosY - 25));
            }
            else
            {
                spriteVector[index].setPosition(sf::Vector2f(cardPosX, cardPosY));
            }
            return;
        }
    }
    if (index == 0)
    {
        if (mousePos.x < spriteVector[index].getGlobalBounds().width && bounds.contains(mousePos))
        {
            spriteVector[index].setPosition(sf::Vector2f(cardPosX, cardPosY - 25));
        }
        else
        {
            spriteVector[index].setPosition(sf::Vector2f(cardPosX, cardPosY));
        }
        return;
    }
    if (mousePos.x > spriteVector[index].getGlobalBounds().width && bounds.contains(mousePos))
    {
        spriteVector[index].setPosition(sf::Vector2f(cardPosX, cardPosY - 25));
    }
    else
    {
        spriteVector[index].setPosition(sf::Vector2f(cardPosX, cardPosY));
    }
}


bool Graphics::useCard(sf::RenderWindow &window, const sf::Sprite& s)
{
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect bounds = s.getGlobalBounds();

    if (bounds.contains(mPos))
    {
        return true;
    }
    return false;
}


bool Graphics::pressPlay(sf::RenderWindow& window)
{
    sf::Vector2f mPos = (sf::Vector2f) sf::Mouse::getPosition(window);
    sf::FloatRect bounds = button.getGlobalBounds();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (bounds.contains(mPos))
        {
            button.setPosition({705, 730});
            buttonText.setPosition(725, 735);
            switchWindow = true;
            return true;
        }
        else
        {
            button.setPosition({705, 745});
            buttonText.setPosition(725, 750);
        }
        return false;
        //switchWindow = false;
        //while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }
}


void Graphics::setPopUpDisplay()
{
    if (!colorMenuTexture.loadFromFile("popUpDisplayBackground.png"))
    {
        exit(0);
    }
    popUpDisplay.setTexture(colorMenuTexture);
    popUpDisplay.setScale(2.25, 2.25);
    popUpDisplay.setPosition(275, 200);
}


//sets the uno button
void Graphics::setUnoButton()
{
    if (!colorFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }

    if (!unoButtonTexture.loadFromFile("unobutton.png"))
    {
        exit(0);
    }
    unoButton.setTexture(unoButtonTexture);
    unoButton.setScale(0.30, 0.30);
    unoButton.setPosition(620, 350);

    pressUnoText.setFont(colorFont);
    pressUnoText.setString("PRESS THE BUTTON");
    pressUnoText.setCharacterSize(85);
    pressUnoText.setPosition(395, 240);
}


void Graphics::setBotDisplay()
{
    if (!colorFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }
    botDecidingText.setFont(colorFont);
    botDecidingText.setString("The bot is deciding what to do...");
    botDecidingText.setCharacterSize(60);
    botDecidingText.setPosition(320, 390);

    botSaysUnoText.setFont(colorFont);
    botSaysUnoText.setString("The bot says UNO!!!");
    botSaysUnoText.setCharacterSize(100);
    botSaysUnoText.setPosition(310, 360);
}


bool Graphics::clickedUnoButton(sf::Vector2f mousePos)
{
    //check for actual bounds since the image is not a pure rectangular shape
    sf::FloatRect bounds = unoButton.getGlobalBounds();

    if (bounds.contains(mousePos))
    {
        oneCardLeft = false;
        return true;
    }
    return false;
}


void Graphics::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    if (!switchWindow)
    {
        window.draw(gameName);
        window.draw(info);
        window.draw(image);
        window.draw(button);
        window.draw(buttonText);
    }
    else
    {
        window.draw(cardDeckImage);
    }

    if (oneCardLeft)
    {
        window.draw(popUpDisplay);
        window.draw(unoButton);
        window.draw(pressUnoText);
    }

    if (botTurnDisplay)
    {
        window.draw(popUpDisplay);

        if(botSaysUno)
        {
            window.draw(botSaysUnoText);
        }
        else
        {
            window.draw(botDecidingText);
        }
    }
}