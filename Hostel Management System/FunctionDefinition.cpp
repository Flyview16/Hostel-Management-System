#include "Functions.h"
#include "Classes.h"
#include <iostream>
#include <cstdlib> // added to use system clear function
#include <string>

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
    Student newStudent;
    newStudent.StudentLogin();
    Hostel hostel;
    int studentoption;
    cout << "\n\n\n\t\t\t*******************************************************************************\n";
    cout << "\t\t\t\t\t Welcome to the Student Portal!" << endl;
    cout << "\n\t\t\t*******************************************************************************\n" << endl;

    cout << "What would you like to do?:\n 1.View Available Rooms\n 2.Book Room\n 3.View Booked Room\n 4.Exit"<< endl;
    cout << "\n Select option: "; cin >> studentoption;

    switch(studentoption)
    {
        case 1: hostel.listRoomsByType(printRoomtypes());
        break;

        case 2: hostel.listRoomsByType(printRoomtypes());
        break;

        case 4:
        break;

        default: cout << "Please select one of the above" << endl;
        break;
    }

}

// manager login
void managerLogin()
{
    Manager manager;
    int managerOption;
    cout << "\n\n\n\t\t\t*******************************************************************************\n" << endl;
    cout << "\t\t\t\t\t Welcome to the Manager Portal!" << endl;
    cout << "\n\t\t\t*******************************************************************************\n" << endl;

    cout << "What would you like to do?:\n 1.Add Room\n 2.View Rooms\n 3.Add Student to Room\n 4.Remove Student\n 5.Exit"<< endl;
    cout << "\n Select option: "; cin >> managerOption;

    switch(managerOption)
    {
        // Options for various selections
        case 1 : manager.AddRoom();

        case 5:
            break;

        default:
            cout << "\nPlease select one of the options above.\n";
            break;
    }

}

string printRoomtypes()
{
    int selectedType;
    string selectedRoomtype;
    Hostel hostel;

    string Roomtypes[] = {"One in one", "Two in one", "Three in one", "Four in one"};

    cout << "\nRoomTypes:" << endl;

    for(int i=0; i< 4; i++)
    {
        // Print  out all room types
        cout << " \n" << i+1 << "." << Roomtypes[i];
    }

    cout << "\n\nSelect option: ";
    cin >> selectedType;

    switch(selectedType)
    {
        case 1: return selectedRoomtype = "One in one";
        break;

        case 2: return selectedRoomtype = "Two in one";
        break;

        case 3: return selectedRoomtype = "Three in one";
        break;

        case 4: return selectedRoomtype = "Four in one";
        break;

        default: cout << "Select one of the above";
                 return "Invalid Selection";
        break;
    }

}

