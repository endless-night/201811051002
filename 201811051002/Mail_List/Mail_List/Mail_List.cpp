#include <iostream>
#include "mysql.h"
#include "conio.h"
#include "Mysql_Op.h"
#include "User_cherk.h"

using namespace std;

int main()
{
	Mysql_Op mysql_op;
	User_cherk user_cherk;
	int id_2 = 0;
	int id_4 = 0;
	char type_4;
	char inf_4[50];
	char cmd;
	char type_t;
	char name_t[50];
	while (true)
	{
		user_cherk.put_values();
		if (user_cherk.cherk_user())
		{
			system("cls");
			break;
		}
		else
		{
			cout << "\n用户名不存在或密码错误,按下任意键重新输入用户名和密码";
			_getch();
			system("cls");
			continue;
		}
			
	}
	while (1)
	{
		cout << "/*******************************************个人通讯录管理系统*************************************************/\n" << endl;
		cout << "/********************************************   1:添加联系人   ************************************************/\n" << endl;
		cout << "/********************************************   2:删除联系人   ************************************************/\n" << endl;
		cout << "/********************************************   3:显示联系人   ************************************************/\n" << endl;
		cout << "/********************************************   4:修改联系人   ************************************************/\n" << endl;
		cout << "/********************************************   5:查找联系人   ************************************************/\n" << endl;
		cout << "请输入指令 1/2/3/4/5 ？";
		cin >> cmd;
		if (cmd == '1')
		{
			mysql_op.insert_contact();
		}
		else if (cmd == '2')
		{
			cout << "\n请输入要删除的联系人的id:";
			cin >> id_2;
			mysql_op.delet_contact(id_2);
		}
		else if (cmd == '3')
		{
			system("cls");
			mysql_op.show_list();
		}
		else if (cmd == '4')
		{
			system("cls");
			cout << "\n属性   1：名字   2：公司   3：固定电话   4：移动电话   5：类型  6：Email   7：QQ    8：家庭地址\n" << endl;
			cout << "请输入要修改的属性、修改的内容、要修改联系人的id" << endl;
			cin >> type_4 >> inf_4 >> id_4;
			mysql_op.correct_contact(type_4, inf_4, id_4);
		}
		else if (cmd == '5')
		{
			cout << "\n类型指令  1：名字     2：公司    3：固定电话    4：移动电话    5：类型\n" << endl;
			cout << "请输入要查询的类型？";
			cin >> type_t;
			cout << "\n" << endl;
			cout << "请输入要查询的信息？";
			cin >> name_t;
			cout << endl;
			mysql_op.search_contact(type_t, name_t);
		}
		system("cls");
	}
}

