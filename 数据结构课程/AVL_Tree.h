#pragma once
#include "BinSearchTree.h"
typedef typename Base_BinTree::Node * AVLTree;
class AVL_Tree :
	public BinSearchTree
{
	
public:
	AVL_Tree()noexcept;
	virtual ~AVL_Tree();
	virtual AVLTree insert(int val) override;
private:
	int max(int a, int b)const;
	AVLTree LL_Rotation(AVLTree discoverer);
	AVLTree RR_Rotation(AVLTree discoverer);
	AVLTree LR_Rotation(AVLTree discoverer);
	AVLTree RL_Rotation(AVLTree discoverer);
	AVLTree insert(int val, AVLTree t);
	int updateHeight(AVLTree t);
};

