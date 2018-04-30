#include "List.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cassert>

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
	
	//List<int> list;
	//list.push(3);
	//list.push(5);
	//list.push(0);
	//list.push(-1);
	//list.push(-10);
	//list.push(4);
	//list.push(5);
	//list.push(-1);
	//list.push(1000);

	//list.setWay(false);

	//std::cout << "aaaa " << list.front() << std::endl;
	//list.pop(); 

	//list.show();

	List<double> list;
	list.setWay(true);
	double  min_range = -5, max_range = 5;
	std::string file_name = "file.txt";


	std::cout << "Podaj nazwe pliku: " << std::endl;
	std::cin >> file_name;
	assert(!file_name.empty());

	std::cout << "Podaj minimalny oraz maksymalny rozmiar: " << std::endl;
	std::cin >> min_range >> max_range;

	if (min_range > max_range)
	{
		std::swap(min_range, max_range);
	}

	std::ifstream file(file_name);
	if (file.is_open())
	{
		std::string number;
		while (std::getline(file, number))
		{
			double temp_number = std::stod(number);
			assert(min_range < max_range);

			if (min_range <= temp_number && max_range >= temp_number)
			{
				assert(temp_number >= min_range);
				assert(temp_number <= max_range);
				list.push(temp_number);
			}
			
		}
	}
	else
	{
		std::cout << "Problem z odczytem pliku. " << std::endl;
	}

	list.getWay();
	list.show();
	list.setWay(false);

	list.getWay();
	list.show();






	return 0;
}