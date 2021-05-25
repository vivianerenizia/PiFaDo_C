#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*cria uma estrutura do tipo noDeque para o deque*/
typedef struct sNoDeque
{
    Baralho info;
    struct sNoDeque *esque;
    struct sNoDeque *dir;
} NoDeque;

/*cria uma estrutura do tipo deque que tem variaveis do tipo NoDeque para o deque*/
typedef struct sDeque
{
    NoDeque* inicio;
    NoDeque* fim;
} Deque;

/*inicializa o deque*/
void inicDeque(Deque *ptrd)
{
    ptrd->inicio = NULL;
    ptrd->fim = NULL;
}

/*aloca os nós do deque*/
NoDeque* alocarNoDeque()
{
    return (NoDeque*) malloc(sizeof(NoDeque));
}

/*desaloca os nós do deque*/
void desalocarNoDeque(NoDeque* q)
{
    free(q);
}

/*verifica se o deque esta vazia*/
int dequeVazia(Deque *ptrd)
{
    if(ptrd ->inicio == NULL && ptrd ->fim == NULL)
    {
        return 1;
    }
    return 0;
}

/*insere no final do deque*/
void inserirFimDeque(Deque *ptrd, Baralho elemento)
{
    NoDeque *novo;

    novo = alocarNoDeque();

    if(novo!=NULL)
    {
        /*inicializa os campos do novo elemento*/
        strcpy(novo->info.nome, elemento.nome);
        novo->info.num = elemento.num;
        novo->dir=NULL;

        /*verifica se não tem nada na deque*/
        if(dequeVazia(ptrd)==1)
        {
            ptrd->inicio=novo; /* o ponteiro inicio aponta pro novo*/
            ptrd->fim=novo; /*o ponteiro fim aponta pro novo*/
        }
        else
        {
            (ptrd->fim)->dir = novo; /*o campo dir do ulimo nó aponta pro novo*/
            novo->esque=ptrd->fim; /*o campo esque do novo aponta pro ultimo nó*/
            ptrd->fim=novo; /*o ponteiro fim aponta pro novo*/
        }
    }
    else
    {
        printf("Erro na alocacao\n\n");
    }
}

/*Insere no inicio da deque*/
void inserirInicioDeque(Deque *ptrd, Baralho elemento)
{
    NoDeque *novo;

    novo = alocarNoDeque();

    if(novo !=NULL)
    {
        /*inicializa os campos do novo elemento*/
        strcpy(novo->info.nome, elemento.nome);
        novo->info.num = elemento.num;

        /*verifica se a deque esta vazia*/
        if(dequeVazia(ptrd)==1)
        {
            ptrd->inicio = novo; /*o ponteiro do inicio aponta pro novo*/
            ptrd->fim = novo; /*o ponteiro do fim aponta pro novo*/
        }
        else
        {
            (ptrd->inicio)->esque = novo; /*o campo esque do primeiro no aponta pro novo*/
            novo->dir = ptrd->inicio; /*o campo dir do novo aponta pro primeiro nó*/
            ptrd->inicio = novo; /*o ponteiro do inicio aponta pro novo*/
        }
    }
    else
    {
        printf("erro na alocacao\n");
    }

}

/*remove a primeira carta do baralho*/
Baralho compraMonte(Deque *ptrd)
{
    NoDeque *aux;
    Baralho x;

    /*verifica se a deque esta vazia*/
    if(dequeVazia(ptrd)==1)
    {
        printf("Deque vazia\n");
        return x;
    }
    else
    {
        aux = (ptrd->inicio)->dir; /*aux recebe o segundo nó da deque*/
        x= (ptrd->inicio)->info; /* x recebe a informação da primeira carta*/
        desalocarNoDeque(ptrd->inicio); /*desaloca a primeira carta da deque*/
        ptrd->inicio = aux; /*o ponteiro inicio aponta pra segunda carta*/

        /*verifica se o ponteiro inicio não esta apontando pra null*/
        if(ptrd->inicio != NULL)
        {
            (ptrd->inicio)->esque = NULL;/*o campo esque do nó que o inicio aponta recebe null*/
        }
        else
        {
            ptrd->fim=NULL; /*ponteiro fim recebe null*/
        }

    }
    return x; /*retorna a carta que foi excluida da deque*/
}

/*coloca a carta no monte novamente depois de descartada*/
void descartaMonte(Deque *monte, Baralho carta)
{
    inserirFimDeque(monte, carta);
}

void imprimeDeque(Deque *ptrd)
{
    NoDeque* aux;

    if(dequeVazia(ptrd)==1)
    {
        printf("O espaco esta vazio\n");
    }
    else
    {
        if(ptrd->inicio == ptrd->fim)
        {

            printf("%d %s\n", (ptrd->inicio)->info.num, (ptrd->inicio)->info.nome);

        }
        else
        {

            aux = ptrd->inicio;

            do
            {
                printf("%d %s\n", (aux)->info.num, (aux)->info.nome);
                aux= aux->dir;
            }
            while(aux != ptrd->fim);

            printf("%d %s\n", (ptrd->fim)->info.num, (ptrd->fim)->info.nome);

        }
    }
}

/*Mostra as cartas em sequencia e exclui em seguida*/
void imprimirClassica(Deque *ptrd)
{
    NoDeque *aux;
    aux = ptrd ->inicio;

    if(aux != NULL)
    {

        if(!dequeVazia(ptrd))
        {
            printf("%d %s\n", (aux)->info.num, (aux)->info.nome);
            do
            {
                aux = aux ->dir;
                printf("%d %s\n", (aux)->info.num, (aux)->info.nome);
                compraMonte(ptrd);
            }
            while(aux != ptrd ->fim);

            ptrd->inicio =NULL;
            ptrd->fim = NULL;
        }
        else
        {
            printf("A lista esta vazia");
        }
    }
    else
    {
        printf("Ocorreu um erro ao alocar o no");
    }
}

