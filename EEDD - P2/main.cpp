/* 
 * File:   main.cpp
 * Author: zackreynolt
 *
 * Created on 10 de octubre de 2014, 16:57
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include "LinkedList.h"
#include "Song.h"
#include "Request.h"
#include "Vdinamic.h"

using namespace std;

void ListSongCharge(LinkedList<Song> &lSong);

void addReq (LinkedList<Request> &lRequest);

void eraReq (LinkedList<Request> &lRequest, Vdinamic<Request> &vRequest);

void searchCode (LinkedList<Song> &lSong, LinkedList<Request> &lRequest, string option);

void addVReq (Vdinamic<Request> &vRequest, Iterator<Request> &ei);

bool canAddRequest (LinkedList<Request> &lRequest, int n);

/*
 * 
 */
int main(int argc, char** argv) {
    LinkedList<Song> lSong;
    LinkedList<Request> lRequest;
    Vdinamic<Request> vRequest;
        
    //Fill out Song's Linked list.
    ListSongCharge(lSong);
    
    //Iterators
    Iterator<Song> i = lSong.iterator(); 
    Iterator<Request> ri = lRequest.iterator();
    
    //Exercise 1
    int option;         // Selected option in menu
    
    //======//
    // MENU //
    //======//
    cout << "\nWelcome to Radionaut!" << endl;
    cout << "You can request your favourite song here. \n" << endl;
    while (option != 5) {
        
        cout << "Options:" << endl;
        cout << "1. Add request." << endl;
        cout << "2. Remove request." << endl;
        cout << "3. Show available song and identifiers." << endl;
        cout << "4. Show request's list." << endl;
        cout << "5. Exit" << endl;
        cout << "Please, introduce the number you prefer and press enter: ";
        
        // Good enough code to avoid undesired choices
        cin >> option;
        while (option < 1 || option > 5) {
            cin.clear();
            cin.ignore(100, '\n');  //discard 100 characters from the input stream.
            cout << "Please, introduce a number between 1 and 5: ";
            cin >> option;
        }
        
        switch (option) {
            case 1: {
                cout << "\nAdd or search song." << endl;
                cout << "Type C to introduce the code, A for artist and T for "
                        "Song's title:" << endl;
                string type;
    
                cin >> type;
    
                while (type != "A" && type != "T" && type != "C") {
                    cin.clear();
                    cin.ignore(100, '\n');  //discard 100 characters from the input stream.
                    cout << "\nPlease, introduce 'A' for Artist or 'T' for Title: ";
                    cin >> type;
                }
                
                if (type == "C") { 
                    addReq(lRequest);
                } else {
                    searchCode(lSong, lRequest, type);
                } 
                break;
            }
            case 2: 
                eraReq(lRequest, vRequest);
                break;
            case 3: 
                cout << "Available songs:" << endl;
                i = lSong.iterator();
                while (!i.end()) {
                    cout << i.data().GetCode() << " - " << i.data().GetArtist() <<
                            " - " << i.data().GetTitle() << endl; 
                    i.next();
                }
                break;
            case 4: 
                cout << "Request's list:" << endl;
                ri = lRequest.iterator();
                while (!ri.end()) {
                    cout << ri.data().getCod() << " - " << ri.data().getNRequest()
                            << endl; 
                    ri.next();
                }
                
                break;
        }
    }
   
    return 0;
}

void ListSongCharge(LinkedList<Song> &lSong) {
    try { 
        fstream fi("canciones.txt");
        string line, atribute[3];

        while (!fi.eof()) {
            getline(fi, line);
            stringstream lineStream(line);

            int i = 0;
            while (getline(lineStream, atribute[i], '|')) {
                i++;
            };

            int cod = atoi(atribute[0].c_str());
            Song s(cod, atribute[1], atribute[2]);
            lSong.insertEnd(s);
        }
        fi.close();
    } catch (std::exception &e) {
        cout << "The file could not be open";
    }
}

void searchCode (LinkedList<Song> &lSong, LinkedList<Request> &lRequest, string option) {
    Iterator<Song> iterator = lSong.iterator();
    string option2;
    
    cout << "\nSearching: " << endl;
    cin >> option2;
        
    while (!iterator.end()) {
        std::size_t found;
        if (option == "A")
            found = iterator.data().GetArtist().find(option2);
        else
            found = iterator.data().GetTitle().find(option2);
        
        if (found!=std::string::npos) {
            cout << iterator.data().GetCode() << " - " << 
                    iterator.data().GetArtist() << " - " << 
                    iterator.data().GetTitle() << endl;
        }
        iterator.next();
    }
    
    addReq(lRequest);
    
    
}

void addReq (LinkedList<Request> &lRequest) {
    int n;
    bool added = false;
    Iterator<Request> si = lRequest.iterator();
    cout << "\nType the code you want to add: ";
    
    cin >> n;
    Request req(n);
    
    if (canAddRequest(lRequest,n))
        cout << "\nThe song is already in the Request's list." << endl;
    else {
        if (lRequest.getLength() == 0) {
            lRequest.insertEnd(req);
        } else {
            while (!si.end() && !added) {
                if (si.data().getCod() == n) {
                    si.data().setNRequest(1);
                    added = true;
                } else {
                    lRequest.insertEnd(req);
                    added = true;
                }
                si.next();
            }
        }
    }
        
        
}

void eraReq (LinkedList<Request> &lRequest, Vdinamic<Request> &vRequest) {
    int n;
    Iterator<Request> ei = lRequest.iterator();
    cout << "\nType the code you want to remove: ";
    
    cin >> n;
    
    while (!ei.end()) {
        if (ei.data().getCod() == n) {
            addVReq(vRequest, ei);
            lRequest.erase(ei);
        } else
            ei.next();
    }
} 

/**
 * Procedure addReq
    Adds a new request to the request's vector or increments the number of 
    times requested when it is already in the vector.  

    @param dinamic vector of requests by reference
    @return not needed because of the reference
*/
void addVReq (Vdinamic<Request> &vRequest, Iterator<Request> &ei) {
    int p;              // Request code introduced by user / position in Vdinamic
    Request *usrReq;    // Pointer - Object the user tries to add

    p = 0;

    usrReq = new Request(ei.data());
    p = vRequest.search(*usrReq);

    if (p != -1) {
        vRequest[p].setNRequest(1);
    } else {
        vRequest.addFirst(*usrReq);
    }
}

bool canAddRequest (LinkedList<Request> &lRequest, int n) {
    bool added = false;
    Iterator<Request> ci = lRequest.iterator();
    
    while (!ci.end() && !added) {
            if (ci.data().getCod() == n) {
                added = true;
            } 
            ci.next();
        }
    
    return added;
}


