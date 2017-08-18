#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista * prox;
};

typedef struct lista Lista;

/* função de inicialização: retorna uma lista vazia */
Lista* inicializa (void)
{
    return NULL;
}

/* função auxiliar: cria e inicializa um nó */
Lista* cria (int v)
{
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->info = v;
    return p;
}
/* inserção no início: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* função insere_ordenado: insere elemento em ordem */
Lista* insere_ordenado (Lista* l, int v)
{
    Lista* novo = cria(v); /* cria novo nó */
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura posição de inserção */
    while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }
    /* insere elemento */
    if (ant == NULL) { /* insere elemento no início */
        novo->prox = l;
        l = novo;
    }
    else { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

/* função imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
    Lista* p; /* variável auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

/* função imprime: imprime valores dos elementos em ordem inversa*/
void imprimeInvertida (Lista* l)
{
    Lista *ll = l;
    if(ll==NULL) return;
    imprimeInvertida(ll->prox);
    printf("INFO = %04d\n", ll->info);
}

/* função vazia: retorna 1 se vazia ou 0 se não vazia */
int vazia (Lista* l)
{
    return (l == NULL);
}

/* função busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
    Lista* p;
    for (p=l; p!=NULL; p=p->prox)
        if (p->info == v)
            return p;
    return NULL; /* não achou o elemento */
}

/* função retira: retira elemento da lista */
Lista* retira (Lista* l, int v) {
    Lista* ant = NULL;  /* ponteiro para elemento anterior */
    Lista* p = l;       /* ponteiro para percorrer a lista*/

                        /* procura elemento na lista, guardando anterior */
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }
    /* verifica se achou elemento */
    if (p == NULL)
        return l;   /* não achou: retorna lista original */
                    /* retira elemento */
    if (ant == NULL) {
        /* retira elemento do inicio */
        l = p->prox;
    }
    else
    {
        /* retira elemento do meio da lista */
        ant->prox = p->prox;
    }

    free(p);

    return l;
}

void libera (Lista* l)
{
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox; /* guarda referência para o próximo elemento*/
        free(p); /* libera a memória apontada por p */
        p = t; /* faz p apontar para o próximo */
    }
}

Lista * popula(Lista * l, int qtde)
{
    int n;
    for(n=1 ;n<=qtde; n++)
    {
        l = insere(l,n);
    }
    return l;
}

int main()
{
    Lista* l; /* declara uma lista não inicializada */
    l = inicializa(); /* inicializa lista como vazia */

    printf("\n-------------- Lista Inicial --------------\n");
    l = insere_ordenado(l, 23); /* insere na lista o elemento 23 */
    l = insere_ordenado(l, 45); /* insere na lista o elemento 45 */
    l = insere_ordenado(l, 56); /* insere na lista o elemento 56 */
    l = insere_ordenado(l, 78); /* insere na lista o elemento 78 */
    imprime(l); /* imprimirá: 78 56 45 23 */
    printf("\n-------------- Retira 78 ------------------\n");
    l = retira(l, 78);
    imprime(l); /* imprimirá: 56 45 23 */
    printf("\n-------------- Retira 45 ------------------\n");
    l = retira(l, 45);
    imprime(l); /* imprimirá: 56 23 */
    libera(l);
    printf("\n-------------- F I M ----------------------\n");

    system("pause");

    system("cls");
    l = inicializa(); /* inicializa lista como vazia */
    l = popula(l,20);
    imprimeInvertida(l);

    return 0;
}
