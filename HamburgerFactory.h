#pragma once
#include"Decorator.h"
class HamburgerFactory
{
public:
	Hamburger* create_hamburger(int _type);// 햄버거 만들기
	Hamburger* add_topping(Hamburger* _hm, int _type);	// 토핑추가
};

