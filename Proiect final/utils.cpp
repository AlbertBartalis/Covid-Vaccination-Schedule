#include <string>
#include <string.h>
#include <iostream>

using namespace std;

int calculatePriority(int age, int sanitaryConditions) {
    if (sanitaryConditions < 1)
        sanitaryConditions = 1;
    if (sanitaryConditions > 10)
        sanitaryConditions = 10;
    int priority = (int)(age / sanitaryConditions);
    return priority;
}

string formatDisplay(int id, string name, int age, int cond, string city, int priority) {
    return "Order Number:" + to_string(id) + ", Name: " + name + ", Sanitary Conditions:" + to_string(cond)
        + ", City:" + city + ", PRIORITY:" + to_string(priority) + "\n";
}


void printMenu() {
    cout << "******************************" << endl;
    cout << "* 0. Exit                    *" << endl;
    cout << "* 1. Initialize Dataset      *" << endl;
    cout << "* 2. Add Person              *" << endl;
    cout << "* 3. Single Vaccination      *" << endl;
    cout << "* 4. Multiple Vaccination    *" << endl;
    cout << "* 5. Display List            *" << endl;
    cout << "******************************" << endl;
}

int getCommand() {
    int command;
    cout << "Enter your choice:";
    cin >> command;
    return command;
}

int getDoses() {
    int doses;
    cout << "How many vaccine dozes are available? ";
    cin >> doses;
    return doses;
}



