#pragma once
#include"Decorator.h"
class HamburgerFactory
{
public:
	Hamburger* create_hamburger(int _type);// �ܹ��� �����
	Hamburger* add_topping(Hamburger* _hm, int _type);	// �����߰�
};

