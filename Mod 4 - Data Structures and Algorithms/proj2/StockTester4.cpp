#include "Stock.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	

	// parameters provided
	Stock stock1("Abbott Laboratories", "ABB", 33.63, 200);
	cout << stock1 << endl;

	// dynamically allocated stock
	// passes all 4 arguments
	Stock * stockPtr2 = new Stock("Activision Blizzard", "ATVI",75.45, 1000 );
	cout << stockPtr2 << endl;

	return 0;

}
