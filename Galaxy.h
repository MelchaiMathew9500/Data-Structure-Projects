//
//  Galaxy.h
//  ESE224Project

#ifndef GALAXY_H
#define GALAXY_H
#include <vector>
#include <string>
#include "Probe.h"

class Galaxy {
private:
    vector <Probe> myProbes;                        //list of probes
public:
    void loadProbeData(const char* file);           //loads probe data from input file
    void sortByName();                              //sorts list of probes by name
    void sortByID();                                //sorts list of probes by ID
    void sortByArea();                              //sorts list of probes by area 
    void searchProbeByName(const string& name);     //searches for a probe by name
    void searchProbeByID(int ID);                   //searches for a probe by ID
    void swapProbeData(int idx1, int idx2);         //swaps probe datas
    void insertProbeData(int galaxyIdx, int probeIdx1, int probeIdx2, int value);   //inserts data into a probe
    void copyProbe(int idx1, int idx2);             //copies probe data onto another probe
    void displayProbe(int idx1);                    //displays a probe details
    void randomizeOrder();                          //randomizes list order of the probes
    void printAllNames();                           //prints all the names in the current order
    void writeGalaxyToFile();                       //writes all probe data into an output file
    void collision();                               //checkes if any probes collide
};

#endif // !GALAXY_H
