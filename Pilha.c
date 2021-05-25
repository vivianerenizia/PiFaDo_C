#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*cria uma estrutura do tipo nóPilha*/
typedef struct sNoPilha
{
    Baralho info;
    struct sNoPilha* prox;
} NoPilha;

/*aloca os nós para a lista*/
NoPilha* alocarNoPilha()
{
    return (NoPilha*) malloc(sizeof(NoPilha));
}

void inicNoPilha(NoPilha **pilha)
{
    *pilha = NULL;
}

/*desaloca os nós para a lista*/
void desalocarNoPilha(NoPilha* q)
{
    free(q);
}

/*verifica se a pilha esta vazia*/
int listaVaziaPilha(NoPilha* ptrp)
{
    if(ptrp == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*insere no fim da pilha*/
void empilharCartas(NoPilha **topo, Baralho elemento)
{
    NoPilha *novo;
    novo = alocarNoPilha();

    if(novo != NULL)
    {
        /*inicializa os campos*/
        strcpy(novo->info.nome, elemento.nome);
        novo->info.num = elemento.num;
        novo->prox = *topo; /*o campo prox do novo aponta pro nó que o topo aponta*/
        *topo = novo; /*o topo aponta pro novo*/
    }
    else
    {
        printf("erro na alocacao\n");
        return;
    }
}



/*tira a ultima carta do espaço extra(desempilhar)*/
Baralho compraExtra(NoPilha** topo)
{
    NoPilha* aux;
    Baralho carta;
    aux = *topo;

    carta = aux->info;

    /*verifica se a lista não esta vazia*/
    if(!listaVaziaPilha(*topo))
    {
        *topo = (*topo)->prox; /*o topo aponta pra segunda carta da pilha*/
        aux->prox = NULL; /*o prox do nó que esta no topo recebe NULL*/
        desalocarNoPilha(aux); /*exclui a carta que estava no topo*/
        return carta;  /*retorna a carta que foi excluida*/
    }
    else
    {
        printf("o extra esta vazio!\n");
    }
}


