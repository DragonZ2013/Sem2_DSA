#include "ExtendedTest.h"
#include "ShortTest.h"

#include "SortedMap.h"


#include <iostream>
using namespace std;

bool relatieTemp(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	testAll();
	testFunc();
	
	/*SortedMap list = SortedMap(relatieTemp);
	list.add(1,1);
	list.add(0,2);
	list.add(4,3);
	list.add(5,7);
	list.add(3,8);
	list.add(1,5);
	cout<<list.size();
	cout<<list.remove(0);
	cout<<list.remove(3);
	cout<<list.remove(1);
	cout<<list.size();*/
	testAllExtended();

	cout << "That's all!" << endl;
	//system("pause");
	return 0;
}


