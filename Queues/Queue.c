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

Arquivo: Queue.c
Descri��o: Implementa��o de fila
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"


/* Cria uma fila */
queue CreateQueue ()
{
	queue myQueue;
	myQueue.queue = NULL;
	myQueue.endOfQueue = NULL;
	myQueue.nodes = 0;
	return myQueue;
}

/* Verifica se a fila est� vazia ou n�o */
int CheckQueue (queue* myQueue)
{
	if (myQueue->queue == NULL){
		return -1;
	}
	return 1;
}

/* Insere elementos na fila */
void Enqueue (queue* myQueue, long int element)
{
	node* newNode;
	newNode = (node*)(malloc(sizeof(node)));
	if (myQueue->queue == NULL){
		if (newNode != NULL) {
			newNode->key = element;
			newNode->pointer = NULL; /* �ltimo elemento n�o aponta pra ningu�m */
			myQueue->queue = newNode;
			myQueue->endOfQueue = newNode;
			myQueue->nodes++;
		}
	} else {
		newNode->key = element;
		newNode->pointer = NULL;
		myQueue->endOfQueue->pointer = newNode;
		myQueue->endOfQueue = newNode;
		myQueue->nodes++;
	}
}

/* Remove elementos da fila */
void Dequeue (queue* myQueue)
{
	if (myQueue->queue == NULL){
		printf("A Fila esta vazia!\n");
		return;
	} else {
		node* remove = myQueue->queue;
		myQueue->queue = remove->pointer;
		free(remove);
		myQueue->nodes--;
	}
}

/* Imprime os elementos da fila */
void ConsultQueue (queue* myQueue)
{
	node* aux = myQueue->queue;
	while (aux != NULL){
		printf("%ld ->", &aux->key);
		aux = aux->pointer;
	}
}

/* Apaga todos os elementos e libera mem�ria */
int DestroyQueue (queue* myQueue)
{
	node* aux = myQueue->queue;
	node* node_rem = NULL;
	while (aux != NULL) {
		node_rem = aux;
		aux = aux->pointer;
		free(node_rem);
	}
	return CheckQueue(myQueue);
}