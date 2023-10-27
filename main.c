#include <stdio.h>

void inicializa_tabuleiro(int tab[4][4]){
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            tab[i][j] = 0;
        }
    }
}

void imprime_tabuleiro(int tab[4][4]){
    for(int i = 0; i<4;i++){
        for(int j = 0;j<4;j++){
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

int pode_por(int tab[4][4], int i, int j){
  for(int l = i,k = j; l < 4 && k < 4; l++,k++){
        if(tab[l][k] == 1){
            return 0;
        }
    }
    for(int l = i,k = j; l >= 0 && k < 4; l--,k++){
        if(tab[l][k] == 1){
            return 0;
        }
    }
    for(int l = i,k = j; l >= 0 && k >= 0; l--,k--){
        if(tab[l][k] == 1){
            return 0;
        }
    }
    for(int l = i,k = j; l < 4 && k >= 0; l++,k--){
        if(tab[l][k] == 1){
            return 0;
        }
    }
    if(tab[i][0] == 0 && tab[i][1] == 0 && tab[i][2] == 0 && tab[i][3] == 0 && tab[0][j] == 0 && tab[1][j] == 0 && tab[2][j] == 0 && tab[3][j] == 0){
        return 1;
    }else{
        return 0;
    }
}

void coloca_rainha(int tab[4][4], int aux[4][4]){
    int rainha = 0;
    int iaux[4] = {{5,5,5,5}};
    int jaux[4] = {{5,5,5,5}};

    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            if(pode_por(tab,i,j)){
                tab[i][j] = 1;
                rainha++;
                iaux[rainha] = i;
                jaux[rainha] = j;
            }
        }
    }

    if(rainha == 4){
        printf("Conseguiu!\n");
    }
}

int main(){

    int tabuleiro[4][4];
    int aux[4][4];
    inicializa_tabuleiro(tabuleiro);
    coloca_rainha(tabuleiro,aux);
    imprime_tabuleiro(tabuleiro);
}
