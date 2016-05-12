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

Arquivo: DoubleLinkedList.c
Descri��o: Implementa��o de Lista dupla
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

/* Cria uma list duplamente encadeada */
doublylist CreateDLinkedList ()
{
	doublylist myDoublyList;
	myDoublyList.list = NULL;
	myDoublyList.startOfList = NULL;
	myDoublyList.endOfList = NULL;
	myDoublyList.nodes = 0;
	return myDoublyList;
}

/* Verifica se h� elementos na lista */
int CheckDLinkedList (doublylist* myDoublyList)
{
	if (myDoublyList->list == NULL){
		return -1;
	}
	return 1;
}

/* Insere elementos no in�cio da lista */
void InsertAtStartDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* newNode;
	newNode = (dnode *)(malloc(sizeof(dnode))); 
	if (newNode != NULL){
		if (myDoublyList->list == NULL){
			newNode->key = element;
			myDoublyList->list = newNode;
			myDoublyList->startOfList = newNode;
			myDoublyList->endOfList = newNode;
			newNode->previous = NULL;
			newNode->next = NULL;
		} else {
			newNode->key = element;
			newNode->next = myDoublyList->list; 
			newNode->previous = NULL;
			myDoublyList->list->previous = newNode; 
			myDoublyList->startOfList = newNode;
			myDoublyList->list = newNode;
		}
	}
}

/* Insere elementos no meio da lista */
void InsertAtMiddleDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* newNode;
	newNode = (dnode *)(malloc(sizeof(dnode)));
	if (newNode != NULL){
		if (myDoublyList->list == NULL){
			newNode->key = element;
			myDoublyList->list = newNode;
			myDoublyList->startOfList = newNode;
			myDoublyList->endOfList = newNode;
			newNode->previous = NULL;
			newNode->next = NULL;
		} else {
			newNode->key = element;
			dnode* aux = myDoublyList->startOfList;
			dnode* previous = NULL;
			while (aux != NULL && newNode->key > aux->key){
				previous = aux; /* Guarda a posi��o do n� previous � aux */
				aux = aux->next;
			}
			if (aux == myDoublyList->startOfList){
				/* Insere no in�cio */
				newNode->next = myDoublyList->list;
				newNode->previous = NULL;
				myDoublyList->startOfList->previous = newNode;
				myDoublyList->list = newNode;
				myDoublyList->startOfList = newNode;
			} else if (aux == NULL){
				/* Insere no fim */
				myDoublyList->endOfList->next = newNode; 
				newNode->previous = myDoublyList->endOfList;
				newNode->next = NULL;
				myDoublyList->endOfList = newNode; 
			} else {
				/* Meio */
				newNode->next = aux;
				previous->next = newNode; /* N� anterior aponta para o newNode n� */
				newNode->previous = previous; 
				aux->previous = newNode; 
			}
		}
	}
}

/* Insere elementos no fim da lista */
void InsertAtEndDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* newNode;
	newNode = (dnode *)(malloc(sizeof(dnode)));
	if (newNode != NULL){
		if (myDoublyList->list == NULL){
			newNode->key = element;
			myDoublyList->list = newNode;
			myDoublyList->startOfList = newNode;
			myDoublyList->endOfList = newNode;
			newNode->previous = NULL;
			newNode->next = NULL;
		} else {
			newNode->key = element;
			myDoublyList->endOfList->next = newNode;
			newNode->previous = myDoublyList->endOfList;
			newNode->next = NULL;
			myDoublyList->endOfList = newNode;
		}
	}
}

/* Busca um dado elemento na lista */
dnode* SearchElementDLinkedList (doublylist* myDoublyList, long int element)
{
	int parametro; 
	dnode* aux;
	printf("Busca Lista Duplamente Encadeada\n1 - Do inicio para o final \t2 - Do final para o inicio\n");
	scanf("%ld", &parametro);
	if (parametro == 1){
		aux = myDoublyList->startOfList;
		while (aux != NULL){
			if (aux->key == element){
				return aux;
			} else {
				aux = aux->next;
			}
		}
	} else if (parametro == 2){
		aux = myDoublyList->endOfList;
		while (aux != NULL){
			if (aux->key == element){
				return aux;
			} else {
				aux = aux->previous;
			}
		}
		
	} else {
		printf("Escolha invalida! \n");
		return NULL;
	}
	return NULL;
}

/* Imprime todos os elementos da lista  */
void ListElementsDLinkedList (doublylist* myDoublyList) 
{
	int parametro;
	dnode* current;

	printf("Mostrar elementos Lista Duplamente Encadeada\n1 - Do inicio para o final \t2 - Do final para o inicio\n");
	scanf("%ld", &parametro);
	if (parametro == 1){
		current = myDoublyList->startOfList;
		while (current != NULL){
			printf("%ld ->", current->key);
			current = current->next;
		}
	} else if (parametro == 2){
		current = myDoublyList->endOfList;
		while (current != NULL){
			printf("%ld ->", current->key);
			current = current->previous;
		}
	}
	else {
		printf("Escolha invalida! \n");
	}
}

/* Remove um dado elemento da lista */
void RemoveElementDLinkedList (doublylist* myDoublyList, long int element)
{
	dnode* aux = myDoublyList->list; 
	while (aux != NULL) { 
		if (aux->key == element) { 
			if (aux == myDoublyList->startOfList) { 
				/* Remove no in�cio */
				myDoublyList->startOfList = aux->next;
				myDoublyList->startOfList->previous = NULL;
				free(aux);
				break;
			} else if (aux != myDoublyList->endOfList){
				/* Remove no meio */
				aux->previous->next = aux->next; 
				aux->previous->previous = aux->previous; 
				dnode* aux2; 
				aux2 = aux->next; 
				free(aux);
				aux = aux2;
				break;
			} else {
				/* Remove no fim */
				myDoublyList->endOfList = myDoublyList->endOfList->previous;
				myDoublyList->endOfList->next = NULL;
				free(aux);
				break;
			}
		}
		aux = aux->next;
	}
}

/* Apaga toda a lista e libera mem�ria */
int DestroyDLinkedList (doublylist* myDoublyList)
{
	dnode* aux = NULL;
	int teste = 0;
	while (myDoublyList->list != NULL) {
		aux = myDoublyList->list->next;
		free(myDoublyList->list);
		myDoublyList->list = aux;
	}
	return CheckDLinkedList(myDoublyList);
}