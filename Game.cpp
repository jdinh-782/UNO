//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_GAME_CPP
#define UNO_GAME_CPP
#include "Game.h"


//runs the entire game through sfml
template <class T>
Game<T>::Game() : window(sf::VideoMode{1600, 900, 32}, "Uno"), colorCardType(0), colorIndex(0)
{
    srand((time(nullptr)));
}


template <class T>
void Game<T>::setup()
{
    t.setDeck();
    t.setHands();

    cout << "\nCard: " << t.chS << endl;

    //sets graphic for card in the middle
    cardMiddleSprite.setCardImage(t.ch.hand, 0, 900, 380);

    //user's card hand graphics
    for (int i = 0; i < 7; i++)
    {
        userCardHandSprite.setCardImage(t.userCh.hand, i, posX, 750);
        posX += 105;
    }

    cout << "\nYour hand:\n" << t.userS << endl << endl;

    //bot's card hand graphics
    for (int i = 0; i < 7; i++)
    {
        botCardHandSprite.setCardImage(t.botCh.hand, i, botPosX, 10);
        botPosX += 105;
    }

    cout << "\nBot's hand:\n" << t.botS;

    d.setGameBackground();
    deckImage = gr.setDeckImage();
    d.setScoreTable();
    d.setCardAndDeckCounterDisplay();
    colorsDisplay.setColorMenu();
    colorsDisplay.setPopUpDisplay();
    pressUno.setUnoButton();
    pressUno.setPopUpDisplay();
    botDisplay.setPopUpDisplay();
    botDisplay.setBotDisplay();
    splashScreen();
}


//go from here and implement function for bot to use a card (then make displays for turn decisions)
template <class T>
void Game<T>::botInGameAction()
{
    int num = t.botAction();

    //if card can't be used, bot will just draw a card
    if (num == -1)
    {
        drawCardInGame("bot");
        return;
    }

    if (num >= 0 && num <= 9)
    {
        changeMiddleCard("bot");
        botTurn = false;
        return;
    }

    //check if the card that was used was an action card
    if (num >= 10 && num <= 14)
    {
        changeMiddleCard("bot");

        //skip returns back to the bot (num = 10)
        if (num == 11 || num == 12)
        {
            if (num == 12)
            {
                drawPlusTwo("user");
            }
            botTurn = false;
            return;
        }

        //FIX PLUSFOUR FOR BOT AND PLAYER
        //wildcard and plusfour for bot
        if (num == 13 || num == 14)
        {
            //bot automatically chooses red and player automatically draws 4 cards
            if (num == 13)
            {
                drawPlusFour("user");
            }
            botTurn = false;
            return;
        }
    }

//    if (t.botS.size() == 1)
//    {
//        pressUno.oneCardLeft = true;
//    }
}


template <class T>
void Game<T>::drawCardInGame(const string& player)
{
    if (player == "bot")
    {
        if (botPosX == 1590)
        {
            botPosX = 15;
            botPosY = 160;
        }
        t.botDrawCard();
        cout << "\nBot's hand:\n" << t.botS << endl;
        botCardHandSprite.setCardImage(t.botCh.hand, botIndex, botPosX, botPosY);
        botIndex++;
        botPosX += 105;
        d.changeScore(true, "bot");
        botTurn = false;
        d.changeDeckSize();
    }

    else if (player == "user")
    {
        if (d.scoreNum == 30 || d.botScoreNum == 30)
        {
            endDisplay.setEndingDisplay("deck");
            endDisplay.setPopUpDisplay();
            endDisplay.showEndingDisplay = true;
            return;
        }
        if (posX == 1590)
        {
            posX = 15;
            posY = 600;
        }
        t.drawCard();
        cout << "\nYour hand:\n" << t.userS << endl;
        userCardHandSprite.setCardImage(t.userCh.hand, index, posX, posY);
        index++;
        posX += 105;
        d.changeScore(true, "user");
        botTurn = true;
        botDisplay.botTurnDisplay = true;
        d.changeDeckSize();
    }
}


template <class T>
void Game<T>::userActionInGame()
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        for (int i = 0; i < t.userS.size(); i++)
        {
            if (userCardHandSprite.useCard(window, userCardHandSprite.spriteVector[i]) && !colorsDisplay.showColorOptions && !pressUno.oneCardLeft)
            {
                int num = t.playCard(t.u.cardToUse(t.userCh, t.ch, i), i, t.userCh, t.userS, "user");

                confirmCardUsedInGame(num);
            }
        }

        //draws a card if user clicks on deck
        userClickDrawCard();
        while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
    }
}


template <class T>
void Game<T>::confirmCardUsedInGame(int num)
{
    if (num >= 0 && num <= 9)
    {
        changeMiddleCard("user");
        botTurn = true;
        botDisplay.botTurnDisplay = true;
    }

    //check if the card that was used is an action card
    if (num >= 10 && num <= 14)
    {
        changeMiddleCard("user");

        //skip returns back to the player (num = 10)
        if (num == 11 || num == 12)
        {
            if (num == 12)
            {
                drawPlusTwo("bot");
            }
            botTurn = true;
            botDisplay.botTurnDisplay = true;
        }

        if (num == 13 || num == 14)
        {
            colorCardType = num;
            colorsDisplay.showColorOptions = true;
        }
    }
}


template <class T>
void Game<T>::chooseColorInGame()
{
    if (colorsDisplay.showColorOptions)
    {
        window.draw(colorsDisplay); //draws the color menu if the user needs to choose a color

        for (int i = 0; i < 4; i++)
        {
            colorIndex = colorsDisplay.chooseColor(pos, i);
            if (colorIndex >= 0 && colorIndex <= 3)
            {
                t.chooseColorInGame(colorIndex, colorCardType, "user");

                if (colorCardType == 13)
                {
                    drawPlusFour("bot"); //if the card was a plusFour, the other player will draw 4 cards automatically
                }
                colorsDisplay.showColorOptions = false;
                botTurn = true;
                botDisplay.botTurnDisplay = true;
            }
        }
    }
}


template <class T>
void Game<T>::drawPlusFour(const string& player)
{
    //draw 4 cards ingame
    for (int i = 0; i < 4; i++)
    {
        drawCardInGame(player);
    }
}


template <class T>
void Game<T>::drawPlusTwo(const string& player)
{
    //draw 2 cards ingame
    for (int i = 0; i < 2; i++)
    {
        drawCardInGame(player);
    }
}


template <class T>
void Game<T>::userClickDrawCard()
{
    //detects mouse click and cursor position on deck
    if (deckImageBounds.contains(pos) && !colorsDisplay.showColorOptions && !pressUno.oneCardLeft)
    {
        if (d.scoreNum == 30 || d.botScoreNum == 30)
        {
            endDisplay.setEndingDisplay("deck");
            endDisplay.setPopUpDisplay();
            endDisplay.showEndingDisplay = true;
            return;
        }
        if (posX == 1590)
        {
            posX = 15;
            posY = 600;
        }
        t.drawCard();
        cout << "\nYour hand:\n" << t.userS << endl;
        userCardHandSprite.setCardImage(t.userCh.hand, index, posX, posY);
        index++;
        posX += 105;
        d.changeScore(true, "user");
        botTurn = true;
        botDisplay.botTurnDisplay = true;
        d.changeDeckSize();
    }
}


template <class T>
void Game<T>::changeMiddleCard(const string& player)
{
    //returns the middle card from "TestGame" class and updates the sfml sprite/texture object
    t.ch.hand[0] = t.returnMiddleCard();
    cardMiddleSprite.textureVector.clear();
    cardMiddleSprite.spriteVector.clear();
    cardMiddleSprite.setCardImage(t.ch.hand, 0, 900, 380);

    shiftCardsOver(player);
}


//clears then updates the cards in the hand
template <class T>
void Game<T>::shiftCardsOver(const string& player)
{
    if (player == "user")
    {
        index--;
        userCardHandSprite.textureVector.clear();
        userCardHandSprite.spriteVector.clear();

        posX = 15;
        for (int i = 0; i < t.userS.size(); i++)
        {
            posY = 750;
            if (i == 15)
            {
                posX = 15;
                posY = 600;
            }
            userCardHandSprite.setCardImage(t.userCh.hand, i, posX, posY);
            posX += 105;
        }
    }
    else if (player == "bot")
    {
        botIndex--;
        botCardHandSprite.textureVector.clear();
        botCardHandSprite.spriteVector.clear();

        botPosX = 15;
        for (int i = 0; i < t.botS.size(); i++)
        {
            botPosY = 10;
            if (i == 15)
            {
                botPosX = 15;
                botPosY = 160;
            }
            botCardHandSprite.setCardImage(t.botCh.hand, i, botPosX, botPosY);
            botPosX += 105;
        }
    }
    d.changeScore(false, player);
}


template <class T>
void Game<T>::checkHandSize()
{
    //prompts a display for the user to press UNO
    if (t.userS.size() >= 2)
    {
        counter = 0;
    }
    if (t.userS.size() == 1 && counter == 0)
    {
        counter = 1;
        pressUno.oneCardLeft = true;
    }

    if (t.userS.size() == 0)
    {
        endDisplay.setEndingDisplay("user");
        endDisplay.setPopUpDisplay();
        endDisplay.showEndingDisplay = true;
    }

    else if (t.botS.size() == 0)
    {
        endDisplay.setEndingDisplay("bot");
        endDisplay.setPopUpDisplay();
        endDisplay.showEndingDisplay = true;
    }
}


template <class T>
bool Game<T>::playerPressedUnoButton(bool temp)
{
    if (temp)
    {
        cout << "Nice! You're ready to win!\n\n\n";
        return true;
    }
    else
    {
        cout << "Since you did not say \"UNO\", you must draw a card! Sorry, my rules!\n\n\n";
        t.drawCard();
        return false;
    }
}


template <class T>
void Game<T>::pressUNOInGame()
{
    //take into account other pop up displays with this one (color menu when 2 cards are left)
    if (pressUno.oneCardLeft)
    {
        window.draw(pressUno);

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!playerPressedUnoButton(pressUno.clickedUnoButton(pos)))
            {
                cout << "\nYour hand:\n" << t.userS << endl;
                userCardHandSprite.setCardImage(t.userCh.hand, index, posX, posY);
                index++;
                posX += 105;
                d.changeScore(true, "user");
                pressUno.oneCardLeft = false;
            }
            while (sf::Mouse::isButtonPressed(sf::Mouse::Left));
        }
    }
}


//setup splash screen
template <class T>
void Game<T>::splashScreen()
{
    gr.setGameName();
    gr.setInfo();
    gr.setImage();
    gr.setButtonText();
    gr.setButton();
}


//condense code!!! (and check other functions in other classes as well) - BEWARE COGNITIVE COMPLEXITY
template <class T>
void Game<T>::run()
{
    setup();

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event)) //check for events
        {
            if (event.type == sf::Event::Closed) //check to see if user closes window
            {
                window.close();
            }
        }
        window.clear();

        pos = (sf::Vector2f) sf::Mouse::getPosition(window); //gets mouse coordinates
        deckImageBounds = deckImage.getGlobalBounds();

        if (!gameScreen)
        {
            gameScreen = gr.pressPlay(window);
            window.draw(gr);
        }

        //only draw the game screen once the play button is clicked (dismiss splash screen)
        if (gameScreen)
        {
            window.clear(sf::Color::Transparent);
            window.draw(d);
            window.draw(gr);

            d.changeCardText(t.ch.hand[0]);

            //draws all the cards in the sprite vector (for each object)
            for (auto& i : cardMiddleSprite.spriteVector)
            {
                window.draw(i);
            }
            for (auto& i : userCardHandSprite.spriteVector)
            {
                window.draw(i);
            }
            for (auto& i : botCardHandSprite.spriteVector)
            {
                window.draw(i);
            }

            //will allow the display to be drawn first and then come back to this statement so it can sleep and then exit the game
            if (endDisplay.showEndingDisplay && counter == 2)
            {
                sleep(2);
                exit(0);
            }

            //really debug this and make sure it works and doesn't crashes
            //implement sleep() function and sfml for bot decisions/functions
            if (botTurn)
            {
                sleep(1);
                botInGameAction();
                botDisplay.botTurnDisplay = false;
            }

            pressUNOInGame();

            //choose a color (plusFour and wildCard)
            chooseColorInGame();


            //goes through functions to check which card the user would like to use
            userActionInGame();

            //checks if user's cardhand is 1 (to display UNO button)
            checkHandSize();

            if (botDisplay.botTurnDisplay)
            {
                if (t.botS.size() == 2)
                {
                    botDisplay.botSaysUno = true;
                }
                window.draw(botDisplay);
                botDisplay.botSaysUno = false;
            }

            //ending display (config on what should be drawn)
            if (endDisplay.showEndingDisplay)
            {
                window.draw(endDisplay);
                counter = 2;
            }
        }

        //hover card graphics
        for (int i = 0; i < t.userS.size(); i++)
        {
            userCardHandSprite.hoverCard(pos, i);
        }
        window.display();
    }
}


#endif //UNO_GAME_CPP