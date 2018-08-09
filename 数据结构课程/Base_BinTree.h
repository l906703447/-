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
	void preTravasal(Node* p); // ��δ���뺯��ָ���������
	void postTravasal(Node* p, void(*pf)(Node&));
	void inTravasal(Node* p); // δ���뺯��ָ���������
	Node* root;
};

