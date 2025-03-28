#include <iostream>
#include <utility>
#include <climits>
#include "stablo.h"

using namespace std;

template <typename Tip>
pair<Stablo<Tip>,Stablo<Tip>> Razdvajanje(Stablo<Tip> &st, Tip k){
    st.Insert(k);
    typename Stablo<Tip>::Cvor *novi = st.getCvor(k);
    novi->setPrioritet(2000);
    st.ModifikovanUpHeap(novi);
    Stablo<Tip> s1;
    Stablo<Tip> s2;
    novi->ld->rod = nullptr;
    novi->dd->rod = nullptr;
    s1.setKorijen(novi->ld);
    s2.setKorijen(novi->dd);
    pair<Stablo<Tip>,Stablo<Tip>> par;
    par.first = s1;
    par.second = s2;
    return {s1,s2};
}

int main()
{
    Stablo<int> s;
    s.Insert(50);
    s.Insert(45);
    s.Insert(40);
    s.Insert(55);
    s.Insert(36);
    s.Insert(15);
    s.Insert(110);
    s.Insert(16);
    s.Insert(12);
    s.Insert(60);
    s.Insert(46);
    s.Insert(44);
    s.Insert(84);
    s.Insert(74);
    s.Insert(14);
    s.Ispis();

    cout<<endl;

    //Primjer kada brišemo korijen
    //s.Erase(16);

    //Primjer kada brišemo čvor koji ima dvoje djece
    //s.Erase(55);

    //Primjer kada brišemo čvor sa desnim djetetom
    //s.Erase(60);

    //Primjer kada brišemo čvor sa lijevim djetetom
    //s.Erase(16);

    //Primjer kada brišemo list
    //s.Erase(40);

    //s.Ispis();

    //cout<<endl<<s.getKorijen()<<endl;

    /*cout<<endl<<"nova stabla: "<<endl<<endl;
    auto rez = Razdvajanje(s,59);
    rez.first.Ispis();
    cout<<endl;
    rez.second.Ispis();*/

    return 0;
}

