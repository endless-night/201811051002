#include "iostream"

using namespace std;


/* ����int����*/
//int fun(int a, int b)
//{
//	int byte_1 = 0, byte_2 = 0, byte_3 = 0, byte_4 = 0, fun = 0;
//	byte_1 = (b / 10) % 10;
//	byte_2 = (a / 10) % 10;
//	byte_3 = b % 10;
//	byte_4 = a % 10;
//	fun = byte_1 + byte_2 * 10 + byte_3 * 100 + byte_4 * 1000;
//	return fun;
//}

/* ������������*/
//int & fun(int a, int b)
//{
//	int byte_1 = 0, byte_2 = 0, byte_3 = 0, byte_4 = 0, fun = 0;
//	int & fun_1 = fun;
//	byte_1 = (b / 10) % 10;
//	byte_2 = (a / 10) % 10;
//	byte_3 = b % 10;
//	byte_4 = a % 10;
//	fun = byte_1 + byte_2 * 10 + byte_3 * 100 + byte_4 * 1000;
//	return fun_1;
//}

/* ����ָ������*/
int * fun(int a, int b)
{
	int byte_1 = 0, byte_2 = 0, byte_3 = 0, byte_4 = 0, fun = 0;
	int * fun_1 = &fun;
	byte_1 = (b / 10) % 10;
	byte_2 = (a / 10) % 10;
	byte_3 = b % 10;
	byte_4 = a % 10;
	fun = byte_1 + byte_2 * 10 + byte_3 * 100 + byte_4 * 1000;
	return fun_1;
}
int main()
{
	int a, b;
	cin >> a >> b;
	cout << *fun(a, b) << endl;
	return 0;
}