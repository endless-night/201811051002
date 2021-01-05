#include <iostream>

using namespace std;

#define OK 10000
#define ERROR 10001

struct node
{
	int data;
	struct node *next;
};
typedef struct node Node;

struct stack
{
	Node *top;
	int count;
};
typedef struct stack Stack;

int InitStack(Stack *S)
{
	S->top = NULL;
	S->count = 0;

	return OK;
}

int EmptyStack(Stack *S)
{
	return (S->count == 0) ? OK : ERROR;
}

int Push(Stack *S, int e)
{
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
	{
		return ERROR;
	}
	p->data = e;
	p->next = S->top;
	S->top = p;
	S->count++;

	return OK;
}

int GetTop(Stack *S)
{
	if (NULL == S->top)
	{
		return ERROR;
	}

	return (S->top->data);
}

int Priority(char s)
{
	switch (s)
	{
	case'(':
		return 3;
	case'*':
	case'/':
		return 2;
	case'+':
	case'-':
		return 1;
	default:
		return 0;
	}
}
int Pop(Stack *S)
{
	int e;

	if (NULL == S->top)
	{
		return ERROR;
	}
	Node *p = S->top;
	e = p->data;
	S->top = p->next;
	free(p);
	S->count--;
	return e;
}
int main()
{
	Stack num, opt;
	char str[100] = { 0 };
	int i = 0, tmp = 0, j;
	if (InitStack(&num) != OK || InitStack(&opt) != OK)
	{
		exit(1);
	}
	cin >> str;
	while (str[i] != '\0' || EmptyStack(&opt) != OK)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			tmp = tmp * 10 + str[i] - '0';
			i++;
			if (str[i] < '0' || str[i] >'9')
			{
				Push(&num, tmp);
				tmp = 0;
			}
		}
		else
		{
			if ((EmptyStack(&opt) == OK) || (GetTop(&opt) == '(' && str[i] != ')') || //进栈不运算
				(Priority(str[i]) > Priority(GetTop(&opt))))
			{
				Push(&opt, str[i]);
				i++;
				continue;
			}

			if (GetTop(&opt) == '(' && str[i] == ')')  //出栈不运算
			{
				Pop(&opt);
				i++;
				continue;
			}

			if ((str[i] == '\0' && EmptyStack(&opt) != OK) || (str[i] == ')' && GetTop(&opt) != '(') ||  //出栈运算
				(Priority(str[i]) <= Priority(GetTop(&opt))))
			{
				switch (Pop(&opt))
				{
				case '+':
					Push(&num, Pop(&num) + Pop(&num));
					break;
				case '-':
					j = Pop(&num);
					Push(&num, Pop(&num) - j);
					break;
				case '*':
					Push(&num, Pop(&num)*Pop(&num));
					break;
				case '/':
					j = Pop(&num);
					Push(&num, Pop(&num) / j);
					break;
				}
				continue;
			}
		}
	}
	cout << Pop(&num);
	return 0;
}