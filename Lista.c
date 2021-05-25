#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*cria uma estrutura do tipo baralho*/
typedef struct sBaralho
{
    char nome[30];
    int num;
} Baralho;

/*cria uma estrutura do tipo nó*/
typedef struct sNo
{
    Baralho info;
    struct sNo* prox;
} No;

/*inicializa a lista*/
void inic(No **lista)
{
    *lista = NULL;
}

/*aloca os nós para a lista*/
No* alocarNo()
{
    return (No*) malloc(sizeof(No));
}

/*desaloca os nós para a lista*/
void desalocarNo(No* q)
{
    free(q);
}

/*verifica se a pilha e lista estão vazias*/
int listaVazia(No* lista)
{
    if(lista == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*insere no inicio da lista*/
void inserirInicioLista(No** lista, Baralho elemento)
{
    No* novo;

    novo = alocarNo();

    if(novo != NULL)
    {
        /*inicializa os campos do novo elemento*/
        strcpy(novo->info.nome, elemento.nome);
        novo->info.num = elemento.num;
        novo->prox=*lista;/*o campo prox aponta pro primeiro elemento da lista*/

        *lista = novo;/*lista aponta pro primeiro elemento*/
    }
    else
    {
        printf("erro na alocacao\n");
    }
}

/*remove o primeiro nó da lista*/
Baralho removerInicio_Lista(No** lista)
{
    No* aux;
    Baralho x;

    aux = *lista;
    x=aux->info;

    /*verifica se a lista esta vazia*/
    if(!listaVazia(*lista))
    {
        *lista = aux->prox; /*lista aponta pro segundo nó da lista*/
        desalocarNo(aux); /*exclui o primeiro nó*/
        return x; /*retorna a carta que foi excluida*/
    }
    else
    {
        printf("\n erro, lista vazia");
        return x; /*retorna a carta que foi excluida*/
    }
}

void imprimeLista(No* lista)
{
    if(listaVazia(lista))
    {
        printf("A lista esta vazia\n\n");
    }
    else
    {
        No* aux;
        aux = lista;
        while(aux != NULL)
        {
            printf("%d %s\n", (aux)->info.num, (aux)->info.nome);
            aux = aux->prox;
        }
    }
    printf("\n");
}
