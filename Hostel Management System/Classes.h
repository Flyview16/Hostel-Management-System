#pragma once
#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

// Classes

//Student class
class Student
{
private:
    string studentName;
    int studentId;
    string studentEmail;
    string studentContact;
    int selectedRoomNumber;
public:
    void StudentLogin();
    void StudentRoomBooking();
};

//Manager class
class Manager
{
public:
    void AddRoom();
    void ViewRooms();
};

//Rooms class
class Rooms
{
public:
    Rooms(int number,string type, int maxoccupants, double price);
    int getRoomNumber();
    int getCurrentOccupants();
    int getMaxOccupants();
    double getPrice();
    string getRoomType();
    void increaseCurrentOccupant();
    void updateCurrentOccupant(int newCount);

private:
    int roomNumber, maxOccupants, currentOccupants;
    string roomType;
    double roomPrice;
};

//Hostel class
class Hostel
{
public:
    //Function to get single instance of hostel class
    static Hostel& getInstance();

    void listRoomsByType(string selectedRoomtype);

    // Folder to store room details based on types and room numbers
    void createDatafolder();

    //Folders and files for each room type
    void savingRoomstoFile(bool isFreshRun);

    //Adding a room
    void addNewRoom(int number, string type, int maxoccupant, double price);

    //Check if room number exists
    bool roomNumberExists(int roomNumber);

    // Booking a room
    void bookingRoom(int roomNumber, string& studentName, int& studentId, string& studentEmail, string& studentContact);

    // Viewing room details
    void viewRoomDetails(string roomtype, int roomnumber);

private:
    Hostel();

    //Copy constructor and copy assignment operator
    Hostel(const Hostel&);
    Hostel& operator = (const Hostel&);

    //Initializing room types
    vector<string> Roomtype = {"One in one", "Two in one", "Three in one", "Four in one"};

    // Vector(dynamic array) to store Room objects
    vector<Rooms> Hostelrooms;
    string datafolder = "Hostel Room Data";

    //Get maximum occupants and price by room type
    void getMaxOccPrice(string& roomtype,int& maxOccupants, double&price);

    // Create 3 rooms for each room type
    void initializeRooms();

    // Adding Student to room
    void addStudentToRoom(Rooms& room, string& studentName, int& studentId, string& studentEmail, string& studentContact);
};


#endif // CLASSES_H_INCLUDED
