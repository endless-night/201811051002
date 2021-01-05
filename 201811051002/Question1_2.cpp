#include <iostream>

using namespace std;

typedef struct node{
	int num;
	struct node * next;
}node;

typedef struct node* linklist;

int MonkeyKing_Linked(int m, int n)
{
	linklist p, q, head;
	int king, i, j;
	if (m == 1)//只有一只猴子时猴王为1 
		king = 1;
	p = q = (linklist)malloc(sizeof(node));//给新节点分配空间 
	head = p;//head指向首元素节点 
	head->num = 1;//给第一只猴子编号 
	for (i = 1; i < m; i++) {//建立m只猴子围成的圆圈 
		p = (linklist)malloc(sizeof(node));//p为等待插入的节点 
		p->num = i + 1;//p的编号为i+1 
		q->next = p;//q始终记录尾节点(实质是链表的尾插法) 
		q = p;
	}
	q->next = head;//链表尾指向链表头 

	p = head;//开始计数 
	for (i = 1; i < m; i++) {//循环m-1轮，淘汰m-1只猴子 
		for (j = 1; j < n - 1; j++) {//让p指向要淘汰的元素的前驱元素 
			p = p->next;
		}
		q = p->next;//q指向要淘汰的猴子 
		//printf("第%d轮淘汰第%d只猴子\n", i, q->num);
		p->next = q->next;//删除q 
		p = q->next;//一定要让下一次计数起点为被删除元素的后继 
		free(q);//释放q 
	}
	king = p->num;
	free(p);
	return king;
}


int MonkeyKing_Arry(int m, int n) //m为猴子个数，n为最大报数
{
	if (m < 1 || n < 1)
	{
		cout << "输入参数错误" << endl;
		return -1;
	}
	int *p = new int[m];
	int *q = p, M = m;
	int res;

	for (int i = 0; i < m; i++)
	{
		p[i] = 1;
	}

	while (M != 1)
	{
		int i = 0;
		while (i != n)
		{
			if (q == p + m)
			{
				q = p;
			}
			if (*q++ == 1)
			{
				++i;
			}
		}
		*(q - 1) = 0;
		--M;
	}

	for (int i = 0; i < m; i++)
	{
		if (*(p + i) == 1)
		{
			res = i + 1;
			break;
		}
		else
			continue;
	}
	delete[] p;
	return res;
}

int main()
{
	int m = 0, n = 0;
	cin >> m >> n;
	cout << "按照" << m << "个猴子，数" << n << "个数的方法，输出为大王的猴子是" << MonkeyKing_Linked(m, n) << "号" << endl;
	return 0;
}






