#include <stdio.h>
#include <stdlib.h>

struct lista{
    int info;
    struct lista * prox;
};

typedef struct lista Lista;


Lista*  inicializa (void)
{
    return NULL;
}




Lista* insere (Lista* l, int i)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}



void imprime (Lista* l)
{
    Lista* p;
      for (p = l; p != NULL; p = p->prox)
        printf("info = %d\n", p->info);

   return (l == NULL);
}


struct lista * separa(struct lista * l, int n){

}

int main(){
    Lista* l;
    l = inicializa();

    printf("\n-------------- Lista Inicial --------------\n");


    l = insere(l, 1);
    l = insere(l, 12);
    l = insere(l, 5);
    l = insere(l, 17);
    l = insere(l, 3);

    imprime(l);
}
