#include <iostream>
#include "sizeFilter.hpp"

int main()
{
	sizeFilter<int,multiset<int>> sf;

	for (int i = 0; i < 10; i++)
	{
		sf.insert(i * 4);
	}
	sf.erase(0);
	sf.erase(36);

	sf.getMax();
	sf.getMin();
}

