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
	virtual BinTree insert(int val);
	BinTree find(int val)const;
	BinTree findMax()const;
	BinTree findMin()const;
	virtual void remove(int x);
private:
	BinTree findMax(BinTree bst)const;
	virtual BinTree insert(int val, BinTree bst); 
	BinTree find(int val, BinTree bst)const;
	BinTree remove(ElementType val, BinTree bst);
};

