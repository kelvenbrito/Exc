#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista * prox;
};

typedef struct lista Lista;

/* fun��o de inicializa��o: retorna uma lista vazia */
Lista* inicializa (void)
{
    return NULL;
}

/* fun��o auxiliar: cria e inicializa um n� */
Lista* cria (int v)
{
    Lista* p = (Lista*) malloc(sizeof(Lista));
    p->info = v;
    return p;
}
/* inser��o no in�cio: retorna a lista atualizada */
Lista* insere (Lista* l, int i)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

/* fun��o insere_ordenado: insere elemento em ordem */
Lista* insere_ordenado (Lista* l, int v)
{
    Lista* novo = cria(v); /* cria novo n� */
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista*/
    /* procura posi��o de inser��o */
    while (p != NULL && p->info < v) {
        ant = p;
        p = p->prox;
    }
    /* insere elemento */
    if (ant == NULL) { /* insere elemento no in�cio */
        novo->prox = l;
        l = novo;
    }
    else { /* insere elemento no meio da lista */
        novo->prox = ant->prox;
        ant->prox = novo;
    }
    return l;
}

/* fun��o imprime: imprime valores dos elementos */
void imprime (Lista* l)
{
    Lista* p; /* vari�vel auxiliar para percorrer a lista */
    for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);
}

/* fun��o imprime: imprime valores dos elementos em ordem inversa*/
void imprimeInvertida (Lista* l)
{
    Lista *ll = l;
    if(ll==NULL) return;
    imprimeInvertida(ll->prox);
    printf("INFO = %04d\n", ll->info);
}

/* fun��o vazia: retorna 1 se vazia ou 0 se n�o vazia */
int vazia (Lista* l)
{
    return (l == NULL);
}

/* fun��o busca: busca um elemento na lista */
Lista* busca (Lista* l, int v)
{
    Lista* p;
    for (p=l; p!=NULL; p=p->prox)
        if (p->info == v)
            return p;
    return NULL; /* n�o achou o elemento */
}

/* fun��o retira: retira elemento da lista */
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
        return l;   /* n�o achou: retorna lista original */
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
        Lista* t = p->prox; /* guarda refer�ncia para o pr�ximo elemento*/
        free(p); /* libera a mem�ria apontada por p */
        p = t; /* faz p apontar para o pr�ximo */
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
    Lista* l; /* declara uma lista n�o inicializada */
    l = inicializa(); /* inicializa lista como vazia */

    printf("\n-------------- Lista Inicial --------------\n");
    l = insere_ordenado(l, 23); /* insere na lista o elemento 23 */
    l = insere_ordenado(l, 45); /* insere na lista o elemento 45 */
    l = insere_ordenado(l, 56); /* insere na lista o elemento 56 */
    l = insere_ordenado(l, 78); /* insere na lista o elemento 78 */
    imprime(l); /* imprimir�: 78 56 45 23 */
    printf("\n-------------- Retira 78 ------------------\n");
    l = retira(l, 78);
    imprime(l); /* imprimir�: 56 45 23 */
    printf("\n-------------- Retira 45 ------------------\n");
    l = retira(l, 45);
    imprime(l); /* imprimir�: 56 23 */
    libera(l);
    printf("\n-------------- F I M ----------------------\n");

    system("pause");

    system("cls");
    l = inicializa(); /* inicializa lista como vazia */
    l = popula(l,20);
    imprimeInvertida(l);

    return 0;
}
