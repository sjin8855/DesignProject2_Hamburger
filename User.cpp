#include "User.h"

User::User()
{
	id = 0;
	mileage = 0;
}

int User::get_id()	// ID ��ȯ
{
	return id;
}

void User::set_id(int _id)	// ID �Է�
{
	id = _id;
}

int User::get_mileage()	// ���ϸ��� ��ȯ
{
	return mileage;
}

void User::set_mileage(int _mileage)	// ���ϸ��� �Է�
{
	mileage = _mileage;
}

string User::get_grade()	// grade ��ȯ
{
	return grade;
}
void User::set_grade(string _grade)	// grade �Է�
{
	grade = _grade;
}

