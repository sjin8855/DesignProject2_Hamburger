#pragma once
#include "User.h"
#include <fstream>
#include <sstream>
// 햄버거 종류, 개수, 가격, 시간, 사용자ID

class Order
{
public:
	Order();
	Order(User* _user, string _burgur_name, int _burger_count, int _price, string _message);

public:
	User* get_user();	// 유저포인터 리턴
	string get_burgur_name();	// 햄버거 이름 리턴
	int get_burger_count();		// 햄버거 개수 리턴
	int get_price();	// 햄버거 가격 리턴
	string get_message();	// 햄버거 대기 메세지 리턴
	void set_user(User* _user);	// 유저포인터 입력
	void set_burgur_name(string _name);	// 햄버거 이름 입력
	void set_burger_count(int _count);	// 주문한 햄버거 개수 입력
	void set_price(int _price);	// 주문 가격 입력
	void set_message(string _message);	//	햄버거 대기 메세지 입력
	int get_age();	// 햄버거 만든 횟수 리턴
	void set_age(int _age);	// 햄버거 만든 횟수 입력
	void set_description(string _description);	// 햄버거 재료 입력
	string get_description();	// 햄버거 재료 리턴
	int* get_topping();	//토핑 리턴
	void set_topping(int ary[], int count);	//토핑 입력
	int get_burger_type();	//버거타입 리턴
	void set_burger_type(int _type);	// 버거타입 입력
	int get_info();	// info반환
	void set_info(int _info);
	int get_count();	// count반환
	void set_count(int _info);

private:
	User* user;	// 유저포인터
	string burgur_name;	// 햄버거 이름
	string description;	// 햄버거 재료
	int burger_count;	// 주문한 햄버거 개수
	int price;	// 햄버거 가격
	int age;	// 햄버거 만든 횟수
	string message;	// 햄버거 메세지
	int topiing[5];	// 토핑
	int burger_type;	// 버거타입
	int info;
	int count; // 토핑갯수
};

