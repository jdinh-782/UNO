//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_STACK_H
#define UNO_STACK_H

#include "LinkedList.h"


template <class T>
class Stack : public LinkedList<T>
{
protected:
    T data;

public:
    void push(T value); //push a card to the stack

    bool isEmpty();

    int size();
    int returnStackCardValue(int index);

    string returnStackCardColor(int index);

    T pop(); //pop a card from the stack
    T popSpecificCard(int index); //pops a specific card in the stack
    T popLastCard(); //pop the last card from the stack (if card is the last index of the user's hand)
    T top();
    T seek(int index);
    T reverseSeek(T value);
};


#include "Stack.cpp"


#endif //UNO_STACK_H
