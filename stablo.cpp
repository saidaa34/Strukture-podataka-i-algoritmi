#ifndef STABLO_CPP
#define STABLO_CPP
#include "stablo.h"
#include <iostream>

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Find(Tip vrijednost) {
    Cvor *trenutni = korijen;
    while(trenutni != nullptr) {
       if(trenutni->element == vrijednost)
         return trenutni;
       if(vrijednost < trenutni->element)
            trenutni = trenutni->ld;
       else trenutni = trenutni->dd;
    }
    return nullptr;
}

template <typename Tip>
void Stablo<Tip>::Insert(const Tip vrijednost) {

    Cvor *trenutni = korijen, *prethodni = nullptr;
    while(trenutni != nullptr) {
       if(trenutni->element == vrijednost)
         break;
       prethodni = trenutni;
       if(vrijednost < trenutni->element)
            trenutni = trenutni->ld;
       else trenutni = trenutni->dd;
    }

    Cvor *novi = new Cvor(vrijednost, prethodni);
    if(korijen == nullptr) {
        korijen = novi;
    }
    else {
        if(prethodni ->element < novi->element)
            prethodni->dd = novi;
        else prethodni->ld = novi;
    }
    n++;
    //cout<<"novi cvor:"<<novi->element<<", "<<novi->prioritet<<endl<<endl;
    if(novi->rod != nullptr && novi->prioritet > novi->rod->prioritet)
    {
        //cout<<"novi cvor:"<<novi->element<<", "<<novi->prioritet<<endl<<"roditelj: "<<novi->rod->element<<", "<<novi->rod->prioritet<<endl<<endl;
        ModifikovanUpHeap(novi);
    }
}

template <typename Tip>
void Stablo<Tip>::ModifikovanUpHeap(Cvor *cvor){
    while(cvor->rod != nullptr && cvor->rod->prioritet < cvor->prioritet){
        if(cvor->rod->dd == cvor){
            bool desno = true;
            if(cvor->rod == korijen){
                korijen = cvor;
                desno = false;
            }
            if(cvor->ld == nullptr && cvor->dd == nullptr){
                //cout<<"slucaj 1"<<endl;
                Cvor* stariRod = cvor->rod;
                cvor->ld = stariRod;
                cvor->rod = stariRod->rod;
                stariRod->dd = nullptr;
                stariRod->rod = cvor;
                //Ispis();
                //cout<<endl;
                //cout<<"cvor element: "<<cvor->element<<" lijevo dijete: "<<cvor->ld->element<<" cvor->rod "<<cvor->rod->element<<" cvor->rod->dd "<<cvor->rod->dd->element<<endl;
            }
            else if(cvor->ld != nullptr && cvor->dd == nullptr){
                //cout<<"slucaj 3"<<endl;
                Cvor* stariRod = cvor->rod;
                Cvor* staroDijete = cvor->ld;
                cvor->ld = stariRod;
                cvor->dd = nullptr;
                cvor->rod = stariRod->rod;
                stariRod->dd = staroDijete;
                stariRod->rod = cvor;
                staroDijete->rod = stariRod;
                //Ispis();
                //cout<<endl;
            }
            else if(cvor->ld == nullptr && cvor->dd != nullptr){
                //cout<<"slucaj 4"<<endl;
                Cvor* stariRod = cvor->rod;
                cvor->ld = stariRod;
                cvor->rod = stariRod->rod;
                stariRod->dd = nullptr;
                stariRod->rod = cvor;
                //Ispis();
                //cout<<endl;
            }
            else if(cvor->ld != nullptr && cvor->dd != nullptr){
                //cout<<"slucaj 7"<<endl;
                Cvor* stariRod = cvor->rod;
                Cvor* staroLDijete = cvor->ld;
                cvor->rod = stariRod->rod;
                cvor->ld = stariRod;
                stariRod->rod = cvor;
                stariRod->dd = staroLDijete;
                staroLDijete->rod = stariRod;
                //Ispis();
                //cout<<endl;
            }
            if(desno && cvor->rod->element < cvor->element)
                cvor->rod->dd = cvor;
            else if(desno && cvor->rod->element > cvor->element)
                cvor->rod->ld = cvor;
        }

        else{
            bool lijevo = true;
            if(cvor->rod == korijen){
                korijen = cvor;
                lijevo = false;
            }
            if(cvor->ld == nullptr && cvor->dd == nullptr){
                //cout<<"slucaj 2"<<endl;
                Cvor* stariRod = cvor->rod;
                cvor->dd = stariRod;
                cvor->rod = stariRod->rod;
                stariRod->ld = nullptr;
                stariRod->rod = cvor;
                //Ispis();
                //cout<<endl;
            }
            else if(cvor->ld == nullptr && cvor->dd != nullptr){
                //cout<<"slucaj 5"<<endl;
                Cvor* stariRod = cvor->rod;
                Cvor* staroDijete = cvor->dd;
                cvor->dd = stariRod;
                cvor->rod = stariRod->rod;
                stariRod->ld = staroDijete;
                stariRod->rod = cvor;
                staroDijete->rod = stariRod;
                //Ispis();
                //cout<<endl;
            }
            else if(cvor->ld != nullptr && cvor->dd == nullptr){
                //cout<<"slucaj 6"<<endl;
                Cvor* stariRod = cvor->rod;
                cvor->dd = stariRod;
                cvor->rod = stariRod->rod;
                stariRod->ld = nullptr;
                stariRod->rod = cvor;
                //Ispis();
                //cout<<endl;
            }
            else if(cvor->ld != nullptr && cvor->dd != nullptr){
                //cout<<"slucaj 8"<<endl;
                Cvor* stariRod = cvor->rod;
                Cvor* staroDDijete = cvor->dd;
                cvor->rod = stariRod->rod;
                cvor->dd = stariRod;
                stariRod->rod = cvor;
                stariRod->ld = staroDDijete,
                staroDDijete->rod = stariRod;
                //Ispis();
                //cout<<endl;
            }
            if(lijevo && cvor->rod->element < cvor->element)
                cvor->rod->dd = cvor;
            else if(lijevo && cvor->rod->element > cvor->element)
                cvor->rod->ld = cvor;
        }
    }
}

template <typename Tip>
void Stablo<Tip>::Ispis(Cvor* cvor) const {
    cout<<"Vrijednost: "<<cvor->element<<", "<<cvor->prioritet;
    if(cvor->ld != nullptr)
        cout<<" Lijevo dijete: "<<cvor->ld->element<<", "<<cvor->ld->prioritet;
    if(cvor->dd != nullptr)
        cout<<" Desno dijete: "<<cvor->dd->element<<", "<<cvor->dd->prioritet;
    cout<<endl;
    if(cvor->ld != nullptr)
        Ispis(cvor->ld);
    if(cvor->dd != nullptr)
        Ispis(cvor->dd);
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::Sljedbenik(Stablo<Tip>::Cvor* cvor) {
    if(cvor->dd != nullptr) {
        Cvor *trenutni = cvor->dd;
        while(trenutni->ld != nullptr)
            trenutni = trenutni->ld;
        return trenutni;
    }

    Cvor* trenutni = cvor;

    while(trenutni->rod != nullptr) {
        if(trenutni->rod->ld == trenutni)
            return trenutni->rod;
        if(trenutni->rod->dd == trenutni)
            trenutni = trenutni->rod;
    }

    return nullptr;

}

template <typename Tip>
void Stablo<Tip>::Erase(const Tip vrijednost) {
    Cvor* cvor = Find(vrijednost); //provjeravamo da li postoji to što želimo izbrisati
    if(cvor == nullptr) return;

    if(cvor->ld == nullptr && cvor->dd == nullptr) { //ako je list
        if(cvor->rod == nullptr) //ako je korijen
           korijen = nullptr;
        else {
            if(cvor->rod->ld == cvor) //ako nije korijen i ako je lijevo dijete svog roditelja, pošto ćemo ga izbrisati, postavljamo na nullprt lijevo dijete njegovog roditelja
                cvor->rod->ld = nullptr;
            else cvor->rod->dd = nullptr; //ako nije korijen i ako je desno dijete svog roditelja, postavljamo ovako onda
        }

    }
    else if(cvor->ld == nullptr) { //ako nema lijevo dijete
        cvor->dd->rod = cvor->rod;
        if(cvor->rod == nullptr) //ako je korijen
           korijen = cvor->dd;
        else {
            if(cvor->rod->ld == cvor)
                cvor->rod->ld = cvor->dd;
            else cvor->rod->dd = cvor->dd;
        }
    }
    else if(cvor->dd == nullptr) { //ako nema desno dijete
        cvor->ld->rod = cvor->rod;
        if(cvor->rod == nullptr) //ako je korijen
           korijen = cvor->ld;
        else {
            if(cvor->rod->ld == cvor)
                cvor->rod->ld = cvor->ld;
            else cvor->rod->dd = cvor->ld;
        }
    }
    else { //ako ima oba djeteta
        Cvor* sljedbenik = Sljedbenik(cvor);
        sljedbenik->ld = cvor->ld;
        cvor->ld->rod = sljedbenik;
        cvor->dd->rod = cvor->rod;
        if(cvor->rod == nullptr) //ako je korijen
           korijen = cvor->dd;
        else {
            if(cvor->rod->ld == cvor)
                cvor->rod->ld = cvor->dd;
            else cvor->rod->dd = cvor->dd;
        }
    }
    Cvor *lijevoDijete = cvor->ld;
    Cvor *desnoDijete = cvor->dd;
    if(lijevoDijete != nullptr)
        ModifikovanUpHeap(lijevoDijete);
    if(desnoDijete != nullptr)
        ModifikovanUpHeap(desnoDijete);
    delete cvor;
    n--;
}

template <typename Tip>
typename Stablo<Tip>::Cvor* Stablo<Tip>::getCvor(Tip el){
    Cvor *trenutni = korijen;
    while(trenutni->element != el){
        if(trenutni->element > el)
            trenutni = trenutni->ld;
        else
            trenutni = trenutni->dd;
    }
    return trenutni;
}


template <typename Tip>
void Stablo<Tip>::ModifikovanDownHeap(Cvor *cvor){
    while(cvor->ld != nullptr || cvor->dd != nullptr && cvor->prioritet < cvor->ld->prioritet || cvor->prioritet < cvor->dd->prioritet){
        Cvor *stariRod = cvor->rod;
        bool desno = false;
        if(cvor->rod->dd == cvor)
            desno = true;
        if(cvor->dd != nullptr && cvor->ld == nullptr){
            Cvor *staroDijete = cvor->dd;
            cvor->rod = staroDijete;
            cvor->dd = staroDijete->ld;
            staroDijete->rod = stariRod;
            if(desno)
                stariRod->dd = staroDijete;
            else
                stariRod->ld = staroDijete;
            staroDijete->ld = cvor;
        }

        else if(cvor->dd == nullptr && cvor->ld != nullptr){
            Cvor *staroDijete = cvor->dd;
            cvor->rod = staroDijete;
            cvor->ld = staroDijete->dd;
            staroDijete->rod = stariRod;
            if(desno)
                stariRod->dd = staroDijete;
            else
                stariRod->ld = staroDijete;
            staroDijete->dd = cvor;
        }
    }
}

#endif

