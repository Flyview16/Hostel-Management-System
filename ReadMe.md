# Hostel Management System

### Overview
The Hostel Management System is a C++ program designed to manage the operations of a hostel, including room allocation, student bookings, and room information management. The system allows both students and managers to interact with the hostel's data, making it efficient for day-to-day operations.

### Features
- Student portal: Students can view available rooms, book a room, and check their booked room details.
- Manager portal: Managers can perform various tasks, including adding new rooms, viewing room details, and removing rooms from the hostel.
- Room Allocation: The system ensures proper room allocation and keeps track of the current number of occupants in each room.
- Data Persistence: Hostel data, including room details and bookings, is stored in text files, allowing the system to maintain state between runs.


### Getting Started
1. Clone the repository:

   ```bash

   git clone https://github.com/Flyview16/Hostel-Management-System/tree/master/Hostel%20Management%20System

2. Compile the program:
    
    ```bash
    g++ main.cpp FunctionDefinition.cpp ClassDefinitions.cpp -o bin/debug/hostel_management_system

3. Run the executable program:
- On Windows:

    ```bash
    bin/debug/hostel_management_system.exe

- On Linux or macOS:

    ```bash
    ./bin/debug/hostel_management_system


### Contributing
If you would like to contribute to the development of the Hostel Management System, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature: git checkout -b feature-name.
3. Commit your changes: ```bash git commit -m 'Add new feature'.
4. Push to the branch: ```bash git push origin feature-name.
5. Submit a pull request.