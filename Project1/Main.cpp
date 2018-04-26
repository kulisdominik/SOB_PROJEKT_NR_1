#include "List.hpp"
#include <iostream>
#include <string>
int main()
{
	List<int> list{ 1,2,4,5 };
	list.push_back(6);
	list.push_front(0);
	list.insert(3, 3);

	std::cout << "Size: " << list.size() << std::endl;
	std::cout << "Empty: " << list.empty() << std::endl;
	
	list.pop_back();
	std::cout << "List_1: " << std::endl;
	list.show(false);


	list.pop_front();
	std::cout << "List_2: " << std::endl;
	list.show();
	
	return 0;
}