//
//  main.cpp
//  ESE224Project

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Probe.h"
#include "Galaxy.h"

using namespace std;

int main() {
    Galaxy myGalaxy;
    srand(time(0));         //seed the random number generator

    vector <string> username;
    vector <string> password;
    ifstream users;         //create an input file stream for reading user creds
    users.open("users.txt");
    if (users.fail()) {     //check if file stream opened successfully
        cerr << "Error: Unable to open file users.txt." << endl;
        exit(1);
    }
    int usercount = 0;
    string u;               //holds username
    string p;               //holds password
    char hash;
    string header;
   while(!users.eof()){
        users >> hash;
        getline(users, header);     //so that the title line of each credential doesn't get stores into any credential data
        getline(users, u);          //gets username
        getline(users, p);          //gets password
        username.push_back(u);      //add username to the vector
        password.push_back(p);      //add password to the vector
        usercount++;
    }
   users.close();
   cout << "Enter credentials: " << endl;
    int link;           //variable to hold the index of the authenticated user
    while (1) {
        link = -1;
        while (link == -1) {
            cout << "Username: ";
            cin >> u;
            for (int i = 0; i < usercount; i++) {           //check if the username exists in the vector
                if (u.compare(username[i]) == 0)            //compare input username with stored username
                    link = i;
            }
            if (link == -1)         //prompt user to try again if username is incorrect
                cout << "Invalid username. Please try again." << endl;
        }
        cout << "Password: ";
        cin >> p;
        if (p.compare(password[link]) == 0) {           //comapre input password with stored password
            cout << "Login Successful!" << endl;
            break;
        }
        else {
            cout << "Incorrect password. Renter credentials:" << endl;
        }
    }

    cout << "\nLoading Probe Data..." << endl;
    myGalaxy.loadProbeData("Probe.txt");

    cout << "Options for Galaxy Data: " << endl;
    cout << "1. Sort By Name" << endl
        << "2. Sort By ID" << endl
        << "3. Sort By Area" << endl
        << "4. Search By Name" << endl
        << "5. Search By ID" << endl
        << "6. Swap Probes' Data" << endl
        << "7. Insert Data to Probe" << endl
        << "8. Copy Probe's Data" << endl
        << "9. Display Probe Data" << endl
        << "10. Randomize Probe Order" << endl
        << "11. Print All Names" << endl
        << "12. Write To File And Quit" << endl
        << "13. See Possible Collisions" << endl;
    int choice = 0;
    int i, idx1, idx2, dop;
    while (choice != 12) {
        cout << "Enter your choice (1-13): ";
        cin >> choice;
        switch (choice) {
        case 1:
            myGalaxy.sortByName();
            break;
        case 2:
            myGalaxy.sortByID();
            break;
        case 3:
            myGalaxy.sortByArea();
            break;
        case 4:
            cout << "Enter the name of the probe to search: ";
            getchar();
            getline(cin, p);
            myGalaxy.searchProbeByName(p);
            break;
        case 5:
            cout << "Enter the ID of the probe to search: ";
            cin >> i;
            myGalaxy.searchProbeByID(i);
            break;
        case 6:
            cout << "Enter the index of the first probe: ";
            cin >> idx1;
            cout << "Enter the index of the second probe: ";
            cin >> idx2;
            myGalaxy.swapProbeData(idx1, idx2);
            break;
        case 7:
            cout << "Enter the index of the probe to modify: ";
            cin >> idx1;
            cout << "Enter 0 to modify dimension, 1 to modify position: ";
            cin >> dop;
            if (dop == 1)
                cout << "Enter the index to modify (0 for X, 1 for Y): ";
            else
                cout << "Enter the index to modify (0 for Length, 1 for Width): ";
            cin >> idx2;
            cout << "Enter new value: ";
            cin >> i;
            myGalaxy.insertProbeData(idx1, dop, idx2, i);
            break;
        case 8:
            cout << "Enter index of source probe: ";
            cin >> idx1;
            cout << "Enter index of destination probe: ";
            cin >> idx2;
            myGalaxy.copyProbe(idx1, idx2);
            break;
        case 9:
            cout << "Enter index of the probe to display: ";
            cin >> idx1;
            cout << "\nProbe Details: " << endl;
            myGalaxy.displayProbe(idx1);
            break;
        case 10:
            myGalaxy.randomizeOrder();
            break;
        case 11:
            myGalaxy.printAllNames();
            break;
        case 12:
            myGalaxy.writeGalaxyToFile();
            break;
        case 13:
            myGalaxy.collision();
            break;
        default:
            if (cin.fail()) {// If a non-integer input is detected
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n');// Ignore all characters until a new line is detected
            }
            cout << "Invalid input." << endl;
            break;
        }
    }

    system("pause");
    return 0;
}
