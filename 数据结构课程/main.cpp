#include <iostream>
#include "List.h"
#include <list>

int main() {
	const std::list<int>::iterator i;
	List<int> l;
	l.insert(2);
	l.insert(3);
	l.insert(3);
	l.insert(5);
	l.insert(2);
	l.insert(45);
	l.erase(3);
	l.show();
	std::cout << l.find(45) << std::endl;
	system("pause");
	return 0;
}