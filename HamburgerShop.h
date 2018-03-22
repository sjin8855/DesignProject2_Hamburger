#pragma once
#include "HamburgerFactory.h"
#include "Order.h"
#include <Windows.h>
#include <queue>
#include <list>
class HamburgerShop
{
// 햄버거 함수
//------------------------------------------------------------------------------------------
public:
	HamburgerShop();	// 생성자
	void priority_sortedlist(Order order); // 우선순위 정렬조건에 맞춰서 list_order에 삽입
	void make_order(int burger_type, int burger_count, int topiing[], int topiing_count, int info);// 오더를 만든다
	void No_topiing_make_order(int burger_type, int burger_count, int info);	// 토핑없는 주문
	void priority_makelist();	// order_list의 햄버거를 만들어서 make_burger_list에 삽입
	Order* make_hamburger(Order& order);// 햄버거를 만든다

// 출력 함수
//------------------------------------------------------------------------------------------
public:
	void print_start();	// 시작
	void print_menu();	// 메뉴 출력
	void print_order();	//	list_order 저장된 변수 출력
	void print_hamburger();	// 완성된 햄버거 출력
	void print_topiing(int burger_type, int burger_count, int &info);
	//void print_current_order(int info);

// 유저 함수
//------------------------------------------------------------------------------------------
public:
	void save_user();	// 유저 저장
	void load_user();	// 유저 로드
	User* search_user(int _id);	// 입력받은 ID로 array_user[10]에서 탐색

// 햄버거 멤버 변수
//------------------------------------------------------------------------------------------
private:
	HamburgerFactory hf;// HamburgerFactory 객체
	Hamburger* hm;	// 현재 주문한 햄버거
	Order current_order;		//큐에 주문을 넣을 때 사용되는 임시 주문객체
	list<Order> make_burger_list;	// 생산 목록
	list<Order> order_list;	// 총 주문 목록
	int employee;	// 종업원 수(생산할 수 있는 갯수)
	list<Order> imedeately_list;
// 유저 멤버 변수
//------------------------------------------------------------------------------------------
private:
	User* array_user[10];	// 유저 배열
	User* current_user;	// 현재 아이디
	int user_count;	// 총 유저 수
};

