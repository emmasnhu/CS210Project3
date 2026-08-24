//Emma Stein
//CS210 Project 3
//8-15-26

#pragma once
#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class GroceryTracker {
public:
    void LoadItems();
    void CreateBackupFile();
    int GetItemFrequency(string foodName);
    void PrintFrequencies();
    void PrintHistogram();

private:
    map<string, int> itemFrequencies;
    ifstream FoodNames;
    ofstream BackupFile;
};

#endif