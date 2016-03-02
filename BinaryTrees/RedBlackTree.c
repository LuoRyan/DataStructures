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
Descri��o: Implementa��o para estruturas do tipo �rvore rubro-negras
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RedBlackTree.h"
#include <stdlib.h>
#include <stdio.h>
/******************************************************************************
Fun��es Utilit�rias
******************************************************************************/

//Retorna o pai do n� atual
noderb* Father(noderb* mynode)
{
	return mynode->father;
}

//Retorna o irm�o do n� atual
noderb* Brother(noderb* mynode) 
{
	noderb* father = Father(mynode);
	if (father == NULL)
		return NULL;
	if (father->key > mynode->key) {
		return father->right;
	} else {
		return father->left;
	}
}

//Rota��o � direita sobre o n�
noderb* RotateRightRedBlackTree(noderb* mynode) 
{
	noderb* aux = mynode->left;
	if (aux->right != NULL) {
		/* Se o filho do n� atual tem sub-�rvore � direita
		Ent�o o n� atual ter� como filho a sub-�rvore esquerda do filho*/
		mynode->left = aux->right;
	}
	else {
		mynode->left = NULL;
	}
	// O n� atual vira filho direito do seu pr�prio filho
	aux->right = mynode;
	return aux;
}

//Rota��o � esquerda sobre o n�
noderb* RotateLeftRedBlackTree(noderb* mynode) 
{
	noderb* aux = mynode->right;
	if (aux->left != NULL) {
		/* Se o filho do n� atual tem sub-�rvore � esquerda
		Ent�o o n� atual ter� como filho a sub-�rvore direita do filho*/
		mynode->right = aux->left;
	}
	else {
		mynode->right = NULL;
	}
	// O n� atual vira filho esquerda do seu pr�prio filho
	aux->left = mynode;
	return aux;
}

//Balanceia a altura negra de todos os n�s
int BlackHeight(noderb* mynode) 
{
	if (mynode == NULL) {
		/*N� nulo � por defini��o negro*/
		return 1;
	} else if (mynode->color == BLACK) {
		/*N� preto conta na altura negra*/
		int rightBlackHeight = BlackHeight(mynode->right);
		int leftBlackHeight = BlackHeight(mynode->left);
		if (rightBlackHeight == leftBlackHeight) {
			//return rightBlackHeight + 1;
			return leftBlackHeight + 1;
		} else {
			// �rvore desbalanceada
			return EXIT_FAILURE;
		}
	} else {
		/*N� vermelho n�o conta na altura negra*/
		int rightBlackHeight = BlackHeight(mynode->right);
		int leftBlackHeight = BlackHeight(mynode->left);
		if (rightBlackHeight == leftBlackHeight) {
			//return rightBlackHeight;
			return leftBlackHeight;
		} else {
			// �rvore desbalanceada
			return EXIT_FAILURE;
		}
	}
}

//Calcula a altura da �rvore
int Height(noderb* mytree) 
{
	if (mytree == NULL) {
		/* A �rvore ou n� n�o tem elementos,
		nesse caso tem altura n-1*/
		return -1;
	} else {
		/*Nesse caso, calcular a altura das sub-�rvores
		Nesse caso, recursivamente*/
		int heightLeft = Height(mytree->left) + 1;
		int heightRight = Height(mytree->right) + 1;
		if (heightLeft < heightRight) {
			return heightRight;
		} else {
			return heightLeft;
		}
	}
}

//Recalcula a altura negra de todos os n�s da �rvore
void SetBlackHeight(noderb* mytree)
{
	if (mytree != NULL) {
		//Percorre as sub-�rvores configurando as alturas negras
		SetBlackHeight(mytree->left);
		SetBlackHeight(mytree->right);
		// Ajusta o fator de balaceamento do n� current
		if ((BlackHeight(mytree->left) == BlackHeight(mytree->right))) {
			// Nesse caso, a �rvore est� perfeitamente balaceada
			mytree->blackHeight = BlackHeight(mytree->left);
			//mytree->BlackHeight = BlackHeight(mytree->right);
		} else {
			// Retorna -1 para a altura negra do n� que est� desbalanceado
			mytree->blackHeight = -1;
		}
	} else {
		// Retorna se n�o houver �rvore
		return;
	}
	return;
}

//Altera a cor de um n�
void ChangeColor(noderb* mynode) {
	if (mynode == NULL) {
		return;
	}
	if (mynode->color == RED) {
		mynode->color = BLACK;
	} else {
		mynode->color = RED;
	}
	return;
}

// Verifica as condi��es das cores de todos os n�s e promove ajustes
void ColorFixUp(noderb* mytree) {
	if (mytree == NULL) {
		return;
	} else {
		ColorFixUp(mytree->right);
		ColorFixUp(mytree->left);
		if (mytree->blackHeight == -1) {
			if (Brother(mytree) == NULL) {
				if (mytree->right != NULL) {
					mytree->right->color = RED;
					return;
				}
			} else {
				mytree->color = BLACK;
				return;
			}
		} else {
			return;
		}
	}
	return;
}

// Inicializa um n�
noderb* CreateRedBlackNode(long int key) 
{
	noderb* newNode = (noderb*) malloc(sizeof(noderb));
	newNode->key = key;
	newNode->blackHeight = 0;
	newNode->color = RED;
	newNode->father = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

/******************************************************************************
Fun��es Gerais
******************************************************************************/

