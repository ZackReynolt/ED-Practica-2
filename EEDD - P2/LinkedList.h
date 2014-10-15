/* 
 * File:   LinkedList.h
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 17:18
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

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

#endif	/* LINKEDLIST_H */

