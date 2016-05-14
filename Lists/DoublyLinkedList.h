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

Arquivo: DoublyLinkedList.h
Descri��o: Defini��es para listas duplas
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "..\TAD.h"

/* Cria uma lista duplamente encadeada */
doublylist CreateDLinkedList();

/* Verifica se h� elementos na lista */
int CheckDLinkedList(doublylist* myDoublyList);

/* Insere elementos no in�cio da lista */
void InsertAtStartDLinkedList(doublylist* myDoublyList, long int element);

/* Insere elementos no meio da lista */
void InsertAtMiddleDLinkedList(doublylist* myDoublyList, long int element);

/* Insere elementos no fim da lista */
void InsertAtEndDLinkedList(doublylist* myDoublyList, long int element);

/* Busca um dado elemento na lista */
dnode* SearchElementDLinkedList(doublylist* myDoublyList, long int element);

/* Imprime todos os elementos da lista */
void ListElementsDLinkedList(doublylist* myDoublyList);

/* Remove um dado elemento da lista */
void RemoveElementDLinkedList(doublylist* myDoublyList, long int element);

/* Apaga toda a lista e libera mem�ria */
int DestroyDLinkedList(doublylist* myDoublyList);

#endif 