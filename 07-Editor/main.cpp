#include <iostream>
#include <list>
#include <sstream>
#include <SFML/Graphics.hpp>
#include "sftext.h"

using namespace std;
//digitar, apagar, crt+
struct Ambiente{
    list<char> texto;
    list<char>::iterator cursor;
    Ambiente(){
        cursor = texto.end();
    }

    string toString(){
        stringstream ss;
        for(auto it = texto.begin(); it != texto.end(); it++){//it = posição
            if(it == cursor)
                ss << "#";
            ss << (*it);//mostrando caractere
        }
        if(cursor == texto.end())
            ss << "#";
        return ss.str();
    }
};

int main()
{
    Ambiente amb;
    amb.texto.push_back('B');
    amb.texto.push_back('e');
    amb.texto.push_back('m');
    amb.texto.push_back('-');
    amb.texto.push_back('v');
    amb.texto.push_back('i');
    amb.texto.push_back('n');
    amb.texto.push_back('d');
    amb.texto.push_back('x');

    sf::RenderWindow janela(sf::VideoMode(800, 600), "Janela");

    while(janela.isOpen()){

        sf::Event event;
        while(janela.pollEvent(event)){
            if(event.type == sf::Event::Closed)
                  janela.close();
            /*lista de ambientes
             * list<ambiente>
             * crtl + r list<ambiente>++;
             * crtl + z list<ambiente>--;
             */
            if(event.type == sf::Event::KeyPressed){// salva copia do que quer e aplica
                if(event.key.code == sf::Keyboard::Z){
                    if(event.key.control)
                        cout << "control z" << endl;
                }
                else if(event.key.code == sf::Keyboard::R){
                    if(event.key.control)
                        cout << "control r" << endl;
                    
                } else if(event.key.code == sf::Keyboard::W){
                    cout << "control w" << endl;
                    janela.close();

                }
                else if((event.key.code >= sf::Keyboard::A) &&
                   (event.key.code <= sf::Keyboard::Z)){
                    char  tecla= (event.key.code - sf::Keyboard::A) + 'a';

                    if(event.key.shift)//APERTANDO SHIFT
                        tecla = tecla - 'a'  + 'A';//dica do prof
                        amb.texto.insert(amb.cursor, tecla);//inserindo a letra na posição do cursor
                        cout << tecla << endl;
                         //   amb.text.insert(amb.cursor, tecla);//fiz em sala
                }
                else if((event.key.code == sf::Keyboard::Space)){//fiz em sala
                    cout << "espaco" << endl;
                    amb.texto.insert(amb.cursor, ' ' );

                }else if((event.key.code == sf::Keyboard::Return)){//fiz em sala
                         cout << "enter" << endl;
                         char n = '\n';
                         amb.texto.insert(amb.cursor, n);

                }else if(event.key.code == sf::Keyboard::BackSpace){
                    cout << "backspace" << endl;
                    if(amb.cursor != amb.texto.begin()  ){
                         amb.texto.erase(amb.cursor++, amb.cursor--);//apagando elementos a esquerda
                    }


                }else if(event.key.code == sf::Keyboard::Delete){
                    cout << "delete" << endl;
                     if(amb.cursor != amb.texto.end()  ){
                               amb.texto.erase((amb.cursor++));// apagando elementos a direita do cursor
                     }

                }
                else if(event.key.code == sf::Keyboard::Left){
                    amb.cursor--;
                }
                else if(event.key.code == sf::Keyboard::Right){
                    amb.cursor++;
                }
            }
        }

        auto pos = sf::Vector2f(30, 50);
        janela.clear();
        janela.draw(sfText(pos, amb.toString(), sf::Color::Cyan, 30));
        janela.display();
    }
    return 0;
}




