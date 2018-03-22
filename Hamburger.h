#pragma once
#include <iostream>
#include <string>
using namespace std;

// �ܹ���
//------------------------------------------------------------------------------------------
class Hamburger
{
public :
	Hamburger();
	virtual int get_cost() = 0;	//���������Լ�, ���ݸ���
	virtual string get_description() //�����Լ�, �̸� ����
	{return description;}

protected :
	string description;	//�̸�
	int cost;
};

// �а��继
//------------------------------------------------------------------------------------------
class Wheat : public Hamburger
{
public :
	Wheat();
	int get_cost(); // ���� ����
};

//ȣ�л�
//------------------------------------------------------------------------------------------
class Rye : public Hamburger
{
public :
	Rye();
	int get_cost();	// ���� ����
};