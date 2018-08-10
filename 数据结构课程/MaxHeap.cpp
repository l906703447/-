#include "MaxHeap.h"

MaxHeap::MaxHeap()noexcept
{
	heap.push_back(MAX_DATA);
}

MaxHeap::MaxHeap(const std::vector<ElementType>& v)
{
	for (size_t i = v.size() / 2; i > 0; i--) {
		percDown(i);
	}
}


MaxHeap::~MaxHeap()
{
}

void MaxHeap::insert(const ElementType& val)
{
	heap.push_back(val);
	int i = heap.size();
	for (; val > heap[i / 2]; i /= 2) {
		heap[i] = heap[i / 2];
	}
	heap[i] = val;
}

ElementType MaxHeap::max() const
{
	return heap[1];
}

ElementType MaxHeap::max(const ElementType & a, const ElementType & b) const
{
	return a < b ? b : a;
}

ElementType MaxHeap::removeMax()
{
	ElementType ret = max();
	size_t parent = 1, maxChild; // maxChild, the node that be floated
	/*find the current position of the last, and remove it*/
	for (; 2 * parent < heap.size(); parent = maxChild) { // the last have not be removed, so it is "<" but "<="
		maxChild = 2 * parent;
		if (maxChild + 1 != heap.size() && heap[maxChild] < heap[maxChild + 1]) { // parent have both left and right maxChild && left < right
			++maxChild; // maxChild = parent.right
		}
		if (heap.back() >= heap[maxChild]) { // here is the current position
			break;
		}
		else{
			heap[parent] = heap[maxChild];
		}
	}
	heap[parent] = heap.back();
	heap.pop_back();
	return ret;
}

void MaxHeap::percDown(size_t root)
{
	size_t parent, maxChild;
	ElementType val = heap[root];
	for (parent = root; 2 * parent < heap.size(); parent = maxChild) {
		maxChild = 2 * parent;
		if (maxChild != heap.size() && heap[maxChild] < heap[maxChild + 1]) {
			++maxChild; // points to the max of parent's children
		}
		if (val >= heap[maxChild]) { // current position
			break;
		}
		else {
			heap[parent] = heap[maxChild];
		}
	}
	heap[parent] = val;
}
