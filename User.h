#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
public:
	User();

public:
	int get_id();	// ID 반환
	void set_id(int _id);	// ID 입력
	int get_mileage();	// 마일리지 반환
	void set_mileage(int _mileage);	// 마일리지 입력
	string get_grade();	// grade 반환
	void set_grade(string _grade);	// grade 입력
	

private:
	int id;	//유저 ID
	int mileage; // 유저 마일리지
	string grade;	// 유저 등급
};

