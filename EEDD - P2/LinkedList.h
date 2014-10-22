/* 
 * File:   LinkedList.h
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 17:18
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H


template<class T>
class Iterator {
    Node<T> *node;
    
public:
    Iterator    (Node<T> *aNode) : node(aNode) {}
    ~Iterator   ();
    
    bool end    () { return node == 0;  }
    void next   () { node = node->next; }
    T &data     () { return node->data; }
};

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
    ~LinkedList ();
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
    
    //When the Linked list is empty, the tail is pointing to the node
    if (tail == 0)
        tail = newNode;
    
    head = newNode;
}

template<class T>
void LinkedList<T>::insertEnd (T &data){
    Node<T> *newNode;
    newNode = new Node<T>(data, 0);
    
    if (tail != 0)
        tail->next = newNode;
    
    //When the Linked list is empty, the header is  pointing to the node
    if (head == 0)
        head = newNode;

    tail = newNode;
}

template<class T>
void LinkedList<T>::insert(Iterator<T>& i, T& data){
    Node<T> *previous = 0;
    Node<T> *p = i.node;
    
    if (head != tail) {
        previous = head;
        while (previous->next != p)
            previous = previous->next;
    }
    
    Node<T> *newNode = new Node(data,p);
    
    previous->next = newNode;
    
    if (head == 0) {
        head = tail = newNode;
    }

}

template<class T>
void LinkedList<T>::eraseFirst(){
    Node<T> *erased = head;
    
    head = head->next;
    
    delete erased;
    
    //When the last node is deleted
    if (head == 0)
        tail = 0;
}

template<class T>
void LinkedList<T>::eraseLast(){
    Node<T> *previous = 0;
    if (head != tail) {
        previous = head;
        while (previous->next != tail)
            previous = previous->next;
    }
    
    delete tail;
    
    tail = previous;
    if (previous != 0)
        previous->next = 0;
    else
        head = 0;
}

template<class T>
void LinkedList<T>::erase(Iterator<T>& i){
    Node<T> *previous = 0;
    Node<T> *p = i.node;
    
    if (head != tail) {
        previous = head;
        while (previous->next != p)
            previous = previous->next;
    }
}

template<class T>
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
}

#endif	/* LINKEDLIST_H */

