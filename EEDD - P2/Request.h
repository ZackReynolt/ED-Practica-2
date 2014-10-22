/* 
 * File:   request.h
 * Author: zackreynolt
 *
 * Created on October 22, 2014, 8:15 PM
 */

#ifndef REQUEST_H
#define	REQUEST_H

using namespace std;

class Request {
private:
    int _cod;           // Song code
    int _nRequest;      // Number of requests
    
public:
    Request();
    Request (int code);
    ~Request() {};
    void addRequest (int code);
    void setNRequest(int _nRequest);
    int getNRequest() const;
    void setCod(int _cod);
    int getCod() const;
    bool operator==(const Request &orig) {
        if (_cod == orig._cod)
            return true;
        return false;
    }
};

Request::Request() {
    _cod = -1;
    _nRequest = -1;
}

Request::Request(int code) {
    _cod = code;
    _nRequest = 1;
}

void Request::setNRequest(int _nRequest) {
    this->_nRequest += _nRequest;
}

int Request::getNRequest() const {
    return _nRequest;
}

void Request::setCod(int _cod) {
    this->_cod = _cod;
}

int Request::getCod() const {
    return _cod;
}

void Request::addRequest(int code) {
    _nRequest++;
}
        

#endif	/* REQUEST_H */

