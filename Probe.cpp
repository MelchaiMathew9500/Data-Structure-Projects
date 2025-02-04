//
//  Probe.cpp
//  ESE224Project

#include <iostream>
#include <string>
#include <vector>
#include "Probe.h"

Probe::Probe() {            //Default constructor
    name = "";
    ID = 0;
    dimension[0] = 0;
    dimension[1] = 0;
    position[0] = 0;
    position[1] = 0;
}
Probe::Probe(string n, int i, int len, int wid, int x, int y) {         //Parameterized Constructor
    name = n;
    ID = i;
    dimension[0] = len;
    dimension[1] = wid;
    position[0] = x;
    position[1] = y;
}
string Probe::getName() {         //Getter function for the name attribute
    return name;                  //Return the name of the probe
}
int Probe::getID() {              //Getter function for the ID attribute
    return ID;                    //Return the ID of the probe
}
int Probe::getLength() {          //Getter function for the length dimension
    return dimension[0];          // Return the length (first dimension) of the probe.
}
int Probe::getWidth() {           //Getter function for the width dimension
    return dimension[1];          // Return the width (second dimension) of the probe.
}
double Probe::getArea() {         //Gett function for the area attribute
    return area;                  //Return the area of the probe
}
int Probe::getX() {               //Getter function for the x-coord of the position
    return position[0];           //Return the x-coord
}
int Probe::getY() {               //Getter function for the y-coord of the position
    return position[1];           //Return the y-coord
}
void Probe::setName(string n) {   //Setter function for the name attribute
    name = n;                     //set the name of the probe to the provided string
}
void Probe::setID(int i) {        //Setter function for the ID attribute
    ID = i;                       //set the ID of the probe to the provided integer
}
void Probe::setLength(int len) {  // Setter function for the length dimension.
    dimension[0] = len;           // Set the length (first dimension) of the probe to the provided length.
}
void Probe::setWidth(int wid) {  // Setter function for the width dimension.
    dimension[1] = wid;          // Set the width (second dimension) of the probe to the provided width.
}
void Probe::setX(int x) {        // Setter function for the x-coordinate of the position.
    position[0] = x;             // Set the x-coordinate of the probe's position to the provided x value.
}
void Probe::setY(int y) {        // Setter function for the y-coordinate of the position.
    position[1] = y;             // Set the y-coordinate of the probe's position to the provided y value.
}
void Probe::calculateArea() {    // Function to calculate the area of the probe based on its dimensions.
    area = 2 * (dimension[0] + dimension[1]);
}
void Probe::displayProbe() {
    cout << "Name: " << name << endl;
    cout << "ID: " << ID << endl;
    cout << "Dimension: [" << dimension[0] << "," << dimension[1] << "]" << endl;
    cout << "Area: " << area << endl;
    cout << "Position: [" << position[0] << "," << position[1] << "]" << endl;
    cout << endl;
}
void Probe::operator<<(Probe& p2) {
    dimension[0] = p2.dimension[0];     //copy the first dimension from p2 to current obeject
    dimension[1] = p2.dimension[1];     //copy the second dimension from p2 to current
    area = p2.area;         //copy the area from p2 to current object
    position[0] = p2.position[0];          //copy the x from p2 to current object
    position[1] = p2.position[1];          //copy the y from p2 to current object
    calculateArea();
    p2.calculateArea();
}
void Probe::operator-(Probe& p2) {
    int t;          //temp variable for swapping dimension

    //uses same swapping algorithm for each one
    t = dimension[0];
    dimension[0] = p2.dimension[0];     
    p2.dimension[0] = t;
    t = dimension[1];
    dimension[1] = p2.dimension[1];
    p2.dimension[1] = t;

    t = position[0];
    position[0] = p2.position[0];
    p2.position[0] = t;
    t = position[1];
    position[1] = p2.position[1];
    p2.position[1] = t;

    calculateArea();
    p2.calculateArea();
}
