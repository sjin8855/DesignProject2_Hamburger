#include"HamburgerFactory.h"

Hamburger* HamburgerFactory::create_hamburger(int _type)		// �ܹ��� �����
{
	Hamburger* burger; 
	switch(_type)
	{
		case 1:	// �Ұ�� ����
			burger = new Wheat(); // �а��继
			burger = new Bulgogi(burger); // �Ұ����Ƽ
			burger = new Tomato(burger); // �丶��
			burger = new Lettuce(burger); //�����
			burger = new Cheese(burger); // ġ��
			return burger;
			break;
		case 2:	// ġŲ ����
			burger = new Wheat(); // �а��继
			burger = new Chicken(burger); // ġŲ
			burger = new Tomato(burger); // �丶��
			burger = new Lettuce(burger); // �����
			burger = new Bacon(burger); // ������
			break;
		case 3:	// ġ�� ����
			burger = new Rye(); // ȣ�л�
			burger = new Cheese(burger); // ġ��
			burger = new Tomato(burger); // �丶��
			burger = new Lettuce(burger); // �����
			burger = new Bacon(burger); // ������
			break;
	}
	return NULL;
}

Hamburger* HamburgerFactory::add_topping(Hamburger* _hm, int _type)	// �����߰�
{
	switch(_type)
	{
	case 1:	// �丶��
		_hm = new Tomato(_hm);
		return _hm;

	case 2:	// ������
		_hm = new Bacon(_hm);
		return _hm;

	case 3:	// ġ��
		_hm = new Cheese(_hm);
		return _hm;

	case 4:	// �����
		_hm = new Lettuce(_hm);
		return _hm;
	}
	return NULL;
}