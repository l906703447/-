#pragma once
class Base_BinTree
{
public:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
		int height;
	};
	void preTravasal();
	void postTravasal();
	void inTravasal();
	void levelTravasal();
protected:
	Base_BinTree()noexcept;
	virtual ~Base_BinTree();
	int getHeight(Node* pNode);
	Node* root;
private:
	void preTravasal(Node* p); // ��δ���뺯��ָ���������
	void postTravasal(Node* p, void(*pf)(Node&));
	void inTravasal(Node* p); // δ���뺯��ָ���������
	
};

