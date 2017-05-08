#include "ArvoreBinariaAVL.h"

ArvoreBinariaAVL::ArvoreBinariaAVL(){
	this->raiz = NULL;
}

ArvoreBinariaAVL::ArvoreBinariaAVL(int data)
{
	this->raiz = new Node(data);
}

ArvoreBinariaAVL::~ArvoreBinariaAVL()
{

}

void ArvoreBinariaAVL::insere_elemento(int e) {


	Node *p = this->raiz;
	Node *q = NULL;

	for (; p != NULL;) {
		q = p;

		if (e < p->getInfo())
			p = p->getLeft();
		else
			p = p->getRight();
	}

	Node *insere = new Node(e);

	if (q == NULL)
		this->raiz = insere;
	else if (e < q->getInfo())
		q->insertLeft(insere);
	else
		q->insertRight(insere);
	
	balancear(this->raiz);

}

void ArvoreBinariaAVL::imprime_preordem(Node *inicio) {
	if (inicio != NULL) {
		std::cout << inicio->getInfo() << " ";
		imprime_preordem(inicio->getLeft());
		imprime_preordem(inicio->getRight());
	}
	return;
}

int ArvoreBinariaAVL::altura(Node * inicio) {
	int tamanhoEsq = 0, tamanhoDir = 0;
	Node *left = inicio->getLeft();
	Node *right = inicio->getRight();

	if (left != NULL)
		tamanhoEsq = 1 + altura(inicio->getLeft());

	if (right != NULL)
		tamanhoDir = 1 + altura(inicio->getRight());


	if (tamanhoEsq > tamanhoDir)
		return tamanhoEsq;
	else
		return tamanhoDir;
}

Node* ArvoreBinariaAVL::existe_elemento_node(int elemento) {
	Node * atual = raiz;
	while (atual != NULL) {
		if (atual->getInfo() == elemento)
			return atual;
		else if (elemento < atual->getInfo())
			atual = atual->getLeft();
		else
			atual = atual->getRight();
	}
	return false;
}

int ArvoreBinariaAVL::existe_elemento_int(int elemento) {
	Node * atual = raiz;

	while (atual != NULL) {
		if (atual->getInfo() == elemento)
			return atual->getInfo();
		else if (elemento < atual->getInfo())
			atual = atual->getLeft();
		else
			atual = atual->getRight();
	}
	return -1;
}

Node *ArvoreBinariaAVL::rotacionaesq(Node *p) {
	Node *q = p->getRight();
	Node *aux = q->getLeft();
	q->insertLeft(p);
	p->insertRight(aux);
	return q;
}

Node *ArvoreBinariaAVL::rotacionadir(Node * rotacionadodir) {
	Node * q1 = rotacionadodir->getLeft();
	Node * aux1 = q1->getRight();
	q1->insertRight(rotacionadodir);
	rotacionadodir->insertLeft(aux1);
	return q1;
}

Node *ArvoreBinariaAVL::balancear(Node *p) {
	if (p == NULL) return p;

	bool ehRaiz = (p == this->raiz ? true : false);

	int tamanhoD = 0, tamanhoE = 0;
	Node *right = p->getRight();
	Node *left = p->getLeft();

	if (right != NULL)
		tamanhoD = altura(right) + 1;
	if (left != NULL)
		tamanhoE = altura(left) + 1;

	int fb_node = tamanhoE - tamanhoD;

	if (fb_node == 0 || fb_node == -1 || fb_node == 1) {

		if (left != NULL) {
			left = balancear(left);
			p->insertLeft(left);
		}
		if (right != NULL) {
			right = balancear(right);
			p->insertRight(right);
		}
	}
	else if (fb_node <= -2)
	{
		Node *q_right = right->getRight();
		Node *q_left = right->getLeft();
		tamanhoD = 0; tamanhoE = 0;

		if (q_right != NULL)
			tamanhoD = altura(q_right) + 1;
		if (q_left != NULL)
			tamanhoE = altura(q_left) + 1;

		int fb_sub = tamanhoE - tamanhoD;

		if (fb_sub >= 2) {
			left = balancear(left);
			p->insertLeft(left);
		}
		else if (fb_sub <= -2) {
			right = balancear(right);
			p->insertRight(right);
		}
		else if (fb_sub == 1) {
			right = rotacionadir(right);
			p->insertRight(right);
			p = rotacionaesq(p);
		}
		else
			p = rotacionaesq(p);
	}
	else
	{
		Node *q_right = left->getRight();
		Node *q_left = left->getLeft();
		tamanhoD = tamanhoE = 0;

		if (q_right != NULL)
			tamanhoD = altura(q_right) + 1;
		if (q_left != NULL)
			tamanhoE = altura(q_left) + 1;

		int fb_sub = tamanhoE - tamanhoD;

		if (fb_sub == 2) {
			left = balancear(left);
			p->insertLeft(left);
		}
		else if (fb_sub == -2){
			right = balancear(right);
			p->insertRight(right);
		}
		else if (fb_sub == -1) {
			left = rotacionaesq(left);
			p->insertLeft(left);
			p = rotacionadir(p);
		}
		else
			p = rotacionadir(p);
	}
	if (ehRaiz)
		this->raiz = p;

	return p;

}