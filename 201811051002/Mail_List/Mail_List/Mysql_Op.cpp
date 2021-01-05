#include "Mysql_Op.h"
#include <iostream>
#include "conio.h"
#include"mysql.h"

using namespace std;

Mysql_Op::Mysql_Op()
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

Mysql_Op::~Mysql_Op()
{
	mysql_close(con);          //关闭与mysql的连接
}

void Mysql_Op::delet_contact(int id)
{
	char sql[100];
	sprintf_s(sql, "delete  FROM contacts where id = %d", id);
	if (!mysql_query(con, sql))
		cout << "删除成功！" << endl;
}

void Mysql_Op::correct_contact(char type, char new_data[], int id)
{
	char sql[100];
	if (type == '1')
	{
		sprintf_s(sql, "update contacts set name = '%s' where id = %d", new_data, id);
	}
	else if (type == '2')
	{
		sprintf_s(sql, "update contacts set company = '%s' where id = %d", new_data, id);
	}
	else if (type == '3')
	{
		sprintf_s(sql, "update contacts set telephone = '%s' where id = %d", new_data, id);
	}
	else if (type == '4')
	{
		sprintf_s(sql, "update contacts set mobelphone = '%s' where id = %d", new_data, id);
	}
	else if (type == '5')
	{
		sprintf_s(sql, "update contacts set type = '%s' where id = %d", new_data, id);
	}
	else if (type == '6')
	{
		sprintf_s(sql, "update contacts set email = '%s' where id = %d", new_data, id);
	}
	else if (type == '7')
	{
		sprintf_s(sql, "update contacts set qq = '%s' where id = %d", new_data, id);
	}
	else if (type == '8')
	{
		sprintf_s(sql, "update contacts set home_address = '%s' where id = %d", new_data, id);
	}
	mysql_query(con, sql);
	cout << "修改成功！" << endl;
}


void Mysql_Op::insert_contact()
{
	char sql[400];
	int num;
	Contact contracts[10];
	cout << "要添加几个联系人？";
	cin >> num;
	system("cls");
	cout << "请以姓名、公司、固定电话、移动电话、类型、email、qq、家庭住址填写" << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> contracts[i].name >> contracts[i].company >> contracts[i].telephone >> contracts[i].mobelphone >> contracts[i].type >> contracts[i].email >> contracts[i].qq >> contracts[i].home_address;
	}
	for (int i = 0; i < num; i++)
	{
		sprintf_s(sql, "insert into contacts(name,company,telephone,mobelphone,type,email,qq,home_address) values('%s','%s','%s','%s','%s','%s','%s','%s')", contracts[i].name, contracts[i].company, contracts[i].telephone, contracts[i].mobelphone, contracts[i].type, contracts[i].email, contracts[i].qq, contracts[i].home_address);
		if (mysql_query(con, sql))
			cout << mysql_error(con);
	}
	cout << "添加成功！" << endl;
}

void Mysql_Op::search_contact(char type, char  name_t[])
{
	MYSQL_ROW row;
	MYSQL_RES *result;
	char sql[200];
	int num, j = 0;
	char cmd;
	if (type == '1')
	{
		sprintf_s(sql, "SELECT name,company,telephone,mobelphone,type,email,qq,home_address,id FROM contacts where name = '%s'", name_t);
	}
	else if (type == '2')
	{
		sprintf_s(sql, "SELECT name,company,telephone,mobelphone,type,email,qq,home_address,id FROM contacts where company = '%s'", name_t);
	}
	else if (type == '3')
	{
		sprintf_s(sql, "SELECT name,company,telephone,mobelphone,type,email,qq,home_address,id FROM contacts where telephone = '%s'", name_t);
	}
	else if (type == '4')
	{
		sprintf_s(sql, "SELECT name,company,telephone,mobelphone,type,email,qq,home_address,id FROM contacts where mobelphone = '%s'", name_t);
	}
	else if (type == '5')
	{
		sprintf_s(sql, "SELECT name,company,telephone,mobelphone,type,email,qq,home_address,id FROM contacts where type = '%s'", name_t);
	}
	mysql_query(con, sql);
	result = mysql_store_result(con);
	num = mysql_num_fields(result);
	system("cls");
	cout << " 姓名 " << "       公司     " << "  固定电话     " << "     移动电话     " << " 类型 " << "         email         " << "        QQ         " << " home_address    id   \n" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		if (j > 10)
		{
			j = 0;
			cout << "\n是否翻页 y/n ?";
			cin >> cmd;
			cout << endl;
			if (cmd == 'n')
				break;
			else
			{
				system("cls");
				cout << " 姓名 " << "       公司     " << "  固定电话     " << "     移动电话     " << " 类型 " << "         email         " << "        QQ         " << " home_address   \n" << endl;
			}

		}
		for (int i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << "\n" << endl;
		j++;
	}
	cout << "\n按任意键退出查询\n";
	_getch();
	system("cls");
}

void Mysql_Op::show_list()
{
	MYSQL_ROW row;
	MYSQL_RES *result;
	int num, j = 0;
	char cmd;
	if (mysql_query(con, "SELECT * FROM contacts"))
		return;
	result = mysql_store_result(con);
	num = mysql_num_fields(result);
	cout << " 姓名        公司       固定电话          移动电话      类型          email                 QQ          home_address  id   \n" << endl;
	while ((row = mysql_fetch_row(result)))  //遇到最后一行，则中止循环
	{
		if (j > 10)
		{
			j = 0;
			cout << "\n是否翻页 y/n ?";
			cin >> cmd;
			cout << endl;
			if (cmd == 'n')
				break;
			else
			{
				system("cls");
				cout << " 姓名 " << "       公司     " << "  固定电话     " << "     移动电话     " << " 类型 " << "         email         " << "        QQ         " << " home_address   \n" << endl;
			}

		}
		for (int i = 0; i < num; i++)         //利用for循环，输出该行的每一列
		{
			cout << row[i] << "\t";    //row是MYSQL_ROW变量，可以当做数组使用，i为列数
		}
		cout << "\n" << endl;
		j++;
	}
	cout << "\n按任意键退出查询\n";
	_getch();
	system("cls");
	mysql_free_result(result);     //释放结果集所占用的内存
}