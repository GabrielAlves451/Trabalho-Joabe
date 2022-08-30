#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define coberto 0
#define descoberto 1
// TABULEIRO
clock_t start, end;
double  tempo;
int jogoF[4][4]=
{
    5,2,2,3,
    5,6,7,8,
    5,2,2,3,
    5,6,7,8
};
int jogoCobertoF[4][4]=
{
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};
int jogoM[4][5]=
{
    5,2,2,3,4,
    5,6,7,8,9,
    5,2,2,3,4,
    5,6,7,8,9
};
// PARA SABER QUAIS JÁ FORAM DESCOBERTOS
int jogoCobertoM[4][5]=
{
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0
};
int jogoD[4][6]=
{
    5,2,2,3,4,6,
    5,6,7,8,9,6,
    5,2,2,3,4,7,
    5,6,7,8,9,7
};
int jogoCobertoD[4][6]=
{
    0,0,0,0,0,0,
    0,0,0,0,0,0,
    0,0,0,0,0,0,
    0,0,0,0,0,0
};

// PROTÓTIPOS DAS FUNÇÕES
void monta(); // Imprime o tabuleiro
int analisa(); // Analiza se todas as peças foram descobertas
int menu();
int jogar();
int validaCoord();


int main(){
    menu();
}

int menu(){
    char tecla;

    printf("\n ____    ____       _       ____  ____     _____   ___   ____  _____   ______");
    printf("\n|_   \\  /   _|     / \\     |_   ||   _|   |_   _|.'   `.|_   \\|_   _|.' ___  |");
    printf("\n  |   \\/   |      / _ \\      | |__| |       | | /  .-.  \\ |   \\ | | / .'   \\_|");
    printf("\n  | |\\  /| |     / ___ \\     |  __  |   _   | | | |   | | | |\\ \\| | | |   ____");
    printf("\n _| |_\\/_| |_  _/ /   \\ \\_  _| |  | |_ | |__' | \\  `-'  /_| |_\\   |_\\ `.___]  |");
    printf("\n|_____||_____||____| |____||____||____|`.____.'  `.___.'|_____|\\____|`._____.'\n");


    printf("Pressione a tecla para escolher o modo:\n");
    printf("1 - Jogar\n");
    printf("2 - Ranking\n");
    printf("3 - Creditos\n");
    printf("4 - Sair");

    tecla = getch();
    if(tecla == 49){
        jogar();
    }
    if(tecla == 50){
        ranking();
    }
    if(tecla == 51){
        creditos();
    }
}
int jogar(){
    int l, c, l2, c2;
    int gameover=0;
    start = clock();
    while(!gameover){
            validaCoord(&l,&c);
            validaCoord(&l2,&c2);
            system("cls");
            monta();
            if(jogoM[l-1][c-1] != jogoM[l2-1][c2-1]){
                printf("Errou!\n");
                jogoCobertoM[l-1][c-1]=coberto;
                jogoCobertoM[l2-1][c2-1]=coberto;
            }
            else printf("Boa!\n");
            Sleep(1000);
            gameover = analisa();
        }
    end = clock();
    tempo =((double)(end - start)) / CLOCKS_PER_SEC;;
    printf("Tempo para ganhar: %f", tempo);
    sleep(2000);
    system("cls");
    exit(2);
    return 0;
}
int ranking(){
    printf("ranking pegando");
}
int creditos(){
    system("cls");
    printf("Progamadores: \n");
    printf("André Luís Bastos de Azevedo Silveira\nBreno Henrique da Silva Peixoto\nGabriel Alves Oliveira Ribeiro\nPaulo Francisco da Silva");
}
void monta(){
    int l, c;
    printf("  1 2 3 4 5\n");
    for(l=0; l<4; l++){
            printf("%d ",l+1);
        for(c=0; c<5; c++){
            if(jogoCobertoM[l][c]==descoberto)
                printf("%d|",jogoM[l][c]);
            else if(l<3) printf("_|");
            else printf(" |");
        }
        printf("\n");
    }
    printf("\n\n");
}
// ANALISA O JOGO
int analisa(){
    int qt, l, c;
    for(l=0; l<4; l++) for(c=0; c<5; c++) if(jogoCobertoM[l][c]==descoberto) qt++;
    if(qt==20) return 1;
    return 0;
}
int validaCoord(int* linha,int* coluna){
    int row, column;
    clear: system("cls");
    monta();
    printf("Digite a linha e a coluna, respectivamente: ");
    scanf("%d %d", &row, &column);
    if(row>4 || row<1 || column>5 || column<1){
        printf("Numeros invalidos!! Digite e 1 a 5 para linha\ne de 1 a 4 para a coluna.\n");
        system("pause");
        goto clear;
            }
    if(jogoCobertoM[row-1][column-1]==descoberto){
        printf("Ops... Lugar ja descoberto.\n");
        system("pause");
        goto clear;
            }
    jogoCobertoM[row-1][column-1]=descoberto;
    *linha = row;
    *coluna = column;
}
