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
#include "TAD.h"

//Criar a �rvore
nodetree* CreateBST(){
	nodetree* myTree;
	myTree = NULL;
	return myTree;
}

//Insere um elemento na �rvore
nodetree* InsertInBST(nodetree* myTree){
	if (myTree == NULL){
		// �rvore vazia
		nodetree* newNode = (nodetree *)(malloc(sizeof(nodetree)));
		if (newNode != NULL){
			printf("Inserir valor da raiz da Arvore Binaria: ");
			scanf("%ld", &newNode->key);
			newNode->right = NULL;
			newNode->left = NULL;
		}
		myTree = newNode;
		return myTree;
	} else {
		nodetree* newNode = (nodetree *)(malloc(sizeof(nodetree)));
		if (newNode != NULL){
			printf("Inserir novo elemento: ");
			scanf("%ld", &newNode->key);
			newNode->right = NULL;
			newNode->left = NULL;
		}
		else {
			printf("Falha na alocacao de memoria!! ");
			return myTree;
		}
		// Buscar a posi��o da nova folha
		nodetree* father = NULL;
		nodetree* current = myTree;
		while (current != NULL){
			if (current->key <= newNode->key){
				father = current;
				current = current->right;
			} else if (current->key > newNode->key){
				father = current;
				current = current->left;
			}
		}
		if (father->key > newNode->key){
			father->left = newNode;
		}
		else if (father->key <= newNode->key){
			father->right = newNode;
		}
	}
	return myTree;
}

// Remo��o de um elemento qualquer da �rvore
nodetree* RemoveBST(nodetree* myTree, long int key){
	nodetree* current = myTree;
	if (current == NULL) {
		return myTree;
	} else if (current->key > key) {
		current->left = RemoveBST(current->left, key);
	} else if (current->key < key) {
		current->right = RemoveBST(current->right, key);
	} else {
		if (current->left == NULL && current->right == NULL) {
			// N� n�o tem filhos
			free(current);
			return NULL;
		} else if (current->left == NULL) {
			// N� s� tem filho direito
			nodetree* toRemove = current;
			current = current->right;
			free(toRemove);
		} else if (current->right == NULL) {
			// N� s� tem filho esquerdo
			nodetree* toRemove = current;
			current = current->left;
			free(toRemove);
		} else {
			// N� tem dois filhos
			nodetree* aux = current->left;
			nodetree* father = current;
			while (aux->right != NULL){
				aux = aux->right;
				father = aux;
			}
			current->key = aux->key;
			free(aux);
			father->right = NULL;
		}
	}
	return myTree;
}

//Busca um elemento na �rvore
nodetree* SearchBST(nodetree* myTree, long int key){
	nodetree* aux = myTree;
	while (aux != NULL){
		if (key < aux->key){
			aux = aux->left;
		}
		else if (key > aux->key){
			aux = aux->right;
		} else {
			printf("Elemento encontrado!: %ld \n ", aux->key);
			return aux;
		}
	}
	printf("Elemento nao encontrado! \n");
	return NULL;
}

//Percorrer a �rvore
//Pr�-ordem
void PreOrderBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	} else {
		printf("%ld",myTree->key);
		PreOrderBST(myTree->left);
		PreOrderBST(myTree->right);
	}
}

//Em Ordem
void InorderBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	}
	else {
		InorderBST(myTree->left);
		printf("%ld", myTree->key);
		InorderBST(myTree->right);
	}
}

//Pos-�rdem
void PostOrderBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	}
	else{
		PostOrderBST(myTree->left);
		PostOrderBST(myTree->right);
		printf("%ld", myTree->key);
	}
}

//Descobrir a altura da �rvore
int HeightOfBST(nodetree* myTree){
	if (myTree == NULL){
		return 1;
	} else {
		int leftSubtreeHeight = HeightOfBST(myTree->left) + 1;
		int rightSubtreeHeight = HeightOfBST(myTree->right) + 1;
		if (leftSubtreeHeight < rightSubtreeHeight){
			return rightSubtreeHeight;
		} else {
			return leftSubtreeHeight;
		}
	}
}

//Destruir a �rvore
void DestroyBST(nodetree* myTree){
	if (myTree == NULL){
		return;
	} else {
		DestroyBST(myTree->left);
		DestroyBST(myTree->right);
		free(myTree);
		myTree = NULL;
	}
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
void DrawBST(nodetree* myTree, branches *previous, int Left){
	if (myTree == NULL){
		return;
	}

	branches show = { previous, "    " };
	char *show_str = show.str;

	DrawBST(myTree->left, &show, 1);
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

	DrawBST(myTree->right, &show, 0);
	if (!previous){
		printf("");
	}
}