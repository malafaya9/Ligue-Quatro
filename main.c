#include <stdio.h>
#include <stdlib.h>

char Jogador = 'X';

char Tabuleiro[6][7];

int jogadas = 0;

void mostrarTabuleiro(){
    int i, j;
    printf("---------------\n");
    for(i=0;i<6;i++){
        printf("|");
        for(j=0;j<7;j++){
            printf("%c|",Tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("---------------\n");
}

void limparTabuleiro(){
    int i, j;
    for(i=0;i<6;i++){
        for(j=0;j<7;j++){
            Tabuleiro[i][j] = ' ';
        }
    }
}

void reiniciarJogo(){
    limparTabuleiro();
    Jogador = 'X';
    jogadas = 0;
    mostrarTabuleiro();
}

int verificarVitoria(){
    int i, j;
    //checa a horizontal
    for(i=0;i<7;i++){
        for(j=0;j<3;j++){
            if(Tabuleiro[i][j] == Jogador && Tabuleiro[i][j]==Tabuleiro[i][j+1] && Tabuleiro[i][j]==Tabuleiro[i][j+2] && Tabuleiro[i][j]==Tabuleiro[i][j+3])
                return 1;
        }
    }
    //checa a vertical
    for(i=0;i<4;i++){
        for(j=0;j<6;j++){
            if(Tabuleiro[i][j] == Jogador && Tabuleiro[i][j]==Tabuleiro[i+1][j] && Tabuleiro[i][j]==Tabuleiro[i+2][j] && Tabuleiro[i][j]==Tabuleiro[i+3][j])
                return 1;
        }
    }
    //checa as diagonais primarias
    for(i=0;i<4;i++){
        for(j=0;j<3;j++){
            if(Tabuleiro[i][j] == Jogador && Tabuleiro[i][j]==Tabuleiro[i+1][j+1] && Tabuleiro[i][j]==Tabuleiro[i+2][j+2] && Tabuleiro[i][j]==Tabuleiro[i+3][j+3]){
                return 1;
            }
        }
    }
    //checa as diagonais secundarias
    for(i=0;i<4;i++){
        for(j=3;j<6;j++){
            if(Tabuleiro[i][j] == Jogador && Tabuleiro[i][j]==Tabuleiro[i+1][j-1] && Tabuleiro[i][j]==Tabuleiro[i+2][j-2] && Tabuleiro[i][j]==Tabuleiro[i+3][j-3]){
                return 1;
            }
        }
    }
    return 0;
}

int verificarEmpate(){
    if(verificarVitoria()==1){
        return 1;
    }
    else if(jogadas==42){
        return 2;
    }
    return 0;
}

void TrocarJogador(){

    if(Jogador=='X'){
        Jogador = 'O';
    }else{
        Jogador = 'X';
    }

}

int fimDeJogo(){
    int flag = verificarEmpate();
    if(flag == 0){
          return 0;
    }else if(flag == 1){
            printf("\nVitoria do Jogador %c!\n", Jogador);
    }else if(flag == 2){
        printf("\nEmpate!\n");
    }
    reiniciarJogo();
    return 1;
}

void realizarJogada(int coluna){
    coluna--;
    if(coluna<0||coluna>6){
        printf("Coluna invalida!\n");
    }else{
        int i;
        for(i=5;i>=0;i--){
            if(Tabuleiro[i][coluna]==' '){
                Tabuleiro[i][coluna] = Jogador;
                system("cls");
                jogadas++;
                printf("Jogada realizada!\n");
                if(fimDeJogo() == 1){
                    return;
                }
                mostrarTabuleiro();
                TrocarJogador();
                return;
            }
        }
    }
    printf("Jogada nao realizada!\n");

}

int main()
{
    int j;
    reiniciarJogo();
    while(1==1){
        printf("Escolha uma coluna: ");
        scanf("%d", &j);
        realizarJogada(j);
    }
    return 0;
}
