//
// Created by jdinh on 12/8/2020.
//

#include "Displays.h"


Displays::Displays()
{

}


void Displays::setGameBackground()
{
    if (!backgroundTexture.loadFromFile("space.jpg"))
    {
        exit(1);
    }
    gameBackground.setTexture(backgroundTexture);
    gameBackground.setPosition(0, 0);
    gameBackground.setScale(1,1);
}


void Displays::setScoreTable()
{
    if (!scoreDisplayFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }

    scoreTable.setFillColor({170, 183, 184});
    scoreTable.setSize({350, 150});
    scoreTable.setPosition({1400, 365});

    playerName.setFont(scoreDisplayFont);
    playerName.setCharacterSize(35);
    playerName.setString("Player:");
    playerName.setPosition(1410, 380);

    playerScore.setFont(scoreDisplayFont);
    playerScore.setCharacterSize(35);
    playerScore.setString('7');
    playerScore.setPosition({1550, 380});

    botName.setFont(scoreDisplayFont);
    botName.setCharacterSize(35);
    botName.setString("Bot:");
    botName.setPosition(1462, 440);

    botScore.setFont(scoreDisplayFont);
    botScore.setCharacterSize(35);
    botScore.setString('7');
    botScore.setPosition({1550, 440});
}


void Displays::changeScore(bool increase, const string& player)
{
    if (player == "user")
    {
        scoreNum = stoi((string)playerScore.getString());

        if (increase)
        {
            playerScore.setString((to_string(scoreNum + 1)));
            scoreNum++;
        }
        else
        {
            playerScore.setString((to_string(scoreNum - 1)));
            scoreNum--;
        }
    }
    else if (player == "bot")
    {
        botScoreNum = stoi((string)botScore.getString());

        if (increase)
        {
            botScore.setString((to_string(botScoreNum + 1)));
            botScoreNum++;
        }
        else
        {
            botScore.setString((to_string(botScoreNum - 1)));
            botScoreNum--;
        }
    }
}


void Displays::setCardAndDeckCounterDisplay()
{
    if (!cardDeckDisplayFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }
    cardDeckDisplayBackground.setFillColor({130, 109, 68});
    cardDeckDisplayBackground.setSize({500, 150});
    cardDeckDisplayBackground.setPosition({0, 365});

    deckSizeText.setFont(cardDeckDisplayFont);
    deckSizeText.setString("Deck Size: ");
    deckSizeText.setCharacterSize(35);
    deckSizeText.setPosition({10, 380});

    deckCounterText.setFont(cardDeckDisplayFont);
    deckCounterText.setString("93");
    deckCounterText.setCharacterSize(35);
    deckCounterText.setPosition({200, 380});

    cardText.setFont(cardDeckDisplayFont);
    cardText.setString("Card: ");
    cardText.setCharacterSize(35);
    cardText.setPosition({95, 440});

    cardInMiddleText.setFont(cardDeckDisplayFont);
    cardInMiddleText.setString("NULL");
    cardInMiddleText.setCharacterSize(35);
    cardInMiddleText.setPosition({200, 440});
}


void Displays::changeDeckSize()
{
    deckSizeCounter = stoi((string)deckCounterText.getString());

    deckCounterText.setString((to_string(deckSizeCounter - 1)));
    deckSizeCounter--;
}


//get the color and value of new card in the middle
void Displays::changeCardText(const Card& c)
{
    string s = c.getColor() + " " + c.getValue();
    cardInMiddleText.setString(s);
}


void Displays::setPopUpDisplay()
{
    if (!popUpDisplayTexture.loadFromFile("popUpDisplayBackground.png"))
    {
        exit(0);
    }
    popUpDisplay.setTexture(popUpDisplayTexture);
    popUpDisplay.setScale(2.25, 2.25);
    popUpDisplay.setPosition(275, 200);
}


//prompts a block of text that will allow the user to choose a color option
void Displays::setColorMenu()
{
    if (!colorFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }
    colorMenuText.setFont(colorFont);
    colorMenuText.setString("Choose A Color!");
    colorMenuText.setCharacterSize(100);
    colorMenuText.setPosition(405, 240);

    redBox.setFillColor(sf::Color::Red);
    redBox.setSize({275, 75});
    redBox.setPosition(425, 395);

    redBoxText.setFont(colorFont);
    redBoxText.setString("RED");
    redBoxText.setCharacterSize(50);
    redBoxText.setPosition(515, 400);
    colorsVector.push_back(redBox);

    yellowBox.setFillColor({255, 215, 0});
    yellowBox.setSize({275, 75});
    yellowBox.setPosition(890, 395);

    yellowBoxText.setFont(colorFont);
    yellowBoxText.setString("YELLOW");
    yellowBoxText.setCharacterSize(50);
    yellowBoxText.setPosition(925, 400);
    colorsVector.push_back(yellowBox);

    greenBox.setFillColor(sf::Color::Green);
    greenBox.setSize({275, 75});
    greenBox.setPosition(425, 495);

    greenBoxText.setFont(colorFont);
    greenBoxText.setString("GREEN");
    greenBoxText.setCharacterSize(50);
    greenBoxText.setPosition(480, 500);
    colorsVector.push_back(greenBox);

    blueBox.setFillColor(sf::Color::Blue);
    blueBox.setSize({275, 75});
    blueBox.setPosition(890, 495);

    blueBoxText.setFont(colorFont);
    blueBoxText.setString("BLUE");
    blueBoxText.setCharacterSize(50);
    blueBoxText.setPosition(965, 500);
    colorsVector.push_back(blueBox);
}


int Displays::chooseColor(sf::Vector2f mousePos, int index)
{
    sf::FloatRect bounds = colorsVector[index].getGlobalBounds();

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (mousePos.x > colorsVector[index].getGlobalBounds().width && bounds.contains(mousePos))
        {
            return index;
        }
    }
    return -1;
}


void Displays::setEndingDisplay(const string &whatToDisplay)
{
    if (!scoreDisplayFont.loadFromFile("OpenSans-Bold.ttf"))
    {
        exit(0);
    }
    endingDisplayText.setFont(scoreDisplayFont);
    endingDisplayText.setCharacterSize(185);

    if (whatToDisplay == "bot")
    {
        endingDisplayText.setString("Bot wins!!!");
        endingDisplayText.setPosition(330, 325);
    }
    else if (whatToDisplay == "user")
    {
        endingDisplayText.setString("You win!!!");
        endingDisplayText.setPosition(345, 325);
    }
    else if (whatToDisplay == "deck")
    {
        endingDisplayText.setString("Game over!!!");
        endingDisplayText.setCharacterSize(150);
        endingDisplayText.setPosition(320, 325);
    }
}


void Displays::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(gameBackground);
    window.draw(scoreTable);
    window.draw(playerName);
    window.draw(playerScore);
    window.draw(botName);
    window.draw(botScore);
    window.draw(cardDeckDisplayBackground);
    window.draw(deckCounterText);
    window.draw(deckSizeText);
    window.draw(cardText);
    window.draw(cardInMiddleText);

    if (showColorOptions)
    {
        window.draw(popUpDisplay);
        window.draw(colorMenuText);
        window.draw(redBox);
        window.draw(greenBox);
        window.draw(yellowBox);
        window.draw(blueBox);
        window.draw(redBoxText);
        window.draw(greenBoxText);
        window.draw(yellowBoxText);
        window.draw(blueBoxText);
    }

    if (showEndingDisplay)
    {
        window.draw(popUpDisplay);
        window.draw(endingDisplayText);
    }
}


