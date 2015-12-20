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
com este programa, Se n�o, veja <http://www.gnu.org/licenses/>.x

Arquivo: ArrayStack.h
Descri��o: Defini��es para estruturas do tipo pilhas est�ticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include <stdlib.h>
#include <stdio.h>
#include "TAD.h"

//Cria uma pilha
array* ArrayStackCreate(long int size){
	array* myArrayStack = (array *)malloc(sizeof(array));
	myArrayStack->size = size;
	myArrayStack->vector = (long int*)malloc(size*sizeof(long int));
	myArrayStack->last = 0;
	return myArrayStack;
}

//Verifica se a pilha est� vazia ou n�o 
int ArrayStackCheck(array* myArrayStack) {
	if (myArrayStack->last == 0) {
		return -1;
	}
	return 1;
}

//Remove um elemento da pilha 
array* ArrayStackPop(array* myArrayStack) {
	if (myArrayStack->last == 0) {
		printf("Pilha Vazia! \n");
		return myArrayStack;
	}
	myArrayStack->last--;
	return myArrayStack;
}

//Insere um elemento na pilha 
array* ArrayStackPush(array* myArrayStack, long int element) {
	if (myArrayStack->last == myArrayStack->size - 1) {
		printf("Pilha cheia! \n");
		return myArrayStack;
	}
	myArrayStack->last++;
	myArrayStack->vector[myArrayStack->last] = element;
	return myArrayStack;
}

//Imprime todos os elementos da pilha 
void ArrayStackConsult(array* myArrayStack) {
	for (long int i = 0; i <= myArrayStack->last; i++) {
		printf("%ld \n", myArrayStack->vector[i]);
	}
}

//Apaga os elementos e libera mem�ria 
array* ArrayStackDestroy(array* myArrayStack) {
	free(myArrayStack->vector);
	return myArrayStack;
}

#endif // ARRAYSTACK_H