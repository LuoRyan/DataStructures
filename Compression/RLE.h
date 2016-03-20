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

Arquivo: RLE.h
Descri��o: Defini��o de fun��es para decodifica��o RLE
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef RLE_H
#define RLE_H
#include "../TAD.h"
#include <stdio.h>
#include <string.h>

// Codifica uma string e retorna a sequ�ncia codificada
char* encodeRLE(char* myString);

// Decodifica uma string e retorna a sequ�ncia decodificada
char* decodeRLE(char* myString);

#endif // !RLE_H
