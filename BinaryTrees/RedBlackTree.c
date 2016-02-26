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
/*Fun��es utilit�rias para as rota��es*/
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

//Fun��es utilit�rias para 'parentes'
//Retorna o n�mero de filhos diretos de um n�
int CountChildren(noderb* mynode) 
{
	int Children = 0;
	if (mynode == NULL) {
		return Children;
	}
	if (mynode->left != NULL) {
		Children = Children + 1;
	}
	if (mynode->right != NULL) {
		Children = Children + 1;
	}
	return Children;
}

//Retorna o irm�o de um n�, se existir
noderb* Brother(noderb* mynode) 
{
	if (mynode == NULL) {
		// N�o existe n�
		return NULL;
	}
	else {
		if (Father(mynode) == NULL) {
			// N� n�o tem father (Raiz)
			return NULL;
		}
		else {
			if (mynode->key >= Father(mynode)->key) {
				// Filho maior que o father, logo, este filho � da direita
				// e seu irm�o da esquerda
				return Father(mynode)->left;
			}
			else {
				// Filho menor que o father, logo, este filho � da esquerda
				// e seu irm�o da direita
				return Father(mynode)->right;
			}
		}
	}
}

//Retorna o tio de um n�
noderb* Uncle(noderb* mynode)
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		noderb* child = mynode;
		noderb* father = Father(mynode);
		noderb* grandfather = GrandFather(mynode);
		if ((Father(mynode) == NULL) && (GrandFather(mynode) == NULL)) {
			return NULL;
		}
		// Descobrir se o tio � filho righteito ou leftuerdo do av�
		if (father == grandfather->left) {
			// Se o father � o filho da left, ent�o o tio � filho da righteita
			return grandfather->right;
		}
		else {
			// E se o father � o filho da righteita, ent�o o tio � da left
			return grandfather->left;
		}
	}
}

//Retorna o pai de um n�
noderb* Father(noderb* mynode)
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		return mynode->father;
	}
}

//Retorna o av� de um n�
noderb* GrandFather(noderb* mynode)
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		return mynode->father->father;
	}
}

//Retorna o bisav� de um n�
noderb* GreatGrandFather(noderb* mynode) 
{
	if (mynode == NULL) {
		return NULL;
	}
	else {
		return GrandFather(Father(mynode));
	}
}

/*Fun��es utilit�rias para Altura Negra e Cores*/
// Balanceia a altura negra de todos os n�s
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
			// mytree->BlackHeight = BlackHeight(mytree->right);
		} else {
			// Retorna -1 para a altura negra do n� que est� desbalanceado
			mytree->blackHeight = -1;
		}

	} else {
		// Retorna se n�o houver �rvore
		return;
	}
	// Retorna ao fim do ajuste
	return;
}

// Muda a color de um n�
void ChangeColor(noderb* mynode) {
	if (mynode == NULL) {
		return;
	}
	if (mynode->color == RED) {
		// Se n� for vermelho, muda para preto
		mynode->color = BLACK;
	} else {
		// Se for preto, muda pra vermelho
		mynode->color = RED;
	}
	return;
}

// Verifica as condi��es das cores de todos os n�s e promove ajustes
void ColorFixUp(noderb* mytree) {
	if (mytree == NULL) {
		return;
	} else {
		ColorFixeUp(mytree->right);
		ColorFixeUp(mytree->left);
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
	noderb* newNode;
	newNode->key = key;
	newNode->blackHeight = 0;
	newNode->color = RED;
	newNode->father = NULL;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
/* Desenha a �rvore Red-Black*/
void DrawRedBlackTree(noderb* mytree, branches *previous, int left);

/******************************************************************************
Fun��es Gerais
******************************************************************************/
/*Criar uma �rvore Red-Black*/
RBTree CreateRedBlackTree() {
	RBTree myTree;
	myTree.nodes = 0;
	myTree.root = NULL;
	return myTree;
}

/*Inserir elementos na �rvore Red-Black*/
void FixUpRedBlackTree(noderb* tree, noderb* newNode) {
	while (Father(newNode)->color == RED) {
		if (Father(newNode) == GrandFather(newNode)->left) {
			noderb* uncle = Uncle(newNode);
			uncle = GrandFather(newNode)->right;
			if (uncle->color == RED) {
				Father(newNode)->color = BLACK;
				uncle->color = BLACK;
				GrandFather(newNode)->color = RED;
				newNode = GrandFather(newNode);
			} else {

			}
		} 
	}
}

void InsertInRedBlackTree(RBTree* mytree, long int key)
{
	noderb* newNode = CreateRedBlackNode(key);
	noderb* current = mytree->root;
	noderb* father = NULL;
	// Encontra e define o pai
	while (current != NULL)
	{
		if (current->key <= newNode->key) {
			father = current;
			current = current->right;
		} else {
			father = current;
			current = current->left;
		}
	}
	if (father->key > newNode->key) {
		father->left = newNode;
		newNode->father = father;
	}
	else if (father->key <= newNode->key) {
		father->right = newNode;
		newNode->father = father;
	}
	mytree->nodes++;
	FixUpRedBlackTree(mytree->root, newNode);
}

/*Buscar elementos na �rvore Red-Black*/
noderb* SearchRedBlackTree(RBTree* mytree, long int key);

/*Remover elemento na �rvore Red-Black*/
noderb* RemoveRedBlackTree(RBTree* mytree, long int key) {
	if (mytree == NULL) {

	} else {

	}
}

/*Destruir a �rvore Red-Black*/
void DestroyRedBlackTree(RBTree* myTree);