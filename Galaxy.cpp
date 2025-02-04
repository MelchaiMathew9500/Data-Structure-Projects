//
//  Galaxy.cpp
//  ESE224Project

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "Probe.h"
#include "Galaxy.h"

void Galaxy::loadProbeData(const char* file) {
    ifstream probes;            //create an input file stream to read
    probes.open(file);          //opens file
    if (probes.fail()) {        //checks if the file was opened succesfully
        cerr << "Error: Unable to open file " << file << "." << endl;
        exit(1);
    }
    string n;
    int id, len, wid, x, y;
    int i = 0;
    char hash;
    string header;
    while (!probes.eof()) {
        probes >> hash;             //indicates where the next probe starts
        getline(probes, header);     //so that the title line of each probe doesn't get stores into any probe data
        getline(probes, n);            //grabs the name
        probes >> id >> len >> wid >> x >> y;
        myProbes.push_back(Probe(n, id, len, wid, x, y));   //stores probe
        myProbes[i].calculateArea();
        i++;
    }
    cout << "\nLoaded Data Successfully!\n" << endl;
    probes.close();         //closes the input file stream
}
void Galaxy::sortByName() {
    Probe temp;         //declare a temp Probe for swapping
    for (int i = 0; i < myProbes.size(); i++) {         //Outer Loop: Iterates through all probes
        for (int j = 0; j < myProbes.size() - i - 1; j++) {         //Inner Loop: compare each probe with the one next to it and swap if they are in the wrong order
            if (myProbes[j].getName() > myProbes[j + 1].getName()) {            //If probe at position j is alphabetically greater than j + 1, we swap
                temp = myProbes[j];            //Swapping the Probes using temp
                myProbes[j] = myProbes[j + 1];
                myProbes[j + 1] = temp;
            }
        }
    }
    cout << "Probes sorted by name.\n\nCurrent order of probes: " << endl;
    for (int i = 0; i < myProbes.size(); i++) {         //Loops through the sorted probes and print
        cout << (i + 1) << ". " << myProbes[i].getName() << endl;
    }
    cout << endl;
}
void Galaxy::sortByID() {
    Probe temp;         //decalre a temp Probe for swapping
    for (int i = 0; i < myProbes.size(); i++) {         //Outer Loop: Iterates through all probes
        for (int j = 0; j < myProbes.size() - i - 1; j++) {         //Inner Loop: compare each probe with the one next to it and swap if they are in the wrong order
            if (myProbes[j].getID() > myProbes[j + 1].getID()) {            //If probe at position j is greater than j + 1, we swap
                temp = myProbes[j];            //Swapping the Probes using temp
                myProbes[j] = myProbes[j + 1];
                myProbes[j + 1] = temp;
            }
        }
    }
    cout << "Probes sorted by ID.\n\nCurrent order of probes: " << endl;

    for (int i = 0; i < myProbes.size(); i++) {         //Loops through the sorted probes and print
        cout << (i + 1) << ". " << myProbes[i].getName() << "(ID: " << myProbes[i].getID() << ")" << endl;
    }
    cout << endl;
}
void Galaxy::sortByArea() {
    Probe temp;         //decalre a temp Probe for swapping
    for (int i = 0; i < myProbes.size(); i++) {         //Outer Loop: Iterates through all probes
        for (int j = 0; j < myProbes.size() - i - 1; j++) {         //Inner Loop: compare each probe with the one next to it and swap if they are in the wrong order
            if (myProbes[j].getArea() > myProbes[j + 1].getArea()) {            //If probe at position j is greater than j + 1, we swap
                temp = myProbes[j];             //Swapping the Probes using temp
                myProbes[j] = myProbes[j + 1];
                myProbes[j + 1] = temp;
            }
        }
    }
    cout << "Probes sorted by Area.\n\nCurrent order of probes: " << endl;

    for (int i = 0; i < myProbes.size(); i++) {           //Loops through the sorted probes and print
        cout << (i + 1) << ". " << myProbes[i].getName() << "(Area: " << myProbes[i].getArea() << ")" << endl;
    }
    cout << endl;
}
void Galaxy::searchProbeByName(const string& name) {
    //Sort the probes by name using bubble sort(same as the sortByName function)
    Probe temp;
    for (int i = 0; i < myProbes.size(); i++) {
        for (int j = 0; j < myProbes.size() - i - 1; j++) {
            if (myProbes[j].getName() > myProbes[j + 1].getName()) {
                temp = myProbes[j];
                myProbes[j] = myProbes[j + 1];
                myProbes[j + 1] = temp;
            }
        }
    }
    int top = 0, bottom = myProbes.size() - 1, mid;         //Binary search for the probe with the given name
    while (top <= bottom) {         //Perform binary search within the range
        mid = top + (bottom - top) / 2;           //Calculate the middle
        if (myProbes[mid].getName() == name) {      //Check if the middle probe's name matches the search item
            cout << "\nProbe found:" << endl;
            myProbes[mid].displayProbe();          //Call the display function to display probe info
            break;
        }
        else if (name > myProbes[mid].getName()) {        //If the name is larger than the mid-point probes name, search the upper half     
            top = mid + 1;                      //Narrow the search to the upper half
        }
        else {      //If the name is smaller than the mid-point probes name, search the lower half
            bottom = mid - 1;                       //Narrow the search to the lower half   
        }
    }
    if (name != myProbes[mid].getName()) {         //If probe not found, output failure message
        cout << "Could not find probe!\n" << endl;
    }
}
void Galaxy::searchProbeByID(int ID) {
    //Sort the probes by ID using bubble sort(same as the sortByID function)
    Probe temp;
    for (int i = 0; i < myProbes.size(); i++) {
        for (int j = 0; j < myProbes.size() - i - 1; j++) {
            if (myProbes[j].getID() > myProbes[j + 1].getID()) {
                temp = myProbes[j];
                myProbes[j] = myProbes[j + 1];
                myProbes[j + 1] = temp;
            }
        }
    }
    int top = 0, bottom = myProbes.size() - 1, mid;         //Binary search for the probe with the given ID
    while (top <= bottom) {         //Perform binary search within the range
        mid = top + (bottom - top) / 2;           // //Calculate the middle
        if (myProbes[mid].getID() == ID) {           //Check if the middle probe's ID matches the search item
            cout << "\nProbe found:" << endl;
            myProbes[mid].displayProbe();           //Call the display function to display probe info
            break;
        }
        else if (ID < myProbes[mid].getID()) {          //If the ID is smaller than the mid-point probes ID, search the lower half
            bottom = mid - 1;            //Narrow the search to the lower half
        }
        else {          //If the ID is larger than the mid-point probes ID, search the upper half
            top = mid + 1;           //Narrow the search to the upper half
        }
    }
    if (myProbes[mid].getID() != ID) {         //If probe not found, output failure message
        cout << "Could not find probe!\n" << endl;
    }
}
void Galaxy::swapProbeData(int idx1, int idx2) {
    myProbes[idx1] - myProbes[idx2];            //swaps the probes at index1 and index2 using the overloaded operator '-'
    cout << "\nProbe data swapped successfully" << endl;
    cout << "Probe at index " << idx1 << endl;
    myProbes[idx1].displayProbe();          //displays the probe at idx1 after the swap
    cout << "\nProbe at index " << idx2 << endl;
    myProbes[idx2].displayProbe();           //displays the probe at idx2 after the swap
}
void Galaxy::insertProbeData(int galaxyIdx, int probeIdx1, int probeIdx2, int value) {
    if (probeIdx1 == 0 && probeIdx2 == 0) {         //if probeIdx1 & probeIdx2 is 0, set the length of the probe at galaxyIdx
        myProbes[galaxyIdx].setLength(value);
    }
    else if (probeIdx1 == 0 && probeIdx2 == 1) {            // If probeIdx1 is 0 & probeIdx2 is 1, set the width of the probe at galaxyIdx
        myProbes[galaxyIdx].setWidth(value);
    }
    else if (probeIdx1 == 1 && probeIdx2 == 0) {            // If probeIdx1 is 1 & probeIdx2 is 0, set the X-coordinate of the probe at galaxyIdx
        myProbes[galaxyIdx].setX(value);
    }
    else if (probeIdx1 == 1 && probeIdx2 == 1) {            // If probeIdx1 is 1 & probeIdx2 is 1, set the Y-coordinate of the probe at galaxyIdx
        myProbes[galaxyIdx].setY(value);
    }
    cout << "\nData inserted successfully." << endl;
    cout << "\nUpdated Probe: " << endl;
    myProbes[galaxyIdx].displayProbe();         //Display the details of the updated probe
}
void Galaxy::copyProbe(int idx1, int idx2) {
    myProbes[idx2] << myProbes[idx1];           //copies idx1 to idx2 using the overloaded operator '<<'
    cout << "\nProbes copied sucessfuly: \n" << endl;
    cout << "Destination Probe (index " << idx2 << "):" << endl;
    myProbes[idx2].displayProbe();          //Display the details of the updated probe
}
void Galaxy::displayProbe(int idx1) {
    myProbes[idx1].displayProbe();           // Call the displayProbe function of the specific probe at index idx1 to show its details
}
void Galaxy::randomizeOrder() {
    vector <int> randpos;           //reates vector to store unique random positionsS
    randpos.push_back(rand() % myProbes.size());        //add the first random position to the ranpos vector
    int flag;           //flag to check if a position is already in randpos
    int pos;            //
    while (randpos.size() != myProbes.size()) {         //continuously generating random positions until we have enough
        flag = 0;           //reset flag
        pos = rand() % myProbes.size();         //generate a random position
        for (int i = 0; i < randpos.size(); i++) {          //check if the generated position is already in randpos
            if (pos == randpos[i])
                flag = 1;       //Position is a duplicate, set flag
        }
        if (flag == 0)      //if the position is unique add to the randpos vector
            randpos.push_back(pos);
    }
    vector <Probe> temp = myProbes;         //create a temp vector to hold the original order
    for (int i = 0; i < myProbes.size(); i++) {
        myProbes[i] = temp[randpos[i]];            //use the overloaded operator '<<' to assign the probe
    }
    cout << "Probe order randomized. " << endl;
    cout << "\nCurrent order of probes: " << endl;
    for (int i = 0; i < myProbes.size(); i++) {            //display the current order of probes after randomization
        cout << (i + 1) << ". " << myProbes[i].getName() << endl;       //print names
    }
    cout << endl;
}
void Galaxy::printAllNames() {
    cout << "\nAll Probe Names: " << endl;
    for (int i = 0; i < myProbes.size(); i++) {         //loop through each probe
        cout << (i + 1) << ". " << myProbes[i].getName() << endl;           //print the index and names of the current probe
    }
    cout << endl;
}
void Galaxy::writeGalaxyToFile() {
    ofstream galaxies;          //creates an ouput file stream to write to
    galaxies.open("Galaxy.txt");
    if (galaxies.fail()) {          //check if the file opened succesfully
        cerr << "Error: Unable to open file Galaxy.txt" << endl;
        exit(1);
    }
    
    for (int i = 0; i < myProbes.size(); i++) {         //loop through each probe
        galaxies << "# Probe " << (i + 1) << ":" << endl;
        galaxies << myProbes[i].getName() << "\n"
            << myProbes[i].getID() << "\n"
            << myProbes[i].getLength() << "\n"
            << myProbes[i].getWidth() << "\n"
            << myProbes[i].getX() << "\n"
            << myProbes[i].getY() << endl;
        galaxies << endl;
        galaxies << endl;
    }
    galaxies.close();           //close file stream
    cout << "Thank you for using the Galactic Explorer System. Goodbye!" << endl;
}

void Galaxy::collision() {
    double iTop, iBottom, jTop, jBottom;
    int prev = 0;
    int empty = 1;
    vector <vector <Probe>> result;
    result.resize(myProbes.size());

    for (int i = 0; i < myProbes.size(); i++){
        iTop = (double)myProbes[i].getY() + ((double)myProbes[i].getWidth() / 2.0); //calculate the y position of the top of the probe
        iBottom = (double)myProbes[i].getY() - ((double)myProbes[i].getWidth() / 2.0); //calculate the y position of the bottom of the probe
        for (int j = 0; j < myProbes.size(); j++){
            if (i != j){
                jTop = (double)myProbes[j].getY() + ((double)myProbes[j].getWidth() / 2.0); //calculate the y position of the top of another probe for comparison
                jBottom = (double)myProbes[j].getY() - ((double)myProbes[j].getWidth() / 2.0); //calculate the y position of the bottom of another probe for comparison
                if ((jTop <= iTop && jTop >= iBottom) || (jBottom >= iBottom && jBottom <= iTop) || (jBottom <= iBottom && jTop >= iTop) || (jBottom >= iBottom && jTop <= iTop)){
                    //check if the top/bottom of the second probe are in between or greater than the top/bottom of the first probe
                    result[i].push_back(myProbes[j]);
                    empty = 0; //if a value is inserted into result, indicate that it is not empty
                }
            }
        }
    }
    if (empty == 0){ //print out all collisions if result is not empty
        for (int i = 0; i < result.size(); i++){
            if (result[i].size() >= 1){
                cout << "Probes that could collide with " << myProbes[i].getName() << ":" << endl << endl;
                for (int j = 0; j < result[i].size(); j++){
                    result[i][j].displayProbe();
                    cout << endl;
                }
                cout << endl;
            }
        }
    }
    else{
        cout << endl << "No probes collide with each other." << endl << endl;
    }
}


