#include "BinSearchTree.h"



BinSearchTree::BinSearchTree()
{
}


BinSearchTree::~BinSearchTree()
{
}

BinTree BinSearchTree::insert(int val)
{
	return insert(val, root);
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
	while (bst->left) {
		bst = bst->left;
	}
	return bst;
}

void BinSearchTree::remove(int x)
{
	remove(x, root);
}



BinTree BinSearchTree::findMax(BinTree bst) const
{
	if (bst) {
		while (bst->right) {
			bst = bst->right;
		}
	}
	return bst;
}

BinTree BinSearchTree::insert(int val, BinTree bst)
{
	if (!bst) {
		bst = new Node;
		bst->data = val;
		bst->left = bst->right = nullptr;
	}
	if (val < bst->data) {
		bst->left = insert(val, bst->left);
	}
	else if(val > bst->data)
	{
		bst->right = insert(val, bst->right);
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

BinTree BinSearchTree::remove(ElementType val, BinTree bst)
{
	if (!bst) {
		// do nothing
	}
	else if (val < bst->data) {
		bst->left = remove(val, bst->left);
	}
	else if (val > bst->data) {
		bst->right = remove(val, bst->right);
	}
	else { // the node is the one should be removed
		BinTree tmp = bst;
		if (bst->left && bst->right) { // both have left and right child
			tmp = findMax(bst->left);
			bst->data = tmp->data; // replace bst with the max of left child tree
			bst->left = remove(bst->data, bst->left); // remove max of "bst->left"
		}
		else if (!bst->left) {
			bst = bst->right;
		}
		else {
			bst = bst->left;
		}
		delete tmp;
	}
	return bst;
}
