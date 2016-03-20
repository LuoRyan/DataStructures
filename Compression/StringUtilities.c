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
	FILE* file = fopen(fileName, "r");
	while ((character = fgetc(file) != EOF)){
		if (character == '\n')
			countLines++;
	}
	return countLines++;
}

// Obtem o n�mero de caracteres no arquivo
unsigned int getCharacteres(char* fileName)
{
	unsigned int countChars = 0;
	int character = 0;
	FILE* file = fopen(fileName, "r");
	while ((character = fgetc(file) != EOF)) {
		if (character != '\n')
			countChars++;
	}
	return countChars;
}

// Converte um inteiro para bin�rio
inline string* intToBin(int toConvert)
{
	string* binarySequence;
	//itoa(toConvert, binarySequence->string, BINARY); // Usada em alguns compiladores mais antigos
	_itoa(toConvert, binarySequence->string, BINARY);
	binarySequence->length = strlen(binarySequence->string);
	return binarySequence;
}

string * strToBin(string myString)
{
	return NULL;
}

// Salva a string em um arquivo incluindo informa��es sobre a compress�o realizada
int toFile(string* myString, char* filename, CompressionAlgorithm algorithm)
{
	FILE* file;
	file = fopen(filename, "w");
	if (file == NULL) {
		printf("Failed to save file! \n");
		return IO_ERROR;;
	}
	fflush(stdout);
	//fprintf(file, "%s \n", intToBin(algorithm));
	for (int i = 0; i < strlen(myString->string); i++) {
		fflush(stdout);
		fputc(myString->string[i], file);
	}
	fclose(file);
	printf("Successfully saved file! \n");
	return IO_SUCESS;
}

// Recupera a string de um arquivo
string* fromFile(char* filename)
{
	FILE* file;
	file = fopen(filename, "r");
	int lines;
	string* myString = (string*)malloc(sizeof(string));
	myString->string = (char*)malloc(LINE_MAX_LENGTH*sizeof(char));
	myString->length = 50;
	if (file == NULL)
		return NULL;
	lines = getLines(filename);
	while (fgets(myString->string, LINE_MAX_LENGTH, file)){}
	return myString;
}

// Concatena duas strings
void strConcatenate(string * firstString, string * sndString)
{
	if (firstString == NULL || sndString == NULL || 
		firstString->string == NULL || sndString->string == NULL) 
		return;
	strOptimize(firstString);
	strOptimize(sndString);
	char* strConcat = (char*)malloc((firstString->length + sndString->length + 1)*sizeof(char));
	strcat(strConcat, firstString->string);
	strcat(strConcat, sndString->string);
	free(firstString->string);
	firstString->string = strConcat;
	strOptimize(firstString);
}

// Copia uma string para outra
void strCopy(string * firstString, string * sndString)
{
	if (firstString == NULL || sndString == NULL ||
		firstString->string == NULL || sndString->string == NULL)
		return;
	strOptimize(firstString);
	strOptimize(sndString);
	char* strCopy = (char*)malloc((firstString->length + sndString->length)*sizeof(char));
	strcpy(firstString->string, sndString->string);
	strOptimize(firstString);
}

// Compara duas strings
int strCompare(string * firstString, string * sndString)
{
	if (firstString == NULL || sndString == NULL ||
		firstString->string == NULL || sndString->string == NULL)
		return;
	strOptimize(firstString);
	strOptimize(sndString);
	return strcmp(firstString->string, sndString->string);
}

// Otimiza o uso de mem�ria para armazenar a string
void strOptimize(string * myString)
{
	if (myString == NULL || myString->string == NULL)
		return;
	int length = strlen(myString->string);
	char* strTemp = myString->string;
	free(myString->string);
	myString->string = (char*)malloc((length + 1)*sizeof(char));
	myString->string = strTemp;
	free(strTemp);
}
