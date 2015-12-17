#include "MAIN.h"
#include "FILE_FACTORY.h"

int main()
{

	string path = "C:\\Users\\Owen James\\Documents\\Visual Studio 2015\\Projects\\Text Input Regex Parser Template1\\input.txt";

	//cout << "Enter path to input file" << endl << "--->  ";
	//getline(cin, path);

	FILE_FACTORY myFactory(path);

	if( !myFactory.startFactory() ) {

		cout << "Could not open input file" << endl << "Press any key to continue...";
		while( !_kbhit() ) {
		}
		return 1;

	}

	while( myFactory.moreElements() ) {

		if( myFactory.getNextElement() ) {

			myFactory.checkElement();

		} else {

			cout << "Error reading input" << endl << "Press any key to continue...";
			while( !_kbhit() ) {
			}
			return 1;

		}

	}

	cout << "The total brightness is " << myFactory.getLit() << " lumens" << endl;
	cout << "Press any key to continue...";
	while( !_kbhit() ) { }
	return 0;

}

