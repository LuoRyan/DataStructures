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

Arquivo: ArrayList.c
Descri��o: Implementa��es para estruturas do tipo listas est�ticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "ArrayList.h"
#include "../Vector/SearchAlgorithms.h"
#include "../Vector/SortingAlgorithms.h"
#include <stdio.h>

//Cria uma pilha
array* ArrayListCreate(unsigned long int size)
{
	array* myArrayList = (array *)malloc(sizeof(array));
	myArrayList->size = size;
	myArrayList->vector = (long int*)malloc(size*sizeof(long int));
	myArrayList->last = 0;
	return myArrayList;
}

//Verifica se a lista est� vazia ou n�o 
int ArrayListCheck(array * myList)
{
	if (myList->last == 0)
		return -1;
	return 1;
}

//Remove um elemento da lista 
array * ArrayListRemove(array * myList, long int key)
{
	/*Implements*/
	return NULL;
}

//Insere um elemento na lista 
array * ArrayListInsert(array * myList, long int element)
{
	if (myList->last <= myList->size - 1) {
		printf("Full list! \n");
		return myList;
	}
	myList->vector[myList->last] = element;
	myList->last++;
	myList->vector = QuickSort(myList->vector, myList->last + 1);
	return myList;
}

//Imprime todos os elementos da lista 
void ArrayListConsult(array * myList)
{
	for (long int i = 0; i <= myList->last; i++) {
		printf("%ld \n", myList->vector[i]);
	}
}

//Apaga os elementos e libera mem�ria 
array * ArrayListDestroy(array * myList)
{
	free(myList->vector);
	return myList;
}
