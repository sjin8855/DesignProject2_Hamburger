#pragma once
#include "HamburgerFactory.h"
#include "Order.h"
#include <Windows.h>
#include <queue>
#include <list>
class HamburgerShop
{
// �ܹ��� �Լ�
//------------------------------------------------------------------------------------------
public:
	HamburgerShop();	// ������
	void priority_sortedlist(Order order); // �켱���� �������ǿ� ���缭 list_order�� ����
	void make_order(int burger_type, int burger_count, int topiing[], int topiing_count, int info);// ������ �����
	void No_topiing_make_order(int burger_type, int burger_count, int info);	// ���ξ��� �ֹ�
	void priority_makelist();	// order_list�� �ܹ��Ÿ� ���� make_burger_list�� ����
	Order* make_hamburger(Order& order);// �ܹ��Ÿ� �����

// ��� �Լ�
//------------------------------------------------------------------------------------------
public:
	void print_start();	// ����
	void print_menu();	// �޴� ���
	void print_order();	//	list_order ����� ���� ���
	void print_hamburger();	// �ϼ��� �ܹ��� ���
	void print_topiing(int burger_type, int burger_count, int &info);
	//void print_current_order(int info);

// ���� �Լ�
//------------------------------------------------------------------------------------------
public:
	void save_user();	// ���� ����
	void load_user();	// ���� �ε�
	User* search_user(int _id);	// �Է¹��� ID�� array_user[10]���� Ž��

// �ܹ��� ��� ����
//------------------------------------------------------------------------------------------
private:
	HamburgerFactory hf;// HamburgerFactory ��ü
	Hamburger* hm;	// ���� �ֹ��� �ܹ���
	Order current_order;		//ť�� �ֹ��� ���� �� ���Ǵ� �ӽ� �ֹ���ü
	list<Order> make_burger_list;	// ���� ���
	list<Order> order_list;	// �� �ֹ� ���
	int employee;	// ������ ��(������ �� �ִ� ����)
	list<Order> imedeately_list;
// ���� ��� ����
//------------------------------------------------------------------------------------------
private:
	User* array_user[10];	// ���� �迭
	User* current_user;	// ���� ���̵�
	int user_count;	// �� ���� ��
};

