# Hostel Management System

### Overview
The Hostel Management System is a C++ program designed to manage the operations of a hostel, including room allocation, student bookings, and room information management. The system allows both students and managers to interact with the hostel's data, making it efficient for day-to-day operations.

### Features
- *Student portal*: Students can view available rooms, book a room, and check their booked room details.
- *Manager portal*: Managers can perform various tasks, including adding new rooms, viewing room details, and removing rooms from the hostel.
- *Room Allocation*: The system ensures proper room allocation and keeps track of the current number of occupants in each room.
- *Data Persistence*: Hostel data, including room details and bookings, is stored in text files, allowing the system to maintain state between runs.This also implements the [`Singleton Pattern`](https://www.digitalocean.com/community/tutorials/java-singleton-design-pattern-best-practices-examples)


### Getting Started
1. *Clone the repository:*

   ```git bash

   git clone https://github.com/Flyview16/Hostel-Management-System.git

2. Open terminal in local repo directory and navigate to project directory

    ```bash
    cd "Hostel Management System"

3. *Compile the program:*
    
    ```bash
    g++ main.cpp FunctionDefinition.cpp ClassDefinitions.cpp -o bin/debug/hostel_management_system

4. *Run the executable program:*
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
3. Commit your changes: `git commit -m 'Add new feature'`
4. Push to the branch:  `git push origin feature-name`
5. Submit a pull request.

### Issues
This project uses `filesystem` which is available in C++17 versions and above so be sure to include the compiler flags which uses this version of C++. Feel free to open issues if you encounter any challenges.

<p align = "center">
<img width="48" height="48" src="https://img.icons8.com/fluency/144/c-plus-plus-logo.png" alt="c-plus-plus-logo"/>
</p>
