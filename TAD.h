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

// Listas, Pilhas e Filas din�micas
struct node{
	long int key;
	struct node* pointer;
};

// Listas Duplas
struct DoubleNode {
	long int key;
	struct DoubleNode* next;
	struct DoubleNode* previous;
};

typedef struct DoubleNode dnode;
typedef struct node node;

struct List {
	node* list;
	node* last;
	long int nodes;
};

struct CircleList {
	node* list;
	node* startOfList;
	node* endOfList;
	long int nodes;
};

struct DoublyList {
	dnode* list;
	dnode* startOfList;
	dnode* endOfList;
	long int nodes;
};

struct Stack {
	node* stack;
	node* top;
	long int nodes;
};

struct Queue {
	node* queue;
	node* endOfQueue;
	long int nodes;
};

// Pilhas e Filas Din�micas
struct Array {
	long int* vector;
	long int size;
	long int last;
};

// Heaps
struct Heap{
	long int *vector;
	long int elements;
	long int maxElements;
};

// Grafos
struct Graph{
	int weighing;
	int vertices;
	int maxDegree;

};

// �rvores Bin�rias
struct nodeBST{
	long int key;
	struct nodeBST* right;
	struct nodeBST* left;
};

//�rvores AVL
struct nodeAVL{
	long int key;
	int balanceFactor;
	struct nodeAVL* right;
	struct nodeAVL* left;
};

//�rvores Red-Black
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

// Conven��es de nome
typedef struct Array array;
typedef struct List list;
typedef struct CircleList circlelist;
typedef struct DoublyList doublylist;
typedef struct Stack stack;
typedef struct Queue queue;
typedef struct nodeBST nodetree;
typedef struct nodeRB noderb;
typedef struct nodeAVL nodeavl;
typedef struct Heap heap;

// Auxiliar nos desenhos das �rvores
struct Branches{
	struct Branches *previous;
	char* str;
};

typedef struct Branches branches;

#endif