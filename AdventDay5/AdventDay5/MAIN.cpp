#include "MAIN.h"
#include "FILE_FACTORY.h"

int main()
{

	string path;
	uint32_t count = 0;

	cout << "Enter path to input file" << endl << "--->  ";
	getline(cin, path);

	FILE_FACTORY myFactory(path);

	if( !myFactory.startFactory() ) {

		cout << "Could not open input file" << endl << "Press any key to continue...";
		while( !_kbhit() ) {
		}
		return 1;

	}

	while( myFactory.moreElements() ) {

		if( myFactory.getNextElement() ) {

			if( myFactory.checkElement() )
				count++;

		} else {

			cout << "Error reading input" << endl << "Press any key to continue...";
			while( !_kbhit() ) {
			}
			return 1;

		}


	}

	cout << "There were " << count << " nice strings" << endl;
	cout << "Press any key to continue...";
	while( !_kbhit() ) { }
	return 0;

}

