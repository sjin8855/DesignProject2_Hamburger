#include "User.h"

User::User()
{
	id = 0;
	mileage = 0;
}

int User::get_id()	// ID 반환
{
	return id;
}

void User::set_id(int _id)	// ID 입력
{
	id = _id;
}

int User::get_mileage()	// 마일리지 반환
{
	return mileage;
}

void User::set_mileage(int _mileage)	// 마일리지 입력
{
	mileage = _mileage;
}

string User::get_grade()	// grade 반환
{
	return grade;
}
void User::set_grade(string _grade)	// grade 입력
{
	grade = _grade;
}

