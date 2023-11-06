#include "Classes.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <string>



using namespace std;

void Student::StudentLogin()
{
    string name;
    cout << "Enter your name(optional): ";
    cin >> name;
    Systemclear();
}

void Student::RoomTypes()
{
    int roomtypeselect;
    //Roomtypes
    string Roomtypes[] = {"One in one", "Two in one", "Three in one", "Four in one"};

    cout << "\nRoomTypes:" << endl;

    for(int i=0; i< 4; i++)
    {
        // Print  out all room types
        cout << " \n" << i+1 << "." << Roomtypes[i];
    }

    cout << "\n\nSelect option: ";
    cin >> roomtypeselect;
}
