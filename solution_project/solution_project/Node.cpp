#include "Node.h"

Node::Node(int dado) : info(dado)
{
	this->esquerda = NULL;
	this->direita = NULL;
}
Node::Node() {
	this->esquerda = NULL;
	this->direita = NULL;
}
Node::~Node()
{
}


int Node::getInfo() {
	return this->info;
}

Node *Node::getLeft() {
	return this->esquerda;
}

Node *Node::getRight() {
	return this->direita;
}


void Node::insertRight(Node *inserir) {
	this->direita = inserir;
}

void Node::insertLeft(Node *inserir) {
	this->esquerda = inserir;
}