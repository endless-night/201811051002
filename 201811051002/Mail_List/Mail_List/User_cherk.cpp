#include "User_cherk.h"
#include <iostream>

using namespace std;

User_cherk::User_cherk()
{
	con = mysql_init(NULL);
	if (0 == mysql_options(con, MYSQL_SET_CHARSET_NAME, "gbk"))//�����ַ���
	{
		cout << "\t-----�����ַ����ɹ�----\n" << endl;
	}
	if (mysql_real_connect(con, "127.0.0.1", "root", "123456", "mail_list", 3306, NULL, 0))  //���ӵ�mysql
	{
		cout << "\t-----  MySQL������ ----\n" << endl;
	}
	cout << "\t-----  ��ʼ���ɹ� ----\n" << endl;
	system("cls");
}

User_cherk::~User_cherk()
{
	mysql_close(con);          //�ر���mysql������
}


bool User_cherk::cherk_user()
{
	MYSQL_ROW row;
	MYSQL_RES *result;
	char sql[200];
	sprintf_s(sql, "SELECT * FROM user where username = '%s' and password = '%s'", username, password);
	mysql_query(con, sql);
	result = mysql_store_result(con);
	row = mysql_fetch_row(result);
	if (row)
		return true;
	else
		return false;
}

void User_cherk::put_values()
{
	cout << "�������û���:";
	cin >> username;
	cout << endl;
	cout << "����������:";
	cin >> password;
	cout << endl;
}