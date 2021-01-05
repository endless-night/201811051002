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
	if (m == 1)//ֻ��һֻ����ʱ����Ϊ1 
		king = 1;
	p = q = (linklist)malloc(sizeof(node));//���½ڵ����ռ� 
	head = p;//headָ����Ԫ�ؽڵ� 
	head->num = 1;//����һֻ���ӱ�� 
	for (i = 1; i < m; i++) {//����mֻ����Χ�ɵ�ԲȦ 
		p = (linklist)malloc(sizeof(node));//pΪ�ȴ�����Ľڵ� 
		p->num = i + 1;//p�ı��Ϊi+1 
		q->next = p;//qʼ�ռ�¼β�ڵ�(ʵ���������β�巨) 
		q = p;
	}
	q->next = head;//����βָ������ͷ 

	p = head;//��ʼ���� 
	for (i = 1; i < m; i++) {//ѭ��m-1�֣���̭m-1ֻ���� 
		for (j = 1; j < n - 1; j++) {//��pָ��Ҫ��̭��Ԫ�ص�ǰ��Ԫ�� 
			p = p->next;
		}
		q = p->next;//qָ��Ҫ��̭�ĺ��� 
		//printf("��%d����̭��%dֻ����\n", i, q->num);
		p->next = q->next;//ɾ��q 
		p = q->next;//һ��Ҫ����һ�μ������Ϊ��ɾ��Ԫ�صĺ�� 
		free(q);//�ͷ�q 
	}
	king = p->num;
	free(p);
	return king;
}


int MonkeyKing_Arry(int m, int n) //mΪ���Ӹ�����nΪ�����
{
	if (m < 1 || n < 1)
	{
		cout << "�����������" << endl;
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
	cout << "����" << m << "�����ӣ���" << n << "�����ķ��������Ϊ�����ĺ�����" << MonkeyKing_Linked(m, n) << "��" << endl;
	return 0;
}






