/* 
 * File:   Vdinamic.h
 * Author: alf
 *
 * Created on September 26, 2014, 11:24 AM
 */

#ifndef VDINAMIC_H
#define	VDINAMIC_H

#include <stdexcept>

using namespace std;

template<class T>
class Vdinamic {
public:
    Vdinamic                ();
    Vdinamic                (int logicLength);
    Vdinamic                (const Vdinamic &orig);
    ~Vdinamic               ();
    
    T read                  (int pos){ return v[pos]; }
    unsigned lenght         (){ return _logicLength; }
    void write              (int pos, T data){ v[pos] = data; }    
    void insert             (T data, unsigned pos);
    void erase              (unsigned pos);
    void addLast            (T &data);                  // Add in last position
    void addFirst           (T &data);                  // Add in first position
    void eraseLast          ();                         // Delete the last data
    void eraseFirst         ();                         // Delete the first data
    int search              (T &data);
    
    Vdinamic<T>& operator=  (Vdinamic &orig);
    T& operator[]           (unsigned pos);
    
private:
    int _logicLength;           // Number of data added in the vector
    int _fisicLenght;           // Reserved memory
    T *v;
    
    void extend();
    void reduce();
};

template<class T>
Vdinamic<T>::Vdinamic() {
    _logicLength = 0;
    _fisicLenght = 50;
    v = new T[_fisicLenght];
}

template<class T>
Vdinamic<T>::Vdinamic(int logicLenght) {
    _logicLength = logicLenght;
    _fisicLenght = logicLenght*2;
    v = new T[logicLenght*2];    
}

template<class T>
Vdinamic<T>::Vdinamic(const Vdinamic& orig) {
    v = new T[_fisicLenght = orig._fisicLenght];
    _logicLength = orig._logicLength;
    for (int i = 0; i < orig._logicLength; ++i)
        v[i] = orig[i];
}

template<class T>
Vdinamic<T>::~Vdinamic() {
    delete[] v;
}

template<class T>
void Vdinamic<T>::addLast(T &data) {
    v[_logicLength] = data;
    _logicLength++;
    extend();
}

template<class T>
void Vdinamic<T>::addFirst(T& data) {
    _logicLength++;
    extend();
    for (int i = _logicLength-1; i >= 0; --i) {
        v[i+1] = v[i];
    v[0] = data;
    }
}

template<class T>
void Vdinamic<T>::insert(T data, unsigned pos) {
    _logicLength++;
    extend();
    for (int i = _logicLength-1; i >= pos; --i)
        v[i+1] = v[i];
    v[pos] = data;
}

template<class T>
void Vdinamic<T>::eraseLast() {
    _logicLength--;
    reduce();
}

template<class T>
void Vdinamic<T>::eraseFirst() {
    for (int i = 0; i < _logicLength; ++i)
        v[i] = v[i+1];
    _logicLength--;
    reduce();
}

template<class T>
void Vdinamic<T>::erase(unsigned pos) {
    if (pos >= _logicLength)    throw std::out_of_range("Out of range");
    if (pos < 0)                throw std::out_of_range("Out of range");
    for (int i = pos; i < _logicLength; ++i)
        v[i] = v[i+1];
    _logicLength--;
    reduce();
}

template<class T>
int Vdinamic<T>::search(T &data) {
    for (int i = 0; i < _logicLength; ++i) {
        if (data == v[i])
            return i;
    }
    return -1;
}

template<class T>
void Vdinamic<T>::extend() {
    if (_logicLength == _fisicLenght) {
        _fisicLenght = _fisicLenght*2;
        T *vaux = new T[_fisicLenght];
        for (int i = 0; i < _logicLength; ++i)
            vaux[i] = v[i];
        delete[] v;
        v = vaux;
    }
}

template<class T>
void Vdinamic<T>::reduce() {
    if (_logicLength*3 < _fisicLenght) {
        _fisicLenght = _fisicLenght/2;
        T* vaux = new T[_fisicLenght];
        for (int i = 0; i < _logicLength; ++i)
            vaux[i] = v[i];
        delete[] v;
        v = vaux;
    }
}

template<class T>
Vdinamic<T>& Vdinamic<T>::operator= (Vdinamic& orig) {
    delete[] v;
    v = new int[orig._fisicLenght];
    _fisicLenght = orig._fisicLenght;
    _logicLength = orig._logicLength;
    for (int i = 0; i < orig._logicLength; ++i)
        v[i] = orig[i];
    return this;
}

template<class T>
T& Vdinamic<T>::operator[] (unsigned pos) {
    if (pos >= _logicLength) throw std::out_of_range("Out of range");
    if (pos < 0) throw std::out_of_range("Out of range");
    return v[pos];
}

#endif	/* VDINAMIC_H */

