/* 
 * File:   LinkedList.h
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 17:18
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

#include "Iterator.h"

template<class U>
class Node {
public:
    U data;
    Node *next;

    Node(U &aData, Node *aNext = 0) :
    data(aData), next(aNext) {
    }
};

template<class T>
class LinkedList {
    Node<T> *head, *tail;
public:
    LinkedList  () : head(0), tail(0) {}
    LinkedList  (const LinkedList &orig);
    ~LinkedLIst ();
    LinkedList& operator= (const LinkedList &orig);
    
    Iterator<T> iterator() { return Iterator<T> (head); }
    void insertBegin    (T &data);
    void insertEnd      (T &data);
    void insert (Iterator<T> &i, T &data);
    void eraseFirst ();
    void eraseLast  ();
    void erase  (Iterator<T> &i);
    T& first    ();
    T& last     ();
};

template<class T>
void LinkedList<T>::insertBegin(T &data){
    Node<T> *newNode;
    newNode = new Node<T>(data, head);
    
    //When the Linked list is empty, the queue pointing to the node
    if (tail == 0)
        tail = newNode;
    
    head = newNode;
}

#endif	/* LINKEDLIST_H */

