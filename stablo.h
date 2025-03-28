#ifndef STABLO_H
#define STABLO_H
#include <cstdlib>
#include <utility>
using namespace std;

template <typename Tip>
class Stablo {
    public:
    struct Cvor {
        Tip element;
        int prioritet;
        Cvor *ld, *dd, *rod;
        Cvor(Tip el, Cvor *rod = nullptr, Cvor *ld = nullptr, Cvor *dd = nullptr):element(el), rod(rod), ld(ld), dd(dd) {
            prioritet = int(((double) rand() / (RAND_MAX))*1000);
        }
        void setPrioritet(int pr) { prioritet = pr;}
    };

    private:
    int n;
    Cvor *korijen;
    void Ispis(Cvor*) const;

    public:
    Stablo():n(0),korijen(nullptr) {}
    Cvor* Find(Tip vrijednost);
    Tip getKorijen(){return korijen->element;}
    void Insert(const Tip vrijednost);
    void Erase(const Tip vrijednost);
    void Ispis() const { Ispis(korijen); }
    Cvor* Sljedbenik(Cvor* cvor);
    void ModifikovanUpHeap(Cvor *cvor);
    void ModifikovanDownHeap(Cvor *cvor);
    void setKorijen(Cvor *cvor) { korijen = cvor;}
    Cvor* getCvor(Tip el);
};

#include "stablo.cpp"

#endif // STABLO_H
