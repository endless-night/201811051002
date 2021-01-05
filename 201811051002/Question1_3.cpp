#include <iostream>

using namespace std;

struct student
{
	int Chinese;
	int Math;
	int English;
	int sum;
	int Id;
};

int main()
{
	int n;
	cin >> n;
	student * student_grade = new student[n];
	for (int i = 0; i < n; i++)
	{
		cin >> student_grade[i].Chinese >> student_grade[i].Math >> student_grade[i].English;
		student_grade[i].sum = student_grade[i].Chinese + student_grade[i].Math + student_grade[i].English;
		student_grade[i].Id = i + 1;
	}
	student temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (student_grade[j].sum < student_grade[j+1].sum)
			{
				temp = student_grade[j];
				student_grade[j] = student_grade[j + 1];
				student_grade[j + 1] = temp;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (student_grade[i].Chinese > student_grade[i - 1].Chinese && student_grade[i].sum == student_grade[i - 1].sum)
		{
			temp = student_grade[i];
			student_grade[i] = student_grade[i - 1];
			student_grade[i - 1] = temp;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (student_grade[i].Chinese == student_grade[i - 1].Chinese && student_grade[i].sum == student_grade[i - 1].sum && student_grade[i].Id < student_grade[i - 1].Id)
		{
			temp = student_grade[i];
			student_grade[i] = student_grade[i - 1];
			student_grade[i - 1] = temp;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		cout << student_grade[i].Id << "  " << student_grade[i].sum << endl;
	}
	return 0;
}