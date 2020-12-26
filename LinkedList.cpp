//
// Created by jdinh on 12/5/2020.
//

#ifndef UNO_LINKEDLIST_CPP
#define UNO_LINKEDLIST_CPP
#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}


template <class T>
LinkedList<T>::LinkedList (const LinkedList& list)
{
    *this = list;
}


template <class T>
LinkedList<T>::~LinkedList()
{
    clear();
}


template <class T>
Node<T>* LinkedList<T>::returnNode(T item)
{
    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (object->data.returnName() == item.returnName()) //check if names equal
        {
            return object;
        }
    }
    return nullptr;
}


template <class T>
void LinkedList<T>::clear()
{
    Node<T>* object = head;
    Node<T>* temp;

    while (object != nullptr)
    {
        temp = object;
        object = object->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}


template<class T>
Node<T>* LinkedList<T>::createNode(T item)
{
    auto* n = new Node<T>;
    n->data = item;
    n->next = nullptr;
    n->prev = nullptr;
    return n;
}


template <class T>
void LinkedList<T>::insertBeginning(T item)
{
    Node<T> *temp = createNode(item);

    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        temp->next = head;
        head->prev = temp;
        temp->prev = nullptr;
        head = temp;
    }
}


template <class T>
void LinkedList<T>::operator += (T item)
{
    Node<T>* temp = createNode(item);
    if (head == nullptr)
    {
        head = temp;
        tail = temp;
    }

    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}


template <class T>
void LinkedList<T>::removeIndex(int index)
{
    int counter = 0;

    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (counter == index)
        {
            Node<T>* deleteNode = returnNode(object->data);
            deleteNode->prev->next = deleteNode->next;
            deleteNode->next->prev = deleteNode->prev;
            delete deleteNode;
            break;
        }
        counter++;
    }
}


//template <class T>
//void LinkedList<T>::removeNode(T value)
//{
//    if (returnNode(value) == nullptr)
//    {
//        cout << "Node value was not found!\n";
//        return;
//    }
//
//    Node<T>* deleteNode = returnNode(value);
//
//    if (head == nullptr)
//    {
//        cout << "\nList is empty! ";
//    }
//
//    else if (head->data == deleteNode->data)
//    {
//        if (head->next == nullptr)
//        {
//            head = nullptr;
//            delete deleteNode;
//        }
//        else
//        {
//            head = deleteNode->next;
//            head->prev = nullptr;
//            delete deleteNode;
//        }
//    }
//
//    else if (tail->data == deleteNode->data)
//    {
//        tail = deleteNode->prev;
//        tail->prev = deleteNode->prev->prev;
//        tail->next = nullptr;
//        delete deleteNode;
//    }
//
//    else
//    {
//        deleteNode->prev->next = deleteNode->next;
//        deleteNode->next->prev = deleteNode->prev;
//        delete deleteNode;
//    }
//}


template <class T>
void LinkedList<T>::removeHead()
{
    Node<T>* deleteNode = returnNode(head->data);

    if (head->next == nullptr)
    {
        head = nullptr;
        delete deleteNode;
    }
    else
    {
        head = deleteNode->next;
        head->prev = nullptr;
        delete deleteNode;
    }
}


template <class T>
void LinkedList<T>::removeTail()
{
    Node<T>* deleteNode = returnNode(tail->data);

    if (head == nullptr)
    {
        cout << "\nList is empty! ";
    }

    else
    {
        tail = deleteNode->prev;
        tail->prev = deleteNode->prev->prev;
        tail->next = nullptr;
        delete deleteNode;
    }
}


template <class T>
bool LinkedList<T>::empty()
{
    if (head == nullptr && tail == nullptr)
    {
        return true;
    }
    return false;
}


template <class T>
bool LinkedList<T>::findItem(T item)
{
    int index = 0;

    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (object->data == item)
        {
            //cout << endl << value << " was found at index " << index;
            return true;
        }
        index++;
    }
    return false;
}


template <class T>
T LinkedList<T>::returnItem(int index)
{
    int counter = 0;

    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (counter == index)
        {
            return object->data;
        }
        counter++;
    }
}


template <class T>
int LinkedList<T>::listSize()
{
    int counter = 0;
    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        counter++;
    }
    return counter;
}


template <class T>
int LinkedList<T>::returnNodeValue(int index)
{
    int count = 0;
    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (count == index)
        {
            return object->data.returnValue();
        }
        count++;
    }
    return -1;
}


template <class T>
string LinkedList<T>::returnNodeColor(int index)
{
    int count = 0;
    for (Node<T>* object = head; object != nullptr; object = object->next)
    {
        if (count == index)
        {
            return object->data.returnColor();
        }
        count++;
    }
    return "NULL";
}


template <class T>
T LinkedList<T>::headValue()
{
    return head->data;
}


template <class T>
T LinkedList<T>::tailValue()
{
    return tail->data;
}


template <class T>
T LinkedList<T>::listSeek(int index)
{
    Node<T>* object = head;
    int counter = 0;

    while (object != nullptr)
    {
        if (counter == index)
        {
            return object->data;
        }
        object = object->next;
        counter++;
    }

    if (object != nullptr)
    {
        return object->data;
    }

    else if (tail != nullptr)
    {
        return tail->data;
    }
    return T();
}



template <class T>
T LinkedList<T>::listReverseSeek(int index)
{
    Node<T>* object = tail;
    int counter = 0;

    while (object != nullptr)
    {
        if (counter == index)
        {
            return object->data;
        }
        object = object->prev;
        counter++;
    }

    if (object != nullptr)
    {
        return object->data;
    }

    else
    {
        return head->data;
    }
}


template <class S>
ostream& operator << (ostream& outs, const LinkedList<S>& list)
{
    for (Node<S>* object = list.head; object != nullptr; object = object->next)
    {
        //outs.width(2);
        outs << object->data << endl;
    }
    return outs;
}


#endif //UNO_LINKEDLIST_CPP