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

Arquivo: RedBlackTree.h
Descri��o: Defini��o para estruturas do tipo �rvore rubro-negra
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "..\TAD.h"

/*Criar uma �rvore Red-Black*/
RBTree CreateRedBlackTree();

/*Inserir elementos na �rvore Red-Black*/
void InsertInRedBlackTree(RBTree* mytree, long int key);

/*Buscar elementos na �rvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na �rvore Red-Black*/
noderb* RemoveRedBlackTree(RBTree* mytree, long int key);

void DestroyRedBlackTree(RBTree* myTree);

/*Destruir a �rvore Red-Black*/
void DrawRedBlackTree(RBTree* myTree);

#endif //!REDBLACKTREE_H