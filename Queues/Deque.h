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

Arquivo: Deque.c
Descri��o: Implementa��o de fila
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef DEQUE_H
#define DEQUE_H
#include "..\TAD.h"

/* Cria um deque */
deque CreateDeque();

/* Verifica se h� elementos no deque */
int CheckDeque(deque* myDeque);

/* Insere elementos no deque  */
void InsertAtFront(deque* myQueue, long int element);
void InsertAtBack(deque* myQueue, long int element);

/* Remove elementos do deque */
void RemoveFromFront(deque* myDeque);
void RemoveFromBack(deque* myDeque);

/* Imprime os elementos do deque */
void ConsultDeque(deque* myDeque);

/* Apaga todos os elementos e libera mem�ria */
int DestroyDeque(deque* myDeque);

#endif /* DEQUE_H */