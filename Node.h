//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_NODE_H
#define UNO_NODE_H


template <class T>
struct Node
{
    T data; //remember the data type associated with template <class T>
    Node* next;
    Node* prev;
};


#endif //UNO_NODE_H
