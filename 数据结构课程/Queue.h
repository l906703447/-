#pragma once
#include "List.h"
#include <assert.h>
template <class T>
class Queue : private List<T>
{
public:
	Queue();
	virtual ~Queue();
	virtual bool empty()const;
	void push(const T& data);
	T pop();
	T front()const;
	size_t getNumber()const;
	
};

template<class T>
inline Queue<T>::Queue()
{
}

template<class T>
inline Queue<T>::~Queue()
{
}

template<class T>
inline bool Queue<T>::empty() const
{
	return List<T>::empty();
}

template<class T>
inline void Queue<T>::push(const T& data)
{
	this->insert(data);
}

template<class T>
inline T Queue<T>::pop()
{
	assert(List<T>::_number != 0);
	T tmp = this->_head->_next->_data;
	typename List<T>::Node* tmpNode = this->_head->_next;
	this->_head->_next = tmpNode->_next;
	delete tmpNode;
	this->_number--;
	return tmp;
}

template<class T>
inline T Queue<T>::front() const
{
	return (*(this->_head->_next))._data;
}

template<class T>
inline size_t Queue<T>::getNumber() const
{
	return List<T>::getNumber();
}
