#include "josephus.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct pessoa
{
  int id;
  bool isOut;
};

struct celula
{
  Pessoa pessoa;
  Celula *prox;
};

struct lista
{
  Celula *primeiro;
  Celula *ultimo;
};

Lista *JOSEPHUS_init()
{
  Lista *lista = (Lista *)malloc(sizeof(Lista));
  lista->primeiro = NULL;

  return lista;
}

void JOSEPHUS_showAll(Lista *l)
{
  Celula *celula_aux = l->primeiro;

  if (celula_aux)
  {
    do
    {
      printf("%d", celula_aux->pessoa.id);
      celula_aux = celula_aux->prox;
    } while (celula_aux != l->primeiro);
  }
}

void JOSEPHUS_insert(Pessoa *pessoa, int size, Lista *l)
{
  for (int i = 0; i < size; i++)
  {
    // printf("id: %d\n", pessoa[i].id);
    Celula *novo = (Celula *)malloc(sizeof(Celula));

    if (l->ultimo == NULL)
    {
      l->primeiro = l->ultimo = novo;
    }
    else
    {
      l->ultimo->prox = novo;
      l->ultimo = l->ultimo->prox;
    }
    l->ultimo->pessoa = pessoa[i];
    l->ultimo->prox = l->primeiro;
  }
}

void JOSEPHUS_remove(Lista *l, int id)
{
  Celula *ant = NULL;
  Celula *p = l->primeiro;

  while (p != NULL && p->pessoa.id != id)
  {
    // printf("\t1\n");
    ant = p;
    p = p->prox;
  }

  if (p == NULL)
  {
    // printf("\t2\n");
    return;
  }

  if (p == l->primeiro && p == l->ultimo)
  {
    // printf("\t3\n");
    l->primeiro = l->ultimo = NULL;
    free(p);
    return;
  }

  if (p == l->ultimo)
  {
    // printf("\t4\n");
    l->ultimo = ant;
    ant->prox = l->primeiro;
    free(p);
    return;
  }

  if (p == l->primeiro)
  {
    // printf("\t5\n");
    l->primeiro = p->prox;
    l->ultimo->prox = l->primeiro;
  }

  else
  {
    // printf("\t6\n");
    ant->prox = p->prox;
  }

  // printf("aq\n");
  free(p);
}

void JOSEPHUS_free(Lista *l)
{
  Celula *celula_aux = l->primeiro;

  if (celula_aux)
  {
    do
    {
      JOSEPHUS_remove(l, celula_aux->pessoa.id);
      celula_aux = l->primeiro;
    } while (celula_aux != NULL);
  }

  free(l);
}

void JOSEPHUS_eliminate(int M, Lista *l)
{
  Celula *p = l->primeiro;
  Celula *ant = NULL;
  Celula *novo_ultimo = NULL;

  // printf("PRIMEIRO DA LISTA ====> %d\n", l->primeiro->pessoa.id);
  // printf("ULTIMO DA LISTA ====> %d\n", l->ultimo->pessoa.id);

  while (M > 0)
  {
    // printf("M %d\n", M);
    // printf("p ====> id: %d\n", p->pessoa.id);
    // printf("p prox ====> id: %d\n", p->prox->pessoa.id);
    if (M == 1)
    {
      // printf("entrou no if");
      novo_ultimo = ant;
    }
    ant = p;
    // printf("\tANT ====> id: %d\n", ant->pessoa.id);
    p = p->prox;
    M--;
  }
  // printf("REMOVEU =====> id: %d\n", ant->pessoa.id);
  // printf("VALOR DE p =====> id: %d\n", p->pessoa.id);
  JOSEPHUS_remove(l, ant->pessoa.id);
  // printf("\n");
  // printf("p %d\n", p->pessoa.id);
  // printf("prox %d\n", p->prox->pessoa.id);

  l->primeiro = p;
  l->ultimo = novo_ultimo;

  // printf("NOVO PRIMEIRO DA LISTA ====> %d\n", l->primeiro->pessoa.id);
  // printf("NOVO ULTIMO DA LISTA ====> %d\n", l->ultimo->pessoa.id);
  // printf("NOVO PROX DA LISTA ====> %d\n", l->primeiro->prox->pessoa.id);
  // printf("NOVO PROX PROX DA LISTA ====> %d\n", l->primeiro->prox->prox->pessoa.id);
}

Pessoa *Inicializa_Pessoa(int id, bool isOut)
{
  Pessoa *p = (Pessoa *)malloc(sizeof(Pessoa));
  p->id = id;
  p->isOut = isOut;

  return p;
}

Pessoa *Inicializa_Array_Pessoas(int size)
{
  Pessoa *p = (Pessoa *)malloc(size * sizeof(Pessoa));

  for (int i = 0; i < size; i++)
  {
    p[i].id = i + 1;
    p[i].isOut = false;
  }

  return p;
}

void Libera_Pessoas(Pessoa *p)
{
  free(p);
}