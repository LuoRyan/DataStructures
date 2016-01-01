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

Arquivo: RedBlackTree.c
Descri��o: Implementa��o de �rvores RedBlack
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RedBlackTree.h"

/******************************************************************************
Fun��es Utilit�rias
******************************************************************************/
/*Fun��es utilit�rias para as rota��es*/
void RotateRightRedBlackTree(noderb* mytree, noderb* root, noderb* pivot);
void RotateLeftRedBlackTree(noderb* mytree, noderb* root, noderb* pivot);

/*Fun��es utilit�rias para 'parentes'*/
int CountChildren(noderb* mynode);
noderb* Brother(noderb* mynode);
noderb* Uncle(noderb* mynode);
noderb* Father(noderb* mynode);
noderb* GrandFather(noderb* mynode);
noderb* GreatGrandFather(noderb* mynode);

/*Fun��es utilit�rias para Altura Negra*/
int BlackHeight(noderb* mynode);
int Height(noderb* mynode);
void SetBlackHeight(noderb* mytree);

/* Desenha a �rvore Red-Black*/
void DrawRedBlackTree(noderb* mytree, branches *previous, int left);

/******************************************************************************
Fun��es Gerais
******************************************************************************/
/*Criar uma �rvore Red-Black*/
RBTree CreateRedBlackTree();

/*Inserir elementos na �rvore Red-Black*/
void InsertInRedBlackTree(RBTree* mytree);

/*Buscar elementos na �rvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na �rvore Red-Black*/
void RemoveRedBlackTree(RBTree* mytree, long int key);

/*Destruir a �rvore Red-Black*/
void DestroyRedBlackTree(AVLTree* myTree);

/*Destruir a �rvore Red-Black*/
void DrawRedBlackTree(RBTree* myTree);