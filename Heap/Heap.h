/**
Este arquivo � parte do projeto Data Structures
Este � um software livre; voc� pode redistribu�-lo e/ou
modific�-lo dentro dos termos da Licen�a P�blica Geral GNU como
publicada pela Funda��o do Software Livre (FSF); na vers�o 3 da
Licen�a, ou (na sua opini�o) qualquer vers�o.

Este programa � distribu�do na esperan�a de que possa ser  �til,
mas SEM NENHUMA GARANTIA; sem uma garantia impl�cita de ADEQUA��O
a qualquer MERCADO ou APLICA��O EM PARTICULAR. Veja a
Licen�a P�blica Geral GNU para maiores detalhes.

Voc� deve ter recebido uma c�pia da Licen�a P�blica Geral GNU junto
com este programa, Se n�o, veja <http://www.gnu.org/licenses/>.

Arquivo: Heap.h
Descri��o: Defini��es para estruturas Heap
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef HEAP_H
#define HEAP_H
#include "..\TAD.h"
// Criar um novo heap
heap* CreateHeap(long int maxElements);

// Destruir um heap
void DestroyHeap(heap* myHeap);

// Insere um novo elemento no heap
int InsertInHeap(heap* myHeap, long int key);

// Remove o elemento de maior prioridade no heap
long int RemoveHeap(heap* myHeap);

// Exibe o Heap
void ShowHeap(heap* myHeap);

// Cria um Heap de M�ximo dado um vetor
void MaxHeapSort(long int* vector, long int numberOfElements);
#endif // !HEAP_H