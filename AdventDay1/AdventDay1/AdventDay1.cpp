// AdventDay1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{

	int floor = 0;
	uint32_t traversals = 0;
	char current;
	string path;
	bool firstEntry = false;

	cout << "Enter Input Path" << endl << "-->  ";
	getline(cin, path);

	ifstream myFile(path, ifstream::in);

	try {

		myFile.exceptions(myFile.failbit);

	} catch( const ios_base::failure& e ) {

		cout << "Error " << e.code() << endl << e.what() << endl << "Press any key to continue...";

		while( !_kbhit() ) { }
		return 1;

	}

	while( myFile.good() ) {

		try {

			current = myFile.get();

		} catch( const ios_base::failure& e ) {

			break;

		}

		traversals++;

		switch( current ) {

			case ')':
				floor--;
				break;

			case '(':
				floor++;
				break;

			default:
				break;
		}

		if( (floor == -1) && (firstEntry == false) ) {

			firstEntry = true;
			cout << "The first basement entry is at " << traversals << endl;

		}

	}

	cout << "There were " << traversals << " floor traversals made by santa" << endl;
	cout << "The floor is " << floor << endl << endl << "Press any key to continue...";
	
	while( !_kbhit() ) { }
    return 0;

}

