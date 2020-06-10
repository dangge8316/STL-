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
	int n = sf.size();
	cout << "n=" << n << endl;
	sf.getMax();
	sf.getMin();
}

