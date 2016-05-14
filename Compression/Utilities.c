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

Arquivo: Utilities.c
Descri��o: Implementa��es de fun��es utilitarias de manipula��o de texto
Autor: Lucas de Souza Vieira <lucassouzavieiraengcomp@gmail.com>	*/

#define _CRT_SECURE_NO_WARNINGS 1
#include "Utilities.h"

/* Converte um inteiro em uma string */
char* intToString(int integer)
{
	char buffer[10] = {'0'};
	sprintf(buffer, '%d', integer);
	printf("intToString: %s \n", buffer);
	return (buffer);
}

/* Obtem o numero de linhas de um arquivo */
int getLines(char* filename) 
{
	int countLines = 0;
	int character = 0;
	FILE* file = fopen(filename, "r");
	while ((character = fgetc(file) != EOF)) {
		if (character == '\n')
			countLines++;
	}
	return countLines++;
}

/* Salva a string em um arquivo incluindo informa��es sobre a compress�o realizada */
int toFile(char* myString, char* filename)
{
	FILE* file;
	file = fopen(filename, "w");
	if (file == NULL) {
		printf("Failed to save file! \n");
		return -1;
	}
	fflush(stdout);
	/*for (int i = 0; i < strlen(myString); i++) {
		fflush(stdout);
		fputc(myString, file);
	}*/
	fprintf(file, "%s", myString);
	fclose(file);
	printf("Successfully saved file! \n");
	return 1;
}

/* Recupera a string de um arquivo */
char* fromFile(char* filename)
{
	FILE* file;
	int lines;
	file = fopen(filename, "r");
	lines = getLines(filename);
	char* string = (char*)malloc(LINE_MAX_LENGTH*sizeof(char));
	if (file == NULL)
		return NULL;
	while (fgets(string, LINE_MAX_LENGTH, file)) {}
	fclose(file);
	return string;
}