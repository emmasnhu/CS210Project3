
#include "GroceryTracker.h"
using namespace std;


		//Function to load the file and make sure it opened properly 
		void  GroceryTracker::LoadItems() {

			//Open file
			FoodNames.open("CS210_Project_Three_Input_File.txt");

			//Check if file opened
			if (!FoodNames.is_open()) {
				cout << "File failed to open." << endl;
				return;
			}
			else {
				cout << "File opened." << endl;
			
			}

			//Read file 
			string food;
			while (FoodNames >> food) {
				itemFrequencies[food]++;
			}
			//Close file
			FoodNames.close();
		}

		//Backup file
		void  GroceryTracker::CreateBackupFile() {
			//Open file
			BackupFile.open("frequency.dat");
				//Make sure file opened
				if (!BackupFile.is_open()) {
					cout << "File failed to open." << endl;
					return;
				}
			//Print grocery item and frequency to file
			for (const auto& pair : itemFrequencies) {
				BackupFile << pair.first << " " << pair.second << endl;
			}
				//Close file
				BackupFile.close();
		}

		//Get item frequency
		int  GroceryTracker::GetItemFrequency(string foodName) {
			if (itemFrequencies.find(foodName) != itemFrequencies.end()) {
				return itemFrequencies[foodName];
			}
			else {
				return 0;
			}
		}


		//Print frequency
		void  GroceryTracker::PrintFrequencies() {
			for (const auto& pair : itemFrequencies) {
				cout << pair.first << " " << pair.second << endl;
			}
		}

		//Make histogram
		void  GroceryTracker::PrintHistogram() {
			for (const auto& pair : itemFrequencies) {
				cout << pair.first << " ";
				for (int i = 0; i < pair.second; i++) {
					cout << "*";
				}
				cout << endl;
			}
		}
