#include "listaCircularDuplamenteEncadeada.h"

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
		this->cabeca->anterior = this->cabeca;
		
	} else { // proximos items
		NODE *noAtual = this->cabeca;
		
		while(noAtual->prox != this->cabeca){ // percorre todos nos ate o final, que eh a cabeca
			noAtual = noAtual->prox; // chega ate o ultimo no
		}
		
		// ultimo no encontrado, adiciona
		novoNo->anterior = noAtual;
		noAtual->prox = novoNo;
		novoNo->prox = this->cabeca;
		
		this->cabeca->anterior = novoNo;
	}
}

void listaCircular::inserirStr(string str_add){
	// adiciona uma sequencia de caracteres na lista
	for(int i=0; i<str_add.size(); i++){
		char c = str_add[i];
		this->inserir(c);
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

void listaCircular::printarReverso(void){
	// exibe tds items ao contrario
	NODE *temp = this->cabeca;
	
	if(temp == NULL){
		cout << "lista vazia\n";
		return;
	}
	
	while(temp->anterior != this->cabeca){
		temp = temp->anterior;
		cout << temp->dado;
	} 
	
	// exibe o primeiro
	cout << temp->anterior->dado;
	cout << endl;
}

void listaCircular::checarPalindromoComum(void){
	if(this->cabeca == NULL){ // lista vazia
		return;
	} else if(this->cabeca->prox == this->cabeca){ // lista de 1 elemento
		cout << "eh palindromo\n";
		return;
	}
	
	NODE *atual, *anterior;
	
	atual = this->cabeca; // primeiro char
	anterior = atual->anterior; // ultimo char
	
	while(atual->prox != this->cabeca){
		if(atual->dado != anterior->dado){
			cout << "nao eh palindromo\n";
			return;
		}
		
		atual = atual->prox;
		anterior = anterior->anterior;
	}
	
	if(atual->dado != anterior->dado){
		cout << "nao eh palindromo\n";
	} else {
		cout << "eh palindromo!\n";
	}
	
}

void listaCircular::checarPalindromoQualquer(void){
 	// checa se os elementos podem ser palindromos comecando de outro caracter sem ser o primeiro
	if(this->cabeca == NULL || this->cabeca->prox == this->cabeca){ // lista vazia ou com apenas 1 elemento
		return;
	} 
	
	listaCircular novaLista; // nova lista pra verificar
	
	NODE *charInicialVerificar = this->cabeca;
	
	int indexLetraInicio = 1;
	
	do {
		// limpa dados antigos
		novaLista.limpar();
		
		NODE *atual = charInicialVerificar;
		
		// preenche a nova lista
		while(atual->anterior != charInicialVerificar) {
			novaLista.inserir(atual->dado);
			atual = atual->anterior;
		}
		novaLista.inserir(atual->dado); // ultimo dado
		
		// exibe os 2
		
		cout << endl;
		this->printar();
		novaLista.printar();
		
		NODE *novaListaAtual = novaLista.cabeca;
		atual = this->cabeca;
		
		while(atual->prox != this->cabeca){
			
			if(atual->dado != novaListaAtual->dado){
				//cout << "nao eh palindromo nunca\n";
				break;
			}
			
			atual = atual->prox;
			novaListaAtual = novaListaAtual->prox;
		}
		
		if(atual->dado != novaListaAtual->dado){
			cout << "nao eh palindromo quando comeca na " << indexLetraInicio << " letra (" << charInicialVerificar->dado << ")\n";
		} else {
			cout << "[*] pode ser palindromo maluco quando comeca na " << indexLetraInicio << " letra (" << charInicialVerificar->dado << ")\n";
			return;
		}
		
		charInicialVerificar = charInicialVerificar->prox;
		indexLetraInicio++;
	} while(charInicialVerificar != this->cabeca);
	
	cout << "[!] nao eh palindromo nunca\n";
}

