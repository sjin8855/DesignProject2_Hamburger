#pragma once
#include <iostream>
#include <string>
using namespace std;

// 햄버거
//------------------------------------------------------------------------------------------
class Hamburger
{
public :
	Hamburger();
	virtual int get_cost() = 0;	//순수가상함수, 가격리턴
	virtual string get_description() //가상함수, 이름 리턴
	{return description;}

protected :
	string description;	//이름
	int cost;
};

// 밀가루빵
//------------------------------------------------------------------------------------------
class Wheat : public Hamburger
{
public :
	Wheat();
	int get_cost(); // 가격 리턴
};

//호밀빵
//------------------------------------------------------------------------------------------
class Rye : public Hamburger
{
public :
	Rye();
	int get_cost();	// 가격 리턴
};