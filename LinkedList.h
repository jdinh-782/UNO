//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_LINKEDLIST_H
#define UNO_LINKEDLIST_H


#include "Node.h"
#include "CardHand.h"
#include <iostream>

using namespace std;


template <class T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    Node<T>* createNode(T item);

public:
    LinkedList();
    LinkedList(const LinkedList<T>& list);
    ~LinkedList();

    Node<T>* returnNode(T item);

    void clear(); //clears the linked list
    void removeHead(); //remove head value
    void removeIndex(int index); //remove specific node value
    void removeTail(); //remove the tail value
    //void removeNode(T value);

    void insertBeginning(T item);
    void operator += (T item); //add cards at the end

    bool empty();
    bool findItem(T value);
    T returnItem(int index);

    int listSize();
    int returnNodeValue(int index);

    string returnNodeColor(int index); //returns color of card by linked list method

    T headValue();
    T tailValue();
    T listSeek(int index);
    T listReverseSeek(int index);

    template <class S>
    friend ostream& operator << (ostream& outs, const LinkedList<S>& list);
};


#include "LinkedList.cpp"


#endif //UNO_LINKEDLIST_H
