#include <iostream>
#include <fstream>
#include "queue.h"
#include "utils.h"

using namespace std;

pr_queue persoane;

void loadDatabase() {
    ifstream in("input.txt");

    while (!in.eof())
    {
        string n;
        int a;
        int s;
        string c;
        in >> n;
        if (n.empty()) {
            break;
        }
        in >> a;
        in >> s;
        in >> c;
        persoane.enqueue(n, a, s, c);
    }
    cout << "Input data was read from file!" << endl;
}

void addPerson()
{
    string n;
    int a;
    int s;
    string c;
    cout << "Give name: ";
    cin >> n;

    cout << "Age: ";
    cin >> a;

    cout << "Give sanitary condition: ";
    cin >> s;

    cout << "Give your city`s name: ";
    cin >> c;
    persoane.enqueue(n, a, s, c);
}

int main()
{

    int cmd;
    cmd = 9;
    while (cmd != 0) {
        printMenu();
        cmd = getCommand();
        switch (cmd) {
        case 1: {

            //initializeDataset();
            loadDatabase();
            break;
        }
        case 2: {
            addPerson();
            break;
        }
        case 3: {
            persoane.dequeue();
            break;
        }
        case 4:
            for (int i = getDoses(); i > 0; i--)
                persoane.dequeue();
            break;
        case 5:
            persoane.display();
            break;
        default:
            break;
        }
    }

    return 0;
}
