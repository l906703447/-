#pragma once
#include "List.h"
class T;// 这是一个临时的前向类声明
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

