



//Meu código e da Sávila

#include <iostream>
#include <list>
using namespace std;

int main()
{   //positivos hombres y negativos mujeres
    //saída: [1, 4, 3, 2]
    list<int*> lista;
    list<int*> lista_casais_het;

    for(auto elem : {1, 2, -1, 1, -1, 1, 4, 3, -3, 3, -2, 2}){
        lista.push_back(new int (elem));
    }
    for(auto it = lista.begin(); it != --lista.end();){
       bool achei = false;
        for(auto itd = ++it; itd != lista.end(); itd++){
            if(((**it)+(**itd)) == 0 ){
              delete *it;
              delete *itd;

              it = lista.erase(it);
              itd = lista.erase(itd);

              achei = true;
              break;

            }

        }
        if(!achei){
            it++;
        }
        cout << lista << " ";
    }

    /*for(auto elem : lista){
        cout << *elem << " ";
    }

}

//Correção
/*Versão do prof
int main()
{   //positivos hombres y negativos mujeres
    //saída: [1, 4, 3, 2]
    list<int*> lista;
    list<int*> lista_casais_het;

    for(auto elem : {1, 2, -1, 1, -1, 1, 4, 3, -3, 3, -2, 2}){
        lista.push_back(new int (elem));
    }
    for(auto it = lista.begin(); it != --lista.end();){

        for(auto itd = ++it; itd != lista.end(); itd++){
            if(((**it)+(**itd)) == 0 ){
                lista_casais_het.push_back(*it);
                lista_casais_het.push_back(*itd);



            }

        }
    }
    for(auto elem : lista_casais_het){
        cout << *elem << " ";
    }

    for(auto elem : lista_casais_het){
        cout << *elem << " ";
    }

}
*/
