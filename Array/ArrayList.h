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

Arquivo: ArrayList.h
Descri��o: Defini��es para estruturas do tipo listas est�ticas
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/
#include "../TAD.h"

/* Cria uma lista est�tica */
array* ArrayListCreate(unsigned long int size);

/* Verifica se a lista est� vazia ou n�o  */
int ArrayListCheck(array* mystack);

/* Remove um elemento da lista  */
array* ArrayListRemove(array* mystack, long int key);

/* Insere um elemento na lista  */
array* ArrayListInsert(array* mystack, long int element);

/* Imprime todos os elementos da lista */ 
void ArrayListConsult(array* mystack);

/* Apaga os elementos e libera mem�ria  */
array* ArrayListDestroy(array* mystack);
