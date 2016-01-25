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

Arquivo: LinkedList.h
Descri��o: Defini��es para Lista encadeada simples
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "..\TAD.h"
// Cria uma lista encadeada
list CreateLinkedList();

// Verifica uma lista encadeada (se vazia)
int CheckLinkedList(list* myList);

// Insere no in�cio da lista
void InsertAtStartLinkedList(list* myList, long int element);

// Insere no meio da lista
void InsertAtMiddleLinkedList(list* myList, long int element);

// Insere no fim da lista
void InsertAtEndLinkedList(list* myList, long int element);

// Busca
node* SearchLinkedList(list* myList, long int element);

// Mostrar os elementos
void ListElementsLinkedList(list* myList);

// Retorna uma lista com os elementos em ordem invertida
list ReverseLinkedList(list* myList);

// Remove elementos
void RemoveElementLinkedList(list* myList, long int element); 

// Destruir a lista
int DestroyLinkedList(list* myList); 

#endif