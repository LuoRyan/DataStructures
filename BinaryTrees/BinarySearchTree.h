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

Arquivo: BinarySearchTree.h
Descri��o: Defini��es para estruturas do tipo �rvore bin�ria de busca
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "..\TAD.h"

/* Criar a �rvore   */
BSTree CreateBST();

/* Insere um elemento na �rvore  */
void InsertInBST(BSTree* myTree, long int key);

/* Remove um elemento da �rvore  */
void RemoveBST(BSTree* myTree, long int key);

/* Busca um elemento na �rvore  */
nodetree* SearchBST(BSTree* myTree, long int key);

/* Maneiras de percorrer a �rvore  */
void PreOrderBST(BSTree* myTree);
void InOrderBST(BSTree* myTree);
void PostOrderBST(BSTree* myTree);

/* Ilustra a estrutura da �rvore - r-e-d (Pr�ordem)   */
void DrawBST(BSTree* myTree);

/* Descobrir a altura da �rvore */ 
int HeightOfBST(BSTree* myTree);

/* Destruir a �rvore */ 
void DestroyBST(BSTree* myTree);
#endif /* !BST_H */