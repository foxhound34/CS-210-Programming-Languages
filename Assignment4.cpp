/*	Assignment 4: Working with Files
	CS210 Professor Eric Gregori
	Code written by Derek Bamford 
*/


#include <iostream> // standard input/output stream
#include <fstream> // Allows for file to be read
#include <string> // Allows for string
#include <iomanip> // Set precision
#include <vector> // Allows a vector list
using namespace std;

int main() {

	//initialization of variables
	ifstream inFS;
	string cityName;
	int cityTemp;

	//Vector Declarations
	vector<string>nameList;
	vector<int>tempList;

	inFS.open("FahrenheitTemperature.txt"); // Opens text file
	if (!inFS.is_open()) { // Checks for failure to open file
		cout << "Could not open the file" << endl;
		return 1; // return of 1 indicates error
	}
	else {
		inFS >> cityName >> cityTemp; //Gets initial input (str)Name  and (int)Temp
		while (!inFS.fail()) { 
			nameList.push_back(cityName); // Pushes input to string vector
			tempList.push_back(cityTemp); // Pushes input to int vector
			inFS >> cityName >> cityTemp; // Gets next input for (str)Name  and (int)Temp
		}
	}
	inFS.close(); // Closes read file

	ofstream outFS;  // Declares an object

	outFS.open("CelsiusTemperature.txt"); //Opens Text file

	if (!outFS.is_open()) { // Checks for failure to open file
		cout << "Could not open file myoutfile.txt." << endl;
		return 1; // return of 1 indicates error
	}

	outFS << setprecision(3); //set output precision to 3

	for (int i = 0; i < nameList.size(); i++) { //loops through vector; both are the same size so only one is needed
		outFS << nameList.at(i) << " " << (tempList.at(i) - 32.0) * (5.0 / 9.0) << endl; //prints vector and converts Fahrenheit to Celsius
	}

	outFS.close(); //closes file that has been written to

	return 0;
}