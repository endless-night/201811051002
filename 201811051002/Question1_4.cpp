#include<iostream>

using namespace std;

int main()
{
	char map[100][100];
	int flag[100][100];
	int N = 0, M = 0, K = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> map[i];
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			flag[i][j] = 0;
		}
	}
	cin >> K;
	for (int s = 0; s < K; s++)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == 'X' && flag[i][j] == s)
				{
					if (map[abs(i - 1)][j] != 'P')
					{
						map[abs(i - 1)][j] = 'X';
						flag[abs(i - 1)][j] = s + 1;
					}
					if (map[i][abs(j - 1)] != 'P')
					{
						map[i][abs(j - 1)] = 'X';
						flag[i][abs(j - 1)] = s + 1;
					}					
					if (map[abs(i + 1)][j] != 'P')
					{
						map[abs(i + 1)][j] = 'X';
						flag[abs(i + 1)][j] = s + 1;
					}					
					if (map[i][abs(j + 1)] != 'P')
					{
						map[i][abs(j + 1)] = 'X';
						flag[i][abs(j + 1)] = s + 1;
					}						
				}
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}