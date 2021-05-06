#include "BBT.c"

int main()
{
    No *ptrListaJ1, *ptrListaJ2, *q;
    Fila *filaJ1, *filaJ2;
    Deque *monte1, *monte2;
    Baralho compra;
    int vez=0, cont=0, opcao=0;

    /*JOGADOR 1*/

    inic(&ptrListaJ1);

    q= alocarNo();
    q;

    baralho(&ptrListaJ1);
    embaralhar(&ptrListaJ1);


    filaJ1 = (Fila*) malloc(sizeof(Fila));

    inicFila(filaJ1);

    monte1 = (Deque*) malloc(sizeof(Deque));

    inicDeque(monte1);

    montes(monte1, &ptrListaJ1, filaJ1);


    /*imprimeDeque(monte1);
    printf("\n\n\n\n");*/

    /*JOGADOR 2*/

    inic(&ptrListaJ2);

    q= alocarNo();
    q;

    baralho(&ptrListaJ2);

    embaralhar(&ptrListaJ2);

    /*imprimeLista(ptrListaJ2);*/

    filaJ2 = (Fila*) malloc(sizeof(Fila));

    inicFila(filaJ2);

    monte2 = (Deque*) malloc(sizeof(Deque));

    inicDeque(monte2);

    montes(monte2, &ptrListaJ2, filaJ2);

    /*imprimeDeque(monte2);*/


    do
    {
        if(vez == 0)
        {
            if(vez %2 == 0)  /*jogador 1*/
            {
                compra = compraMonte(ptrDequeJ1);
                printf("****** JOGADOR 1***********");
                printf("O que voce deseja fazer? \n");
                printf("1 - Colocar em um dos espaços (E1, E2, E3 ou E4).\n");
                printf("2 - Colocar no espaco extra.\n");
                printf("3 - Descartar, colocando no monte\n\n");

                printf("insira a opcao desejada: ");
                scanf("%d", &opcao);
                switch(opcao)
                {
                case 1:
                    int espaco;
                    espaco = 0;

                    printf("Deseja inserir no: \n");
                    printf("1- E1\n");
                    printf("2- E2\n");
                    printf("3- E3\n");
                    printf("4- E4\n\n");

                    printf("insira: ");
                    scanf("%d", &espaco);

                }
            }
        }
    }
    free(filaJ2);
    free(ptrDequeJ2);

    free(q);
    free(filaJ1);
    free(ptrDequeJ1);



    return 0;
}



