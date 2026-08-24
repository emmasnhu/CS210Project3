
#include <iostream>
#include "GroceryTracker.h"
#include <limits>

int main()
{
    //Import class
    GroceryTracker tracker; 
    tracker.LoadItems();
    tracker.CreateBackupFile();

    //Create main menu 
    int menuChoice = 0;

    while (menuChoice != 4) {
        cout << endl;
        cout << "~~~---~~~---~~~---~~~---~~~---~~~---~~~---~~~---~~~" << endl;
        cout << "                   Grocery Tracker" << endl;
        cout << "~~~---~~~---~~~---~~~---~~~---~~~---~~~---~~~---~~~" << endl;
        cout << "1. Lookup a grocery item." << endl;
        cout << "2. Print items purchased frequency." << endl;
        cout << "3. Turn items purchased frequency into a histogram." << endl;
        cout << "4. Quit program." << endl;
        cout << "~~~---~~~---~~~---~~~---~~~---~~~---~~~---~~~---~~~" << endl;

        cout << "Please enter your menu choice: " << endl;
        cin >> menuChoice;

        //Validate user input
        if (cin.fail()) {
            cout << endl << "Invalid input. Please enter a valid menu choice (1-4)." << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        //If chocie is 1
        if (menuChoice == 1) {
            string foodName;
            //Ask user for the item they want to look up
            cout << "What grocery item would you like to look up?" << endl;
            cin >> foodName;

            //Return a numeric value for the frequency of the specific word
            int frequency = tracker.GetItemFrequency(foodName);
            cout << endl << "\"" << foodName << "\"" << " was bought " << frequency << " times." << endl;

        }
        //If choice is 2 
        else if (menuChoice == 2) {
            tracker.PrintFrequencies();
        }
        
        //If choice is 3
        else if (menuChoice == 3) {
            tracker.PrintHistogram();
        }

        //If choice is 4
        else if (menuChoice == 4) {
            cout << "Quitting program." << endl;
        }
        else {
            cout << endl << "Invalid input. Please enter a valid menu choice (1-4)." << endl;
        }
        
    }
    return 0;
}


