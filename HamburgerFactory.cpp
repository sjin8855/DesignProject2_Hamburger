#include"HamburgerFactory.h"

Hamburger* HamburgerFactory::create_hamburger(int _type)		// 햄버거 만들기
{
	Hamburger* burger; 
	switch(_type)
	{
		case 1:	// 불고기 버거
			burger = new Wheat(); // 밀가루빵
			burger = new Bulgogi(burger); // 불고기패티
			burger = new Tomato(burger); // 토마토
			burger = new Lettuce(burger); //양상추
			burger = new Cheese(burger); // 치즈
			return burger;
			break;
		case 2:	// 치킨 버거
			burger = new Wheat(); // 밀가루빵
			burger = new Chicken(burger); // 치킨
			burger = new Tomato(burger); // 토마토
			burger = new Lettuce(burger); // 양상추
			burger = new Bacon(burger); // 베이컨
			break;
		case 3:	// 치즈 버거
			burger = new Rye(); // 호밀빵
			burger = new Cheese(burger); // 치즈
			burger = new Tomato(burger); // 토마토
			burger = new Lettuce(burger); // 양상추
			burger = new Bacon(burger); // 베이컨
			break;
	}
	return NULL;
}

Hamburger* HamburgerFactory::add_topping(Hamburger* _hm, int _type)	// 토핑추가
{
	switch(_type)
	{
	case 1:	// 토마토
		_hm = new Tomato(_hm);
		return _hm;

	case 2:	// 베이컨
		_hm = new Bacon(_hm);
		return _hm;

	case 3:	// 치즈
		_hm = new Cheese(_hm);
		return _hm;

	case 4:	// 양상추
		_hm = new Lettuce(_hm);
		return _hm;
	}
	return NULL;
}