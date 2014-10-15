/* 
 * File:   Iterator.h
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 17:17
 */

#ifndef ITERATOR_H
#define	ITERATOR_H

template<class T>

class Iterator {
    Node<T> *node;
    friend class LinkedList;
    
public:

    Iterator(Node<T> *aNode) : node(aNode) {}

    bool end() {return node == 0;}

    void next() {node = node->next;}

    T &data() {return node->data;}
    
};

#endif	/* ITERATOR_H */

