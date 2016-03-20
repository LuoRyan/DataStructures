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

Arquivo: StringUtilities.h
Descri��o: Defini��es de fun��es auxiliares para manipula��o de Strings
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef STRINGUTILITIES_H
#define STRINGUTILITIES_H

#include "../TAD.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define IO_ERROR -1
#define IO_SUCESS 0
#define BINARY 2
#define LINE_MAX_LENGTH 5000

#define CHAR_TO_INT(char)character){return atoi(character);} // Converte um char em um inteiro

/******************************************************************************
Fun��es Utilit�rias
******************************************************************************/

// Converte um inteiro para bin�rio
string* intToBin(int toConvert);

// Converte uma string para bin�rio
string* strToBin(string myString);

// Salva a string em um arquivo incluindo informa��es sobre a compress�o realizada
int toFile(string* myString, char* filename, CompressionAlgorithm algorithm);

// Recupera a string de um arquivo
string* fromFile(char* filename);

// Concatena duas strings
void strConcatenate(string* firstString, string* sndString);

// Copia uma string para outra
void strCopy(string* firstString, string* sndString);

// Compara duas strings
int strCompare(string* firstString, string* sndString);


/******************************************************************************
Fun��es para otimiza��o da estrutura string
******************************************************************************/
// Otimiza o uso de mem�ria para armazenar a string
void strOptimize(string* myString);

#endif // STRINGUTILITIES_H