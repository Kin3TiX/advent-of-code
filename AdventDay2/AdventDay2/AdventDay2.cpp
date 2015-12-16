#include "Main.h"
#include "PRESENT.h"
#include "PRESENT_FACTORY.h"

int main()
{

	string path;
	uint32_t totalPaper = 0;
	uint64_t totalRibbon = 0;
	PRESENT currentPresent;

	cout << "Enter path to input file" << endl << "--->  ";
	getline(cin, path);

	PRESENT_FACTORY myFactory(path);

	if( !myFactory.startFactory() ) {

		cout << "Could not open input file" << endl << "Press any key to continue...";
		while( !_kbhit() ) { }
		return 1;

	}

	while( myFactory.morePresents() ) {

		if( myFactory.getNextPresent(currentPresent) ) {

			totalPaper += currentPresent.getPaperSize();
			totalRibbon += currentPresent.getRibbonLength();

		} else {

			cout << "Error reading input" << endl << "Press any key to continue...";
			while( !_kbhit() ) { }
			return 1;

		}
			

	}

	cout << "The elves need " << totalPaper << " total square feet of paper" << endl;
	cout << "The elves need " << totalRibbon << " total feet of ribbon" << endl << "Press any key to continue...";
	while( !_kbhit() ) { }
    return 0;

}