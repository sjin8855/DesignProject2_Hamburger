#include "Decorator.h"

//토마토
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
	return hamburger->get_description()+", 토마토";
}


//베이컨
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
	return hamburger->get_description()+", 베이컨";
}

//치즈
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
	return hamburger->get_description()+", 치즈";
}


//양상추
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
	return hamburger->get_description()+", 양상추";
}


//패티
//------------------------------------------------------------------------------------------


//불고기 패티
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
	return hamburger->get_description()+", 불고기패티";
}

//치킨 패티
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
	return hamburger->get_description()+", 치킨패티";
}
