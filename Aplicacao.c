
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#include "Lista.c"
#include "Fila.c"
#include "Pilha.c"
#include "Deque.c"
#include "Misto.c"


int main()
{
    No *ptrListaJ1, *ptrListaJ2, *q;

    Fila *filaJ1, *filaJ2;

    NoPilha *extra1, *extra2; /*espacos extra*/

    Deque *monte1, *monte2;
    Deque *e1J1, *e2J1, *e3J1, *e4J1;/*espacos do jogador1*/
    Deque *e1J2, *e2J2, *e3J2, *e4J2;/*espacos do jogador2*/

    Baralho carta;

    int vez=0, cont=0, opcao=0, esp=0;
    int cont1=0, cont2=0;
    int pontoJ1=0, pontoJ2=0;

    /*JOGADOR 1*/

    inic(&ptrListaJ1);

    q= alocarNo();
    q;

    baralho(&ptrListaJ1); /*chama o baralho para inserir as cartas na lista*/
    embaralhar(&ptrListaJ1); /*embaralha as cartas do baralho na lista*/


    filaJ1 = (Fila*) malloc(sizeof(Fila));

    inicFila(filaJ1);

    monte1 = (Deque*) malloc(sizeof(Deque));

    inicDeque(monte1);

    montes(monte1, &ptrListaJ1, filaJ1);/*coloca as cartas no monte 1*/

    extra1 = alocarNoPilha();
    inicNoPilha(&extra1);

    /*cria os espacos*/

    e1J1=(Deque*) malloc(sizeof(Deque));
    inicDeque(e1J1);

    e2J1=(Deque*) malloc(sizeof(Deque));
    inicDeque(e2J1);

    e3J1=(Deque*) malloc(sizeof(Deque));
    inicDeque(e3J1);

    e4J1=(Deque*) malloc(sizeof(Deque));
    inicDeque(e4J1);

    /*JOGADOR 2*/

    inic(&ptrListaJ2);

    q= alocarNo();
    q;

    baralho(&ptrListaJ2); /*chama o baralho para inserir as cartas na lista*/

    embaralhar(&ptrListaJ2); /*embaralha as cartas do baralho na lista*/

    filaJ2 = (Fila*) malloc(sizeof(Fila));

    inicFila(filaJ2);

    monte2 = (Deque*) malloc(sizeof(Deque));

    inicDeque(monte2);

    montes(monte2, &ptrListaJ2, filaJ2);/*coloca as cartas no monte 2*/

    extra2 = alocarNoPilha();
    inicNoPilha(&extra2);

    /*cria os espacos*/

    e1J2=(Deque*) malloc(sizeof(Deque));
    inicDeque(e1J2);

    e2J2=(Deque*) malloc(sizeof(Deque));
    inicDeque(e2J2);

    e3J2=(Deque*) malloc(sizeof(Deque));
    inicDeque(e3J2);

    e4J2=(Deque*) malloc(sizeof(Deque));
    inicDeque(e4J2);

    printf("\t****************************\n\t*          PiFaDo          *\n\t****************************\n\t*    Welcome to the game.  *\n\t*        Boa sorte!        *\n\t****************************\n\t*       Emilly - 5978      *\n\t*      Gabriel - 6020      *\n\t*      Viviane - 5209      *\n\t****************************\n");
    printf("\t-> Carregando...");
    Sleep(5000);
    system("cls || clear");
    do
    {
        /*verifica se é a PRIMEIRA rodada*/
        if(vez == 0)
        {
            if(vez %2 == 0)  /*jogador 1*/
            {
                printf("\t********* JOGADOR 1 ********* \n\t-> Score: %d\n", pontoJ1);
                carta = compraMonte(monte1); /*compra a carta do monte*/
                printf("\t-> Carta da rodada: %d %s\n\n", carta.num, carta.nome);
                pontoJ1 = pontoJ1 + menu(monte1, e1J1, e2J1, e3J1, e4J1, &extra1, carta); /*chama a função menu e incrementa no ponto se o espaço tiver 3 cartas*/
                vez++;
            }

            if(vez %2 != 0)  /*JOGADOR 2*/
            {
                system("cls || clear");
                printf("\t********* JOGADOR 2 ********* \n\t-> Score: %d\n", pontoJ2);
                carta = compraMonte(monte2); /*compra a carta do monte*/
                printf("\t-> Carta da rodada: %d %s\n\n", carta.num, carta.nome);

                pontoJ2 = pontoJ2 + menu(monte2, e1J2, e2J2, e3J2, e4J2, &extra2, carta); /*chama a função menu e incrementa no ponto se o espaço tiver 3 cartas*/
                vez++;

            }
        }
        /*ACABOU PRIMEIRA RODADA*/

        /*demais rodadas*/
        if(vez >= 2)
        {
            system("cls || clear");
            if(vez %2 == 0) /*JOGADOR 1*/
            {
                int compra;

                printf("\t********* JOGADOR 1 ********* \n\t-> Score: %d\n\n", pontoJ1);
                mostrarEspacos(e1J1, e2J1, e3J1, e4J1); /*caso o usuario queira ver as cartas dos espacos*/
                printf("Deseja comprar de onde?\n");
                printf("1. Monte\n");
                printf("2. Extra\n");
                printf("Insira: ");
                scanf("%d", &compra);

                if(compra == 1)
                {
                    carta = compraMonte(monte1); /*compra a carta do monte*/
                    printf("\n\t-> Carta da rodada: %d %s\n\n", carta.num, carta.nome);
                    pontoJ1 = pontoJ1 + menu(monte1, e1J1, e2J1, e3J1, e4J1, &extra1, carta);/*chama a função menu e incrementa no ponto se o espaço tiver 3 cartas*/
                    vez ++;
                }


                else
                {
                    /*verifica se o extra esta vazio*/
                    if (listaVaziaPilha(extra1)==1)
                    {
                        printf("Espaco extra vazio\n");
                        Sleep(1000);
                    }
                    else
                    {
                        carta = compraExtra(&extra1);
                        printf("\n\t-> Carta da rodada: %d %s\n\n", carta.num, carta.nome);

                        pontoJ1 = pontoJ1 + menu(monte1, e1J1, e2J1, e3J1, e4J1, &extra1, carta);/*chama a função menu e incrementa no ponto se o espaço tiver 3 cartas*/

                        vez ++;
                    }
                }
            }

            else
            {
                if(vez %2 != 0) /*JOGADOR 2*/
                {
                    system("cls || clear");
                    int compra;
                    printf("\t********* JOGADOR 2 ********* \n\t-> Score: %d\n\n", pontoJ2);
                    mostrarEspacos(e1J2, e2J2, e3J2, e4J2);
                    printf("Deseja comprar de onde?\n");
                    printf("1. Monte\n");
                    printf("2. Extra\n");

                    printf("Insira: ");
                    scanf("%d", &compra);

                    if(compra == 1)
                    {
                        carta = compraMonte(monte2); /*compra a carta do monte*/
                        printf("\n\t-> Carta da rodada: %d %s\n\n", carta.num, carta.nome);
                        pontoJ2 = pontoJ2 + menu(monte2, e1J2, e2J2, e3J2, e4J2, &extra2, carta);/*chama a função menu e incrementa no ponto se o espaço tiver 3 cartas*/
                        vez++;
                    }
                    else
                    {
                        /*verifica se o extra esta vazio*/
                        if (listaVaziaPilha(extra1)==1)
                        {

                            printf("Este espaco extra esta vazio.\n");
                            Sleep(1000);
                        }
                        else
                        {
                            carta = compraExtra(&extra1);
                            printf("\n\t-> Carta da rodada: %d %s\n\n", carta.num, carta.nome);

                            pontoJ2 = pontoJ2 + menu(monte2, e1J2, e2J2, e3J2, e4J2, &extra2, carta);/*chama a função menu e incrementa no ponto se o espaço tiver 3 cartas*/
                            vez++;
                        }
                    }
                }
            }
            system("cls || clear");
        }
    }
    while(pontoJ1 != 5 && pontoJ2 != 5);  /*sai do while quando algum jogador vencer*/


    if(pontoJ1 == 5)
    {
        printf("\t****************************\n\t*          VENCEU!         *\n\t****************************\n\t*   Parabens, Jogador 1!   *\n\t****************************\n\t*    PLACAR: J1 %d x %d J2   *\n\t****************************\n", pontoJ1, pontoJ2);
        exit(1);

    }
    else if(pontoJ2 == 5)
    {
        printf("\t****************************\n\t*          VENCEU!         *\n\t****************************\n\t*   Parabens, Jogador 2!   *\n\t****************************\n\t*    PLACAR: J1 %d x %d J2   *\n\t****************************\n", pontoJ1, pontoJ2);
        exit(1);
    }

    /*desaloca*/

    free(q);
    free(filaJ1);
    free(monte1);
    free(&extra1);
    free(e1J1);
    free(e2J1);
    free(e3J1);
    free(e4J1);

    free(q);
    free(filaJ2);
    free(monte2);
    free(&extra2);
    free(e1J2);
    free(e2J2);
    free(e3J2);
    free(e4J2);

    return 0;
}


