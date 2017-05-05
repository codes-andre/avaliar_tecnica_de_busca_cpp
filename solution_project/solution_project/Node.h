#pragma once

#include <iostream>


class Node
{
private:
	int info;
	Node *esquerda;
	Node *direita;
public:
	Node();
	Node(int elemento);
	~Node();

	int getInfo();
	Node *getLeft();
	Node *getRight();

	void insertLeft(Node*);
	void insertRight(Node*);
};