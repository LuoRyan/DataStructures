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

Arquivo: CircleList.h
Descri��o: Defini��es para lista circular simples
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef CIRCLELIST_H
#define CIRCLELIST_H

#include "..\TAD.h"
#include "LinkedList.h" 

//Cria uma lista circular 
circlelist CreateCircleList(); 

//Verifica se a lista est� vazia ou n�o  
int CheckCircleList(circlelist* myList);

//Insere novos elementos na lista 
void InsertAtCircleList(circlelist* myList, long int element);

//Busca um dado valor na lista 
node* SearchElementCircleList(circlelist* myList, long int element);

//Imprime todos os elementos da lista 
void ListElementsCircleList(circlelist* myList);

//Remove um dado elemento da lista 
void RemoveElementCircleList(circlelist* myList, long int element);

//Apaga toda a lista e libera a mem�ria 
int DestroyCircleList(circlelist* myList);

#endif // !CIRCLELIST_H