#include "AVL_Tree.h"
#include <assert.h>

AVL_Tree::AVL_Tree()noexcept
{
}

AVL_Tree::~AVL_Tree()
{
}


AVLTree AVL_Tree::insert(int val)
{
	return root = insert(val, root);
}

int AVL_Tree::max(int a, int b) const
{
	return a > b ? a : b;
}

AVLTree AVL_Tree::LL_Rotation(AVLTree discoverer)
{
	assert(discoverer->left);
	AVLTree newRoot = discoverer->left;
	discoverer->left = newRoot->right;
	newRoot->right = discoverer;
	updateHeight(discoverer);
	updateHeight(newRoot);
	return newRoot;
}

AVLTree AVL_Tree::RR_Rotation(AVLTree discoverer)
{
	assert(discoverer->right);
	AVLTree newRoot = discoverer->right;
	discoverer->right = newRoot->left;
	newRoot->left = discoverer;
	updateHeight(discoverer);
	updateHeight(newRoot);
	return newRoot;
}

AVLTree AVL_Tree::LR_Rotation(AVLTree discoverer)
{
	discoverer->left = RR_Rotation(discoverer->left);
	return LL_Rotation(discoverer);
}

AVLTree AVL_Tree::RL_Rotation(AVLTree discoverer)
{
	discoverer->right = LL_Rotation(discoverer->right);
	return RR_Rotation(discoverer);
}

AVLTree AVL_Tree::insert(int val, AVLTree t)
{
	if (!t) {
		t = new Node{ val, nullptr, nullptr, 1 };
	}
	else {
		if (val < t->data) {
			t->left = insert(val, t->left);
			if (getHeight(t->left) - getHeight(t->right) == 2) { // cause unbalance
				if (val < t->left->data) { // left-left subtree
					t = LL_Rotation(t);
				}
				else{ // left-right subtree
					t = LR_Rotation(t);
				}
			}
		}
		else {
			t->right = insert(val, t->right);
			if (t->right->height - t->right->height == -2) {
				if (val > t->right->data) {
					t = RR_Rotation(t);
				}
				else {
					t = RL_Rotation(t);
				}
			}
		}
		
	}
	updateHeight(t);
	return t;
}

int AVL_Tree::updateHeight(AVLTree t)
{

	return t->height = max(getHeight(t->left), getHeight(t->right)) + 1;
}
