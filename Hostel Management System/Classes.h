#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

// Classes

//Student class
class Student
{
public:
    void StudentLogin();
};

//Manager class
class Manager{};

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

private:
    int roomNumber, maxOccupants,currentOccupants;
    string roomType;
    double roomPrice;
};

//Hostel class
class Hostel
{
public:
    Hostel();
    void listRoomsByType(string selectedRoomtype);
private:
    //Initializing room types
    vector<string> Roomtype = {"One in one", "Two in one", "Three in one", "Four in one"};

    // Vector(dynamic array) to store Room objects
    vector<Rooms> Hostelrooms;

    //Get maximum occupants and price by room type
    void getMaxOccPrice(string& roomtype,int& maxOccupants, double&price);
};


#endif // CLASSES_H_INCLUDED
