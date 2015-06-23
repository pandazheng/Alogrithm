#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}List;

void HeadCreateList(List* L)
{
	List *s;
	L->next = NULL;
	for (int i = 0 ; i < 10 ; i++)
	{
		s = (struct List*)malloc(sizeof(struct List));
		s->data = i;
		s->next = L->next;
		L->next = s;
	}
}

void TailCreateList(List* L)
{
	List *s,*r;
	r = L;
	for (int i = 0 ; i < 10 ;i++)
	{
		s = (struct List*)malloc(sizeof(struct List));
		s->data = i;
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

void Display(List* L)
{
	List *p = L->next;
	while (p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	List *L1,*L2;
	L1 = (struct List*)malloc(sizeof(struct List));
	L2 = (struct List*)malloc(sizeof(struct List));
	HeadCreateList(L1);
	Display(L1);
	TailCreateList(L2);
	Display(L2);

	return 0;
}