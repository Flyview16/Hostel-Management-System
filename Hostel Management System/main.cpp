#include <iostream>
#include "Classes.h"
#include "Functions.h"

using namespace std;

int main()
{
    int userlogin;

    cout << "\n\n\n\t\t\t*******************************************************************************\n" << endl;
    cout << "\t\t\t\t\t Welcome to Hostel Management System" << endl;
    cout << "\n\t\t\t*******************************************************************************\n" << endl;

    cout << "Login As: \n 1.Student\n 2.Manager\n"<< endl;
    cout << "Select option: ";
    cin >> userlogin;

    Systemclear();
    if(userlogin == 1)
    {
        Student newStudent;
        newStudent.StudentLogin();
        studentLogin();
    }else if(userlogin == 2)
    {
        managerLogin();
    }else
    {
        cout << "Please select 1 or 2" << endl;
    }

    return 0;
}
