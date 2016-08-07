/**
Este arquivo é parte do projeto Data Structures
Este é um software livre; você pode redistribuí-lo e/ou
modificá-lo dentro dos termos da Licença Pública Geral GNU como
publicada pela Fundação do Software Livre (FSF); na versão 3 da
Licença, ou (na sua opinião) qualquer versão.

Este programa é distribuído na esperança de que possa ser  útil,
mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
Licença Pública Geral GNU para maiores detalhes.

Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
com este programa, Se não, veja <http:/*www.gnu.org/licenses/>.

Arquivo: ArrayStack.h
Descri��o: Defini��es para estruturas do tipo pilhas est�ticas
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
#include "..\TAD.h"

/* Cria uma pilha est�tica */
array* ArrayStackCreate(unsigned long int size);

/* Verifica se a pilha est� vazia ou n�o  */
int ArrayStackCheck(array* mystack);

/* Remove um elemento da pilha  */
array* ArrayStackPop(array* mystack);

/* Insere um elemento na pilha  */
array* ArrayStackPush(array* mystack, long int element);

/* Imprime todos os elementos da pilha  */
void ArrayStackConsult(array* mystack);

/* Apaga os elementos e libera mem�ria  */
array* ArrayStackDestroy(array* mystack);

#endif /* ARRAYSTACK_H */