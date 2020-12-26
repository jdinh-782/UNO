//
// Created by jdinh on 12/5/2020.
//
#ifndef UNO_TESTGAME_CPP
#define UNO_TESTGAME_CPP
#include "TestGame.h"


//use this as a guide for the game and really debug any issues
template <class T>
TestGame<T>::TestGame()
{
    srand((time(nullptr)));
    saidUno = false;
    skip = false;
}


template <class T>
void TestGame<T>::setDeck()
{
    d.setDeck(); //set the deck
    d.setCardNamesAndValues(); //set the card names and values for each card
    d.shuffle(); //shuffle deck

    chS.push(ch.addCard(d)); //sets card in the middle
}


template <class T>
void TestGame<T>::setHands()
{
    for (int i = 0; i < 7; i++)
    {
        userS.push(userCh.addCard(d)); //set user's hand
    }

    for (int i = 0; i < 7; i++)
    {
        botS.push(botCh.addCard(d)); //set bot's hand
    }
}


//return the value for the card in the middle
template <class T>
Card TestGame<T>::returnMiddleCard()
{
    return ch.hand[0];
}


template <class T>
void TestGame<T>::chooseOption()
{
    do
    {
        cout << "\nYour hand:\n" << userS << endl; //displays user's hand

        cout << "\nBot has " << botS.size() << " cards.\n\n"; //displays number of cards in bot's hand

        cout << "\nCard: " << ch.hand[0] << endl;

        int option, cardSelect, n;
        cout << "\n[1] Use A Card\n"
                "[2] Draw A Card\n"
                "[3] Quit Game\n"
                "Enter Option: ";
        cin >> option;

        while (!cin)
        {
            cout << "\nInput must be 1, 2, or 3! "
                 << "\nEnter Option: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> option;
        }

        switch (option)
        {
            case 1:
                cout << "\nEnter the index of the card you would like to use. \"" << userCh.hand[0] << "\" is index 0: ";

                while (true)
                {
                    cin >> cardSelect;
                    if (cardSelect >= userCh.handSize || cardSelect < 0)
                    {
                        cout << "\nAccess to card index is out of range!!"
                             << "\nEnter card index again: ";
                    }
                    else if (cin.fail())
                    {
                        cout << "\nInvalid Input!"
                                "\nEnter card index again: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    else
                    {
                        break;
                    }
                }
                n = playCard(u.cardToUse(userCh, ch, cardSelect), cardSelect, userCh, userS, "user");

                //n represents the values of cards (-1 would infer card could not be used for play)
                if (n >= 0 && n <= 9)
                {
                    return;
                }

                //check if the card that was used is an action card
                if (n >= 10 && n <= 14)
                {
                    actionCardFunctions(n, "user");
                    return;
                }
                break;

            case 2:
                drawCard();
                sleep(3);
                return;

            case 3:
                cout << "\n\n\nSee ya next time!";
                exit(0);

            default:
                cout << "Invalid Choice!\n\n\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
        }
    } while (true);
}


template <class T>
int TestGame<T>::playCard(int n, int cardIndex, CardHand& temp, Stack<T>& s, const string& player)
{
    int num;

    //if a card can be used, replace the card in the middle with the played card
    if (n >= 0 && n <= 5)
    {
        if (player == "user")
        {
            cout << "You played \"" << temp.hand[cardIndex] << "\"!\n\n";
        }
        else if (player == "bot")
        {
            cout << "\nBot played \"" << temp.hand[cardIndex] << "\"!\n\n";
        }
        //sleep(3);
        num = temp.hand[cardIndex].returnValue();
        ch.hand[0] = temp.hand[cardIndex];
        chS.pop();
        chS.push(ch.hand[0]);
        temp.removeCard(cardIndex);

        //pop the card data after removing the card from the user's hand
        if (cardIndex == 0)
        {
            s.pop();
        }
        else if (cardIndex == s.size() - 1)
        {
            s.popLastCard();
        }
        else
        {
            s.popSpecificCard(cardIndex);
        }
        cout << "\nCard: " << ch.hand[0] << endl;
        cout << "\nYour hand:\n" << userS << endl; //displays user's hand
        return num;
    }
    else
    {
        cout << "\"" << temp.hand[cardIndex] << "\" does not match color and/or value!\n\n\n";
    }
    return -1;
}


template <class T>
void TestGame<T>::drawCard()
{
    if (d.deckSize == 0)
    {
        cout << "\n\nThere are no more cards in the deck!"
             << "\nGame over!";
        cout << "\n\nDeck size: " << d.deckSize;
        exit(0);
    }
    userS.push(userCh.addCard(d));
    cout << "\nDeck size: " << d.deckSize;
    cout << "\nYou draw a card!\n\n\n";
}


template <class T>
void TestGame<T>::actionCardFunctions(int actionNum, const string& player)
{
    //change skip card so that it works with sfml (possibly use bool to determine who's turn it is)

    //checks for a specific action card
    if (actionNum == 10) //skip card action
    {
        skip = true;
        if (player == "user")
        {
            cout << "\nThe bot's turn is skipped!\n\n";
            chooseOption();
        }
        else if (player == "bot")
        {
            cout << "\nYour turn is skipped! ";
            botAction();
        }
        return;
    }
    else if (actionNum == 11) //reverse card action (does nothing with 2 players)
    {
        return; //implement
    }
    else if (actionNum == 12) //plusTwo card action
    {
        for (int i = 0; i < 2; i++)
        {
            if (player == "user")
            {
                botS.push(botCh.addCard(d));
            }
            else if (player == "bot")
            {
                userS.push(userCh.addCard(d));
            }
        }
    }

    //plusFour card action and wildCard action
    else if (actionNum == 13 || actionNum == 14)
    {
        chooseColor(actionNum, player);
    }
}


template <class T>
void TestGame<T>::chooseColor(int actionNum, const string& player)
{
    string color;
    if (player == "user")
    {
        cout << "\nChoose a color: ";
        cin >> color;

        if (color == "Red")
        {
            ch.hand[0].setColor(0);
        }
        else if (color == "Yellow")
        {
            ch.hand[0].setColor(1);
        }
        else if (color == "Green")
        {
            ch.hand[0].setColor(2);
        }
        else if (color == "Blue")
        {
            ch.hand[0].setColor(3);
        }
        ch.hand[0].setCardColor(color);
        ch.hand[0].setCardName(color + to_string(actionNum));

//        if (actionNum == 13) //only for plusFour
//        {
//            for (int i = 0; i < 4; i++)
//            {
//                botS.push(botCh.addCard(d));
//            }
//        }
    }

    else if (player == "bot")
    {
        color = "Red";
        ch.hand[0].setCardColor(color);
        ch.hand[0].setCardName(color + to_string(actionNum));
        ch.hand[0].setColor(0);

//        if (actionNum == 13) //only for plusFour
//        {
//            for (int i = 0; i < 4; i++)
//            {
//                userS.push(userCh.addCard(d));
//            }
//        }
        cout << "\nThe bot chooses the color Red! ";
        //sleep(1);
    }
}


template <class T>
void TestGame<T>::chooseColorInGame(int index, int cardType, const string &player)
{
    string color;
    if (player == "user")
    {
        if (index == 0) //red
        {
            ch.hand[0].setColor(0);
            color = "Red";
        }
        else if (index == 1) //yellow
        {
            ch.hand[0].setColor(1);
            color = "Yellow";
        }
        else if (index == 2) //green
        {
            ch.hand[0].setColor(2);
            color = "Green";
        }
        else if (index == 3) //blue
        {
            ch.hand[0].setColor(3);
            color = "Blue";
        }
        ch.hand[0].setCardColor(color);
        ch.hand[0].setCardName(color + to_string(cardType));

//        if (cardType == 13) //only for plusFour
//        {
//            for (int i = 0; i < 4; i++)
//            {
//                botS.push(botCh.addCard(d));
//            }
//        }
        cout << endl << ch.hand[0] << endl;
    }
}


template <class T>
int TestGame<T>::botAction()
{
    int a, n;

    cout << "\nCard: " << ch.hand[0] << endl;
    cout << "\nThe bot is deciding what to do...";
    //sleep(1);

    for (int i = 0; i < botS.size(); i++)
    {
        n = u.cardToUse(botCh, ch, i);
        if (n >= 0 && n <= 5)
        {
            a = playCard(n, i, botCh, botS, "bot");
            break;
        }
        else
        {
            n = -1;
        }
    }

    if (n == -1)
    {
        cout << "\nThe bot decides to draw a card!\n";
        //botS.push(botCh.addCard(d));
        return n;
    }

//    if (a >= 10 && a <= 14)
//    {
//        actionCardFunctions(a, "bot");
//    }
    return a;
    //cout << "\nBot's hand:\n" << botS << endl;
}


template <class T>
void TestGame<T>::botDrawCard()
{
    if (d.deckSize == 0)
    {
        cout << "\n\nThere are no more cards in the deck!"
             << "\nGame over!";
        cout << "\n\nDeck size: " << d.deckSize;
        exit(0);
    }
    botS.push(botCh.addCard(d));
}


template <class T>
void TestGame<T>::noMoreCards()
{
    if (userS.size() == 0)
    {
        cout << "\n\nYou win!";
        exit(0);
    }
    else if (botS.size() == 0)
    {
        cout << "\n\nBot wins!";
        exit(0);
    }
}


template <class T>
void TestGame<T>::runGame()
{
    cout << "----------WELCOME TO UNO----------\n";
    setDeck();
    setHands();

    //cout << "\nYour hand:\n" << userS << endl;
    //cout << "Bot's hand:\n" << botS << endl;

    do
    {
        noMoreCards();

        string uno;

        if (userS.size() == 1)
        {
            cout << "\n\nSAY IT: ";
            cin >> uno;

            if (uno == "UNO" || uno == "uno" || uno == "Uno")
            {
                cout << "Nice! You're ready to win!\n\n\n";
                saidUno = true;
            }
            else
            {
                cout << "Since you did not say \"UNO\", you must draw a card! Sorry, my rules!\n\n\n";
                userS.push(userCh.addCard(d));
                saidUno = false;
            }
        }

        if (botS.size() == 1)
        {
            cout << "The bot says \"UNO\"!\n\n\n";
        }
        chooseOption();

        botAction();
    } while (d.deckSize > 0);
}


#endif //UNO_TESTGAME_CPP