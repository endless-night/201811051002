#pragma once

#include "mysql.h"

class User_cherk
{
private:
	MYSQL * con;
	char username[255];
	char password[255];
public:
	User_cherk();
	~User_cherk();
	bool cherk_user();
	void put_values();
};

