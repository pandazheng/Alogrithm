#include <iostream>
#include <stdio.h>

void reverse(int[], int);
void output(int[], int);

int main()
{
	printf("hello world\n");

	int array[] = {5,4,10,1,7,9,2};
	output(array,7);
	reverse(array,7);
	output(array,7);
	return 0;
}


void reverse(int array[], int length)
{
	int left = 0;
	int right = length - 1;

	while (left < right)
	{
		int temp = array[left];
		array[left] = array[right];
		array[right] = temp;
		left++;
		right--;
	}
}

void output(int array[], int length)
{
	for (int i = 0 ; i < length ; i++)
	{
		printf("%d ",array[i]);
	}
	printf("\n");
}