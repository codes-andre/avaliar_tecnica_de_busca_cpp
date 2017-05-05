#pragma once
#include "Node.h"

class ArvoreBinariaAVL
{
public:
	Node *raiz;

	ArvoreBinariaAVL();
	ArvoreBinariaAVL(int data);
	~ArvoreBinariaAVL();

	void insere_elemento(int e);
	void imprime_preordem(Node * inicio);
	
	int altura(Node * inicio);
	Node* existe_elemento_node(int elemento);
	int existe_elemento_int(int elemento);
	Node *rotacionaesq(Node * rotacionadoesq);
	Node *rotacionadir(Node * rotacionadodir);
	Node *balancear(Node *atual);
};
