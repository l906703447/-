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

protected:
	struct Node 
	{
		Node* left;
		int data;
		Node* right;
	};
	void preTravasal(Node* p); // ��δ���뺯��ָ���������
	void postTravasal(Node* p, void(*pf)(Node&));
	void inTravasal(Node* p); // δ���뺯��ָ���������
	Node* root;
};

