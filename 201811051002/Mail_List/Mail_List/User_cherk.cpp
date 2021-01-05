#include "User_cherk.h"
#include <iostream>

using namespace std;

User_cherk::User_cherk()
{
	con = mysql_init(NULL);
	if (0 == mysql_options(con, MYSQL_SET_CHARSET_NAME, "gbk"))//设置字符集
	{
		cout << "\t-----设置字符集成功----\n" << endl;
	}
	if (mysql_real_connect(con, "127.0.0.1", "root", "123456", "mail_list", 3306, NULL, 0))  //连接到mysql
	{
		cout << "\t-----  MySQL已连接 ----\n" << endl;
	}
	cout << "\t-----  初始化成功 ----\n" << endl;
	system("cls");
}

User_cherk::~User_cherk()
{
	mysql_close(con);          //关闭与mysql的连接
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
	cout << "请输入用户名:";
	cin >> username;
	cout << endl;
	cout << "请输入密码:";
	cin >> password;
	cout << endl;
}