#ifndef JOSEPHUS_H_
#define JOSEPHUS_H_

#include <stdbool.h>

/**
 * Tipo opaco para pessoa
 * - id (int)
 * - isOut (bool)
*/
typedef struct pessoa Pessoa;

typedef struct celula Celula;

typedef struct lista Lista;

/**
 * Inicializa uma lista circular para representar quem está na mesa
 * @return Retorna um ponteiro para uma lista circular
*/
Lista *JOSEPHUS_init();

Pessoa *Inicializa_Pessoa(int id, bool isOut);

/**
 * Exibe na tela todos as pessoas do array
 * @param l Lista a ser exibida
*/
void JOSEPHUS_showAll(Lista *l);

/**
 * Insere uma pessoa na lista
 * @param pessoa Representa uma pessoa da mesa
 * @param l Representa a lista circula (ou seja, a mesa)
*/
void JOSEPHUS_insert(Pessoa *pessoa, int size, Lista *l);

/**
 * Libera o espaço alocado para o vetor de bool
 * @param size Tamanho do array
*/
void JOSEPHUS_free(Lista *l);

void JOSEPHUS_eliminate(int M, Lista *l);

Pessoa *Inicializa_Array_Pessoas(int size);

void Libera_Pessoas(Pessoa *p);

#endif