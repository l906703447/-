#pragma once
template <class T>
class BaseList {// head等成员设为protected，子类继承时用protected继承
	struct Node {
		T _data;
		Node* _next;
		Node()noexcept {}
		explicit Node(const T& data) : _data(data), _next(nullptr) {}
	};

	class iterator {
	public:
		iterator() : pNode(nullptr) {}
		iterator(Node* p) : pNode(p) {}
		T & operator*() {
			return pNode->_data;
		}
		const iterator&& operator++() {
			pNode = pNode->_next;
			return iterator(pNode);
		}
		const iterator&& operator++(int) {
			iterator tmp{ *this };
			++(*this);
			return tmp;
		}
	private:
		Node * pNode;
	};

	class const_iterator {
	public:
		const_iterator() : pNode(nullptr) {}
		const_iterator(Node* p) : pNode(p) {}
		const T&& operator*() {
			return pNode->_data;
		}
		const const_iterator&& operator++() {
			pNode = pNode->_next;
			return const_iterator(pNode);
		}
		const const_iterator&& operator++(int) {
			const const_iterator tmp{ *this };
			++(*this);
			return tmp;
		}
	private:
		Node * pNode;
	};
public:
	BaseList();
	BaseList(const BaseList&& l);
	virtual ~BaseList();
	iterator begin()const;
	void insert(const T& data);
	void insert(const T& data, size_t index);
	void erase(const T& val);
	const T& at(size_t index)const;// index begins from one
	bool find(const T& val)const;	// find the index of the first one 
	void show()const;
	void update(size_t index, const T& val);
	size_t getNumber();
	friend class Queue;
private:
	size_t _number = 0;
	Node* _head;
	Node* _tail;
	Node* _end;
};

template<class T>
inline BaseList<T>::BaseList() :
	_head(new Node),
	_tail(_head),
	_end(new Node)
{
	_head->_next = _end;
	_end->_next = nullptr;
}

template<class T>
inline BaseList<T>::BaseList(const BaseList && l) :
	BaseList()
{
	for (BaseList<T>::const_iterator j = l._head; j->_next != l._end; j++) {
		insert(*(j->_next));
	}

}

template<class T>
inline BaseList<T>::~BaseList()
{
	for (Node* p = _head, *q = _head->_next; p->_next; p = q, q = q->_next) {
		delete p;
	}
	_number = 0;
}

template<class T>
inline typename BaseList<T>::iterator BaseList<T>::begin() const
{
	return ++iterator(_head);
}

template<class T>
inline void BaseList<T>::insert(const T & data)
{
	_tail->_next = new Node(data);
	_tail = _tail->_next;
	_tail->_next = _end;
	_number++;
}

template<class T>
inline void BaseList<T>::insert(const T & data, size_t index)
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
inline void BaseList<T>::erase(const T & val)
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
inline const T & BaseList<T>::at(size_t index) const
{
	Node* p = _head;
	for (size_t i = 0; i < index; i++) {
		p = p->_next;
	}
	return *p;
}

template<class T>
inline bool BaseList<T>::find(const T & val) const
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
inline void BaseList<T>::show() const
{
	for (Node* p = _head; p->_next != _end; p = p->_next) {
		std::cout << p->_next->_data << std::endl;
	}
}

template<class T>
inline void BaseList<T>::update(size_t index, const T & val)
{
	const_cast<T&>(at(index)) = val;
}

template<class T>
inline size_t BaseList<T>::getNumber()
{
	return _number;
}


};
