
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Huffman.h"
#define DEBUG

// Codifica uma string em uma �rvore de Huffman
huffmantreenode* encodeHuffman(char* myString)
{

	int stringSize = strlen(myString);
	int vectorSize = 0;
	int position = 0;
	int occurrence = 0;
	char character;
	if (myString == NULL)
		return NULL;
	int* occurrences = (int*)malloc(stringSize*sizeof(int));
	double* frequency = (double*)malloc(stringSize*sizeof(double));
	char* characters = (char*)malloc((stringSize + 1)*sizeof(char));
	char* string = (char*)malloc((stringSize + 1)*sizeof(char));
	strcpy(string, myString);
	FILE* file = fopen("tmpHuffmanOutputFile", "w");
	// Conta as ocorr�ncias de cada caractere
	for (int i = 0; i < stringSize; i++) {
		if (string[i] != '@') {
			occurrence = 1;
			character = string[i];
			characters[position] = string[i];
			string[i] = '@';
			for (int j = (i + 1); j < stringSize; j++) {
				printf("%s \n", string);
				if (string[j] == character) {
					occurrence++;
					string[j] = '@';
				}
			}
			occurrences[position] = occurrence;
			position++;
			vectorSize++;
		}
		occurrence = 0;
	}
	for (int i = 0; i < vectorSize; i++) {
		printf("%c \t %d \n", characters[i], occurrences[i]);
	}
	printf("vectorSize: %d \n", vectorSize);
	printf("position: %d \n", position);
	// Ordenar as frequ�ncias - Bubble Sort
	/*charfrequency aux;
	for (long int i = 1; i <= vectorSize; i++) {
		for (long int j = 0; j < (vectorSize); j++) {
			/* Se o valor da posi��o j for maior que o valor da posi��o
			j+1, ent�o trocar a posi��o dos dois valores 
			if (charFrequency[j].frequency > charFrequency[j + 1].frequency) {
				aux = charFrequency[j];
				charFrequency[j] = charFrequency[j + 1];
				charFrequency[j + 1] = aux;
			}
		}
	}*/
	// Montar a �rvore
	return NULL;
}

// Decodifica uma �rvore de Huffman
char* decodeHuffman(huffmantreenode* huffmanTree)
{
	return NULL;
}
