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

Arquivo: RLE.c
Descri��o: Implementa��o das fun��es para decodifica��o RLE
Autor: Lucas de Souza Vieira <lukaslka_my08@hotmail.com>	*/

#include "RLE.h"
#define _CRT_SECURE_NO_WARNINGS 1;

/*********************************************************************************************
Run-Length Encoding:
	*Conjunto de Caracteres: A-Za-z ; 0-9;
	*Delimitadores: '@' para repeti��o de letras (A-Za-z); 
					'#' para repeti��o de n�meros (0-9)
					'-' para espa�os em branco
					'$' para repeti��o de espa�os em branco
					'&' para repeti��o dos demais caracteres
					'R' para identifica��o dessa codifica��o no arquivo

	*Exemplo:	Input:	'aaaaawwwwab   hhhhrrttttt332'
				Output: '@4a@4wab$3-@4h@2r@5t#232'

Tabela ASCII usada como base: <http://ic.unicamp.br/~everton/aulas/hardware/tabelaASCII.pdf>
**********************************************************************************************/

// Avalia as repeti��es
char* generateRLECode(rlecodenode* codingVector, int vectorSize)
{
	if (codingVector == NULL || vectorSize <= 0)
		return NULL;
	char rleEncoded[LINE_MAX_LENGTH];
	for (int i = 0; i <= vectorSize; i++) {
		int character = charToInt(codingVector[i].character);
		if (character == 32) {
			// Caractere � um espa�o em branco (' ')
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, '-');
			} else {
				strcat(rleEncoded,'$');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, '-');
			}
		} else if ((character > 64 && character < 91) || (character > 96 && character < 123)) {
			// Caractere est� em [A - Z] ou em [a - z]
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, codingVector[i].character);
			} else {
				strcat(rleEncoded, '@');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, codingVector[i].character);
			}
		} else if ((character > 47 && character < 59)) {
			// Caractere est� entre [0 - 9]
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, codingVector[i].character);
			} else {
				strcat(rleEncoded, '#');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, codingVector[i].character);
			} 
		} else {
			// Caractere � outro qualquer
			/*
			if (codingVector[i].occurrences == 1) {
				strcat(rleEncoded, codingVector[i].character);
			} else {
				strcat(rleEncoded, '&');
				strcat(rleEncoded, intToString(codingVector[i].occurrences));
				strcat(rleEncoded, codingVector[i].character);
			}*/
		}
	} // End for
	return rleEncoded;
}

// Codifica uma string e retorna a sequ�ncia codificada
string* encodeRLE(string* myString)
{
	//strOptimize(myString);
	printf("encodeRLE: %s \n", myString->string);
	string* encodedString = (string*)malloc(sizeof(string));
	rlecodenode* coding = (rlecodenode*)malloc((myString->length)*(sizeof(rlecodenode)));
	for (int i = 0; i < myString->length; i++) {
		if (i == 0) {
			coding[i].character = myString->string[i];
			coding[i].occurrences = 1;
		} else if (coding[i - 1].character == myString->string[i]) {
			coding[i - 1].occurrences++;
		} else {
			coding[i].character = myString->string[i];
			coding[i].occurrences = 1;
		}
	}
	encodedString->string = generateRLECode(coding, myString->length);
	strOptimize(encodedString);
	return encodedString;
}

// Decodifica uma string e retorna a sequ�ncia decodificada
string* decodeRLE(string* myString)
{
	return NULL;
}