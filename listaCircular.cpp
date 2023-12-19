#include "listaCircular.h"

using namespace std;

listaCircular::listaCircular(){
	this->cabeca = NULL;	
}

listaCircular::~listaCircular(){
	this->limpar();
}

void listaCircular::inserir(char dado_add){
	NODE *novoNo = (NODE*)malloc(sizeof(NODE));
	if(novoNo == NULL){
		cout << "erro na alocacao de NO\n";
		return;	
	}
	
	// guarda a informacao
	novoNo->dado = dado_add;
	
	if(this->cabeca == NULL){ // primeiro item adicionado	
		this->cabeca = novoNo;
		this->cabeca->prox = this->cabeca; // proximo no da lista, que eh o primeiro
	
	} else { // proximos items
		
		NODE *noAtual = this->cabeca;
		
		while(noAtual->prox != this->cabeca){ // percorre todos nos ate o final, que eh a cabeca
			noAtual = noAtual->prox; // chega ate o ultimo no
		}
		
		// ultimo no encontrado, adiciona
		noAtual->prox = novoNo;
		novoNo->prox = this->cabeca;
	
	}
}

void listaCircular::inserirStr(string str_add){
	// adiciona uma sequencia de caracteres na lista
	for(int i=0; i<str_add.size(); i++){
		char c = str_add[i];
		this->inserir(c);
	}
}

void listaCircular::checarPalindromoComum(void){
	if(this->cabeca == NULL){ // lista vazia
		return;
	} else if(this->cabeca->prox == this->cabeca){ // lista de 1 elemento
		cout << "eh palindromo\n";
		return;
	}
	
	while(this->cabeca == this->cabeca->prox){
		
	}
}

void listaCircular::limpar(void){
	// limpa a lista
	
	if(this->cabeca == NULL){ // lista vazia
		return;
	} else if(this->cabeca->prox == this->cabeca){ // lista de 1 elemento
		this->cabeca->dado = '\0';
		this->cabeca = NULL;
		
		free(this->cabeca); // cabeça da lista (a lista só tinha 1 elemento)
		return;
	}
	
	// mais de 1 elemento
	
	NODE *temp = this->cabeca->prox;
	NODE *tempProx = temp->prox;
	
	// limpa todos apartir do segundo elemento
	while(temp->prox != this->cabeca){
		temp->dado = '\0';
		free(temp);
		
		temp = tempProx;
		tempProx = tempProx->prox;
	}
	
	temp->dado = '\0';
	tempProx->dado = '\0';
	this->cabeca = NULL;
	
	free(temp); // ultimo elemento
	free(tempProx); // cabeca da lista
	
}

void listaCircular::printar(void){
	// exibe tds items
	NODE *temp = this->cabeca;
	
	if(temp == NULL){
		cout << "lista vazia\n";
		return;
	}
	
	while(temp->prox != this->cabeca){
		cout << temp->dado;
		temp = temp->prox;
	} 
	
	// exibe o ultimo dado
	cout << temp->dado;
	cout << endl;
}

