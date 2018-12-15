#include <stdio.h>



int main(){

    int vjogadores[1000]; 

    int i = 0;
    int qtd = 0;
    int primeiro = 0;
    int vivos = 0;
    int espada = 0;
    int decapitado = 0;

    printf("Digite o numero de jogadores: ");
    scanf("%d", &qtd);
    printf("Digite o numero do primeiro: ");
    scanf("%d", &primeiro);

    for(i=0; i<qtd; i++){//preenchendo jogadores
        vjogadores[i] = i+1;
    }

    vivos = qtd;
    espada = primeiro;

    while(vivos > 1){
		//mata o que vem após ao da espada
        decapitado = (espada+1)%qtd; 
        // procurando p/ matar
        while( vjogadores[decapitado] == -1 ){ 
           decapitado = (decapitado+1)%qtd; //  %qtd = voltar p/ 0 quando chega em qtd
        } 
		// decapitando
        vjogadores[decapitado] = -1; 
        vivos--;
		// procurando o da espada
        espada = (decapitado+1)%qtd; 
        
	while(  vjogadores[espada] == -1 ){ 
            espada = (espada+1)%qtd; 
        }  

    }

    printf("O ganhador é o jogador:  %d\n", espada);


    return 0;
}

