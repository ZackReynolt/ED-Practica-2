/* 
 * File:   LinkedList.h
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 17:18
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H

template<class T>
class Node {
public:
    T     data;
    Node *next;

    Node (T &aData, Node *aNext = 0) : data(aData), next(aNext) {}
};

template<class T>
class Iterator {
    //friend class LinkedList;
    Node<T> *node;
    
public:
    Iterator            (Node<T> *aNode) : node(aNode) {}
    ~Iterator           () {};    
    
    bool end            () { return node == 0;  }
    void next           () { node = node->next; }
    T &data             () { return node->data; }
    Node<T>* getNode    () { return node; } 
};

template<class T>
class LinkedList {
    Node<T> *head, *tail;
    int _length;
public:
    LinkedList              () : head(0), tail(0), _length(0) {}
    LinkedList              (const LinkedList &orig);
    ~LinkedList             ();
    LinkedList& operator=   (const LinkedList &orig);
    
    Iterator<T> iterator    () { return Iterator<T> (head); }
    void insertBegin        (T &data);
    void insertEnd          (T &data);
    void insert             (Iterator<T> &i, T &data);
    void eraseFirst         ();
    void eraseLast          ();
    void erase              (Iterator<T> &i);
    T& first                ();
    T& last                 ();
    int getLength           () { return _length; }
};

/**
 * 
 * @param data  The data to add
 * @description Insert data at the begin of the list
 */
template<class T>
void LinkedList<T>::insertBegin(T &data){
    Node<T> *newNode;
    newNode = new Node<T>(data, head);
    
    //When the Linked list is empty, the tail is pointing to the node
    if (tail == 0)
        tail = newNode;
    
    head = newNode;
    _length++;
}

/**
 * 
 * @param data The data to add
 * @description insert data at the end of the list
 */
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
    _length++;
}

/**
 * 
 * @param i     The iterator
 * @param data  The data to add 
 * @description insert data at the position pointer by the iterator
 */
template<class T>
void LinkedList<T>::insert(Iterator<T>& i, T& data){
    Node<T> *previous = 0;
    Node<T> *p = i.getNode();
    
    if (head != tail) {
        previous = head;
        while (previous->next != p)
            previous = previous->next;
    }
    
    Node<T> *newNode = new Node<T>(data,p);
    
    previous->next = newNode;
    
    if (head == 0) {
        head = tail = newNode;
    }
    _length++;
}

/**
 * @description erase the first data of the list
 */
template<class T>
void LinkedList<T>::eraseFirst(){
    Node<T> *erased = head;
    
    head = head->next;
    
    delete erased;
    
    //When the last node is deleted
    if (head == 0)
        tail = 0;
    _length--;
}

/**
 * @description erase the last data of the list
 */
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
    _length--;
}

/**
 * 
 * @param i The iterator
 * @description erase the data pointer by the iterator
 */
template<class T>
void LinkedList<T>::erase(Iterator<T>& i){
    Node<T> *previous = 0;
    Node<T> *p = i.getNode();
    
    if (head != tail){
        previous = head;
        while (previous->next != p)
            previous = previous->next;
        previous->next = p->next;
        delete p;
        _length--;
    }else if (_length = 1 || p == tail) {
        eraseLast();
    } else if (p == head) {
        eraseFirst();
    } 
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& orig) {
    Node<T> *p, *aux;
    if (head != 0) {
        p = head;
        for (int i = 0; i < _length; ++i) {
            aux = p->next;
            delete p;
            p = aux;
        }
    }
    
    if (orig.head != 0) {
        Iterator<T> i = orig.iterator();
        head = p = new Node<T>  (i.data(), 0);

        i.next();
        while (!i.end()) {
            aux = new Node<T>   (i.data(), 0);
            p->next = aux;
            p = aux;
            i.next();
        }
        
        _length = orig._length;
        tail = p;
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator= (const LinkedList& orig) {
    Node<T> *p, *aux;
    if (head != 0) {
        p = head;
        for (int i = 0; i < _length; ++i) {
            aux = p->next;
            delete p;
            p = aux;
        }
        
        p = orig.head;
        aux = new Node<T> (p->data, 0);
        while (p->next) {
            this->insertEnd(p->data);
            p = p->next;
        }
    }
}

template<class T>
LinkedList<T>::~LinkedList() {
    Node<T> *p, *aux;
    if (head != 0) {
        p = head;
        for (int i = 0; i < _length; ++i) {
            aux = p->next;
            delete p;
            p = aux;
        }
        _length = 0;
    }
}


#endif	/* LINKEDLIST_H */

