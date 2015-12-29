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

Arquivo: BST.c
Descri��o: Implementa��o para �rvore bin�ria 
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1;
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include "..\TAD.h"

//Criar a �rvore
BSTree CreateBST(){
	BSTree myBSTree;
	myBSTree.root = NULL;
	myBSTree.nodes = 0;
	return myBSTree;
}

//Insere um elemento na �rvore
void InsertInBST(BSTree* myTree, long int key) {
	if (myTree->root == NULL){
		// �rvore vazia
		nodetree* newNode = (nodetree *)(malloc(sizeof(nodetree)));
		if (newNode != NULL){
			newNode->key = key;
			newNode->right = NULL;
			newNode->left = NULL;
		}
		myTree->root = newNode;
	} else {
		nodetree* newNode = (nodetree *)(malloc(sizeof(nodetree)));
		if (newNode != NULL){
			newNode->key = key;
			newNode->right = NULL;
			newNode->left = NULL;
		} 
		// Buscar a posi��o da nova folha
		nodetree* father = NULL;
		nodetree* current = myTree->root;
		while (current != NULL){
			if (current->key <= newNode->key){
				father = current;
				current = current->right;
			} else if (current->key > newNode->key){
				father = current;
				current = current->left;
			}
		} if (father->key > newNode->key){
			father->left = newNode;
		}
		else if (father->key <= newNode->key){
			father->right = newNode;
		}
	}
	myTree->nodes++;
}

// Remo��o de um elemento qualquer da �rvore
// Busca o elemento mais � direita
nodetree* MostRight(nodetree* tree) {
	if (tree->right != NULL) {
		return MostRight(tree->right);
	} else {
		nodetree* aux = tree;
		if (tree->left != NULL) {
			tree = tree->left;
		} else {
			tree = NULL;
		}
		return aux;
	}
}
// Busca o elemento mais � esquerda
nodetree* MostLeft(nodetree* tree) {
	if (tree->left != NULL) {
		return MostLeft(tree->left);
	} else {
		nodetree* aux = tree;
		if (tree->right != NULL) {
			tree = tree->right;
		} else {
			tree = NULL;
		}
		return aux;
	}
}
// Busca e remove elementos da �rvore bin�ria
nodetree* RemoveBSTree(nodetree* myTree, long int key) {
	nodetree *toRemove = myTree;
	nodetree *father = NULL;
	nodetree *substitute;
	nodetree *aux;
	nodetree *heritor;
	// Busca o n� a ser removido
	while (toRemove != NULL && toRemove->key != key) {
		father = toRemove;
		if (key < toRemove->key) {
			toRemove = toRemove->left;
		}
		else if (key>toRemove->key) {
			toRemove = toRemove->right;
		}
	}
	if (toRemove == NULL) {
		printf("Elemento nao encontrado ! \n");
		return myTree;
	}
	// Dois primeiros casos: O n� tem 0 ou 1 filho
	if (toRemove->left == NULL) {
		substitute = toRemove->right;
	}
	else if (toRemove->right == NULL) {
		substitute = toRemove->left;
	}
	else {
		// �ltimo caso: n� com 2 filhos
		aux = toRemove;
		substitute = toRemove->right;
		heritor = substitute->left; //Sucessor � sempre o filho mais esquerdo do substituto
		while (heritor != NULL) {
			aux = substitute;
			substitute = heritor;
			heritor = heritor->left;
		}
		if (aux != toRemove) {
			aux->left = substitute->right;
			substitute->right = toRemove->right;
		}
		/*O substituto ocupa o lugar de n� removido,
		o filho esquerda do substituto � manipulado
		para permitir isso*/
		substitute->left = toRemove->left;
	}
	if (father == NULL) {
		myTree = substitute;
	}
	else {
		if (toRemove == father->left) {
			father->left = substitute;
		}
		else {
			father->right = substitute;
		}
	}
	free(toRemove);
	return myTree;
}

void RemoveBST(BSTree* myTree, long int key) {
	myTree->root = RemoveBSTree(myTree->root, key);
	myTree->nodes--;
}

//Busca um elemento na �rvore
nodetree* SearchBST(BSTree* myTree, long int key){
	nodetree* aux = myTree->root;
	while (aux != NULL){
		if (key < aux->key){
			aux = aux->left;
		} else if (key > aux->key){
			aux = aux->right;
		} else {
			return aux;
		}
	}
	return NULL;
}

//Percorrer a �rvore
//Pr�-ordem
void PreOrderBSTree(nodetree* tree) {
	if (tree == NULL) {
		return;
	}
	else {
		printf("%ld", tree->key);
		PreOrderBSTree(tree->left);
		PreOrderBSTree(tree->right);
	}
}

void PreOrderBST(BSTree* myTree){
	PreOrderBSTree(myTree->root);
}

//Em Ordem
void InOrderBSTree(nodetree* tree) {
	if (tree == NULL) {
		return;
	}
	else {
		InOrderBSTree(tree->left);
		printf("%ld ", tree->key);
		InOrderBSTree(tree->right);
	}
}

void InOrderBST(BSTree* myTree){
	InOrderBSTree(myTree->root);
}

//Pos-�rdem
void PostOrderBSTree(nodetree* tree){
	if (tree == NULL){
		return;
	}
	else{
		PostOrderBSTree(tree->left);
		PostOrderBSTree(tree->right);
		printf("%ld", tree->key);
	}
}

void PostOrderBST(BSTree* myTree) {
	PostOrderBSTree(myTree->root);
}

//Descobrir a altura da �rvore
int HeightOfBSTree(nodetree* myTree){
	if (myTree == NULL){
		return 1;
	} else {
		int leftSubtreeHeight = HeightOfBSTree(myTree->left) + 1;
		int rightSubtreeHeight = HeightOfBSTree(myTree->right) + 1;
		if (leftSubtreeHeight < rightSubtreeHeight){
			return rightSubtreeHeight;
		} else {
			return leftSubtreeHeight;
		}
	}
}

int HeightOfBST(BSTree* myTree) {
	return HeightOfBSTree(myTree->root);
}

//Destruir a �rvore
void DestroyBSTree(nodetree* myTree){
	if (myTree == NULL){
		return;
	} else {
		DestroyBSTree(myTree->left);
		DestroyBSTree(myTree->right);
		free(myTree);
		myTree = NULL;
	}
}

void DestroyBST(BSTree* myTree){
	DestroyBSTree(myTree->root);
}

// Desenha a �rvore bin�ria
// Mostra tra�os ligando os n�s
void ShowBranch(branches *t){
	if (!t){
		return;
	}
	ShowBranch(t->previous);
	printf(t->str);
}

// Desenha a �rvore
void DrawBSTree(nodetree* myTree, branches *previous, int Left){
	if (myTree == NULL){
		return;
	}

	branches show = { previous, "    " };
	char *show_str = show.str;

	DrawBSTree(myTree->left, &show, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	if (!previous){
		show.str = "---";
	} else if (Left){
		show.str = ".--";
		show_str = "  |";
	} else {
		show.str = "`--";
		previous->str = show_str;
	}
	ShowBranch(&show);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("%ld \n",myTree->key);
	
	if (previous){
		previous->str = show_str;
	}
	show.str = "   |";

	DrawBSTree(myTree->right, &show, 0);
	if (!previous){
		printf("");
	}
}

// Desenha a �rvore bin�ria
void DrawBST(BSTree* myTree) {
	DrawBSTree(myTree->root, 0, 0);
}