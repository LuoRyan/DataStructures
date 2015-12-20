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
com este programa, Se n�o, veja <http://www.gnu.org/licenses/>.x

Arquivo: Programa.c
Descri��o: Teste das implementa��es das estruturas de dados
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1 // Desabilita verifica��es de seguran�a

#include <stdio.h>
#include <stdlib.h>
#include "TAD.h"
#include "Vector.h"
#include "LinkedList.h"
#include "CircleList.h"
#include "DoublyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Heap.h"
#include "SortingAlgorithms.h"
#include "BinarySearchTree.h"
#include "AVLTree.h"

// Testa as fun��es de Inser��o e Remo��o de Heap
void HeapTest() {
	heap* myHeap = CreateHeap(10);
	InsertInHeap(myHeap, 12);
	InsertInHeap(myHeap, 22);
	InsertInHeap(myHeap, -2);
	InsertInHeap(myHeap, 31);
	InsertInHeap(myHeap, 24);
	InsertInHeap(myHeap, 13);
	InsertInHeap(myHeap, 18);
	InsertInHeap(myHeap, 50);
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
	RemoveHeap(myHeap);
	printf("\n");
	ShowHeap(myHeap);
}

// Teste da �rvore AVL
void AVLTest() {
	nodeavl* myTree = CreateAVLTree();
	myTree = InsertInAVLTree(myTree, 10);
	myTree = InsertInAVLTree(myTree, 11);
	myTree = InsertInAVLTree(myTree, 12);
	myTree = InsertInAVLTree(myTree, 13);
	myTree = InsertInAVLTree(myTree, 14);
	myTree = InsertInAVLTree(myTree, 15);
	myTree = InsertInAVLTree(myTree, 5);
	DrawAVLTree(myTree, 0 ,0);
	myTree = RemoveAVLTree(myTree, 12);
	DrawAVLTree(myTree, 0, 0);
}

// Teste da �rvore Bin�ria
void BSTTest() {
	nodetree* myTree = CreateBST();
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	myTree = InsertInBST(myTree);
	DrawBST(myTree, 0, 0);
	myTree = RemoveBST(myTree, 10);
}

int main (void){
	AVLTest();
	system("pause");
	return 0;
}
