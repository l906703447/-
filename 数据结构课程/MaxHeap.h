#pragma once
#include <vector>

// using iterator = size_t;
template <class ElementType, class Compare = less>
class Heap
{
	class iterator {
	public:
		iterator(size_t pos) : pos(pos){}
		ElementType& operator*() {
			return heap[pos];
		}
		iterator operator++() {
			++pos;
			return iterator{ pos };
		}
		iterator operator++(int) {
			iterator ret{ *this };
			++(*this);
			return ret;
		}
		size_t() const{
			return pos;
		}
	private:
		size_t pos = 0;
	};

public:
	Heap()noexcept;
	Heap(const std::vector<ElementType>& v);
	virtual ~Heap();
	void insert(const ElementType& val);
	ElementType getFrontEle()const;
	ElementType removeFront();

private:
	size_t size()const; // size of heap
	bool isInScope(iterator i)const; // whether i is legal
	iterator front()const; // first element
	iterator back()const; // last element
	void percDown(iterator root);
	ElementType max(const ElementType& a, const ElementType& b)const;// should be changed
	iterator Parent(iterator aChild)const;
	iterator leftChild(iterator parent)const;
	iterator rightChild(iterator parent)const;

	const ElementType MAX_DATA = 65535; // could update when necessary
	std::vector<ElementType> heap; // completely bin-tree, heap[0] is a sentinel
	Compare cmp;
};

template<class ElementType, class Compare>
Heap<ElementType, Compare>::Heap()noexcept
{
	heap.push_back(MAX_DATA);
}

template <class ElementType, class Compare>
Heap<ElementType, Compare>::Heap(const std::vector<ElementType>& v)
{
	for (iterator i = Parent(back()); i > 0; i--) {
		percDown(i);
	}
}

template <class ElementType, class Compare>
Heap<ElementType, Compare>::~Heap()
{
}

template <class ElementType, class Compare>
void Heap<ElementType, Compare>::insert(const ElementType& val)
{
	heap.push_back(val);
	iterator i = back();
	for (; val > *Parent(i); i = Parent(i)) {
		*i = *Parent(i);
	}
	*i = val;
}

template <class ElementType, class Compare = less>
ElementType Heap<ElementType, Compare>::getFrontEle() const
{
	return *front();
}

template <class ElementType, class Compare = less>
ElementType MaxHeap::max(const ElementType & a, const ElementType & b, Compare cmp) const
{
	return cmp(a, b) ? b : a;// TODO : should be updated
}

template <class ElementType, class Compare = less>
ElementType Heap<ElementType, Compare>::removeFront()
{
	ElementType ret = getFrontEle();
	iterator parent = front(), maxChild; // maxChild, the node that will be floated
	 /*find the current position of the last element, then remove it*/
	for (; leftChild(parent) < size(); parent = maxChild) { // the last have not be removed, so it is "<" but "<="
		maxChild = leftChild(parent); // assume max child is the left one
		if (maxChild != back() && !cmp(*maxChild, *(maxChild + 1))) { // parent have both left and right maxChild && left child < right
			++maxChild; // maxChild = parent.right
		}
		if (cmp(*back(), *maxChild)) { // here is the current position
			break;
		}
		else {
			*parent = *maxChild;
		}
	}
	*parent = *back();
	heap.pop_back();
	return ret;
}

template<class ElementType, class Compare>
inline size_t Heap<ElementType, Compare>::size() const
{
	return heap.size();
}

template<class ElementType, class Compare>
inline bool Heap<ElementType, Compare>::isInScope(iterator i) const
{
	return i < size();
}

template<class ElementType, class Compare>
inline iterator&& Heap<ElementType, Compare>::front() const
{
	return iterator{ 1 };
}

template<class ElementType, class Compare>
inline iterator&& Heap<ElementType, Compare>::back() const
{
	return iterator(heap.size() - 1); // point to the last element
}

template <class ElementType, class Compare = less>
void Heap<ElementType, Compare>::percDown(iterator root)
{
	iterator parent = root, maxChild;
	ElementType val = *root;
	for (parent = root; isInScope(leftChild(parent)); parent = maxChild) {
		maxChild = leftChild(parent);
		if (maxChild != back() && !cmp(*maxChild, *(maxChild + 1))) {
			++maxChild; // points to the maximal(¼«´óÔª) of parent's children
		}
		if (cmp(val, *maxChild)) { // current position
			break;
		}
		else {
			*parent = *maxChild;
		}
	}
	*parent = val;
}

template<class ElementType, class Compare>
inline iterator Heap<ElementType, Compare>::Parent(iterator aChild) const
{
	return iterator{ size_t(aChild) / 2 };
}

template<class ElementType, class Compare>
inline iterator Heap<ElementType, Compare>::rightChild(iterator parent) const
{
	size_t ret = 2 * size_t(parent) + 1;
	assert(ret <= heap.size());
	return iterator{ ret };
}

template<class ElementType, class Compare>
inline iterator Heap<ElementType, Compare>::leftChild(iterator parent) const
{
	assert(2 * size_t(parent) <= heap.size());
	return iterator{ 2 * size_t(parent) };
}



