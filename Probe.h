//
//  Probe.h
//  ESE224Project

#ifndef PROBE_H
#define PROBE_H
#include <string>
#include <vector>

using namespace std;

class Probe {
private:
    string name;                //name of probe
    int ID;                     //ID number of probe
    int dimension[2];           //index 0 length of probe, index 1 width of probe
    double area;                //area of the probe
    int position[2];            //index 0 X coordinate of the probe, index 1 of Y coordinate
public:
    Probe();                    //default constructor
    Probe(string n, int i, int len, int wid, int x, int y);         //parametrized constructor

    //accsessor methods
    string getName();
    int getID();
    int getLength();
    int getWidth();
    double getArea();
    int getX();
    int getY();

    //mutator methods
    void setName(string n);
    void setID(int i);
    void setLength(int len);
    void setWidth(int wid);
    void setX(int x);
    void setY(int y);

    void calculateArea();          //calulates the area
    void displayProbe();           //displays probe details 

    void operator<<(Probe& p2);    //copies probe data
    void operator-(Probe& p2);      //swaps probe data
};

#endif // !PROBE_H
