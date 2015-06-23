#include <iostream>

struct node{
	int payload;
	node* next;
};

int main()
{
	node* head = nullptr;

	node* temp = new node;

	head = temp;

	for (int i = 1 ; i < 10 ; i++)
	{
		node* new_node = new node;
		new_node->payload = i * 10;
		//头插法
		//new_node->next = head;
		//head = new_node;
		//尾插法
		head->next = new_node;
		head = new_node;
	}
	head->next = nullptr;

	//头插法
	//node* iterator = head;
	//尾插法
	node* iterator = temp;
	while (iterator)
	{
		std::cout << iterator->payload << std::endl;
		iterator = iterator->next;
	}

	return 0;
}