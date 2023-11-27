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

void Student::StudentRoomBooking()
{
    Hostel& hostel = Hostel::getInstance();

    cout << "\nEnter room number of choice: ";
    cin >> selectedRoomNumber;
    cin.ignore();

    cout << "\nEnter student name: ";
    getline(cin, studentName);

    cout << "\nEnter student Id: ";
    cin >> studentId;
    cin.ignore();

    cout << "\nEnter email: ";
    getline(cin, studentEmail);

    cout << "\nEnter contact info(number): ";
    cin >> studentContact;

    hostel.bookingRoom(selectedRoomNumber, studentName, studentId, studentEmail, studentContact);

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

void Rooms::increaseCurrentOccupant()
{
    currentOccupants++;
}

void Rooms::updateCurrentOccupant(int newCount)
{
    currentOccupants = newCount;
}


//Hostel class methods implementation
Hostel::Hostel()
{
    createDatafolder();
    initializeRooms();
    savingRoomstoFile(true);
}

Hostel& Hostel::getInstance()
{
    static Hostel instance;
    return instance;
}

void Hostel::createDatafolder()
{
    if(!fs::exists(datafolder))
    {
        fs::create_directory(datafolder);
    }
}

void Hostel::savingRoomstoFile(bool isFreshRun)
{
    //iterate through room vector
    for(Rooms& room : Hostelrooms)
    {
        string roomType = room.getRoomType();
        int roomNumber = room.getRoomNumber();
        int currentOccupants = room.getCurrentOccupants();

        //Creating folder for each room type
        fs::path roomTypeFolder = fs::path(datafolder) / roomType;
        if(!fs::exists(roomTypeFolder))
        {
            fs::create_directory(roomTypeFolder);
        }

        //Creating files for each room number under each room type
        fs::path roomFile= roomTypeFolder / to_string(roomNumber) += ".txt";

        //If file does not exist
        if(!fs::exists(roomFile))
        {
            ofstream file(roomFile);
            if(file.is_open())
            {
                file << "Room type:" << roomType << endl;
                file << "Room number:" << roomNumber << endl;
                file << "Current Occupants:"<<currentOccupants <<endl;
                file << "Occupants Details:\n"<< endl;

                file.close();
            }
        }
        else
        {
            //File already exist, read room details and update in program
            vector<string> filecontent;  //Save current file content to a vector
            string line;

            ifstream readfile(roomFile);
            if(readfile.is_open())
            {

                while(getline(readfile,line))
                {

                    if(line.find("Current Occupants:") != string::npos)
                    {
                       if(isFreshRun)
                       {
                            int currentOccupants = stoi(line.substr(line.find(":") + 1));
                            room.updateCurrentOccupant(currentOccupants);
                       }else
                       {
                           line = "Current Occupants: " + to_string(currentOccupants);
                       }
                    }
                    filecontent.push_back(line);
                }

                readfile.close();
            }
            //Rewrite Details to file
            ofstream writeFile(roomFile);
            if(writeFile.is_open())
            {
                for(string& line : filecontent)
                {
                    writeFile << line << endl;
                }
                writeFile.close();
            }
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

        savingRoomstoFile(true);

        cout << "\n Room added successfully!!" << endl;
    }else
        cout << "\n Ooops!! Room number " << number << " already exists. Choose a different room number" << endl;
}

void Hostel::addStudentToRoom(Rooms& room, string& studentName, int& studentId, string& studentEmail, string& studentContact)
{
    //Defining the path
    fs::path roomTypeFolder = fs::path(datafolder) / room.getRoomType();

    fs::path roomFile = roomTypeFolder / (to_string(room.getRoomNumber()) + ".txt");

    //Opening and appending details
    try
    {
        ofstream file(roomFile, ios::app | ios::ate);
        if(file.is_open())
        {
            file << "Student name: " << studentName << endl;
            file << "Student Id: " << studentId << endl;
            file << "Student email: " << studentEmail << endl;
            file << "Student contact: " << studentContact << endl;
            file << "" << endl;

            file.flush();
            file.close();
        }else
            cout << "\nUnable to open file for append" << endl;
        }catch(const exception& e)
        {
            cout<< "Unable to open and write to file" << e.what() << endl;
        }
}

void Hostel::bookingRoom(int roomNumber, string& studentName, int& studentId, string& studentEmail, string& studentContact)
{
    for(Rooms& room : Hostelrooms)
    {
        if(room.getRoomNumber() == roomNumber)
        {
            //Add student details to room
            addStudentToRoom(room, studentName, studentId, studentEmail, studentContact);

            //Update room details
            room.increaseCurrentOccupant();
            savingRoomstoFile(false);

            cout << "\nRoom booked successfully!!" << endl;
            return;
        }
    }
    cerr << "\nError!! Room not found. Make sure room number is part of the list." << endl;     //if loop completes without finding the room
}

void Hostel::viewRoomDetails(string roomtype, int roomnumber)
{
    fs::path roomFile = fs::path (datafolder) / roomtype / (to_string(roomnumber) + ".txt");

    //Check if file exists
    if(fs::exists(roomFile))
    {
        ifstream file(roomFile);
        if(file.is_open())
        {
            string line;
            while(getline(file,line))
            {
                cout << line << endl;

                //Print the student data in a table form
                if(line.find("Occupants Details") != string::npos)
                {
                    cout << setw(20) << left << "\nStudent Name"
                    << setw(20) << left << "Student Id"
                    << setw(20) << left << "Student Email"
                    << setw(20) << left << "Student Contact" << endl;

                    while(getline(file, line))
                    {
                        if(line.empty())
                        {
                            cout << endl;
                            continue;
                        }

                        size_t colon = line.find(":");
                        if(colon != string::npos)
                        {
                            string detailValue = line.substr(colon + 1);
                            cout << setw(20) << left << detailValue;
                        }
                    }

                }
            }
            file.close();
        }else
        {
            cerr << "Unable to open file for reading" << endl;
        }
    }else
    {
        cerr << "Room not found! Room not found!!" << endl;
    }
}

// Manager class methods implementations
void Manager::AddRoom()
{
    Hostel& hostel = Hostel::getInstance();
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

void Manager::ViewRooms()
{
    int selectedRoomnumber;
    string roomtype;
    Hostel& hostel = Hostel::getInstance();

    roomtype = printRoomtypes();
    hostel.listRoomsByType(roomtype);

    cout << "\nEnter room number to view room details: " ;
    cin >> selectedRoomnumber;

    Systemclear();

    cout << "\nRoom details for room " << selectedRoomnumber << ": \n" << endl;

    hostel.viewRoomDetails(roomtype,selectedRoomnumber);
}
