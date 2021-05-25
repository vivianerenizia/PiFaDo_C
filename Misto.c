#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* função que cria o baralho e insere na lista*/
void baralho(No **lista)
{
    No *q;

    Baralho cartaPaus[13], cartaOuros[13], cartaCopas[13], cartaEspadas[13];/*cria vetores de cartas separadas pelo naipe*/

    int i, numero1=1, numero2=1, numero3=1, numero4=1;/*numeros das cartas*/

    q=alocarNo();

    /*insere as cartas na lista*/
    for(i=0; i<13; i++)
    {

        strcpy(cartaPaus[i].nome, "Paus");
        cartaPaus[i].num = numero1;
        inserirInicioLista(lista, cartaPaus[i]);
        numero1 ++;
    }
    /*insere as cartas na lista*/
    for(i=0; i<13; i++)
    {

        strcpy(cartaOuros[i].nome, "Ouros");
        cartaOuros[i].num = numero2;
        inserirInicioLista(lista, cartaOuros[i]);
        numero2 ++;
    }
    /*insere as cartas na lista*/
    for(i=0; i<13; i++)
    {

        strcpy(cartaCopas[i].nome, "Copas");
        cartaCopas[i].num = numero3;
        inserirInicioLista(lista, cartaCopas[i]);
        numero3 ++;
    }
    /*insere as cartas na lista*/
    for(i=0; i<13; i++)
    {

        strcpy(cartaEspadas[i].nome, "Espadas");
        cartaEspadas[i].num = numero4;
        inserirInicioLista(lista, cartaEspadas[i]);
        numero4 ++;
    }

}

/*foi utilizado o metodo de ordenação mover pra frente,
para embaralhar as cartas*/
void embaralhar(No** lista)
{
    No* aux;
    No* ant;
    int contador, i, posicao;

    contador=1;

    aux=(*lista);

    while(contador != 20)
    {
        posicao= rand()%(52)+1; /*sorteia um numero aleatório entre 1 a 52*/

        /*verifica se é o primeiro nó*/
        if(posicao == 1)
        {
            contador ++;
        }
        else
        {
            /*verifica se é o ultimo*/
            if(posicao == 52)
            {
                /*anda até o nó*/
                for(i=0; i<52; i++)
                {
                    ant=aux; /*fica um nó antes do aux*/
                    aux=aux->prox; /*anda 53 vezes*/
                }
                ant->prox=NULL; /*o campo prox do nó onde o ant aponta, comça a apontar pra null*/
                aux->prox=(*lista); /*o campo prox do nó onde o aux aponta, aponta pra onde lista aponta*/
                (*lista)=aux; /*lista aponta pra onde aux aponta*/
                contador ++; /*incrementa*/

            }
            else
            {
                /*caso não seja a primeira nem a ultima posição*/

                /*anda até o nó*/
                for(i=0; i<posicao; i++)
                {
                    ant=aux; /*fica um nó antes do aux*/
                    aux=aux->prox; /*anda 53 vezes*/
                }
                ant->prox=aux->prox; /*o campo prox onde ant aponta, passa a apontar pro campo prox onde aux aponta*/
                aux->prox=(*lista); /*o campo prox onde aux aponta, passa a apontar pra onde lista aponta*/
                (*lista)=aux; /*onde lista aponta passa a apontar pra onde aux aponta*/
                contador ++; /*incrementa*/

            }
        }
    }

}

/*transforma lista em deque*/
void montes(Deque* deque, No** lista,Fila* fila)
{
    int i;
    Baralho carta;

    /*remove da lista e passa pra fila, as 52 cartas*/
    for(i=0; i<52; i++)
    {
        carta = removerInicio_Lista(lista);/*remove a primeira carta do baralho na lista*/
        enfileirar(fila, carta);/*coloca a primeira carta da lista na fila*/
    }

    /*remove da fila e passa pra deque, as 52 cartas*/
    for(i=0; i<52; i++)
    {
        carta = desenfileirar(fila);/*remove a primeira carta do baralho na fila*/
        inserirInicioDeque(deque, carta);/*insere a carta no inicio do deque*/
    }

}

/*pego a carta do monte principal e coloco no espaco*/
void espaco(Deque *monte, Deque *espacoE, Baralho carta)
{
    int cont=0, ponto=0;
    NoDeque *aux;

    aux = espacoE->inicio;

    /*verifica caso o espaço estiver vazio*/
    if(dequeVazia(espacoE)==1)
    {
        inserirInicioDeque(espacoE, carta);/*insere no inicio do novo deque*/
    }
    else
    {
        /*caso tenha somente 1 elemento*/
        if(espacoE->inicio == espacoE->fim)
        {
            if(carta.num == (espacoE->inicio)->info.num) /*verifica se o numero da carta que o usuario comprou é igual ao numero da carta que esta no espaço*/
            {
                inserirInicioDeque(espacoE, carta); /*insere a carta no inicio do deque*/
            }
            else
            {
                if(carta.num > (espacoE->inicio)->info.num) /*verifica se o numero da carta que o usuario comprou é maior que numero da carta que esta no espaço*/
                {
                    inserirInicioDeque(espacoE, carta);/*insere a carta no inicio do deque*/
                }
                else
                {
                    if(carta.num < (espacoE->inicio)->info.num) /*verifica se o numero da carta que o usuario comprou é menor que numero da carta que esta no espaço*/
                    {
                        inserirFimDeque(espacoE, carta);/*insere a carta no fim do deque*/
                    }
                }
            }
        }
        else
        {
            /*caso tenha mais de 1 elemento*/

            aux = aux->dir;

            /*se a cada carta adicionada for igual a uma existente, coloca em cima*/
            if(carta.num == (aux->info).num)
            {
                inserirInicioDeque(espacoE, carta);
            }
            else
            {
                if(carta.num == (espacoE->inicio)->info.num)
                {
                    inserirInicioDeque(espacoE, carta);
                }

                if(carta.num == (espacoE->fim)->info.num)
                {
                    inserirInicioDeque(espacoE, carta);
                }
                else
                {
                    /*se a cada carta adicionada for maior a uma existente, coloca em cima*/
                    if(carta.num > (espacoE->inicio)->info.num)
                    {
                        inserirInicioDeque(espacoE, carta);
                    }
                    else
                    {
                        if(carta.num > aux->info.num)
                        {
                            inserirInicioDeque(espacoE, carta);
                        }
                        else
                        {
                            if(carta.num > (espacoE->fim)->info.num)
                            {

                                inserirInicioDeque(espacoE, carta);
                            }
                            else
                            {
                                /*se a cada carta adicionada for menor a uma existente, coloca embaixo*/
                                if(carta.num < (espacoE->inicio)->info.num)
                                {

                                    inserirFimDeque(espacoE, carta);
                                }
                                else
                                {
                                    if(carta.num < (aux->info).num)
                                    {

                                        inserirFimDeque(espacoE, carta);
                                    }
                                    else
                                    {
                                        if(carta.num < (espacoE->fim)->info.num)
                                        {

                                            inserirFimDeque(espacoE, carta);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

/*empilha a carta no espaço extra*/
void espacoExtra(Deque* monte, NoPilha** extra, Baralho carta)
{
    empilharCartas(extra, carta);
}

/*Confere se tem as 3 cartas no espaco*/
int cartasFormadas(Deque *espaco, Baralho carta)
{
    NoDeque *aux;

    /*Caso tenha somente uma carta*/
    if(espaco ->inicio == espaco ->fim)
    {
        return 0;
    }
    else
    {
        /*Caso tenha mais de uma carta*/
        aux = (espaco ->fim) ->esque;
        /*Caso tenha duas cartas*/
        if(aux == espaco ->inicio)
        {
            return 0;
        }
        else
        {
            /*caso tenha tres cartas*/
            if(aux->esque == espaco ->inicio)
            {
                return 1;
            }
        }
    }
}

int menu(Deque *monte, Deque *e1, Deque *e2, Deque *e3,Deque *e4, NoPilha **extra, Baralho carta)
{
    int opcao=0, esp=0, ponto=0;

    printf("O que voce deseja fazer? \n");
    printf("1 - Colocar em um dos espacos (E1, E2, E3 ou E4).\n");
    printf("2 - Colocar no espaco extra.\n");
    printf("3 - Descartar, colocando no monte\n\n");

    printf("Insira a opcao desejada: ");
    scanf("%d", &opcao);

    switch(opcao)
    {
    case 1:
        /*pergunta em qual espaco ele deseja colocar a carta*/
        printf("Deseja inserir no: \n");
        printf("1- E1\n");
        printf("2- E2\n");
        printf("3- E3\n");
        printf("4- E4\n\n");

        printf("Insira: ");
        scanf("%d", &esp);

        if(esp == 1)
        {
            espaco(monte, e1, carta); /*tira a carta do monte e coloca no espaco*/
            printf("Inserido no espaco 1!!\n\n");
            Sleep(1000);
            /*verifica se tem tres cartas no espaco*/
            if(cartasFormadas(e1, carta) == 1)
            {
                imprimirClassica(e1);/*imprime as cartas e exclui*/
                ponto++; /*contabiliza 1 ponto*/
                printf("\n\t-> 1 ponto marcado!!\n");
                Sleep(1000);
            }
        }
        else if(esp == 2)
        {
            espaco(monte, e2, carta);
            printf("Inserido no espaco 2!!\n\n");
            Sleep(1000);
            if(cartasFormadas(e2, carta) == 1)
            {
                imprimirClassica(e2);
                ponto++;
                printf("\n\t-> 1 ponto marcado!!\n");
                Sleep(1000);
            }
        }
        else
        {
            if(esp == 3)
            {
                espaco(monte, e3, carta);
                printf("Inserido no espaco 3!!\n\n");
                Sleep(1000);
                if(cartasFormadas(e3, carta) == 1)
                {
                    imprimirClassica(e3);
                    ponto++;
                    printf("\n\t-> 1 ponto marcado!!\n");
                    Sleep(1000);
                }
            }
            else
            {
                espaco(monte, e4, carta);
                printf("Inserido no espaco 4!!\n\n");
                Sleep(1000);
                if(cartasFormadas(e4, carta) == 1)
                {
                    imprimirClassica(e4);
                    ponto++;
                    printf("\n\t-> 1 ponto marcado!!\n");
                    Sleep(1000);
                }
            }
        }
        return ponto;

        break;

    case 2:
        espacoExtra(monte, extra, carta); /*tira a carta do monte e coloca no extra*/
        return ponto;

        break;

    case 3:
        descartaMonte(monte, carta);/*tira a carta do monte e coloca no monte*/
        return ponto;

        break;
    }
}

/*imprime as cartas dos espacos*/
void mostrarEspacos(Deque *e1,Deque *e2,Deque *e3,Deque *e4)
{
    int op=0;
    printf("Deseja ver as cartas que esta nos espacos antes de comprar?\n");
    printf("1 - SIM\n");
    printf("2 - NAO\n");
    scanf("%d", &op);
    if(op == 1)
    {
        printf("1 - Ver cartas do espaco 1\n");
        printf("2 - Ver cartas do espaco 2\n");
        printf("3 - Ver cartas do espaco 3\n");
        printf("4 - Ver cartas do espaco 4\n");
        printf("Insira a opcao: ");
        scanf("%d", &op);
        if(op == 1)
        {
            imprimeDeque(e1);
        }
        if(op == 2)
        {
            imprimeDeque(e2);
        }
        if(op == 3)
        {
            imprimeDeque(e3);
        }
        if(op == 4)
        {
            imprimeDeque(e4);
        }
    }
}
