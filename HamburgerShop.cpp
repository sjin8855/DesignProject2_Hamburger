#include "HamburgerShop.h"


// 햄버거 함수
//------------------------------------------------------------------------------------------
HamburgerShop::HamburgerShop()	// 생성자
{
	employee = 0;
	current_user = NULL;
	user_count = 0;
	load_user();
}

void HamburgerShop::priority_sortedlist(Order order) // 우선순위 정렬조건에 맞춰서 list_order에 삽입
{
	list<Order>::iterator iter;
	list<Order>::iterator imedeately;
	list<Order> list;
	bool check = false;

	//대량주문 무조건 맨뒤로뺌.
	if(order.get_burger_count()>=20)
		order_list.push_back(order);
	//소량주문
	else
	{
		if(order_list.size()==0)	//하나도 없을시
			order_list.push_front(order);	//맨처음 추가
		else
		{
			if(order.get_user()->get_grade()=="VIP")	//VIP
			{
				for(iter = order_list.begin(); iter!=order_list.end(); iter++)
				{
					if(iter->get_age()<5)
					{
						if(iter->get_user()->get_grade()=="GUEST")
						{
							order_list.insert(iter,order);	//게스트 앞에추가(r)
							check = true;
							break;
						}
					}
					else	// age 5보다 클때
					{
						imedeately = iter;
						for(;imedeately!=order_list.end();imedeately++)
						{
							if(check == true)
								break;

							if(imedeately->get_age()<5)
							{
								order_list.insert(imedeately,order);	// 5보다 큰것 뒤에다 추가
								check = true;
								break;
							}
						}
					}
				}
				if(check==false)
					order_list.push_back(order);	// 맨처음에 추가
			}

			else//GUEST
			{
				iter = order_list.begin();
				imedeately = iter;
				for(; iter!=order_list.end(); iter++)
				{
					if(check == true)
						break;

					if(iter->get_age()>5)	// 5번 이상 실행했을시
					{
						order_list.push_back(order);	// 맨뒤에 추가
						check = true;
						break;
					}
				}

				//5번 이상 실행한게 없을때
				if(check == false)
				{
					//20개이상 존재할때
					for( ; imedeately!=order_list.end(); imedeately++)
					{
						if(imedeately->get_burger_count()>20)
						{
							order_list.insert(imedeately, order);
							check = true;
							break;
						}
					}
				}
				//20개이상 존재X
				if(check == false)
					order_list.push_back(order);
			}
		}
	}
}

void HamburgerShop::make_order(int burger_type, int burger_count, int topiing[], int topiing_count, int info)// 오더를 만든다
{
	current_order.set_user( current_user );	// current_user 입력 
	current_order.set_burger_type(burger_type);	// 버거 종류 입력
	current_order.set_burger_count(burger_count); // 버거 개수 입력
	current_order.set_topping(topiing, topiing_count);  // 토핑 입력
	current_order.set_info(info);
	priority_sortedlist(current_order);  // 우선순위 정렬 함수 호출
}

void HamburgerShop::No_topiing_make_order(int burger_type, int burger_count, int info)
{
	current_order.set_user( current_user );	// current_user 입력
	current_order.set_burger_type(burger_type);	// 버거 종류 입력
	current_order.set_burger_count(burger_count); // 버거 개수 입력
	current_order.set_info(info);
	priority_sortedlist(current_order);  // 우선순위 정렬 함수 호출
}
/*
1. 생산량 확인
2. 
*/
void HamburgerShop::priority_makelist()	// order_list의 햄버거를 만들어서 make_burger_list에 삽입
{
	/*	한객체당 3개
	종업원 만큼 만들 수 있음
	*/
	int total_count = 0;	// employee많큼 실행 횟수
	int _current = 0;		// 현재 객체에서 실행한 양
	bool check = false;
	if(order_list.size()==0)
	{
		cout<<"주문목록이 없습니다."<<endl;
		return ;
	}

	list<Order>::iterator iter = order_list.begin();
	list<Order>::iterator imedi = order_list.begin();

	while(total_count<employee)		// employee만큼 반복
	{
		if(iter->get_burger_count()<=0)
		{
			if(iter!=--order_list.end())
			{
				order_list.erase(iter);
				iter = order_list.begin();
				_current = 0;
			}

			else
			{
				order_list.erase(iter);
				return ;
			}
			/*else
				return ;*/
		}

		if(_current == 3)
		{
			if(iter!=--order_list.end())
			{
				iter++;
				_current = 0;
			}

			else
				return ;
		}
		
		else if(_current<3)
		{
			Order order(iter->get_user(), iter->get_burgur_name(), _current+1, iter->get_price(), "");
			order.set_topping(iter->get_topping(), iter->get_count());
			order.set_burger_type(iter->get_burger_type());
			order.set_age(iter->get_age());
			order.set_info(iter->get_info());
			total_count++;
			_current++;
			iter->set_burger_count(iter->get_burger_count()-1);

/**/		if(iter->get_burger_count()==0 || _current == 3 || total_count == employee)
			{
				if(iter->get_burger_count()==0)
				{
					iter->set_message("");
					order.set_message("");
				}

				else
				{
					iter->set_message("기다려주세요");
					order.set_message("기다려주세요");
				}
					imedi = iter;
					for( ; imedi!=order_list.end(); imedi++)
						imedi->set_age(imedi->get_age()+1);
					make_burger_list.push_back(*make_hamburger(order));
/**/		}
	
		}
	}
}

Order* HamburgerShop::make_hamburger(Order& order)// 햄버거를 만든다
{
	hm = hf.create_hamburger(order.get_burger_type());
	for(int i=0;i<order.get_count();i++)
		hm = hf.add_topping(hm,order.get_topping()[i]);
	order.set_description(hm->get_description());
	order.set_price(hm->get_cost() * order.get_burger_count());
	order.get_user()->set_mileage(order.get_user()->get_mileage() +order.get_price()/10);
	
	return &order;

}

// 출력 함수
//------------------------------------------------------------------------------------------
void HamburgerShop::print_start()	// 시작
{
	cout<<"\tHambergerShop"<<endl<<endl;
	cout<<"\t종업원수를 입력해주세요 : ";
	cin >> employee;
	system("pause");
	system("cls");
	print_menu();
}

void HamburgerShop::print_topiing(int burger_type, int burger_count, int& info)
{
	int topiing;
	int sellect;
	int order[5];//토핑배열
	int count = 0;//토핑갯수
	while(count<5)
	{
		if(count == 4)	//토핑 갯수 꽉참
		{
			make_order(burger_type, burger_count, order, count, info);
			info ++;
			cout<<endl<<endl<<"\t더이상 토핑을 추가할 수 없습니다. 토핑추가를 종료합니다."<<endl;
			system("pause");
			system("cls");
			return ;
		}

		else
		{
			cout<<"\t   토핑 메뉴"<<endl<<endl;
			cout<<"\t1. 토마토"<<endl;
			cout<<"\t2. 베이컨"<<endl;
			cout<<"\t3. 치즈"<<endl;
			cout<<"\t4. 양상추"<<endl;
			cout<<"\t0. 종료"<<endl<<endl;
			cout<<"토핑 입력 : ";
			cin >> topiing;
			if(topiing==1 || topiing==2 || topiing==3 || topiing==4)
			{
				cout<<"\t토핑을 추가하시겠습니까? <Yes : 1 , No : 2>"<<endl;
				cin >> sellect;
				switch(sellect)
				{
				case 1:
					hm = hf.add_topping(hm, topiing);
					order[count] = topiing;
					count++;
					cout<<"\t토핑 추가되었습니다."<<endl<<endl;
					system("pause");
					system("cls");
					break;

				case 2:
					cout<<"\t추가하지 않았습니다."<<endl<<endl;
					system("pause");
					system("cls");
					continue;
					break;

				default:
					cout<<"\t잘못 입력 하셨습니다."<<endl;
					system("pause");
					system("cls");
					break;
				}	//스위치문
			}
			else if(topiing == 0)
			{
				make_order(burger_type, burger_count, order, count, info);
				system("cls");
				info ++;
				return ;
			}

			else
				cout<<"\t잘못된 값을 입력하셨습니다. 다시 입력해주세요"<<endl;
		}//안꽉찬 else문
	}//무한반복문
}//함수

void HamburgerShop::print_menu()	// 메뉴 출력
{
	list<Order>::iterator iter = make_burger_list.begin();
	int sellect=0;
	int id, form, count;
	int info = 0; // 현재 주문 찾기용 일련번호

	while(true)
	{
		cout<<"\tHambergerShop"<<endl<<endl;
		cout<<"\t메뉴"<<endl<<endl;
		cout<<"\t1. 햄버거 주문"<<endl;
		cout<<"\t2. 주문 내역"<<endl;
		cout<<"\t3. 햄버거 만들기"<<endl;
		cout<<"\t0. 종료 "<<endl;

		cout<<"\t메뉴 선택 : ";
		cin >> sellect;
		system("cls");
		switch(sellect)
		{
		case 1:
			cout<<"\t메뉴"<<endl<<endl;
			cout<<"\t1. 불고기 버거"<<endl;
			cout<<"\t2. 치킨 버거"<<endl;
			cout<<"\t3. 치즈 버거"<<endl;
			cout<<"\t0. 종료"<<endl<<endl<<endl;
			cout<<"\t아이디 입력 : ";
			cin >> id;
			current_user = search_user(id);
			if(current_user!=NULL)
			{
				cout<<"\t햄버거 종류 선택 : ";
				cin >> form;
				cout<<"\t개수 입력 : ";
				cin >> count;
				cout<<"\t사용 가능한 마일리지 : "<<current_user->get_mileage()<<endl;
				cout<<"\t토핑을 추가하시겠습니까? <YES : 1, No : 2> ";
				cin >> sellect;
				cout<<endl;

				switch(sellect)
				{
				case 1:
					system("cls");
					print_topiing(form, count, info);
					break;

				case 2:
					No_topiing_make_order(form, count, info);
					system("cls");
					/*print_current_order(info);*/
					info++;
					break;

				default:
					break;
				}//스위치문
			}//if문
			else
				cout<<"\t아이디가 일치하지 않습니다."<<endl;
			break;

		case 2:	// 주문목록 출력
			print_order();
			system("pause");
			system("cls");
			break;

		case 3:	// 햄버거 만들기
			priority_makelist();
			print_hamburger();
			break;

		case 0:
			save_user();
			return ;
		}//스위치문
	}//while문
}//함수

void HamburgerShop::print_order()	//	list_order 저장된 변수 출력
	//	주문내역 보기
{
	if(order_list.size()==0)
	{
		cout<<endl<<endl<<"\t주문목록이 없습니다."<<endl;
		system("pause");
		system("cls");
		return ;
	}


	list<Order>::iterator start = order_list.begin();
	list<Order>::iterator end = order_list.end();
	for( ; start!=end; start++)
	{
		cout<< "\tID : " << start->get_user()->get_id() 
			<< ", 등급 : "	<< start->get_user()->get_grade() << endl
			<< "\t햄버거 이름 : "<< start->get_burgur_name()  << endl
			<< "\t햄버거 개수 : "<< start->get_burger_count() << endl
			<< "\t누적된 마일리지 : "<< start->get_user()->get_mileage() 
			<< endl << endl << "\t---------------------------------"<<endl;
	}
}

//void HamburgerShop::print_current_order(int info)
//{
//	cout<<"\t햄버거 주문 완료"<<endl<<endl;
//	list<Order>::iterator order = order_list.begin();
//
//	for(; order!=order_list.end(); order++)
//	{
//		if(order->get_info() == info)
//		{
//			cout<<"\tID :"<<current_user->get_id() <<", 등급 : "<<current_user->get_grade() << endl
//				<<"\t햄버거 이름 : "<< order->get_burgur_name() << endl
//				<<"\t햄버거 재료 : "<< order->get_description()<<endl
//				<<"\t햄버거 개수 : "<< order->get_burger_count() << endl
//				<<"\t햄버거 가격 : "<< order->get_price() << endl
//				<<"\t누적된 마일리지 : "<< current_user->get_mileage() <<endl<<endl;
//			system("pause");
//			system("cls");
//		}
//	}
//}

void HamburgerShop::print_hamburger()	// 완성된 햄버거 출력
{
	list<Order>::iterator hamburger;
	list<Order>::iterator initialization;
	hamburger = make_burger_list.begin();
	initialization = make_burger_list.begin();

	if(make_burger_list.empty())
		return ;	

	for(; hamburger != make_burger_list.end(); hamburger = make_burger_list.begin())
	{

		cout<<"ID : "<<hamburger->get_user()->get_id()<<", 등급 : "<<hamburger->get_user()->get_grade()<<endl;
		cout<<"햄버거이름 : "<<hamburger->get_burgur_name()<<endl;
		cout<<"햄버거재료 : "<<hamburger->get_description()<<endl;
		cout<<"햄버거개수 : "<<hamburger->get_burger_count()<<endl;
		cout<<"햄버거가격 : "<<hamburger->get_price()<<endl;
		cout<<"누적된 마일리지 : "<<hamburger->get_user()->get_mileage()<<endl;
		cout<<hamburger->get_message()<<endl;
		cout<<"-----------------------------------"<<endl;
		//if(make_burger_list.begin()->get_burger_count()==0)
		make_burger_list.erase(hamburger);
		//hamburger = make_burger_list.begin();
	}
}


// 유저 함수
//------------------------------------------------------------------------------------------
void HamburgerShop::save_user()	// 유저 저장
{
	ofstream ofs;
	ofs.open("user.txt");
	for(int i=0; i<user_count; i++)
	{
		ofs << endl
			<< array_user[i]->get_id() << ' ' 
			<< array_user[i]->get_mileage() << ' '
			<< array_user[i]->get_grade();
	}

	ofs.close();
}

void HamburgerShop::load_user()	// 유저 로드
{ 
	ifstream ifs;
	ifs.open("user.txt");
	int id, mileage;
	string grade;
	while(!ifs.eof())
	{
		User* user = new User;
		ifs >> id >> mileage >> grade;
		user->set_id(id);
		user->set_mileage(mileage);
		user->set_grade(grade);
		array_user[user_count] = user;
		user_count++;
	}
	ifs.close();
}

User* HamburgerShop::search_user(int _id)	// 입력받은 ID로 array_user[10]에서 탐색
{
	for(int i=0; i<user_count; i++)
		if(array_user[i]->get_id() == _id)
			return array_user[i];
	return NULL;
}