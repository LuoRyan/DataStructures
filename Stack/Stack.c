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

Arquivo: Stack.c
Descri��o: Implementa��o de pilha
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1; 

#include <stdlib.h>
#include <stdio.h>
#include "..\TAD.h"

node* top;

//Cria uma pilha
stack CreateStack ()
{
	stack myStack;
	myStack.stack = NULL;
	myStack.top = NULL;
	myStack.nodes = 0;
	return myStack;
}

//Verifica se a pilha est� vazia ou n�o
int CheckStack (stack* myStack) 
{
	if (myStack->stack == NULL){
		return -1;
	}
	return 1;
}

//Remove um elemento da pist
void Pop (stack* myStack)
{
	if (myStack->stack == NULL){
		printf("Pilha vazia! \n");
		return;
	}
	node* current = myStack->stack;
	node* previous = NULL;
	while (current != myStack->top) {
		previous = current;
		current = current->pointer;
	}
	free(current);
	previous->pointer = NULL;
	myStack->top = previous;
	myStack->nodes--;
}

//Insere um elemento na pilha 
void Push (stack* myStack, int element)
{
	node* newNode;
	newNode = (node *)(malloc(sizeof(node)));
	if (newNode != NULL){
		if (myStack->stack == NULL){
			newNode->key = element;
			newNode->pointer = NULL;
			myStack->stack = newNode;
			myStack->top = newNode;
		} else {
			newNode->key = element;
			newNode->pointer = NULL;
			myStack->top = newNode;
		}
		myStack->nodes++;
	} else {
		printf("Falha ao inserir elemento na pilha! \n");
	}
}

//Imprime todos os elementos da pilha 
void ConsultStack (stack* myStack) 
{
	node* aux = myStack->stack;
	while (aux != NULL){
		printf("%ld ->", aux->key);
		aux = aux->pointer;
	}
}

//Apaga os elementos e libera mem�ria 
int DestroyStack (stack* myStack)
{
	node* aux = myStack->stack;
	node* node_rem = NULL;
	while (aux != NULL){
		node_rem = aux;
		aux = aux->pointer;
		free(node_rem);
	}
	return CheckStack(myStack);
}