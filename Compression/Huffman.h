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

Arquivo: Huffman.h
Descri��o: Defini��o de fun��es para codifica��o de Huffman
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "../TAD.h"
#include "StringUtilities.h"
#include <stdio.h>
#include <string.h>

// Codifica uma string e retorna a sequ�ncia codificada
string* encodeHuffman(string* myString);

// Decodifica uma string e retorna a sequ�ncia decodificada
string* decodeHuffman(string* myString);

#endif // HUFFMAN_H