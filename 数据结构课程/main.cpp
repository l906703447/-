#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"

int main() {
	List<int>::const_iterator i;
	Queue<int> que;
	que.push(3);
	que.push(4);
	std::cout << que.front() << std::endl;
	std::cout << que.pop() << std::endl;
	std::cout << que.getNumber() << std::endl;
	std::cout << que.empty() << std::endl;
	system("pause");
	return 0;
}