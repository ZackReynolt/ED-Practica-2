/* 
 * File:   Node.h
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 17:16
 */

#ifndef NODE_H
#define	NODE_H

template<class T>

class Node {
public:
    T data;
    Node *next;

    Node(T &aData, Node *aNext = 0) :
    data(aData), next(aNext) {
    }
    
};

#endif	/* NODE_H */

