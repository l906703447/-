#include "BinSearchTree.h"



BinSearchTree::BinSearchTree()
{
}


BinSearchTree::~BinSearchTree()
{
}

BinTree BinSearchTree::insert()
{
	
}

BinTree BinSearchTree::find(int val) const
{
	return find(val, root);
}

BinTree BinSearchTree::findMax() const
{
	if (!root) {
		return nullptr;
	}
	BinTree bst{ root };
	while (bst->right)
	{
		bst = bst->right;
	}
	return bst;
}

BinTree BinSearchTree::findMin() const
{
	if (!root) {
		return nullptr;
	}
	BinTree bst{ root };
	while (bst->right) {
		bst = bst->right;
	}
	return bst;
}

BinTree BinSearchTree::find(int val, BinTree bst) const
{
	if (!bst) {
		return nullptr;
	}
	else if (val < bst->data)
	{
		return find(val, bst->left);
	}
	else if(val > bst->data)
	{
		return find(val, bst->right);
	}
	else {
		return bst;
	}
}
