#pragma once
#include <iostream>
#include <string>
using namespace std;

class User
{
public:
	User();

public:
	int get_id();	// ID ��ȯ
	void set_id(int _id);	// ID �Է�
	int get_mileage();	// ���ϸ��� ��ȯ
	void set_mileage(int _mileage);	// ���ϸ��� �Է�
	string get_grade();	// grade ��ȯ
	void set_grade(string _grade);	// grade �Է�
	

private:
	int id;	//���� ID
	int mileage; // ���� ���ϸ���
	string grade;	// ���� ���
};

