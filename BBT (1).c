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

/*cria uma estrutura do tipo fila que contem atributos do tipo no*/
typedef struct sFila
{
    No* inicio;
    No* fim;

}Fila;

/*cria uma estrutura do tipo noDeque para o deque*/
typedef struct sNoDeque
{
    Baralho info;
    struct sNoDeque* esque;
    struct sNoDeque* dir;
} NoDeque;

/*cria uma estrutura do tipo deque que tem variaveis do tipo NoDeque para o deque*/
typedef struct sDeque
{
    NoDeque* inicio;
    NoDeque* fim;
} Deque;

/*inicializa a lista*/
void inic(No **lista)
{
    *lista = NULL;
}

/*inicializa a fila*/
void inicFila(Fila *ptrf)
{
    ptrf->inicio = NULL;
    ptrf->fim = NULL;
}

/*inicializa o deque*/
void inicDeque(Deque *ptrd)
{
    ptrd->inicio = NULL;
    ptrd->fim = NULL;
}


/*aloca os nós para a lista*/
No* alocarNo()
{
    return (No*) malloc(sizeof(No));
}

Fila* alocarNoFila()
{
    return (Fila*) malloc(sizeof(Fila));
}

/*aloca os nós do deque*/
NoDeque* alocarNoDeque()
{
    return (NoDeque*) malloc(sizeof(NoDeque));
}

/*desaloca os nós para a lista*/
void desalocarNo(No* q)
{
    free(q);
}

/*desaloca os nós do deque*/
void desalocarNoDeque(NoDeque* q)
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

/*verifica se o deque esta vazia*/
int dequeVazia(Deque *ptrd)
{
    if(ptrd ->inicio == NULL && ptrd ->fim == NULL)
    {
        return 1;
    }
    return 0;
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

/*insere no fim da fila*/
void enfileirar(Fila *ptrf, Baralho elemento){
    No* novo;
    novo = alocarNo();

    if(novo!= NULL){
        /*inicializa os campos*/
        strcpy(novo->info.nome, elemento.nome);
        novo->info.num = elemento.num;
        novo->prox = NULL; /*o campo prox do novo aponta pra null*/

        /*verifica se a fila esta vazia*/
        if(filaVazia(ptrf)==1){
            ptrf->inicio=novo; /*ponteiro inicio aponta pro novo*/
            ptrf->fim=novo; /*ponteiro fim aponta pro novo*/
        }else{
            (ptrf->fim)->prox = novo; /*o campo prox do ultimo nó aponta pro novo*/
            ptrf->fim = novo;/*o ponteiro fim aponta pro novo*/
        }
    }
    else{
        printf("\nErro alocacao\n");
    }
}

/* remove o primeiro nó da fila*/
Baralho desenfileirar(Fila *ptrf){
    Baralho carta;
    No *aux;

    aux= ptrf->inicio;
    carta = aux->info;

    /*verifica se a fila esta vazia*/
    if(filaVazia(ptrf)==1){
        printf("fila vazia\n");
        return;
    }else{
        ptrf->inicio = (ptrf->inicio)->prox; /*o ponteiro do inicio aponta pro segundo nó*/
        desalocarNo(aux); /*desaloca o primeiro nó da fila*/
        return carta; /*retorna a carta que foi excluida da fila*/
    }
}

/*insere no final do deque*/
void inserirFimDeque(Deque *ptrd, Baralho elemento)
{
    NoDeque* novo;

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
    NoDeque* novo;

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
    NoDeque* aux;
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

/*insere no fim da pilha*/
void empilharCartas(No **topo, Baralho elemento)
{
    No *novo;
    novo = alocarNo();

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

/*tira a ultima carta do espaço extra(desempilha)*/
Baralho compraExtra(No** topo)
{
    No* aux;
    Baralho carta;
    aux = *topo;

    carta = aux->info;

    /*verifica se a lista não esta vazia*/
    if(!listaVazia(*topo))
    {
        *topo = (*topo)->prox; /*o topo aponta pra segunda carta da pilha*/
        aux->prox = NULL; /*o prox do nó que esta no topo recebe NULL*/
        desalocarNo(aux); /*exclui a carta que estava no topo*/
        return carta;  /*retorna a carta que foi excluida*/
    }
    else{
        printf("o extra esta vazio!\n");
    }
}

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
    for(i=0; i<52; i++){
        carta = desenfileirar(fila);/*remove a primeira carta do baralho na fila*/
        inserirInicioDeque(deque, carta);/*insere a carta no inicio do deque*/
    }

}


/*pego a carta do monte principal e coloco no espaco*/
void espaco(Deque *monte, Deque *espacoE, Baralho carta)
{
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
        if(espacoE->inicio == espacoE->fim){
            if(carta.num == (espacoE->inicio)->info.num){/*verifica se o numero da carta que o usuario comprou é igual ao numero da carta que esta no espaço*/
               inserirInicioDeque(espacoE, carta); /*insere a carta no inicio do deque*/
            }else{
                if(carta.num > (espacoE->inicio)->info.num){/*verifica se o numero da carta que o usuario comprou é maior que numero da carta que esta no espaço*/
                   inserirInicioDeque(espacoE, carta);/*insere a carta no inicio do deque*/
                }else{
                   if(carta.num < (espacoE->inicio)->info.num){/*verifica se o numero da carta que o usuario comprou é menor que numero da carta que esta no espaço*/
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
                if(carta.num == (espacoE->inicio)->info.num){
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
void espacoExtra(Deque* monte, No** extra, Baralho carta){

    empilharCartas(extra, carta);
}

/*coloca a carta no monte novamente depois de descartada*/
void descartaMonte(Deque *monte, Baralho carta){
    inserirFimDeque(monte, carta);
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

void imprimeDeque(Deque *ptrd)
{
    NoDeque* aux;

    if(dequeVazia(ptrd)==1)
    {
        printf("lista vaziaz\n");
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

void exibirFila(Fila* ptrf){
    No* aux;

    aux = ptrf->inicio;

    if(filaVazia(ptrf)==1){
        printf("lista vazia\n");
    } else{
        if(aux->prox != NULL){
            printf("%d %s\n", (aux)->info.num, (aux)->info.nome);

        while(aux->prox != NULL){
            aux= aux-> prox;
             printf("%d %s\n", (aux)->info.num, (aux)->info.nome);

        }

    }
}
}
