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

Arquivo: Stack.h
Descri��o: Defini��es para estruturas do tipo pilhas 
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef STACK_H
#define STACK_H
#include "..\TAD.h"

/* Cria uma pilha */
stack CreateStack();

/* Verifica se a pilha est� vazia ou n�o */
int CheckStack(stack* myStack);

/* Remove um elemento da pista */
void Pop(stack* myStack);

/* Insere um elemento na pilha */
void Push(stack* myStack, int element);

/* Imprime todos os elementos da pilha */
void ConsultStack(stack* myStack);

/* Apaga os elementos e libera mem�ria */
int DestroyStack(stack* myStack);

#endif /* STACK_H */