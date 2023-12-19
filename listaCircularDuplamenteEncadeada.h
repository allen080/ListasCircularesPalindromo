#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// circle double linked list de strings -> csll

typedef struct node {
	struct node *anterior;
	char dado;
	struct node *prox;
} NODE;

class listaCircular {
	public:
		NODE *cabeca;
		listaCircular();
		~listaCircular();
		
		void inserir(char dado_add); // insere no fim
		void printar(void); // printa todos dados
		void printarReverso(void); // printa todos dados ao contrario
		void limpar(void); // limpar os dados da lista inteira
		void inserirStr(string str_add); // adiciona uma sequencia de caracteres na lista
		void checarPalindromoComum(void); // checa se os elementos sao palindromo
		void checarPalindromoQualquer(void); // checa se os elementos podem ser palindromos comecando de outro caracter sem ser o primeiro
};


