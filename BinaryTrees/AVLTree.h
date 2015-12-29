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

Arquivo: AVLTree.h
Descri��o: Defini��es para �rvores AVL
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef AVLTREE_H
#define AVLTREE_H
#include "..\TAD.h"

/*Criar uma �rvore AVL*/
AVLTree CreateAVLTree();

/*Inserir elementos na �rvore AVL*/
void InsertInAVLTree(AVLTree* myTree, long int key);

/*Buscar elementos na �rvore AVL*/
nodeavl* SearchAVLTree(AVLTree* myTree, long int key);

/*Remover elemento na �rvore AVL*/
void RemoveAVLTree(AVLTree* myTree, long int key);

/*Destruir a �rvore AVL*/
void DestroyAVLTree(AVLTree* myTree);

/*Desenha a �rvore AVL*/
void DrawAVLTree(AVLTree* myTree);

#endif // AVLTREE_H