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

Arquivo: Heap.c
Descri��o: Implementa��o para Heap
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"
#include "..\Vector\Vector.h"

#define LEFT(x)  (2*x + 1)
#define RIGHT(x) (2*x + 2)
#define FATHER(x)(x / 2)

void MaxHeapfy(heap* myHeap, long int position);
void MaxHeapSort(long int* vector, long int numberOfElements);

// Criar um novo heap
heap* CreateHeap (long int maxElements)
{
	heap* myHeap = (heap*)malloc(sizeof(heap));
	if (myHeap != NULL) {
		myHeap->vector = (long int*)malloc((maxElements)*sizeof(long int));
		myHeap->maxElements = maxElements;
		myHeap->elements = 0;
		return myHeap;
	} else {
		return NULL;
	}
}

// Destruir um heap
void DestroyHeap (heap* myHeap)
{
	free(myHeap->vector);
	free(myHeap);
}

// Build Heap
void BuildHeap (heap* myHeap) 
{
	if (myHeap->elements == myHeap->maxElements) {
		for (long int i = (myHeap->elements) / 2; i--; i >= 1) {
			MaxHeapfy(myHeap, i);
		}
	}
}

// Reorganiza o heap caso o elemento i possa ser maior que seus filhos
void MaxHeapfy (heap* myHeap, long int position)
{
	long int left = LEFT(position);
	long int right = RIGHT(position);
	long int aux;
	long int bigger = position;
	if ((left <= myHeap->elements) && 
		(myHeap->vector[left] > myHeap->vector[position])){
		bigger = left;
	}
	if ((right <= myHeap->elements) &&
		(myHeap->vector[right] > myHeap->vector[bigger])) {
		bigger = right;
	}
	if (bigger != position) {
		aux = myHeap->vector[position];
		myHeap->vector[position] = myHeap->vector[bigger];
		myHeap->vector[bigger] = aux;
		MaxHeapfy(myHeap, bigger);
	}
}

// Insere um novo elemento no heap
int InsertInHeap (heap* myHeap, long int key) 
{
	long int aux;
	long int position;
	if (myHeap->elements == myHeap->maxElements) {
		return 0;
	}
	position = myHeap->elements;
	myHeap->elements++;
	myHeap->vector[position] = key;
	while ((position > 1) && 
		(myHeap->vector[FATHER(position)] < myHeap->vector[position])) {
		aux = myHeap->vector[position];
		myHeap->vector[position] = myHeap->vector[FATHER(position)];
		myHeap->vector[FATHER(position)] = aux;
		position = FATHER(position);
	}
	return 1;
}

// Remove o elemento de maior prioridade no heap
long int RemoveHeap (heap* myHeap)
{
	if (myHeap->elements == 0) {
		printf("Heap Vazio \n");
		return 0;
	} 
	long int max = myHeap->vector[0];
	myHeap->vector[0] = myHeap->vector[myHeap->elements - 1];
	myHeap->vector[myHeap->elements - 1] = max;
	myHeap->elements--;
	MaxHeapfy(myHeap, 1);
	return max;
}

// Exibe o Heap
void ShowHeap (heap* myHeap)
{
	ShowVector(myHeap->vector, myHeap->elements);
}

// HEAP SORT
// Cria um Heap de M�ximo dado um vetor
void MaxHeapSort (long int* vector, long int numberOfElements)
{
	//Checar se o Heap est� vazio
	if (numberOfElements == 0) {
		printf("O Heap esta vazio! \n");
	}
	long int aux; // Vari�vel auxiliar
	long int n = numberOfElements; // + 1 para ajuste de posi��o
	long int father = numberOfElements / 2;
	long int index, child;

	while (1) {
		if (father > 0) {
			//Ordenar o Heap
			aux = vector[--father];
		}
		else {
			//Extrair os elementos
			n--;
			if (n == 0) {
				//Quando o heap fica vazio, o algoritmo termina
				return;
			}
			aux = vector[n];
			vector[n] = vector[0];
		}
		//Empurrando t para baixo para recolocar o pai
		index = father;
		child = index * 2 + 1;
		while (child < n) {
			if (child + 1 < n && vector[child + 1] < vector[child]) {
				child++;
			}
			if (vector[child] < aux) {
				vector[index] = vector[child];
				index = child; //�ndice fica igual ao filho
				child = index * 2 + 1; // Pega o filho da esquerda e repetir o processo
			}
			else {
				break;
			}
		}
		//Novos valores s�o salvos tempor�riamente em novas posi��es
		vector[index] = aux;
	}
}