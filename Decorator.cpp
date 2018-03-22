#include "Decorator.h"

//�丶��
//----------------------------------------------
Tomato::Tomato(Hamburger* _hamburger)
{
	hamburger = _hamburger;
}

int Tomato::get_cost()
{
	return hamburger->get_cost()+500;
}

string Tomato::get_description()
{
	return hamburger->get_description()+", �丶��";
}


//������
//------------------------------------------------------------------------------------------
Bacon::Bacon(Hamburger* _hamburger)
{
	hamburger = _hamburger;
}

int Bacon::get_cost()
{
	return hamburger->get_cost()+300;
}

string Bacon::get_description()
{
	return hamburger->get_description()+", ������";
}

//ġ��
//------------------------------------------------------------------------------------------

Cheese::Cheese(Hamburger* _hamburger)
{
	hamburger = _hamburger;
}

int Cheese::get_cost()
{
	return hamburger->get_cost()+200;
}

string Cheese::get_description()
{
	return hamburger->get_description()+", ġ��";
}


//�����
//------------------------------------------------------------------------------------------

Lettuce::Lettuce(Hamburger* _hamburger)
{
	hamburger = _hamburger;
}

int Lettuce::get_cost()
{
	return hamburger->get_cost()+500;
}

string Lettuce::get_description()
{
	return hamburger->get_description()+", �����";
}


//��Ƽ
//------------------------------------------------------------------------------------------


//�Ұ�� ��Ƽ
//------------------------------------------------------------------------------------------

Bulgogi::Bulgogi(Hamburger* _hamburger)
{
	hamburger = _hamburger;
}

int Bulgogi::get_cost()
{
	return hamburger->get_cost()+1000;
}

string Bulgogi::get_description()
{
	return hamburger->get_description()+", �Ұ����Ƽ";
}

//ġŲ ��Ƽ
//------------------------------------------------------------------------------------------
Chicken::Chicken(Hamburger* _hamburger)
{
	hamburger = _hamburger;
}

int Chicken::get_cost()
{
	return hamburger->get_cost()+1500;
}

string Chicken::get_description()
{
	return hamburger->get_description()+", ġŲ��Ƽ";
}
