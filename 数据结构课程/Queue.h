#pragma once
#include "List.h"
class T;// ����һ����ʱ��ǰ��������
class Queue
{
public:
	Queue();
	~Queue();
	bool empty();
	void add();
	T dlt();// delete
private:
	T * front;
	T * rear;
};

