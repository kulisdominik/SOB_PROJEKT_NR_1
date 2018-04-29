#include "List.hpp"
#include <iostream>
#include <string>
int main()
{
	//List<int> list{ 1,2,4,5 };
	//list.push_back(6);
	//list.push_front(0);
	//list.insert(3, 3);

	//std::cout << "Size: " << list.size() << std::endl;
	//std::cout << "Empty: " << list.empty() << std::endl;
	//
	//list.pop_front();
	//list.pop_back();
	//std::cout << "List_1: " << std::endl;
	//list.show(false);

	//list.swap(0, 2);

	//std::cout << "List_2: " << std::endl;
	//list.show();
	

	List<int> list;
	list.push(3);
	list.push(5);
	list.push(0);
	list.push(-1);
	list.push(-10);
	list.push(4);
	list.push(5);
	list.push(-1);
	list.push(1000);

	list.setWay(false);

	std::cout << "aaaa " << list.front() << std::endl;
	list.pop(); 

	list.show();
	return 0;
}