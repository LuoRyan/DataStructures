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

Arquivo: CircleList.c
Descri��o: Implementa��o de Lista circular simples
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

/* Cria uma lista circular  */
circlelist CreateCircleList ()
{
	circlelist myList;
	myList.list = NULL;
	myList.nodes = 0;
	return myList;
}

/* Verifica se a lista est� vazia ou n�o */
int CheckCircleList (circlelist* myList)
{
	if (myList->list == NULL) {
		return -1;
	}
	return 1;
}

/* Insere novos elements na lista  */
void InsertAtCircleList (circlelist* myList, long int element)
{
	if (myList->list == NULL) {
		node* newNode;
		newNode = (node *)(malloc(sizeof(node)));
		if (newNode != NULL) {
			newNode->key = element;
			myList->list = newNode;
			newNode->pointer = myList->list;
			myList->nodes++;
		}
	} else {
		node* newNode;
		newNode = (node *)(malloc(sizeof(node)));
		if (newNode != NULL) {
			newNode->pointer = myList->list;
			myList->list = newNode;
			myList->nodes++;
		}
	}
}

/* Busca um dado valor na lista  */
node* SearchElementCircleList (circlelist* myList, long int element) 
{
	node* aux = myList->list;

	while (aux != myList->list && aux->key != element) {
		aux = aux->pointer;
	}
	if (aux->key == element) {
		return aux;
	}
	else {
		return NULL;
	}
}

/* Imprime todos os elements da lista */
void ListElementsCircleList (circlelist* myList)
{
	node* aux = myList->list;
	if (myList->nodes == 0) {
		printf("Lista vazia! \n");
		return;
	} else {
		while (aux != myList->list) {
			printf("%ld ->", aux->key);
			aux = aux->pointer;
		}
	}
}

/* Apaga toda a lista e libera a mem�ria  */
void RemoveElementCircleList (circlelist* myList, long int element)
{
	node* current = myList->list;
	node* previous = NULL;
	while (current != myList->list && current->key != element) {
		previous = current;
		current = current->pointer;
	}
	if (current == myList->list) {
		printf("Elemento nao encontrado\n");
		return;
	}
	if (previous == NULL) {
		myList->list = current->pointer;
	}
	else {
		previous->pointer = current->pointer;
	}
	free(current);
}

/* Destuir a Lista */
int DestroyCircleList(circlelist* myList)
{
	node* aux = myList->list;
	while (aux != myList->list) {
		aux = myList->list;
		free(myList->list);
		myList->list = aux;
	}
	myList->list = NULL;
	return CheckCircleList(myList);
}