#pragma once
#include "Base_BinTree.h"
typedef Base_BinTree::Node* BinTree;
typedef int ElementType;
class BinSearchTree :
	public Base_BinTree
{
public:
	BinSearchTree();
	virtual ~BinSearchTree();
	BinTree insert();
	BinTree find(int val)const;
	BinTree findMax()const;
	BinTree findMin()const;
	BinTree remove(int x);
private:
	BinTree insert(BinTree bst);
	BinTree find(int val, BinTree bst)const;
	BinTree remove(BinTree bst,ElementType x);
};

