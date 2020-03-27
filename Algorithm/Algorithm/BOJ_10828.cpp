/*
백준 10828번 스택
20/03/27
*/
#include <iostream>
#include <string>

using namespace std;

int result[10001];

typedef struct Node
{
	int element;
	Node* next;
}Node;

typedef struct Stack
{
	Node* top;
	int size;
}Stack;

void init(Stack* s)
{
	s->top = NULL;
	s->size = 0;
}

void push(Stack* s, int item)
{
	Node* temp = s->top;
	Node* newTop = new Node;
	newTop->element = item;
	s->top = newTop;
	newTop->next = temp;
	s->size += 1;
}

int pop(Stack* s)
{
	if (s->size == 0)
	{
		//printf("%d\n", -1);
		return -1;
	}
	else
	{
		int item = s->top->element;
		s->top = s->top->next;
		s->size -= 1;
		return item;
	}
}

int size(Stack* s)
{
	return s->size;
}

int empty(Stack* s)
{
	if (s->size == 0)
		return 1;
	else
		return 0;
}

int top(Stack* s)
{
	if (empty(s))
		return -1;
	else
	{
		int item = s->top->element;
		return item;
	}
}

int main(void)
{	
	Stack* stack = new Stack;
	init(stack);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		/*char s[BUFSIZ];
		scanf("%s", s);*/
		string s;
		cin >> s;

		if (s =="push")
		{
			int item;
			scanf("%d", &item);

			push(stack, item);
			result[i] = -6;
		}
		else if (s == "pop")
		{
			result[i] = pop(stack);
		}
		else if (s == "size")
		{
			result[i] = size(stack);
		}
		else if (s == "empty")
		{
			result[i] = empty(stack);
		}
		else if (s == "top")
		{
			result[i] = top(stack);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (result[i] != -6)
			printf("%d\n", result[i]);
	}
		
	delete stack;

	return 0;
}
