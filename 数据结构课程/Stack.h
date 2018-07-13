#pragma once
template<class T, int SIZE = 10>
class Stack// 该堆栈为数组实现，可能在堆中剩余空间较小时发生动态内存分配失败，可用链表实现加以解决
{
public:	// 将分支推送到远程存储库时遇到错误: Git failed with a fatal error.
	Stack();
	Stack(const Stack& stack);
	virtual ~Stack();
	bool empty()const;
	void push(const T& data)const;
	T pop()const;
	const T& pick()const;
private:
	const size_t step = static_cast<size_t>(20);
	size_t number = 0;// 堆栈中存储的元素个数
	size_t capacity = SIZE;// 通过与number比较，判断堆栈是否已满
	T* ptr;
	bool full()const;
	void increase();// 功能为堆中的数组增长长度step
};

template<class T, int SIZE>
inline Stack<T, SIZE>::Stack():
	number(0), 
	ptr(new T[capacity])
{
}

template<class T, int SIZE>
inline Stack<T, capacity>::Stack(const Stack & stack):
	ptr(new T[stack.capacity])
{
	for (size_t i = 0; i < stack.number; i++) {
		ptr[i] = stack.ptr[i];
	}
}

template<class T, int SIZE>
inline Stack<T, SIZE>::~Stack()
{
	delete[] ptr;
}

template<class T, int SIZE>
inline bool Stack<T, SIZE>::empty() const
{
	return 0 == number;
}

template<class T, int SIZE>
inline void Stack<T, SIZE>::push(const T & data) const
{
	if (!full()) {
		ptr[number] = data;
	}
	else
	{
		increase();
		ptr[number] = data;
	}
	number++;
}

template<class T, int SIZE>
inline T Stack<T, SIZE>::pop() const
{
	--number;
	return ptr[number];
}

template<class T, int SIZE>
inline const T & Stack<T, SIZE>::pick() const
{
	return ptr[number - 1];
}

template<class T, int SIZE>
inline bool Stack<T, SIZE>::full() const
{
	bool ret;
	if (number < capacity) {
		ret = false;
	}
	else
	{
		ret = true;
	}
	return ret;
}

template<class T, int SIZE>
inline void Stack<T, SIZE>::increase()
{
	T* newptr = new T[capacity + step];
	for (size_t i = 0; i < number; i++) {
		newptr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newptr;
}
