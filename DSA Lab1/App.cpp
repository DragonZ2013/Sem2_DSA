#include "Bag.h"
#include "ShortTest.h"
#include "ExtendedTest.h"
//#include "BagIterator.h"
#include <iostream>
#include <assert.h>

using namespace std;


int main() {

	testDiff();
	cout<< "Additional function tests over" << endl;

	testAll();
	cout << "Short tests over" << endl;

	testAllExtended();
	cout << "All test over" << endl;
}