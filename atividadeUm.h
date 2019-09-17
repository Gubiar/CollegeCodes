/**
 * @file ordenacao.h
 * @author Gubiar
 * @date 10 Set 2019
 * @brief Implementacao dos métodos de ordenacao
 * Implementa os metodos de ordenacao vistos na disciplina
 * pesquisa e classificacao de dados.
 */

#ifndef UNTITLED_ORDENACAO_H
#define UNTITLED_ORDENACAO_H

#include<stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void organizabubble(int *V, int N);
/**
 * \brief Método de organização bubble sort
 *
 * \param V vetor a ser organizado
 * \param N tamanho do vetor
 *
 * Organiza um vetor de numeros pelo metodo bubble sort
 */

void organizaSelection(int *V, int N);
/**
 * \brief Método de organização selection sort
 *
 * \param V vetor a ser organizado
 * \param N tamanho do vetor
 *
 * Organiza um vetor de numeros pelo metodo Selection sort
 */

void organizaInsertion(int *V, int N);
/**
 * \brief Método de organização insertion sort
 *
 * \param V vetor a ser organizado
 * \param N tamanho do vetor
 *
 * Organiza um vetor de numeros pelo metodo Insertion Sort
 */

void merge(int *V, int inicio, int meio, int fim);
/**
 * \brief Função recursiva usada pelo método merge sort
 *
 * \param V vetor a ser organizado
 * \param inicio posicao do vetor inicial para comecar a organizar
 * \param meio posicao do meio do vetor, calculada pela funcao principal
 * \param fim tamanho do vetor
 *
 * Faz o merge, onde divide o vetor para organiza-lo
 */

void mergesort(int *V, int inicio, int fim);
/**
 * \brief Método de organização merge sort
 *
 * \param V vetor a ser organizado
 * \param inicio posicao do vetor inicial para comecar a organizar
 * \param fim tamanho do vetor
 *
 * Funcao principal recursiva que organiza o vetor pelo metodo mergesort
 */

int particiona(int *V, int inicio, int fim);
/**
 * \brief Função recursiva usada pela quick sort
 *
 * \param V vetor a ser organizado
 * \param inicio posicao do vetor inicial para comecar a organizar
 * \param fim tamanho do vetor
 *
 * Funcao coloca o valor do pivo no seu lugar, garantindo que esse numero esteja ordenado
 */

void quicksort(int *V, int inicio, int fim);
/**
 * \brief Método de organização quick sort
 *
 * \param V vetor a ser organizado
 * \param inicio posicao do vetor inicial para comecar a organizar
 * \param fim tamanho do vetor
 *
 * Funcao recursiva que ordena o vetor por meio da quick sort
 */

void criaHeap(int *V, int pai, int fim);
/**
 * \brief Função usada pela heap sort para ordenar o vetor
 *
 * \param V vetor a ser organizado
 * \param pai posicao do vetor inicial para comecar a organizar
 * \param fim tamanho do vetor
 *
 * funcao que organiza o vetor em forma de heap
 */

void heapSort(int *V, int tamanho);
/**
 * \brief Método de organização heap sort
 *
 * \param V vetor a ser organizado
 * \param tamanho tamanho do vetor
 *
 * funcao recuersiva que orgazina um vetor pelo metodo heapsort
 */

#endif //UNTITLED_ORDENACAO_H
