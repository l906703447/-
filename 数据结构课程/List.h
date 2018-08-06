#pragma once
#include <assert.h>

template <class T>
class List
{
protected:
	struct Node {
		T _data;
		Node* _next;
		Node()noexcept{}
		explicit Node(const T& data) : _data(data), _next(nullptr){}
	};
public:
	class iterator {
	public:
		iterator(): pNode(nullptr){}
		iterator(Node* p) : pNode(p){}
		T & operator*() {
			
			return pNode->_data;
		}
		const iterator next()const {
			return pNode->_next;
		}
		const iterator operator+(size_t step) const{
			auto ptmp = pNode;
			for (size_t i = 0; i < step; i++) {
				//assert(pNode != _end);
				/*if (pNode == _end) {
					throw invalid_argument("the step exceeded the length of this List")
				}*/
				ptmp = ptmp->_next;
			}
			return iterator(ptmp);
		}
		const iterator operator++() {
			pNode = pNode->_next;
			return iterator(pNode);
		}
		const iterator operator++(int) {
			iterator tmp{ *this };
			++(*this);
			return tmp;
		}
		bool operator==(const iterator& that)const {
			return this->pNode == that.pNode;
		}
		bool operator!=(const iterator& that)const {
			return !(this->pNode == that.pNode);
		}
		static void operator delete(void*) {
			delete pNode;
		}
	private:
		Node * pNode;
	};

	class const_iterator {
	public:
		const_iterator() : pNode(nullptr){}
		const_iterator(Node* p) : pNode(p){}
		const T&& operator*() {
			return pNode->_data;
		}
		const const_iterator&& operator++() {
			pNode = pNode->_next;
			return const_iterator(pNode);
		}
		const const_iterator&& operator++(int) {
			const_iterator tmp{ *this };
			++(*this);
			return tmp;
		}
	private:
		Node * pNode;
	};

public:
	List();
	List(const List&& l);
	virtual ~List();
	iterator begin()const;
	iterator end()const;
	void insert(const T& data);
	void insert(const T& data, size_t index);
	void erase(const T& val);
	void erase(const iterator& it);
	const T& at(size_t index)const;// index begins from one
	bool find(const T& val)const;	// find the index of the first one 
	void show()const;
	void update(size_t index, const T& val);
	bool empty()const;
	size_t getNumber()const;
protected:
	size_t _number = 0;
	Node* _head;
	Node* _tail;
	Node* _end;
};

template<class T>
inline List<T>::List() :
	_head(new Node),
	_tail(_head), 
	_end(new Node)
{
	_head->_next = _end;
	_end->_next = nullptr;
}

template<class T>
inline List<T>::List(const List && l):
	List()
{
	for (List<T>::const_iterator j = l._head; j->_next != l._end; j++) {
		insert(*(j->_next));
	}
	
}

template<class T>
inline List<T>::~List()
{
	for (Node* p = _head, *q = _head->_next; p->_next; p = q, q = q->_next) {
		delete p;		
	}
	_number = 0;
}

template<class T>
inline typename List<T>::iterator List<T>::begin() const
{
	return ++iterator(_head);
}

template<class T>
inline typename List<T>::iterator List<T>::end() const
{
	return iterator(_end);
}

template<class T>
inline void List<T>::insert(const T & data)
{
	_tail->_next = new Node(data);
	_tail = _tail->_next;
	_tail->_next = _end;
	_number++;
}

template<class T>
inline void List<T>::insert(const T & data, size_t index)
{
	Node* p = _head;
	for (size_t i = 0; i < index - 1; i++) {
		p = p->_next;
	}
	Node* tmp = p->_next;
	p->_next = new Node(data);
	p->_next->_next = tmp;
	_number++;
}

template<class T>
inline void List<T>::erase(const T & val)
{
	_end->_data = val;
	Node* p = _head;
	Node* q = p->_next;
	while (true) {
		if (q->_data == val) {
			if (q != _end) {
				if (q == _tail) {
					_tail = p;
				}
				p->_next = q->_next;
				delete q;
				_number--;
				q = p->_next;
				continue;
			}
			else {
				break;
			}
		}
		p = p->_next;
		q = p->_next;
	}
	
}

template<class T>
inline void List<T>::erase(const iterator & it)
{
	//assert(bool found = false, true);
	for (Node* p = _head,*q = _head->_next; q != _end; p++, q++) {
		if (it == iterator(q)) {
			p->_next = q->_next;
			delete q;
			break;
		}
	}
}

template<class T>
inline const T & List<T>::at(size_t index) const
{
	Node* p = _head;
	for (size_t i = 0; i < index; i++) {
		p = p->_next;
	}
	return (*p)._data;
}

template<class T>
inline bool List<T>::find(const T & val) const
{
	_end->_data = val;
	Node* p = _head;
	while (true) {
		if (p->_next->_data == val) {
			if (p->_next != _end) {
				return true;
			}
			else {
				return false;
			}
		}
		p = p->_next;
	}
}

template<class T>
inline void List<T>::show() const
{
	for (Node* p = _head; p->_next != _end; p = p->_next) {
		std::cout << p->_next->_data << std::endl;
	}
}

template<class T>
inline void List<T>::update(size_t index, const T & val)
{
	const_cast<T&>(at(index)) = val;
}

template<class T>
inline bool List<T>::empty() const
{
	return _number == 0;
}

template<class T>
inline size_t List<T>::getNumber()const
{
	return _number;
}
