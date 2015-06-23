#include <iostream>

using namespace std;

int main()
{
	int array[] = {9,2,3,4,5,6,7};
	int *p;
	int i;

	p = &array[0];
	for (i = 0 ; i < 7 ; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;

	std::cout << array[4] << std::endl;
	std::cout << *(array + 4) << std::endl;
	std::cout << *array + 4 << std::endl;
	std::cout << *(p + 4) << std::endl;
	std::cout << *p + 4 << std::endl;
	return 0;
}

