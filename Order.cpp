#include "Order.h"
// �ܹ��� ����, ����, ����, �ð�, �����ID

Order::Order()
{
	burger_count = 0;
	price = 0;
	age = 0;
	burger_type = 0;
	message = "";
}

Order::Order(User* _user, string _burgur_name, int _burger_count, int _price, string _message)
{
	user = _user;
	burgur_name = _burgur_name;
	burger_count = _burger_count;
	price = _price;
	message = _message;
}

User* Order::get_user()	// ���������� ����
{
	return user;
}
string Order::get_burgur_name()	// �ܹ��� �̸� ����
{
	return burgur_name;
}

int Order::get_burger_count()		// �ܹ��� ���� ����
{
	return burger_count;
}

int Order::get_price()	// �ܹ��� ���� ����
{
	return price;
}

string Order::get_message()	// �ܹ��� ��� �޼��� ����
{
	return message;
}

void Order::set_user(User* _user)	// ���������� �Է�
{
	user = _user;
}

void Order::set_burgur_name(string _name)	// �ܹ��� �̸� �Է�
{
	burgur_name = _name;
}

void Order::set_burger_count(int _count)	// �ֹ��� �ܹ��� ���� �Է�
{
	burger_count = _count;
	price *= burger_count;
}

void Order::set_price(int _price)	// �ֹ� ���� �Է�
{
	price = _price;
}

void Order::set_message(string _message)	//	�ܹ��� ��� �޼��� �Է�
{
	message = _message;
}

int Order::get_age()	// �ܹ��� ���� Ƚ�� ����
{
	return age;
}

void Order::set_age(int _age)	// �ܹ��� ���� Ƚ�� �Է�
{
	age = _age;
}


void Order::set_description(string _description)	// �ܹ��� ���
{
	description = _description;
}

string Order::get_description()	// �ܹ��� ���
{
	return description;
}

int* Order::get_topping()	//���� �Է�
{
	return topiing;
}

void Order::set_topping(int ary[],int count)	//���� ����
{
	this->count = count;
	for(int i=0; i<count; i++)
		topiing[i] = ary[i];
			
	for(int i=0; i<count; i++)
	{

		/*switch(topiing[i])
		{
		case 1:
			price+=500;
			description = description+", �丶��";
			break;

		case 2:
			price+=300;
			description = description+", ������";
			break;

		case 3:
			price+=200;
			description = description+", ġ��";
			break;
			
		case 4:
			price+=500;
			description = description+", �����";
			break;
		}*/
	}
}

int Order::get_burger_type()	//����Ÿ�� ����
{
	return burger_type;
}

void Order::set_burger_type(int _type)	// ����Ÿ�� �Է�
{
	burger_type = _type;
	switch(burger_type)
	{
	case 1:
		burgur_name = "�Ұ�����";
		break;

	case 2:
		burgur_name = "ġŲ����";
		break;

	case 3:
		burgur_name = "ġ�����";
		break;
	}
}

int Order::get_info()
{
	return info;
}

void Order::set_info(int _info)
{
	info = _info;
}

int Order::get_count()
{
	return count;
}

void Order::set_count(int _count)
{
	count = _count;
}