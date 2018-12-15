#include "lib/cpen.h"
#include <stdlib.h>
#include <lib/pen.h>


void arvore3(Pen& p, int lado){
    float ang = 35;
    float dec = 0.75;
    lado -= lado/20;
    if(lado < 10)
        return;
    p.setColor(130,230,180);
    p.setColor(10,100,0);
    //p.setColor(rand()%255,205,50);
    p.walk(lado);
    p.right(ang);
    arvore3(p, lado * dec);
    p.left(ang);
    arvore3(p, lado * dec);
    p.left(ang);
    arvore3(p, lado * dec);
    p.right(ang);
    if(lado%3==0){
        p.setColor(160,100,90);
    }
    p.walk(-lado);
}
void fractal(){
    Pen p(800, 600);
    p.setThickness(2);
    //coloca o pincel na posicao x 300 y 500
    p.setXY(400, 500);

    //faz o pincel apontar pra direita
    p.setHeading(90);
    //se speed = 0 entao ele faz o mais rapido possivel
    //se foi a partir de 1 ele controla a velocidade
    p.setSpeed(100);

    arvore3(p, 140);
    //triangulo(p, 400);
    //espera clicar no botao de fechar
    p.wait();
}


// Quadrado
void quadrado(Pen &p, int l){
    int ang = 90;
    if(l < 15)
        return;
    for(int i=0; i<4; i++){
        p.walk(l);
        p.left(ang);
        p.up();
        p.walk(l/3);
        p.down();
        quadrado(p, l*2/6);
        p.up();
        p.walk(-l/3);
        p.down();

    }


}
/*void quadrado(Pen &p, int l){
 * int ang = 90;
    if(l < 15)
        return;
    for(int i=0; i<4; i++){
        p.walk(l);
        p.left(ang);
        quadrado(p, l/8);
        p.setColor(rand()%255, rand()%255, rand()%255);
    }
    quadrado(p, l - 20);

}*/


void fractal_1(){
    Pen p(1000, 800);
    p.setThickness(2);
    p.setXY(200, 590);
    p.setHeading(0);
    p.setSpeed(200);
    quadrado(p, 400);
    p.wait();
}


//Trigo
void trigo(Pen &p, int l){
    int x=0;
    int angulo=35;
    if(l<1)
        return;
    while (x!=4) {
        p.walk(l);
        p.right(angulo);
        trigo(p,l/3);
        p.left(2*angulo);
        trigo(p,l/3);
        p.right(angulo);
        x++;
        p.setColor(0,180,210);
    }
    p.walk(-l*x);
}

void fractal_2(){
    Pen p(800, 600);
    int l = 100;
    p.setXY(400, 600);
    p.setColor(255,255,255);
    p.setHeading(90);
    p.setSpeed(0);
    p.setThickness(1);
    trigo(p,l);
    p.wait();
}

//Hexagono
void Hexagono(Pen &p, int l){
    int angulo=60;
    if(l<5)
        return;
    p.setColor(rand()%230, rand()%230, rand()%210);
    for(int i=0; i<6; i++){
        p.walk(l);
        p.left(angulo);
        Hexagono(p, l/3);
        p.setColor(rand()%230, rand()%230, rand()%210);
    }

}

void fractal_3(){
    Pen p(800, 600);
    p.setThickness(2);
    p.setXY(300, 500);
    p.setHeading(0);
    p.setSpeed(0);
    Hexagono(p, 200);
    p.wait();
}


//Bolinhas
void c(Pen& p, int l){
    int ang = 60;
    if(l< 2)
          return;
    for(int i=0;i<6;i++){
        p.setColor(0,180,210);
          p.circle(l);
          p.left(ang);
          p.up();
          p.walk(l);
          p.down();
          c(p, l*2/6);
          p.up();
          p.walk(-l);
          p.down();
     }

}
void fractal_4(){
    Pen p(800, 600);
    int l = 100;
    p.setXY(400, 300);
    p.setColor(255,255,255);
    p.setHeading(90);
    p.setSpeed(0);
    p.setThickness(1);
    c(p,l);
    p.wait();
}

int main(){

   //fractal_3();
   fractal_4();
   //fractal_1();
    //fractal_2();
    return 0;
}
