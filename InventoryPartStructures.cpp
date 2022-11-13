// Source(s) of logic assistance:  
// Gaddis, T. (2018). Starting out with C++:
// From control structures through objects. Pearson. 

#include <iostream> // To use cin/cout
#include <iomanip>  // To access setw for output width
#include <string>   // To implement to_string, getline functions
#include <fstream>  // To utilize ifstream, ofstream, fstream
using namespace std;

// Global Constant Initialization
const string TITLE = "Inventory Parts Structures Program";
const string AUTHOR_LINE = "By Forrest Moulin";

// Declare data structure for inventory parts,
// which contains part variables (fields)
struct Inventory
{	// "P-12345" "LED1"
	string number, name;
	char classification; // 'E'
	int quantity;// 100
	double unitCost;// 25.50
};

// Function prototypes to notify compiler
char partPrompt();
void readEntry(Inventory& part);
void writeEntry(Inventory part, ofstream& fout);

// Create output file stream object
// cout for console output
// fout for output file
ofstream fout;

int main()
{
	// Initialize inventory part structure
	Inventory part;
	// Set another part to 'Y' (keep looping by default)
	char anotherPart = 'Y';
	// Windows file path used to write the txt file
	string outputFilePath =
		"C:\\Users\\UserName\\Path\\To\\Output.txt";
	fout.open(outputFilePath);
	// Handle output file stream failures
	if (fout.fail())
	{
		cout << "File output failure:" << endl
			<< outputFilePath << endl;
		fout.close();
		return 0;
	}
  
	// Visibility of program status
	cout << fixed << setprecision(2) << TITLE << endl
		<< AUTHOR_LINE << endl << endl
		<< "Please enter the part number, name, class,"
		<< endl << "inventory quantity, and unit cost"
		<< endl << "(separated by spaces)." << endl << endl;

	fout << fixed << setprecision(2)<< TITLE 
		<< endl << AUTHOR_LINE << endl << endl;

	// While another part is 'Yes' (keep looping)
	while (anotherPart == 'Y')
	{
		readEntry(part);
		writeEntry(part, fout);
		// 'Y'/'N' to continue/exit
		anotherPart = partPrompt();
		// Exit the program and close output file
		if (anotherPart == 'N')
		{
			cout << "Created data structure file. Program closed."
				<< endl << "Until next time! :)" << endl;
			fout.close();
			return 0;
		}
	}
}
// Prompts user to enter Y for yes, N for No
// returns only valid char entry (recursive)
char partPrompt()
{
	char anotherPart;
	cout << endl << "Would you like to enter another part?"
		<< endl << "(Y for yes, N for no)" 
		<< endl << endl;
	cin >> anotherPart;
	if (anotherPart == 'y' || anotherPart == 'Y')
	{
		cout << "Ok! Ready when you are..." 
			<< endl << endl;
		return 'Y';
	}
	else if (anotherPart == 'n' || anotherPart == 'N')
	{
		cout << "Got it!" << endl << endl;
		return 'N';
	}
	else
	{
		cin.ignore(1000, '\n');
		cout << "Invalid entry." << endl;
		// Recursive call to prompt valid entry
		partPrompt();
	}
}
// Uses reference param to update part variables
void readEntry(Inventory& part)
{
	cin >> part.number >> part.name >> part.classification
		>> part.quantity >> part.unitCost;
}
// Uses fout reference param to write out part structure
void writeEntry(Inventory part, ofstream& fout)
{
	cout << left << setw(16) << "Number:" << part.number << endl
		<< left << setw(16) << "Name:" << part.name << endl
		<< left << setw(16) << "Classification:"
		<< part.classification << endl
		<< left << setw(16) << "Quantity:"
		<< part.quantity << endl
		<< left << setw(16) << "Unit Cost:"
		<< "$" << right << setw(6) << part.unitCost
		<< endl;
	// Mirror cout
	fout << left << setw(16) << "Number:" << part.number << endl
		<< left << setw(16) << "Name:" << part.name << endl
		<< left << setw(16) << "Classification:"
		<< part.classification << endl
		<< left << setw(16) << "Quantity:"
		<< part.quantity << endl
		<< left << setw(16) << "Unit Cost:"
		<< "$" << right << setw(6) << part.unitCost
		<< endl << endl;
}
/*
* CONSOLE OUTPUT EXAMPLE
* Inventory Parts Structures Program
* By Forrest Moulin
*
* Please enter the part number, name, class,
* inventory quantity, and unit cost
* (separated by spaces).
*
* 1234 Hammer A 10 5.50
* Number:         1234
* Name:           Hammer
* Classification: A
* Quantity:       10
* Unit Cost:      $  5.50
*
* Would you like to enter another part?
* (Y for yes, N for no)
*
* k
* Invalid entry.
*
* Would you like to enter another part?
* (Y for yes, N for no)
*
* y
* Ok! Ready when you are...
*
* 2345 Drill C 20 18.50
* Number:         2345
* Name:           Drill
* Classification: C
* Quantity:       20
* Unit Cost:      $ 18.50
*
* Would you like to enter another part?
* (Y for yes, N for no)
*
* n
* Got it!
*
* Created data structure file. Program closed.
* Until next time! :)
*/

/*
* OUTPUT.TXT FILE EXAMPLE
* Inventory Parts Structures Program
* By Forrest Moulin
*
* Number:         1234
* Name:           Hammer
* Classification: A
* Quantity:       10
* Unit Cost:      $  5.50
*
* Number:         2345
* Name:           Drill
* Classification: C
* Quantity:       20
* Unit Cost:      $ 18.50
*/
