#include <assert.h>

#include "SortedMap.h"
#include "SMIterator.h"
#include "ShortTest.h"
#include <exception>
#include "iostream"
using namespace std;

bool relatie1(TKey cheie1, TKey cheie2) {
	if (cheie1 <= cheie2) {
		return true;
	}
	else {
		return false;
	}
}

void testAll(){
	SortedMap sm(relatie1);
	assert(sm.size() == 0);
	assert(sm.isEmpty());
    sm.add(1,2);
    assert(sm.size() == 1);
    assert(!sm.isEmpty());
    assert(sm.search(1)!=NULL_TVALUE);
    TValue v =sm.add(1,3);
    assert(v == 2);
    assert(sm.search(1) == 3);
    SMIterator it = sm.iterator();
    it.first();
    while (it.valid()){
    	TElem e = it.getCurrent();
    	assert(e.second != NULL_TVALUE);
    	it.next();
    }
    assert(sm.remove(1) == 3);
    assert(sm.isEmpty());
}

void testFunc(){
    SortedMap sm(relatie1);
    sm.add(1,2);
    sm.add(5,6);
    sm.add(3,3);
    sm.add(2,8);
    sm.add(8,10);
    sm.add(6,14);
    sm.add(20,7);
    sm.add(-5,23);
    assert(sm.size()==8);
    TKey values[sm.size()];
    sm.Key_Mult(values);
    assert(values[0]==-5);
    assert(values[1]==1);
    assert(values[2]==2);
    assert(values[3]==3);
    assert(values[4]==5);
    assert(values[5]==6);
    assert(values[6]==8);
    assert(values[7]==20);

}

