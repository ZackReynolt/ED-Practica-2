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
    int _length;
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
<<<<<<< dca07ee387dac93eb2214b10753866b7b88e3b8b
void LinkedList<T>::insertBegin(T &data){
    Node<T> *newNode;
    newNode = new Node<T>(data, head);
    
    //When the Linked list is empty, the queue pointing to the node
    if (tail == 0)
        tail = newNode;
    
    head = newNode;
=======
LinkedList<T>::LinkedList(const LinkedList& orig) {
    if (head) {
        Node *aux;
        for (int i = 0; i < _length; ++i) {
            aux = head->next;
            delete head;
            head = aux;
        }
        
        _length = orig._length;
        head = new Node(orig.head, orig.head->next);
        for (int i = 0; i < orig._length; ++i) {
            
        }
        
    } else {
        
    }
>>>>>>> af79c80d45ff3e5428531377abc080cb62449103
}

#endif	/* LINKEDLIST_H */

