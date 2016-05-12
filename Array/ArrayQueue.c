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
com este programa, Se n�o, veja <http:/*www.gnu.org/licenses/>.

Arquivo: ArrayQueue.c
Descri��o: Implementa��es para estruturas do tipo filas est�ticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

/* Cria e retorna uma fila est�tica  */
array* ArrayQueueCreate (unsigned long int size) 
{
	array* myArrayQueue = (array *)malloc(sizeof(array));
	myArrayQueue->size = size;
	myArrayQueue->vector = (long int*)malloc(size*sizeof(long int));
	myArrayQueue->last = 0;
	return myArrayQueue;
}

/* Verifica se h� elementos na fila  */
int ArrayQueueCheck (array* myArrayQueue) 
{
	if (myArrayQueue->last == 0)
		return -1;
	return 1;
}

/* Insere elementos na fila  */
array* ArrayQueueEnqueue (array* myArrayQueue, long int element) 
{
	if (myArrayQueue->last == myArrayQueue->size - 1){
		printf("Pilha cheia! \n");
		return myArrayQueue;
	}
	myArrayQueue->vector[myArrayQueue->last] = element;
	myArrayQueue->last++;
	return myArrayQueue;
}

/* Remove elementos da fila  */
array* ArrayQueueDequeue (array* myArrayQueue)
{
	if (myArrayQueue->last == 0){
		printf("Fila vazia! \n");
		return myArrayQueue;
	}
	for (long int i = 0; i < myArrayQueue->last; i++) {
		myArrayQueue->vector[i] = myArrayQueue->vector[i + 1];
	}
	myArrayQueue->last--;
	return myArrayQueue;
}

/* Imprime os elementos da fila  */
void ArrayQueueConsult (array* myArrayQueue) 
{
	for (long int i = 0; i <= myArrayQueue->last; i++) {
		printf("%ld \n", myArrayQueue->vector[i]);
	}
}

/* Apaga todos os elementos e libera mem�ria  */
array* ArrayQueueDestroy (array* myArrayQueue) 
{
	free(myArrayQueue->vector);
	return myArrayQueue;
}