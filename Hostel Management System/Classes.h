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
class Manager
{
public:
    void AddRoom();
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

    // Folder to store room details based on types and room numbers
    void createDatafolder();

    //Folders and files for each room type
    void savingRoomstoFile();

    //Adding a room
    void addNewRoom(int number, string type, int maxoccupant, double price);

    //Check if room number exists
    bool roomNumberExists(int roomNumber);

private:
    //Initializing room types
    vector<string> Roomtype = {"One in one", "Two in one", "Three in one", "Four in one"};

    // Vector(dynamic array) to store Room objects
    vector<Rooms> Hostelrooms;
    string datafolder = "Hostel Room Data";

    //Get maximum occupants and price by room type
    void getMaxOccPrice(string& roomtype,int& maxOccupants, double&price);

    // Create 3 rooms for each room type
    void initializeRooms();
};


#endif // CLASSES_H_INCLUDED
