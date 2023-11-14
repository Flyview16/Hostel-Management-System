// Class methods implementations

#include "Classes.h"
#include "Functions.h"
#include <iostream>
#include <string>
#include <cstdlib>   // system clear
#include <iomanip>  // setw function
#include <filesystem>
#include <fstream>


using namespace std;
namespace fs = std::filesystem;


// student class methods implementation
void Student::StudentLogin()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    Systemclear();
}


// Room class methods implementation

Rooms::Rooms(int number,string type,int maxoccupants, double price) : roomNumber(number),roomType(type),maxOccupants(maxoccupants),roomPrice(price){
    currentOccupants = 0;
}

int Rooms::getRoomNumber()
{
    return roomNumber;
}

int Rooms::getCurrentOccupants()
{
    return currentOccupants;
}

int Rooms::getMaxOccupants()
{
    return maxOccupants;
}

double Rooms::getPrice()
{
    return roomPrice;
}

string Rooms::getRoomType()
{
    return roomType;
}


//Hostel class methods implementation
Hostel::Hostel()
{
    createDatafolder();
    initializeRooms();
    savingRoomstoFile();
}

void Hostel::createDatafolder()
{
    if(!fs::exists(datafolder))
    {
        fs::create_directory(datafolder);
    }
}

void Hostel::savingRoomstoFile()
{
    //iterate through room vector
    for(Rooms& room : Hostelrooms)
    {
        string roomType = room.getRoomType();
        int roomNumber = room.getRoomNumber();

        //Creating folder for each room type
        fs::path roomTypeFolder = fs::path(datafolder) / roomType;
        if(!fs::exists(roomTypeFolder))
        {
            fs::create_directory(roomTypeFolder);
        }

        //Creating files for each room number under each room type
        fs::path roomFile= roomTypeFolder / to_string(roomNumber) += ".txt";
        ofstream file(roomFile);
        if(file.is_open())
        {
            file << "Room type:" << roomType << endl;
            file << "Room number:" << roomNumber << endl;

            file.close();
        }else
        {
            cerr << "Unable to save room data to file" << endl;
        }
    }
}
void Hostel::initializeRooms()
{
     //Create room objects for each room type
    int roomNumberCounter = 1;
    for(string& roomtype : Roomtype){
        int maxOccupants;
        double price;
        getMaxOccPrice(roomtype,maxOccupants,price);

        //Create 3 rooms each for every room type
        for(int i =0; i<3;i++)
        {
            Hostelrooms.push_back(Rooms(roomNumberCounter, roomtype,maxOccupants, price)); //Add created rooms to vector
            roomNumberCounter++;
        }
    }
}

void Hostel::getMaxOccPrice(string& roomtype,int& maxOccupants, double&price)
{
    //Assigning max occupants and price based on room type
    maxOccupants = 0;
    price = 0.0;

    if(roomtype == "One in one")
    {
        maxOccupants = 1;
        price = 5000.00;
    }else if(roomtype == "Two in one")
    {
        maxOccupants = 2;
        price = 4700.00;
    }else if(roomtype == "Three in one")
    {
        maxOccupants = 3;
        price = 4200.00;
    }else if(roomtype == "Four in one")
    {
        maxOccupants = 4;
        price = 3500.00;
    }else {maxOccupants = 0; price = 0.0;}
}

void Hostel::listRoomsByType(string selectedRoomtype)
{
    Systemclear();
    // Table columns
    cout << setw(30) << endl;
    cout << left << setw(15) << "Room Number"
    << setw(20) << "Room Type"
    << setw(25) << "Current Occupants"
    << setw(15) << "Price" << endl;

    // Iterate through hostel rooms vector to print room details for selected room type
    for(Rooms& room : Hostelrooms)
    {

        if(room.getRoomType() == selectedRoomtype)
        {
            string occupantsRatio = to_string(room.getCurrentOccupants()) + "/" + to_string(room.getMaxOccupants());

            cout << left << setw(15) << room.getRoomNumber()
            << setw(20) << room.getRoomType()
            << setw(25) << occupantsRatio
            << setw(15) << room.getPrice() << endl;
        }
    }

}

bool Hostel::roomNumberExists(int roomNumber)
{
    for(Rooms& room : Hostelrooms)
    {
        if(room.getRoomNumber() == roomNumber)
            return true; // The room number exists
    }
    return false; // the room number does not exist
}


void Hostel::addNewRoom(int number, string type,int maxoccupant,double price)
{
    if(!roomNumberExists(number))
    {
        Hostelrooms.push_back(Rooms(number, type, maxoccupant, price));
        savingRoomstoFile();
        cout << "\n Room added successfully!!" << endl;
    }else
        cout << "\n Ooops!! Room number " << number << " already exists. Choose a different room number" << endl;
}
// Manager class methods implementations

void Manager::AddRoom()
{
    Hostel hostel;
    int newRoomNumber;
    int newMaxOccupants;
    double newRoomPrice;
    string newRoomType;

    Systemclear();

    cout << "Select room type:" ;
    newRoomType = printRoomtypes();

    cout << "Enter maximum number of occupants: ";
    cin >> newMaxOccupants;

    cout << "Enter new room number: ";
    cin >> newRoomNumber;

    cout << "Enter new room price: ";
    cin >> newRoomPrice;

    hostel.addNewRoom(newRoomNumber, newRoomType, newMaxOccupants, newRoomPrice);

}
