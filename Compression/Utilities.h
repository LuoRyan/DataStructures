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

Arquivo: Utilities.h
Descri��o: Defini��es para fun��es utilitarias de manipula��o de texto
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef UTILITIES_H
#define UTILITIES_H

#include "..\TAD.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Converte um inteiro em uma string
char* intToString(int integer);

// Salva a string em um arquivo incluindo informa��es sobre a compress�o realizada
int toFile(char* myString, char* filename);

// Recupera a string de um arquivo
char* fromFile(char* filename);

#endif // !UTILITIES_H