#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "josephus.h"

int main(int argc, char *argv[])
{
  if (argc < 3)
  {
    // printf("É necessário informar o valor de N e M.\n");
    return 0;
  }

  int size = atoi(argv[1]);
  int indexElimination = atoi(argv[2]);

  Lista *lista = JOSEPHUS_init();
  Pessoa *p = Inicializa_Array_Pessoas(size);

  JOSEPHUS_insert(p, size, lista);

  // Pessoa *p0 = Inicializa_Pessoa(1, false);
  // Pessoa *p1 = Inicializa_Pessoa(2, false);
  // Pessoa *p2 = Inicializa_Pessoa(3, true);
  // Pessoa *p3 = Inicializa_Pessoa(4, false);
  // Pessoa *p4 = Inicializa_Pessoa(5, false);
  // Pessoa *p5 = Inicializa_Pessoa(6, false);
  // Pessoa *p6 = Inicializa_Pessoa(7, false);
  // Pessoa *p7 = Inicializa_Pessoa(8, false);
  // Pessoa *p8 = Inicializa_Pessoa(9, false);

  /* JOSEPHUS_insert(p0, lista);
  JOSEPHUS_insert(p1, lista);
  JOSEPHUS_insert(p2, lista);
  JOSEPHUS_insert(p3, lista);
  JOSEPHUS_insert(p4, lista);
  JOSEPHUS_insert(p5, lista);
  JOSEPHUS_insert(p6, lista);
  JOSEPHUS_insert(p7, lista);
  JOSEPHUS_insert(p8, lista); */

  for (int i = 0; i < size - 1; i++)
  {

    JOSEPHUS_eliminate(indexElimination, lista);
  }

  printf("O id eleito é: ");
  JOSEPHUS_showAll(lista);
  printf("\n");

  JOSEPHUS_free(lista);
  Libera_Pessoas(p);
  /* free(p0);
  free(p1);
  free(p2);
  free(p3);
  free(p4);
  free(p5);
  free(p6);
  free(p7);
  free(p8); */
  return 0;
}