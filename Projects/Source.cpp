#include <Python.h> // Python header file
#include <iostream> // input/output stream
#include <Windows.h> // windows header file
#include <cmath> // declares a set of functions to compute common mathematical operations
#include <string> //allows for string input
#include <fstream> //file stream
#include <iomanip> //set precision

using namespace std;

/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

int main(){

	ifstream itemFile; //input file stream 
	string item;
	int count; 
	int i = 0;

	// Changes the color of the text being displayed to green
	system("Color 02"); 

	int menuSelection;
	do { //do while loop for the menu selection
		cout << "        Make a selection         " << endl;
		cout << "*********************************" << endl;
		cout << "* 1.  List all items purchased  *" << endl;
		cout << "* 2.  Search for single item    *" << endl;
		cout << "* 3.  Histogram of items        *" << endl;
		cout << "* 4.  Exit Program              *" << endl;
		cout << "*********************************" << endl;
		cout << endl;

		do { //do while loop for the user input validation

			cin >> menuSelection;
			if (cin.fail()) {
				cin.clear(); //clears cin buffer
				cin.ignore(80, '\n');
			}
		} while (cin.fail()); //loops wull cin.fail is trur

		switch (menuSelection) {
		case 1:
			//calls the Python definition to produce a dictionary and print to the terminal
			CallProcedure("itemsSoldList"); 
			cout << endl;
			break; //prevents fall through of switch case
		case 2:
			cout << "Seach For Item Quantity" << endl;

				cin >> item; //stores user input into variable
				item[0] = toupper(item[0]); //sets the first character of user input to be capitalized

				// Passes the name of the Python function and the user input as the string parameter then prints to terminal
				cout << item << "                " << callIntFunc("itemsSearch", item) << endl;
			cout << endl;
			break;
		case 3:
			cout << "Histogram Of Items" << endl;
			CallProcedure("itemsHistograms");

			// Opens .dat file
			itemFile.open("frequency.dat");

			// Code to check if .dat file is open properly
			if (!itemFile.is_open()) {
				cout << "Could not open file frequency.dat" << endl;
				return 1;
			}
			else {
				cout << ("      Item Histogram") << endl;
				cout << ("============================= ") << endl;
				cout << ("Item               Number Sold") << endl;
				cout << ("-----------------------------") << endl;
				
				/* while the stream extraction operator is still able to get a string from the .dat 
				 * the loop will continue through the end of the file.  
				 * I originally tried eof but learned that it only returns true after reading the end of the stream 
				 * and does not indicate, that the next read will be the end of the stream.
				 * I used a for loop and the extraction operator to print '*' for each item count
				*/ 
				while (itemFile >> item) {
					cout <<left<< setw(11) << item << right << setw(10);
					itemFile >> count;
						for (i = 0; i < count; ++i) {
							cout << '*';
						}
					cout << endl;
				}
			}
			cout << endl;
			itemFile.close(); //closes file
			break;
		case 4:
			//Exits program after user enters 4
			cout << "Exit Program" << endl;
			break;

			// default used as partial user input error handling
		default:
			cout << "Not a valid menu choice" << endl;
			cout << endl;
			break;
		}
	} while (menuSelection != 4);
	return 0;
}
