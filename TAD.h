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

Arquivo: TAD.h
Descri��o: Defini��o dos Tipos Abstratos de Dados b�sicas usadas no projeto
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#ifndef TAD_H
#define TAD_H
#define LINE_MAX_LENGTH 500

/******************************************************************************
Listas, Pilhas e Filas
******************************************************************************/
/* N� simples */
typedef struct Node{
	long int key;
	struct Node* pointer;
} node;

/* N� duplo */
typedef struct DoubleNode {
	long int key;
	struct DoubleNode* next;
	struct DoubleNode* previous;
} dnode;

/* Lista */
typedef struct List {
	node* list;
	node* last;
	long int nodes;
}list;

/* Lista Circular */
typedef struct CircleList {
	node* list;
	long int nodes;
} circlelist;

/* Lista Dupla */
typedef struct DoublyList {
	dnode* list;
	dnode* startOfList;
	dnode* endOfList;
	long int nodes;
} doublylist;

/* Pilha */
typedef struct Stack {
	node* stack;
	node* top;
	unsigned long int nodes;
} stack;

/* Fila e Deque */
typedef struct Queue {
	node* queue;
	node* endOfQueue;
	unsigned long int nodes;
} queue;

typedef struct Deque {
	node* startOfQueue;
	node* endOfQueue;
	unsigned long int nodes;
} deque;

/* Pilha e Fila Est�ticas */
typedef struct Array {
	long int* vector;
	unsigned long int size;
	long int last;
} array;

/******************************************************************************
Heap
******************************************************************************/
typedef struct Heap{
	long int *vector;
	long int elements;
	long int maxElements;
} heap;

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
/* �rvore Bin�ria de Busca */
typedef struct nodeBST{
	long int key;
	struct nodeBST* right;
	struct nodeBST* left;
} nodetree;

typedef struct BinarySearchTree{
	nodetree* root;
	long int nodes;
} BSTree;

/* �rvore AVL */
typedef struct nodeAVL{
	long int key;
	int balanceFactor;
	struct nodeAVL* right;
	struct nodeAVL* left;
} nodeavl;

typedef struct AVLTree{
	nodeavl* root;
	long int nodes;
} AVLTree;

/*�rvore Red-Black */
typedef enum Color { RED = 0, BLACK = 1 } Color;

typedef struct nodeRB{
	long int key;
	int blackHeight;
	Color color;
	struct nodeRB* right;
	struct nodeRB* left;
	struct nodeRB* father;
} noderb;

typedef struct RedBlackTree{
	noderb* root;
	long int nodes;
} RBTree;
/******************************************************************************
Algoritmos de Compress�o de Strings
******************************************************************************/

typedef enum CompressionAlgorithm {RLE = 0, HUFFMAN = 1} CompressionAlgorithm;

typedef struct HuffmanTreeNode {
	unsigned char character;
	unsigned int occurrences;
	struct HuffmanTreeNode* parent;
	struct HuffmanTreeNode* left;
	struct HuffmanTreeNode* right;
} huffmantreenode;

/******************************************************************************
Estruturas Auxiliares
******************************************************************************/
/* Auxiliar nos desenhos das �rvores */
typedef struct Branches{
	struct Branches *previous;
	char* str;
} branches;

#endif