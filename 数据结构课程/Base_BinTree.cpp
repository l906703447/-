#include "Base_BinTree.h"
#include <iostream>
#include "Queue.h"


Base_BinTree::Base_BinTree() : 
	root{0}
{
}

Base_BinTree::~Base_BinTree()
{
	postTravasal(root, [](Node& p)->void { delete &p; });
}

void Base_BinTree::preTravasal()
{
	preTravasal(root);
}

void Base_BinTree::postTravasal()
{
	postTravasal(root, [](Node& p)->void { std::cout << p.data << std::endl; });
}

void Base_BinTree::inTravasal()
{
	inTravasal(root);
}

void Base_BinTree::levelTravasal()
{
	Queue<Node> q;
	if (!root) {
		return;
	}
	else {
		q.push(*root);
	}
	
	while (!q.empty()) {
		std::cout << q.front().data << std::endl;
		Node tmp = q.pop();
		if (tmp.left) {
			q.push(*(tmp.left));
		}
		if (tmp.right) {
			q.push(*(tmp.right));
		}
	}
	
}

void Base_BinTree::preTravasal(Node * p)
{
	if (p) {
		std::cout << p->data << std::endl;
		preTravasal(p->left);
		preTravasal(p->right);
	}
}

void Base_BinTree::postTravasal(Node * p, void (*pf)(Node&))
{
	if (p) {
		postTravasal(p->left, pf);
		postTravasal(p->right, pf);
		pf(*p);
	}
}

void Base_BinTree::inTravasal(Node * p)
{
	if (p) {
		inTravasal(p->left);
		std::cout << p->data << std::endl;
		inTravasal(p->right);
	}
}
