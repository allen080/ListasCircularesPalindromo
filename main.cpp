#include <iostream>
#include "listaCircularDuplamenteEncadeada.h"

using namespace std;

int main(void){	
	listaCircular lista;
	
	lista.inserirStr("cabaca"); // cabaca
	
	lista.printar();
	cout << endl;
	lista.checarPalindromoQualquer();

	return 0;
} 
