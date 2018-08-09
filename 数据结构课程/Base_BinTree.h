#pragma once
class Base_BinTree
{
public:
	Base_BinTree();
	virtual ~Base_BinTree();
	void preTravasal();
	void postTravasal();
	void inTravasal();
	void levelTravasal();


	struct Node 
	{
		int data;
		Node* left;
		Node* right;
		int height;
	};
	void preTravasal(Node* p); // 尚未加入函数指针或函数对象
	void postTravasal(Node* p, void(*pf)(Node&));
	void inTravasal(Node* p); // 未加入函数指针或函数对象
	Node* root;
};

