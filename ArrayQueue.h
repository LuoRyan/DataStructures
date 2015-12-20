/**
Este arquivo � parte do projeto Data Structures
/*
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

Arquivo: ArrayQueue.h
Descri��o: Defini��es para estruturas tipo fila est�tica
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H
#define MAX 50;

#include "TAD.h"

//Cria uma fila 
array* ArrayQueueCreate();

//Verifica se h� elementos na fila 
int ArrayQueueCheck(array* myArrayQueue);

//Insere elementos na fila 
array* ArrayQueueEnqueue(array* myArrayQueue, long int element);

//Remove elementos da fila 
array* ArrayQueueDequeue(array* myArrayQueue);

//Imprime os elementos da fila 
void ArrayQueueConsult(array* myArrayQueue);

//Apaga todos os elementos e libera mem�ria 
array* ArrayQueueDestroy(array* myArrayQueue);

#endif // !ARRAYQUEUE_H