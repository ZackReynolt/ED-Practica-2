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

using namespace std;

void ListSongCharge(LinkedList<Song> &lSong);

/*
 * 
 */
int main(int argc, char** argv) {
    LinkedList<Song> lSong;
    LinkedList<Request> lRequest;
        
    //Fill out Song's Linked list.
    ListSongCharge(lSong);
    
    //Test
    Iterator<Song> i = lSong.iterator();    
    
    while (!i.end()) {
        cout << i.data().GetCode() << endl; //Si esto no se muestra así, no tengo ni idea
        i.next();
    }
    
    
    /*
    //Exercise 1
    int option;         // Selected option in menu
    
    //======//
    // MENU //
    //======//
    while (option != 5) {
        cout << "\nWelcome to Radionaut!" << endl;
        cout << "You can request your favourite song here. \n" << endl;
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
            case 1:
                cout << "\nAdd or search song:" << endl;
                break;
            case 2: 
                cout << "\nRemove request:" << endl;
                break;
            case 3: 
                cout << "Available songs:" << endl;
                break;
            case 4: 
                cout << "Request's list:" << endl;
                break;
        }
    }
    */
    
   
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

