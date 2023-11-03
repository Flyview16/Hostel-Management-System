#include "Functions.h"
#include <iostream>
#include <cstdlib> // added to use system clear function

using namespace std;

// Clear screen
void Systemclear()
{
    char anykey;
    cout << "Press any key to continue...";
    anykey = cin.get();

    //get user to press enter
    if(anykey == ' ' || anykey == '\n')
    {
        anykey = cin.get();
    }

    system("cls");//clear the screen

}

//Student Login
void studentLogin()
{
    int studentoption;
    cout << "\n\n\n\t\t\t*******************************************************************************\n" << endl;
    cout << "\t\t\t\t\t Welcome to the Student Portal!" << endl;
    cout << "\n\t\t\t*******************************************************************************\n" << endl;

    cout << "What would you like to do?:\n 1.View Available Rooms\n 2.Book Room\n 3.View Booked Room\n 4.Exit"<< endl;
    cout << "\n Select option: "; cin >> studentoption;

}

// manager login
void managerLogin()
{
    int managerOption;
    cout << "\n\n\n\t\t\t*******************************************************************************\n" << endl;
    cout << "\t\t\t\t\t Welcome to the Manager Portal!" << endl;
    cout << "\n\t\t\t*******************************************************************************\n" << endl;

    cout << "What would you like to do?:\n 1.Add Room\n 2.View Rooms\n 3.Add Student to Room\n 4.Remove Student\n 5.Exit"<< endl;
    cout << "\n Select option: "; cin >> managerOption;

}

