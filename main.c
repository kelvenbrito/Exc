#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int info;
    struct lista * prox;
};

typedef struct lista Lista; // struct lista é igual a  Lista

Lista * inicializa(void)
{
    return NULL;
}

int vazia (Lista* l)
{
        return (l == NULL);
}

Lista * insere(Lista *l, int v)
{
    Lista * novo;

    novo = (Lista *) malloc(sizeof(Lista));
    novo->info = v;
    novo->prox = l;

    return novo;
}
  void imprimeLista(Lista * l)
  {
      Lista * aux;
      if(vazia(l)){
        printf("Lista vazia!\n\n");
        return;
      }
       //percorre a lista
    for(aux=l; aux!=NULL; aux=aux->prox)
    {
        printf("%d \n", aux->info);
    }

  }

  // função busca: busca um elemento na lista
  Lista* busca(Lista* l, int v)
  {
      Lista* p;
      for(p=l; p!=NULL; p=p->prox)
        if(p->info == v);
            return p;

        return NULL; // não achou o elemento


  }

  Lista* retira (Lista* l, int v){
    Lista* ant = NULL; // ponteiro para elemento anterior
    Lista* p = l; //poteiro para percorrer a lista
    // procura elemento na lista, guardando anterior
    while (p!= NULL && p-> info != v){
        ant = p;
        p = p ->prox;

    }
    //varifica se achou elemento
    if(p == NULL)
        return l; // não achou: retorna lista original
     //retira elelmento
    if(ant == NULL){
        //retira elemento do inicio
        l= p->prox;
    }
    else
    {
        //retira elemento do meio da lista
        ant -> prox = p-> prox;
    }
    free(p);
    return l;
}

void libera (Lista* l)
{
    Lista* p = l;
    while (p!= NULL){
        Lista* t = p ->prox; // guarda referencia  para o proximo elemento

        free(p); // libera a memoria apontada por p

        p = t; //
    }
}

int main()
{
    Lista * l; //variavel lista
     Lista * p;
    int v;
    //Lista * novo;
   // Lista * aux;

    l = inicializa(); //lista vazia

    l = insere(l, 3);
    l = insere(l, 17);
    l = insere(l,  5);
    l = insere(l,  12);
    l = insere(l,  1);


/*
    //criar um novo elemento
   novo = (Lista *) malloc(sizeof(Lista));
    novo->info = 10;
    novo->prox = NULL;
    l = novo;

     //criar um novo elemento
   novo = (Lista *) malloc(sizeof(Lista));
    novo->info = 12;
    novo->prox = l;
    l = novo;


    //percorre a lista
    for(aux=l; aux!=NULL; aux=aux->prox)
    {
        printf("%d \n", aux->info);
    }
    */

    imprimeLista(l);

    printf("\n\nDigite um valor: ");
    scanf("%d",&v);
    l = retira(l,v);

    imprimeLista(l);

    /*
    p = busca(l,v);
    if(p)
    {
        printf("%d \n",p->info);
    }
    else
    {

        printf("Valor nao encontrado!\n");
    }
*/

    return 0;
}
