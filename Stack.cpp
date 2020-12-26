//
// Created by jdinh on 12/5/2020.
//
#ifndef UNO_STACK_CPP
#define UNO_STACK_CPP
#include "Stack.h"


template<class T>
void Stack<T>::push(T value)
{
    LinkedList<T>::operator+=(value);
}


template<class T>
bool Stack<T>::isEmpty()
{
    bool temp = LinkedList<T>::empty();
    return temp;
}


template <class T>
int Stack<T>::size()
{
    int num = LinkedList<T>::listSize();
    return num;
}


template <class T>
int Stack<T>::returnStackCardValue(int index)
{
    int value = LinkedList<T>::returnNodeValue(index);
    return value;
}


template <class T>
string Stack<T>::returnStackCardColor(int index)
{
    string color = LinkedList<T>::returnNodeColor(index);
    return color;
}


template <class T>
T Stack<T>::pop()
{
    if (LinkedList<T>::empty())
    {
        cout << "\nStack is empty!";
        exit(1);
    }

    else
    {
        data = LinkedList<T>::headValue();
        LinkedList<T>::removeHead();
    }
    return data;
}


template <class T>
T Stack<T>::popSpecificCard(int index)
{
    if (LinkedList<T>::empty())
    {
        cout << "\nStack is empty!";
        exit(1);
    }

    else
    {
        data = LinkedList<T>::returnItem(index);
        LinkedList<T>::removeIndex(index);
    }
    return data;
}


template <class T>
T Stack<T>::popLastCard()
{
    if (LinkedList<T>::empty())
    {
        cout << "\nStack is empty!";
        exit(1);
    }

    else
    {
        data = LinkedList<T>::tailValue();
        LinkedList<T>::removeTail();
    }
    return data;
}


template <class T>
T Stack<T>::top()
{
    data = LinkedList<T>::headValue();
    return data;
}


template <class T>
T Stack<T>::seek(int index)
{
    return LinkedList<T>::listSeek(index);
}


template <class T>
T Stack<T>::reverseSeek(T value)
{
    return LinkedList<T>::listReverseSeek(value);
}


#endif //UNO_STACK_CPP