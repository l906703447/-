#include <iostream>
#include "List.h"
#include "Stack.h"
#include "Queue.h"
#include "AVL_Tree.h"

struct PolyNode
{
	int ceof;
	int expon;
	friend std::ostream& operator<<(std::ostream& os, const PolyNode& ob);
};

std::ostream& operator<<(std::ostream& os, const PolyNode& ob) {
	return os << ob.ceof << " " << ob.expon << " ";
}

int main() {
	/*List<PolyNode> p1, p2;
	size_t size1, size2;
	std::cin >> size1;
	for (size_t i = 0; i < size1; i++) {
		int ceof;
		int expon;
		std::cin >> ceof >> expon;
		p1.insert(PolyNode{ ceof, expon });
	}
	std::cin >> size2;
	for (size_t i = 0; i < size2; i++) {
		int ceof;
		int expon;
		std::cin >> ceof >> expon;
		p2.insert(PolyNode{ ceof, expon });
	}
	List<PolyNode> mul, sum;
	for (size_t i = 1; i < size1 + 1; i++) {
		for (size_t j = 1; j < size2 + 1; j++) {
			mul.insert(PolyNode{ p1.at(i).ceof * p2.at(j).ceof, p1.at(i).expon + p2.at(j).expon });
		}
	}
	for (auto i = mul.begin(); i != mul.end(); i++) {
		for (auto j = i + 1; j != mul.end(); j++) {
			if ((*i).expon == (*j).expon) {
				(*i).ceof += (*j).ceof;
				mul.erase(j);
			}
			std::cout << "(*i).expon == (*j).expon : " << std::boolalpha << ((*i).expon == (*j).expon) << std::endl;
			std::cout << "*i = " << "{ ceof = " << (*i).ceof << ", expon = " << (*i).expon << " }" << std::endl;
			std::cout << "*j = " << "{ ceof = " << (*j).ceof << ", expon = " << (*j).expon << " }" << std::endl;
			std::cout << std::endl;
		}
	}
	mul.show();*/
	AVL_Tree av;
	av.insert(55);
	av.insert(34);
	av.insert(67);
	av.insert(57);
	av.insert(66);
	std::cout << "inorder : " << std::endl;
	av.inTravasal();
	std::cout << "preorder : " << std::endl;
	av.preTravasal();
	system("pause");
	return 0;
}