#pragma once
#include <vector>

using ElementType = int;

class MaxHeap
{
	
public:
	MaxHeap()noexcept;
	MaxHeap(const std::vector<ElementType>& v);
	virtual ~MaxHeap();
	void insert(const ElementType& val);
	ElementType max()const;
	ElementType max(const ElementType& a, const ElementType& b)const;
	ElementType removeMax();

private:
	void percDown(size_t root);

	const ElementType MAX_DATA = 65535; // could update
	std::vector<ElementType> heap; // completely bin-tree
};

