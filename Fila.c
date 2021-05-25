#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*cria uma estrutura do tipo nó*/
typedef struct sNoFila
{
    Baralho info;
    struct sNoFila* prox;
} NoFila;

/*cria uma estrutura do tipo fila que contem atributos do tipo no*/
typedef struct sFila
{
    NoFila* inicio;
    NoFila* fim;
} Fila;

/*aloca na fila*/
NoFila* alocarNoFila()
{
    return (NoFila*) malloc(sizeof(NoFila));
}

/*desaloca os nós para a lista*/
void desalocarNoFila(NoFila* q)
{
    free(q);
}

/*inicializa a fila*/
void inicFila(Fila *ptrf)
{
    ptrf->inicio = NULL;
    ptrf->fim = NULL;
}

/*verifica se a fila esta vazia*/
int filaVazia(Fila *ptrf)
{
    if(ptrf ->inicio == NULL && ptrf ->fim == NULL)
    {
        return 1;
    }
    return 0;
}

/*insere no fim da fila*/
void enfileirar(Fila *ptrf, Baralho elemento)
{
    NoFila* novo;
    novo = alocarNoFila();

    if(novo!= NULL)
    {
        /*inicializa os campos*/
        strcpy(novo->info.nome, elemento.nome);
        novo->info.num = elemento.num;
        novo->prox = NULL; /*o campo prox do novo aponta pra null*/

        /*verifica se a fila esta vazia*/
        if(filaVazia(ptrf)==1)
        {
            ptrf->inicio=novo; /*ponteiro inicio aponta pro novo*/
            ptrf->fim=novo; /*ponteiro fim aponta pro novo*/
        }
        else
        {
            (ptrf->fim)->prox = novo; /*o campo prox do ultimo nó aponta pro novo*/
            ptrf->fim = novo;/*o ponteiro fim aponta pro novo*/
        }
    }
    else
    {
        printf("\nErro alocacao\n");
    }
}

/* remove o primeiro nó da fila*/
Baralho desenfileirar(Fila *ptrf)
{
    Baralho carta;
    NoFila *aux;

    aux = ptrf->inicio;
    carta = aux->info;

    /*verifica se a fila esta vazia*/
    if(filaVazia(ptrf)==1)
    {
        printf("fila vazia\n");
        return;
    }
    else
    {
        ptrf->inicio = (ptrf->inicio)->prox; /*o ponteiro do inicio aponta pro segundo nó*/
        desalocarNoFila(aux); /*desaloca o primeiro nó da fila*/
        return carta; /*retorna a carta que foi excluida da fila*/
    }
}


void exibirFila(Fila* ptrf)
{
    NoFila* aux;

    aux = ptrf->inicio;

    if(filaVazia(ptrf)==1)
    {
        printf("lista vazia\n");
    }
    else
    {
        if(aux->prox != NULL)
        {
            printf("%d %s\n", (aux)->info.num, (aux)->info.nome);

            while(aux->prox != NULL)
            {
                aux= aux-> prox;
                printf("%d %s\n", (aux)->info.num, (aux)->info.nome);
            }
        }
    }
}
