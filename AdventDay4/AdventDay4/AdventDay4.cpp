#include "main.h"
#include "md5.h"
#include <ctime>

int main()
{

	string seed = "bgvyzdsv";
	string current = "";
	string hash = "";
	bool run = true;
	uint64_t count = 0;
	string front = "";

	MD5 hasher;

	clock_t time = clock();
	while( run ) {
		current = seed + to_string(count);
		hasher.update(current.c_str(), current.length());
		hasher.finalize();
		hash = hasher.hexdigest();
		hasher = MD5();
		if( (hash[0]=='0') && (hash[1]=='0') && (hash[2]=='0') &&
				(hash[3] == '0') && (hash[4] == '0') && (hash[5] == '0') )
			run = false;
		else
			count++;
	}
	time = clock() - time;

	cout << "The count is " << count << endl << "It took " << time << " ticks & " << ((float) time) / CLOCKS_PER_SEC << "s" << endl;

	cout << "Press any key to continue...";
	while(!_kbhit() ) { }
    return 0;

}

