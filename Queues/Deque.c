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

Arquivo: Deque.c
Descri��o: Implementa��o de deque
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include <stdlib.h>
#include <stdio.h>
#include "Deque.h"

//Cria um deque 
deque CreateDeque()
{
	deque myDeque;
	myDeque.startOfQueue = NULL;
	myDeque.endOfQueue = NULL;
	myDeque.nodes = 0;
}

//Verifica se h� elementos no deque 
int CheckDeque(deque* myDeque) 
{
	if (myDeque->startOfQueue == NULL) {
		return -1;
	}
	return 1;
}

//Insere elementos no deque 
void InsertAtFront(deque* myDeque, long int element)
{
	if (myDeque == NULL)
		return;
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL) {
		newNode->key = element;
		newNode->pointer = myDeque->startOfQueue;
		myDeque->startOfQueue = newNode;
		myDeque->nodes++;
	}
	// Atualiza o �ltimo n� do deque, caso necess�rio
	if (myDeque->endOfQueue == NULL) {
		node* current;
		node* previous;
		current = myDeque->startOfQueue;
		while (current->pointer != NULL) {
			current = current->pointer;
			previous = current;
		}
		myDeque->endOfQueue = current;
	}
}

void InsertAtBack(deque* myDeque, long int element)
{
	if (myDeque == NULL)
		return;
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL) {
		newNode->key = element;
		newNode->pointer = NULL;
	}
	node* current = myDeque->startOfQueue;
	node* previous = NULL;
	while (current->pointer != NULL) {
		current = current->pointer;
		previous = current;
	}
	current->pointer = newNode;
	myDeque->endOfQueue = newNode;
	myDeque->nodes++;
}

//Remove elementos do deque 
void RemoveFromFront(deque* myDeque) 
{
	if (myDeque == NULL || myDeque->startOfQueue == NULL)
		return;
	node* tempNode = myDeque->startOfQueue;
	myDeque->startOfQueue = tempNode->pointer;
	free(tempNode);
	myDeque->nodes--;
}

void RemoveFromBack(deque* myDeque)
{
	if (myDeque == NULL || myDeque->startOfQueue == NULL)
		return;
	node* current = myDeque->startOfQueue;
	node* previous = NULL;
	while (current->pointer != NULL) {
		current = current->pointer;
		previous = current;
	}
	myDeque->endOfQueue = previous;
	free(current);
	myDeque->nodes--;
}

//Imprime os elementos do deque 
void ConsultDeque(deque* myDeque) 
{
	if (myDeque == NULL || myDeque->startOfQueue == NULL)
		return;
	node* current = myDeque->startOfQueue;
	while (current != NULL) {
		printf("%ld \n", current->key);
		current = current->pointer;
	}
}

//Apaga todos os elementos e libera mem�ria 
int DestroyDeque(deque* myDeque) 
{
	node* current = NULL;
	while (myDeque->startOfQueue != NULL) {
		current = myDeque->startOfQueue->pointer;
		free(myDeque->startOfQueue);
		myDeque->startOfQueue = current;
	}
	return EXIT_SUCCESS;
}