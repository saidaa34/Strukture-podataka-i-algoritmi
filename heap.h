#ifndef HEAP_H
#define HEAP_H
#include <vector>
using namespace std;

template <typename Tip>
class Heap {
    vector<Tip> niz;

    int LD(int i) { return 2*i+1; }
    int DD(int i) { return 2*i+2; }
    int ROD(int i) { return (i-1)/2; }
    void UpHeap(int indeks);
    void DownHeap(int indeks);
    void MakeHeap();

    public:
    Heap() {}
    Heap(vector<Tip> niz) : niz(niz) { MakeHeap(); }
    Tip Top() { return niz[0]; }
    bool Empty() { return niz.size() == 0; }
    int Size() { return niz.size(); }
    void Pop();
    void Insert(Tip element);
    void Ispisi();
};

template <typename Tip>
void Heap<Tip>::Insert(Tip element) {
    niz.push_back(element);
    UpHeap(niz.size() - 1);
}

template <typename Tip>
void Heap<Tip>::UpHeap(int indeks) {
    if(indeks > 0 && niz[indeks] > niz[ROD(indeks)]) {
        swap(niz[indeks], niz[ROD(indeks)]);
        UpHeap(ROD(indeks));
    }
}

template <typename Tip>
void Heap<Tip>::Pop() {
    swap(niz[0], niz[niz.size()-1]);
    niz.pop_back();
    if(!Empty())
        DownHeap(0);
}

template <typename Tip>
void Heap<Tip>::DownHeap(int indeks) {
    if(DD(indeks) < niz.size()) {//ima oba djeteta
        if(niz[indeks] < max(niz[LD(indeks)], niz[DD(indeks)])) //trebamo mijenjati
            if(niz[LD(indeks)] > niz[DD(indeks)]) {
                swap(niz[indeks], niz[LD(indeks)]);
                DownHeap(LD(indeks));
            }
            else {
                swap(niz[indeks], niz[DD(indeks)]);
                DownHeap(DD(indeks));
            }
    }
    else { //nema oba djeteta
        if(DD(indeks) == niz.size() && niz[LD(indeks)] > niz[indeks])
            swap(niz[indeks], niz[LD(indeks)]);
    }
}

template <typename Tip>
void Heap<Tip>::Ispisi() {
    for(auto el: niz)
        cout<<el<<" ";

}

template <typename Tip>
void Heap<Tip>::MakeHeap() {
    for(int i = ROD(niz.size()-1); i>=0; i--)
        DownHeap(i);

}
#endif // HEAP_H

