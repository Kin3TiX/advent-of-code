#include "main.h"
#include "HOUSE_GRID.h"
#include "HOUSE_DIRECTOR.h"

int main() {

	string input;

	cout << "Enter path to input file" << endl << "--->  ";
	getline(cin, input);

	HOUSE_GRID santa;
	HOUSE_GRID roboSanta("roboSanta");
	HOUSE_GRID * currentSanta = &santa;
	HOUSE_DIRECTOR drunkElf(input);

	if( drunkElf.startDirector() ) {

		bool run = true;
		HOUSE_DIRECTOR::direction nextMove;
		nextMove = drunkElf.getNextDirection();

		while(run) {

			switch( nextMove ) {

				case HOUSE_DIRECTOR::NORTH:
					currentSanta->moveNorth();
					break;

				case HOUSE_DIRECTOR::SOUTH:
					currentSanta->moveSouth();
					break;

				case HOUSE_DIRECTOR::EAST:
					currentSanta->moveEast();
					break;

				case HOUSE_DIRECTOR::WEST:
					currentSanta->moveWest();
					break;

				case HOUSE_DIRECTOR::END:
				case HOUSE_DIRECTOR::ERROR:
					run = false;
					break;

			}

			nextMove = drunkElf.getNextDirection();
			if( *currentSanta == santa )
				currentSanta = &roboSanta;
			else
				currentSanta = &santa;

		}

		if( nextMove == HOUSE_DIRECTOR::ERROR ) {

			cout << "Error reading input" << endl << "Press any key to continue...";
			while( !_kbhit() ) { }
			return 1;

		}

	} else {

		cout << "Could not open input file" << endl << "Press any key to continue...";
		while( !_kbhit() ) { }
		return 1;

	}

	cout << "Santa visited " << santa.getGridUniques() << " unique houses" << endl;
	cout << "Robo-Santa visited " << roboSanta.getGridUniques() << " unique houses" << endl;
	santa.mergeGrids(roboSanta);
	cout << "Combined they visited " << santa.getGridUniques() << " unique houses" << endl;
	cout << "Press any key to continue...";
	while( !_kbhit() ) { }
    return 0;

}