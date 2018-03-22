#include "Order.h"
// 햄버거 종류, 개수, 가격, 시간, 사용자ID

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

User* Order::get_user()	// 유저포인터 리턴
{
	return user;
}
string Order::get_burgur_name()	// 햄버거 이름 리턴
{
	return burgur_name;
}

int Order::get_burger_count()		// 햄버거 개수 리턴
{
	return burger_count;
}

int Order::get_price()	// 햄버거 가격 리턴
{
	return price;
}

string Order::get_message()	// 햄버거 대기 메세지 리턴
{
	return message;
}

void Order::set_user(User* _user)	// 유버포인터 입력
{
	user = _user;
}

void Order::set_burgur_name(string _name)	// 햄버거 이름 입력
{
	burgur_name = _name;
}

void Order::set_burger_count(int _count)	// 주문한 햄버거 개수 입력
{
	burger_count = _count;
	price *= burger_count;
}

void Order::set_price(int _price)	// 주문 가격 입력
{
	price = _price;
}

void Order::set_message(string _message)	//	햄버거 대기 메세지 입력
{
	message = _message;
}

int Order::get_age()	// 햄버거 만든 횟수 리턴
{
	return age;
}

void Order::set_age(int _age)	// 햄버거 만든 횟수 입력
{
	age = _age;
}


void Order::set_description(string _description)	// 햄버거 재료
{
	description = _description;
}

string Order::get_description()	// 햄버거 재료
{
	return description;
}

int* Order::get_topping()	//토핑 입력
{
	return topiing;
}

void Order::set_topping(int ary[],int count)	//토핑 리턴
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
			description = description+", 토마토";
			break;

		case 2:
			price+=300;
			description = description+", 베이컨";
			break;

		case 3:
			price+=200;
			description = description+", 치즈";
			break;
			
		case 4:
			price+=500;
			description = description+", 양상추";
			break;
		}*/
	}
}

int Order::get_burger_type()	//버거타입 리턴
{
	return burger_type;
}

void Order::set_burger_type(int _type)	// 버거타입 입력
{
	burger_type = _type;
	switch(burger_type)
	{
	case 1:
		burgur_name = "불고기버거";
		break;

	case 2:
		burgur_name = "치킨버거";
		break;

	case 3:
		burgur_name = "치즈버거";
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