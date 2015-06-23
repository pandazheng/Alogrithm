#include <iostream>

struct node{
	int payload;
	node* next;
};

node* reverse_recursive(node* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}

	node* second = head->next;
	node* new_head = reverse_recursive(second);
	second->next = head;
	head->next = nullptr;
	return new_head;
}

node* reverse(node* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	node* p = head->next;
	node* p_previous = head;
	head->next = nullptr;
	while (p != nullptr)
	{
		node* p_next = p->next;
		p->next = p_previous;
		p_previous = p;
		p = p_next;
	}
	return p_previous;
}

int main()
{
	node* head = nullptr;

	for (int i = 0 ; i < 10 ; i++)
	{
		node* new_node = new node;
		new_node->payload = i * 10;
		new_node->next = head;
		head = new_node;
	}
	head = reverse_recursive(head);

	node* iterator = head;
	while (iterator)
	{
		std::cout << iterator->payload << std::endl;
		iterator = iterator->next;
	}

	return 0;
}