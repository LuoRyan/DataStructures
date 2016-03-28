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
Descri��o: Algoritmo RLE para Compress�o de Texto
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#ifndef RLE_H
#define RLE_H
#include "..\TAD.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* encodeRLE(char* myString);

char* decodeRLE(char* myString);

#endif //RLE_H
