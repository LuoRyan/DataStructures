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

Arquivo: StringUtilities.c
Descri��o: Implementa��o de fun��es auxiliares para manipula��o de Strings
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "StringUtilities.h"

// Obtem o n�mero de linhas do arquivo
unsigned int getLines(char* fileName)
{
	unsigned int countLines = 0;
	int character = 0;
	FILE* file = fopen(fileName, "rb");
	while ((character = fgetc(file) != EOF)){
		if (character == '\n')
			countLines++;
	}
	return countLines++;
}

// Converte um inteiro para bin�rio
inline char* intToBin(int toConvert)
{
	char* binarySequence;
	itoa(toConvert, binarySequence, BINARY);
	return binarySequence;
}

// Salva a string em um arquivo incluindo informa��es sobre a compress�o realizada
inline int toFile(char * string, char * filename, CompressionAlgorithm algorithm)
{
	FILE* file;
	file = fopen(filename, "wb");
	if (file == NULL) {
		printf("Failed to save file! \n");
		return IO_ERROR;;
	}
	fflush(stdout);
	fprintf(file, "%s \n", intToBin(algorithm));
	for (int i = 0; i < strlen(string); i++) {
		fflush(stdout);
		fprintf(file, "%s \n", string[i]);
	}
	fclose(file);
	printf("Successfully saved file! \n");
	return IO_SUCESS;
}

// Recupera a string de um arquivo
inline char* fromFile(char * filename)
{
	
}

