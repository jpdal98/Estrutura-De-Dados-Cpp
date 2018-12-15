#include <iostream>
#include <map>//arvore TreeMap
#include <unordered_map> //arvore HashMap

#include <set> //arvore TreeSet
#include <unordered_set>//hash HashSet
using namespace std;


enum Marcador {cheio, vazio, deletado};
struct Elem {
    int key;
    string value;
    Marcador marcador;


    Elem(int key = 0){
        this->key = key;
    }

    bool operator ==(Elem other){
        return key == other.key;
    }

    friend ostream& operator << (ostream& os, Elem e){
        os << e.key;
        return os;
    }
};

/*

  tree -> imponho ordenacao - chaves ou elementos devem ser ordenaveis
                              mapa      set
  hash -> não imponho ordenacao - preciso saber calcular o hash
                              das chaves ou dos elementos
                                  mapa          set


*/

#include <vector>
#include <list>
#include <algorithm>
#include <pair>
struct HashLinear{

    pair<Elem, Marcador> * vet;
    int size ;
    int capacity;
    HashLista(int size){
        vet = new pair<Elem, Marcador>[capacity];
        this->capacity = capacity;
        this->size = 0;
        for(int i = 0; i < capacity; i++){
            vet[i].first = Elem();
            vet[i].second = vazio;

        }
    }

    bool remove(Elem elem) {
        auto it = busca(elem.key);
        if(it != -1){
            vet[it].marcador = vazio;
            return false;
        }

        size --;
        it = (it + 1) % capacity;
        while(vet[it].marcador != vazio){
            vet[it].marcador = vazio;
            insert(vet[it].elem);
            it = (it + 1) % capacity;

        }
    }
    //inseri a partir da busca.
    bool insert(Elem e){

        int it;
        it = busca(e.key);
        int pos = e.key % size;
        if(vet[it] != nullptr)
                vet[it].marcador = deletado;

        while((vet[it].second != vazio) || (vet[it].second != deletado))
            pos = (pos + 1) % capacity;
        vet[it].first = e;
        vet[it].second = cheio;
        size--;



        /* it = find(key);

            if não é nulo
                it.marcador = deletado;
         // pos = alculaposição da base;
         //enquanto (vet na posiçõa  for vazio nem a key, eu ando)
                    pos = pos + 1 % capacity;
          pos.elem = elem;
          pos.maracdor = cheio;
          size-- se inserir



        */
    }
    //encontra o menor
    int menor(){
        auto it = busca(elem.key);
        if(it != -1){
            vet[it].marcador = vazio;
            return false;
        }
    }

    void resize(int capacity){
        auto old_vet =  vet;
        vet = new pair<>[capacity];
        for(auto i = 0; i < capacity; i++)
            vet[i].marcador = vaio;
        for(auto& e : old_vet){
            this-> insert(elem);
        }
        delete old_vet;
    }

    //cria um novo vetor de listas com tam new_vet_sizee reinsere todos os outros elementos no novo
    void resize(int new_vet_size){
        auto vet_old  = this -> vet;
        this->vet = new vector<list<Elem>>(new_vet_size);
        for(auto& lista : *vet_old)
            for(auto& elem : lista)
                this -> insert(elem);
        delete vet_old;

        //tentativa em sala, pouco tempo
       /* auto vet_old = vet;
        this -> vet = vector<list<Elem>>(new_vet_size);
        for (list<Elem> a : vet) {
            this->insert(a);
        }*/
    }

    int busca(Elem elem){
        int base = elem.key % vet.size();
         auto& lista = vet->at(base);
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it == lista.end())
            return false;
        return it;
    }

    bool remocao(Elem elem) {
        int base = elem.key % vet.size();
         auto& lista = vet->at(base);
        auto it = std::find(lista.begin(), lista.end(), elem);
        if(it == lista.end())
            return false;
        lista.erase(it);
        return true;
    }

}







