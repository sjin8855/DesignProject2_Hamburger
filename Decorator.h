#pragma once
#include "Hamburger.h"

class Decorator : public Hamburger
{
};

//토마토
//------------------------------------------------------------------------------------------

class Tomato : public Decorator
{
public :
	Tomato(Hamburger* _hamburger);//생성자
	int get_cost();				//가격반환
	string get_description();//이름반환
private :
	Hamburger* hamburger;		//추가할 햄버거 객체포인터
};


//베이컨
//------------------------------------------------------------------------------------------

class Bacon : public Decorator
{
public :
	Bacon(Hamburger* _hamburger);//생성자
	int get_cost();				//가격반환
	string get_description();//이름반환
private :
	Hamburger* hamburger;		//추가할 햄버거 객체포인터
};

//치즈
//------------------------------------------------------------------------------------------

class Cheese : public Decorator
{
public :
	Cheese(Hamburger* _hamburger);//생성자
	int get_cost();				//가격반환
	string get_description();//이름반환
private :
	Hamburger* hamburger;		//추가할 햄버거 객체포인터
};

//양상추
//------------------------------------------------------------------------------------------

class Lettuce : public Decorator
{
public :
	Lettuce(Hamburger* _hamburger);//생성자
	int get_cost();				//가격반환
	string get_description();//이름반환
private :
	Hamburger* hamburger;		//추가할 햄버거 객체포인터
};

//패티
//------------------------------------------------------------------------------------------

class Patty : public Decorator
{
protected:
	Hamburger* hamburger;
};

//불고기 패티
//------------------------------------------------------------------------------------------

class Bulgogi : public Patty
{
public :
	Bulgogi(Hamburger* _hamburger);//생성자
	int get_cost();				//가격반환
	string get_description();//이름반환
};

//치킨 패티
//------------------------------------------------------------------------------------------

class Chicken : public Patty
{
public :
	Chicken(Hamburger* _hamburger);//생성자
	int get_cost();				//가격반환
	string get_description();//이름반환
};

