#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIteratedList::SortedIteratedList(Relation r) {
    //TODO - Implementation
    //theta(n)
    this->nrElem = 0;
    this->head = -1;
    this->firstEmpty = 0;
    this->cap = 8;
    this->next = new int[this->cap];
    this->liste_elemente = new TComp [this->cap];
    for(int i = 0; i < this->cap; i++)
    {
        this->liste_elemente[i] = NULL_TCOMP;
        this->next[i] = i+1;
    }
    this->next[this->cap - 1] = -1;
    this->relation = r;
}

int SortedIteratedList::size() const {
    //TODO - Implementation
    //theta(1)
    return this->nrElem;
}

bool SortedIteratedList::isEmpty() const {
    //TODO - Implementation
    //theta(1)
    if(this->nrElem == 0)
        return true;
    return false;
}

TComp SortedIteratedList::getElement(ListIterator poz) const {
    //TODO - Implementation
    //theta(1)
    if(poz.valid())
    {
        int i = poz.index;
        return this->liste_elemente[i];
    }
    else
        throw exception();

}

ListIterator SortedIteratedList::first() const {
    //TODO - Implementation
    //theta(1)
    //trebuie sa imi dau seama cum sa lucrez cu obiectul curent si nu unul copie

        /*SortedIteratedList s(this->relation);
        s.head = this->head;
        s.nrElem = this->nrElem;
        s.firstEmpty = this->firstEmpty;
        s.cap = this->cap;
        s.next = this->next;
        s.liste_elemente = this->liste_elemente;
         */
        ListIterator iterator(*this);
        iterator.index = this->head;
        return iterator;


}

ListIterator SortedIteratedList::search(TComp e) const{
    //TODO - Implementation
    //O(n)
    ListIterator iterator(*this);
    int i = this->head;
    bool found = false;
    while(i != -1 && !found)
    {
        if(this->liste_elemente[i] == e)
            found = true;
        if(found != true) //!found
            i = this->next[i];
    }

    if(found)
    {
        iterator.index = i;
        return iterator;
    }
    else
    {
        iterator.index = -1;
        return iterator;
    }
}

TComp SortedIteratedList::remove(ListIterator& poz) {
    //TODO - Implementation
    //O(n)
    if(!poz.valid())
        throw exception();
    
    if(poz.valid())
    {
        int aux_elem = NULL_TCOMP;
        bool gasit = false;
        int i = poz.index;//pe care il stergem
        int j = this->head;//prev
        poz.next();
        if(i == this->head)
        {

            this->head = this->next[i];
            this->next[i] = -1;
            this->nrElem --;
            aux_elem = this->liste_elemente[i];
            this->liste_elemente[i] = NULL_TCOMP;

            if(this->firstEmpty == -1)
                this->firstEmpty = i;
            else
            {
                //cautam ultima pozitie libera care il va primi drept next pe i
                j = this->firstEmpty;
                while(this->next[j] != -1)
                    j = this->next[j];
                this->next[j] = i;
            }
            return aux_elem;
        }

        //caut elementul care il are pe next pe i
        while(!gasit)
        {
            if( this->next[j] == i)
                gasit = true;
            else
                j = this->next[j];
        }

        //elementul dinaintea elementului pe care vrem sa il stergem primeste next nextul lui i
        this->next[j] = this->next[i];
        this->next[i] = -1;
        if(this->firstEmpty == -1)
            this->firstEmpty = i;
        else
        {
            //cautam ultima pozitie libera care il va primi drept next pe i
            j = this->firstEmpty;
            while(this->next[j] != -1)
                j = this->next[j];
            this->next[j] = i;
        }
        this->nrElem --;
        aux_elem = this->liste_elemente[i];
        this->liste_elemente[i] = NULL_TCOMP;
        //cazul de amortizare
        if(this->nrElem<this->cap/4)//cand avem un sfert din memoria alocata ocupata cu valori injumatatim
        {
            //injumatatim memorie
            //mutam sirurile
            //mutam iteratorul de pe pozitia i
            //injumatatit cap
            TComp* new_liste_elemente = new TComp[this->cap/2];
            int* new_next = new int[this->cap/2];
            //for(int i = 0;i<this->nrElem;i++)//valori
            int idx=0;
            bool done=false;
            for(int i=this->head;i!=-1;i=this->next[i])
            {
                if(i==poz.index&&done==false)
                {
                    done=true;
                    poz.index=idx;
                }
                new_liste_elemente[idx]=this->liste_elemente[i];
                new_next[idx]=idx+1;
                idx++;
            }
            new_next[idx-1]=-1;
            for(int i=this->nrElem;i<this->cap/2;i++)//valori goale
            {
                new_liste_elemente[i]=NULL_TCOMP;
                new_next[i]=i+1;
            }
            new_next[this->cap/2-1]=-1;
            delete[] this->liste_elemente;
            delete[] this->next;
            this->liste_elemente=new_liste_elemente;
            this->next=new_next;
            this->head=0;
            this->firstEmpty=this->cap/4;
            this->cap=this->cap/2;
        }
        return aux_elem;
        
    }



    //trebuie sa cautam pozitia la ultimul leer care trebuie schimbata cu i
    //elementul care il are pe next pe i primeste nextul lui i
    //daca this->first_empty e -1 atunci el devine i iar next la i e tot -1
    //next la i primeste -1
    //cazul ala pt complexitate amortizata

}

void SortedIteratedList::add(TComp e) {
    //TODO - Implementation
    /*e sorted deci trebuie sa fim atenti la relatie deci trebuie sa comparam fiecare el
    cu el pe care vrem sa il punem. Cand ne da relatia false ne oprim.
     Trebuie sa il tinem si pe anterior minte. Punem pe o pozitie libera
     pe care o cautam cu ajutorul lui this->first_empty. Nextul la prev devine indexul elementului,
     nextul la elementul nostru e elementul pe care ne aflam(ala cu care ne-o dat false la relatie),
     this->first_empty il ia pe next.
    */
    //cazu in care e headu
    //caz separat si ultimul element

    // daca this->first_empty e -1 atunci dublam capacitatea
    //O(n)
    if(this->firstEmpty == -1)
    {
        this->cap = this->cap*2;
        int i;
        TComp* new_liste_elemente = new TComp[this->cap];
        int* new_next = new int[this->cap];
        this->firstEmpty = this->cap/2;
        for(i = 0; i < this->cap/2; i++)
        {
            new_liste_elemente[i] = this->liste_elemente[i];
            new_next[i] = this->next[i];
        }

        for(i = this->cap/2; i < this->cap-1; i++)
        {
            new_liste_elemente[i] = NULL_TCOMP;
            new_next[i] = i+1;
        }
        new_next[i] = -1;

        delete[] this->liste_elemente;
        delete[] this->next;

        this->liste_elemente = new_liste_elemente;
        this->next = new_next;
    }

    if(this->head == -1)
    {
        int aux;
        aux = this->firstEmpty;
        this->liste_elemente[aux] = e;
        this->firstEmpty = this->next[aux];
        this->next[aux] = -1;
        this->nrElem ++;
        this->head = aux;
    }
    else
    {
        int i = this->head;
        int aux;
        bool gasit_poz = false;
        //cazul in care e head
        if(this->relation(e, this->liste_elemente[i]))
        {
            aux = this->firstEmpty;
            this->liste_elemente[aux] = e;
            this->firstEmpty = this->next[aux];
            this->next[aux] = i;//head
            this->head = aux;
            this->nrElem ++;
        }
        else
        {
            int prev = this->head;
            i = this->next[prev];
            while(!gasit_poz && i!=-1)
            {
                if(this->relation(e, this->liste_elemente[i]))
                    gasit_poz = true;
                else
                {
                    prev = i;
                    i = this->next[prev];
                }

            }

            if(gasit_poz)
            {
                aux = this->firstEmpty;
                this->liste_elemente[aux] = e;
                this->firstEmpty = this->next[aux];
                this->next[aux] = this->next[prev];//i
                this->next[prev] = aux;
                this->nrElem ++;
            }
            else //la final
            {
                aux = this->firstEmpty;
                this->liste_elemente[aux] = e;
                this->firstEmpty = this->next[aux];
                this->next[aux] = -1;//next[prev]=-1
                this->next[prev] = aux;
                this->nrElem ++;
            }
        }
    }

}

void SortedIteratedList::k_loschen(int k) {
//worst case: O(n)
//best case: theta(1)
//average: theta(n)
    int cont=1;
    ListIterator it(*this);
    while(it.valid())
    {
        if(cont%k==0)
            this->remove(it);
        else
            it.next();
        cont++;
    }

}
SortedIteratedList::~SortedIteratedList() {
    //TODO - Implementation
    delete[] this->liste_elemente;
    delete[] this->next;
}
