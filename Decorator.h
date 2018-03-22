#pragma once
#include "Hamburger.h"

class Decorator : public Hamburger
{
};

//�丶��
//------------------------------------------------------------------------------------------

class Tomato : public Decorator
{
public :
	Tomato(Hamburger* _hamburger);//������
	int get_cost();				//���ݹ�ȯ
	string get_description();//�̸���ȯ
private :
	Hamburger* hamburger;		//�߰��� �ܹ��� ��ü������
};


//������
//------------------------------------------------------------------------------------------

class Bacon : public Decorator
{
public :
	Bacon(Hamburger* _hamburger);//������
	int get_cost();				//���ݹ�ȯ
	string get_description();//�̸���ȯ
private :
	Hamburger* hamburger;		//�߰��� �ܹ��� ��ü������
};

//ġ��
//------------------------------------------------------------------------------------------

class Cheese : public Decorator
{
public :
	Cheese(Hamburger* _hamburger);//������
	int get_cost();				//���ݹ�ȯ
	string get_description();//�̸���ȯ
private :
	Hamburger* hamburger;		//�߰��� �ܹ��� ��ü������
};

//�����
//------------------------------------------------------------------------------------------

class Lettuce : public Decorator
{
public :
	Lettuce(Hamburger* _hamburger);//������
	int get_cost();				//���ݹ�ȯ
	string get_description();//�̸���ȯ
private :
	Hamburger* hamburger;		//�߰��� �ܹ��� ��ü������
};

//��Ƽ
//------------------------------------------------------------------------------------------

class Patty : public Decorator
{
protected:
	Hamburger* hamburger;
};

//�Ұ�� ��Ƽ
//------------------------------------------------------------------------------------------

class Bulgogi : public Patty
{
public :
	Bulgogi(Hamburger* _hamburger);//������
	int get_cost();				//���ݹ�ȯ
	string get_description();//�̸���ȯ
};

//ġŲ ��Ƽ
//------------------------------------------------------------------------------------------

class Chicken : public Patty
{
public :
	Chicken(Hamburger* _hamburger);//������
	int get_cost();				//���ݹ�ȯ
	string get_description();//�̸���ȯ
};

