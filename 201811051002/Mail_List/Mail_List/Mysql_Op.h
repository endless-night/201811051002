#pragma once
#include"mysql.h"

class Mysql_Op
{
private:
	MYSQL *con;
public:
	Mysql_Op();
	~Mysql_Op();
	void insert_contact();
	void correct_contact(char type, char new_data[], int id);	
	void search_contact(char type, char  name_t[]);
	void delet_contact(int id);
	void show_list();
};

struct Contact
{
	char name[20];
	char company[40];
	char telephone[20];
	char mobelphone[20];
	char type[20];
	char email[20];
	char qq[40];
	char home_address[100];
};

