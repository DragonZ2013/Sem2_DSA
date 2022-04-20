#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
    //TODO - Implementation
    //theta(1)
    this->index = list.head;
}

void ListIterator::first(){
    //TODO - Implementation
    //theta(1)
    if(list.isEmpty())
        this->index = -1;
    else
        this->index = list.head;
}

void ListIterator::next() {
    //TODO - Implementation
    //theta(1)
    if (this->valid())
        this->index = list.next[this->index]; //trebuie sa se duca pe elementul de pe next
    else
        throw exception();
}

bool ListIterator::valid() const{
    //TODO - Implementation
    //theta(1)
    if(this->index >=list.cap)
        return false;

    if(list.isEmpty())
        return false;

    if(this->index < 0)
        return false;

    if(0 <= this->index &&  this->index < list.cap)
        if(list.liste_elemente[this->index] != NULL_TCOMP)
            return true;

    return false;
}

TComp ListIterator::getCurrent() const{
    //TODO - Implementation
    //theta(1)
    if(this->valid())
        return list.liste_elemente[this->index];
    else
        throw exception();
}


