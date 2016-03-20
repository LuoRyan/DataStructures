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

Arquivo: TAD.h
Descri��o: Defini��o dos Tipos Abstratos de Dados b�sicas usadas no projeto
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef TAD_H
#define TAD_H

/******************************************************************************
Listas, Pilhas e Filas
******************************************************************************/
// N� simples
struct Node{
	long int key;
	struct Node* pointer;
};

// N� duplo
struct DoubleNode {
	long int key;
	struct DoubleNode* next;
	struct DoubleNode* previous;
};

typedef struct DoubleNode dnode;
typedef struct Node node;

// Lista
struct List {
	node* list;
	node* last;
	long int nodes;
};

// Lista Circular
struct CircleList {
	node* list;
	long int nodes;
};

// Lista Dupla
struct DoublyList {
	dnode* list;
	dnode* startOfList;
	dnode* endOfList;
	long int nodes;
};

// Pilha
struct Stack {
	node* stack;
	node* top;
	unsigned long int nodes;
};

//Fila e Deque
struct Queue {
	node* queue;
	node* endOfQueue;
	unsigned long int nodes;
};

struct Deque {
	node* startOfQueue;
	node* endOfQueue;
	unsigned long int nodes;
};

// Pilha e Fila Est�ticas
struct Array {
	long int* vector;
	unsigned long int size;
	long int last;
};

/******************************************************************************
Heap
******************************************************************************/
struct Heap{
	long int *vector;
	long int elements;
	long int maxElements;
};

/******************************************************************************
Grafos
******************************************************************************/
struct Graph{
	int weighing;
	int vertices;
	int maxDegree;

};

/******************************************************************************
�rvores Bin�rias
******************************************************************************/
// �rvore Bin�ria de Busca
struct nodeBST{
	long int key;
	struct nodeBST* right;
	struct nodeBST* left;
};
typedef struct nodeBST nodetree;

struct BinarySearchTree{
	nodetree* root;
	long int nodes;
};

//�rvore AVL
struct nodeAVL{
	long int key;
	int balanceFactor;
	struct nodeAVL* right;
	struct nodeAVL* left;
};
typedef struct nodeAVL nodeavl;

struct AVLTree{
	nodeavl* root;
	long int nodes;
};

//�rvore Red-Black
enum Color { RED = 0, BLACK = 1 };
typedef enum Color Color;

struct nodeRB{
	long int key;
	int blackHeight;
	Color color;
	struct nodeRB* right;
	struct nodeRB* left;
	struct nodeRB* father;
};
typedef struct nodeRB noderb;

struct RedBlackTree{
	noderb* root;
	long int nodes;
};
/******************************************************************************
Algoritmos de Compress�o de Strings
******************************************************************************/

typedef enum CompressionAlgorithm {RLE = 0, HUFFMAN = 1} CompressionAlgorithm;

typedef struct String {
	char* string;
	unsigned int length;
} string;

/******************************************************************************
Redefini��o de nomes
******************************************************************************/
typedef struct Array array;
typedef struct List list;
typedef struct CircleList circlelist;
typedef struct DoublyList doublylist;
typedef struct Stack stack;
typedef struct Queue queue;
typedef struct Deque deque;
typedef struct Heap heap;
typedef struct BinarySearchTree BSTree;
typedef struct AVLTree AVLTree;
typedef struct RedBlackTree RBTree;

/******************************************************************************
Estruturas Auxiliares
******************************************************************************/
// Auxiliar nos desenhos das �rvores
struct Branches{
	struct Branches *previous;
	char* str;
};

typedef struct Branches branches;

#endif