#include <iostream>

int fib(int n)
{
	if (n < 2)
		return n;
	else
		return fib(n - 1) + fib(n - 2);
}

int main()
{
	for (int i = 1 ; i < 10 ; i++)
	{
		std::cout << fib(i) << std::endl;
	}
}