#pragma once
template<class T, int SIZE = 10>
class Stack// �ö�ջΪ����ʵ�֣������ڶ���ʣ��ռ��Сʱ������̬�ڴ����ʧ�ܣ���������ʵ�ּ��Խ��
{
public:	// ����֧���͵�Զ�̴洢��ʱ��������: Git failed with a fatal error.
	Stack();
	Stack(const Stack& stack);
	virtual ~Stack();
	bool empty()const;
	void push(const T& data)const;
	T pop()const;
	const T& pick()const;
private:
	const size_t step = static_cast<size_t>(20);
	size_t number = 0;// ��ջ�д洢��Ԫ�ظ���
	size_t capacity = SIZE;// ͨ����number�Ƚϣ��ж϶�ջ�Ƿ�����
	T* ptr;
	bool full()const;
	void increase();// ����Ϊ���е�������������step
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
