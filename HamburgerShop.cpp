#include "HamburgerShop.h"


// �ܹ��� �Լ�
//------------------------------------------------------------------------------------------
HamburgerShop::HamburgerShop()	// ������
{
	employee = 0;
	current_user = NULL;
	user_count = 0;
	load_user();
}

void HamburgerShop::priority_sortedlist(Order order) // �켱���� �������ǿ� ���缭 list_order�� ����
{
	list<Order>::iterator iter;
	list<Order>::iterator imedeately;
	list<Order> list;
	bool check = false;

	//�뷮�ֹ� ������ �ǵڷλ�.
	if(order.get_burger_count()>=20)
		order_list.push_back(order);
	//�ҷ��ֹ�
	else
	{
		if(order_list.size()==0)	//�ϳ��� ������
			order_list.push_front(order);	//��ó�� �߰�
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
							order_list.insert(iter,order);	//�Խ�Ʈ �տ��߰�(r)
							check = true;
							break;
						}
					}
					else	// age 5���� Ŭ��
					{
						imedeately = iter;
						for(;imedeately!=order_list.end();imedeately++)
						{
							if(check == true)
								break;

							if(imedeately->get_age()<5)
							{
								order_list.insert(imedeately,order);	// 5���� ū�� �ڿ��� �߰�
								check = true;
								break;
							}
						}
					}
				}
				if(check==false)
					order_list.push_back(order);	// ��ó���� �߰�
			}

			else//GUEST
			{
				iter = order_list.begin();
				imedeately = iter;
				for(; iter!=order_list.end(); iter++)
				{
					if(check == true)
						break;

					if(iter->get_age()>5)	// 5�� �̻� ����������
					{
						order_list.push_back(order);	// �ǵڿ� �߰�
						check = true;
						break;
					}
				}

				//5�� �̻� �����Ѱ� ������
				if(check == false)
				{
					//20���̻� �����Ҷ�
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
				//20���̻� ����X
				if(check == false)
					order_list.push_back(order);
			}
		}
	}
}

void HamburgerShop::make_order(int burger_type, int burger_count, int topiing[], int topiing_count, int info)// ������ �����
{
	current_order.set_user( current_user );	// current_user �Է� 
	current_order.set_burger_type(burger_type);	// ���� ���� �Է�
	current_order.set_burger_count(burger_count); // ���� ���� �Է�
	current_order.set_topping(topiing, topiing_count);  // ���� �Է�
	current_order.set_info(info);
	priority_sortedlist(current_order);  // �켱���� ���� �Լ� ȣ��
}

void HamburgerShop::No_topiing_make_order(int burger_type, int burger_count, int info)
{
	current_order.set_user( current_user );	// current_user �Է�
	current_order.set_burger_type(burger_type);	// ���� ���� �Է�
	current_order.set_burger_count(burger_count); // ���� ���� �Է�
	current_order.set_info(info);
	priority_sortedlist(current_order);  // �켱���� ���� �Լ� ȣ��
}
/*
1. ���귮 Ȯ��
2. 
*/
void HamburgerShop::priority_makelist()	// order_list�� �ܹ��Ÿ� ���� make_burger_list�� ����
{
	/*	�Ѱ�ü�� 3��
	������ ��ŭ ���� �� ����
	*/
	int total_count = 0;	// employee��ŭ ���� Ƚ��
	int _current = 0;		// ���� ��ü���� ������ ��
	bool check = false;
	if(order_list.size()==0)
	{
		cout<<"�ֹ������ �����ϴ�."<<endl;
		return ;
	}

	list<Order>::iterator iter = order_list.begin();
	list<Order>::iterator imedi = order_list.begin();

	while(total_count<employee)		// employee��ŭ �ݺ�
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
					iter->set_message("��ٷ��ּ���");
					order.set_message("��ٷ��ּ���");
				}
					imedi = iter;
					for( ; imedi!=order_list.end(); imedi++)
						imedi->set_age(imedi->get_age()+1);
					make_burger_list.push_back(*make_hamburger(order));
/**/		}
	
		}
	}
}

Order* HamburgerShop::make_hamburger(Order& order)// �ܹ��Ÿ� �����
{
	hm = hf.create_hamburger(order.get_burger_type());
	for(int i=0;i<order.get_count();i++)
		hm = hf.add_topping(hm,order.get_topping()[i]);
	order.set_description(hm->get_description());
	order.set_price(hm->get_cost() * order.get_burger_count());
	order.get_user()->set_mileage(order.get_user()->get_mileage() +order.get_price()/10);
	
	return &order;

}

// ��� �Լ�
//------------------------------------------------------------------------------------------
void HamburgerShop::print_start()	// ����
{
	cout<<"\tHambergerShop"<<endl<<endl;
	cout<<"\t���������� �Է����ּ��� : ";
	cin >> employee;
	system("pause");
	system("cls");
	print_menu();
}

void HamburgerShop::print_topiing(int burger_type, int burger_count, int& info)
{
	int topiing;
	int sellect;
	int order[5];//���ι迭
	int count = 0;//���ΰ���
	while(count<5)
	{
		if(count == 4)	//���� ���� ����
		{
			make_order(burger_type, burger_count, order, count, info);
			info ++;
			cout<<endl<<endl<<"\t���̻� ������ �߰��� �� �����ϴ�. �����߰��� �����մϴ�."<<endl;
			system("pause");
			system("cls");
			return ;
		}

		else
		{
			cout<<"\t   ���� �޴�"<<endl<<endl;
			cout<<"\t1. �丶��"<<endl;
			cout<<"\t2. ������"<<endl;
			cout<<"\t3. ġ��"<<endl;
			cout<<"\t4. �����"<<endl;
			cout<<"\t0. ����"<<endl<<endl;
			cout<<"���� �Է� : ";
			cin >> topiing;
			if(topiing==1 || topiing==2 || topiing==3 || topiing==4)
			{
				cout<<"\t������ �߰��Ͻðڽ��ϱ�? <Yes : 1 , No : 2>"<<endl;
				cin >> sellect;
				switch(sellect)
				{
				case 1:
					hm = hf.add_topping(hm, topiing);
					order[count] = topiing;
					count++;
					cout<<"\t���� �߰��Ǿ����ϴ�."<<endl<<endl;
					system("pause");
					system("cls");
					break;

				case 2:
					cout<<"\t�߰����� �ʾҽ��ϴ�."<<endl<<endl;
					system("pause");
					system("cls");
					continue;
					break;

				default:
					cout<<"\t�߸� �Է� �ϼ̽��ϴ�."<<endl;
					system("pause");
					system("cls");
					break;
				}	//����ġ��
			}
			else if(topiing == 0)
			{
				make_order(burger_type, burger_count, order, count, info);
				system("cls");
				info ++;
				return ;
			}

			else
				cout<<"\t�߸��� ���� �Է��ϼ̽��ϴ�. �ٽ� �Է����ּ���"<<endl;
		}//�Ȳ��� else��
	}//���ѹݺ���
}//�Լ�

void HamburgerShop::print_menu()	// �޴� ���
{
	list<Order>::iterator iter = make_burger_list.begin();
	int sellect=0;
	int id, form, count;
	int info = 0; // ���� �ֹ� ã��� �Ϸù�ȣ

	while(true)
	{
		cout<<"\tHambergerShop"<<endl<<endl;
		cout<<"\t�޴�"<<endl<<endl;
		cout<<"\t1. �ܹ��� �ֹ�"<<endl;
		cout<<"\t2. �ֹ� ����"<<endl;
		cout<<"\t3. �ܹ��� �����"<<endl;
		cout<<"\t0. ���� "<<endl;

		cout<<"\t�޴� ���� : ";
		cin >> sellect;
		system("cls");
		switch(sellect)
		{
		case 1:
			cout<<"\t�޴�"<<endl<<endl;
			cout<<"\t1. �Ұ�� ����"<<endl;
			cout<<"\t2. ġŲ ����"<<endl;
			cout<<"\t3. ġ�� ����"<<endl;
			cout<<"\t0. ����"<<endl<<endl<<endl;
			cout<<"\t���̵� �Է� : ";
			cin >> id;
			current_user = search_user(id);
			if(current_user!=NULL)
			{
				cout<<"\t�ܹ��� ���� ���� : ";
				cin >> form;
				cout<<"\t���� �Է� : ";
				cin >> count;
				cout<<"\t��� ������ ���ϸ��� : "<<current_user->get_mileage()<<endl;
				cout<<"\t������ �߰��Ͻðڽ��ϱ�? <YES : 1, No : 2> ";
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
				}//����ġ��
			}//if��
			else
				cout<<"\t���̵� ��ġ���� �ʽ��ϴ�."<<endl;
			break;

		case 2:	// �ֹ���� ���
			print_order();
			system("pause");
			system("cls");
			break;

		case 3:	// �ܹ��� �����
			priority_makelist();
			print_hamburger();
			break;

		case 0:
			save_user();
			return ;
		}//����ġ��
	}//while��
}//�Լ�

void HamburgerShop::print_order()	//	list_order ����� ���� ���
	//	�ֹ����� ����
{
	if(order_list.size()==0)
	{
		cout<<endl<<endl<<"\t�ֹ������ �����ϴ�."<<endl;
		system("pause");
		system("cls");
		return ;
	}


	list<Order>::iterator start = order_list.begin();
	list<Order>::iterator end = order_list.end();
	for( ; start!=end; start++)
	{
		cout<< "\tID : " << start->get_user()->get_id() 
			<< ", ��� : "	<< start->get_user()->get_grade() << endl
			<< "\t�ܹ��� �̸� : "<< start->get_burgur_name()  << endl
			<< "\t�ܹ��� ���� : "<< start->get_burger_count() << endl
			<< "\t������ ���ϸ��� : "<< start->get_user()->get_mileage() 
			<< endl << endl << "\t---------------------------------"<<endl;
	}
}

//void HamburgerShop::print_current_order(int info)
//{
//	cout<<"\t�ܹ��� �ֹ� �Ϸ�"<<endl<<endl;
//	list<Order>::iterator order = order_list.begin();
//
//	for(; order!=order_list.end(); order++)
//	{
//		if(order->get_info() == info)
//		{
//			cout<<"\tID :"<<current_user->get_id() <<", ��� : "<<current_user->get_grade() << endl
//				<<"\t�ܹ��� �̸� : "<< order->get_burgur_name() << endl
//				<<"\t�ܹ��� ��� : "<< order->get_description()<<endl
//				<<"\t�ܹ��� ���� : "<< order->get_burger_count() << endl
//				<<"\t�ܹ��� ���� : "<< order->get_price() << endl
//				<<"\t������ ���ϸ��� : "<< current_user->get_mileage() <<endl<<endl;
//			system("pause");
//			system("cls");
//		}
//	}
//}

void HamburgerShop::print_hamburger()	// �ϼ��� �ܹ��� ���
{
	list<Order>::iterator hamburger;
	list<Order>::iterator initialization;
	hamburger = make_burger_list.begin();
	initialization = make_burger_list.begin();

	if(make_burger_list.empty())
		return ;	

	for(; hamburger != make_burger_list.end(); hamburger = make_burger_list.begin())
	{

		cout<<"ID : "<<hamburger->get_user()->get_id()<<", ��� : "<<hamburger->get_user()->get_grade()<<endl;
		cout<<"�ܹ����̸� : "<<hamburger->get_burgur_name()<<endl;
		cout<<"�ܹ������ : "<<hamburger->get_description()<<endl;
		cout<<"�ܹ��Ű��� : "<<hamburger->get_burger_count()<<endl;
		cout<<"�ܹ��Ű��� : "<<hamburger->get_price()<<endl;
		cout<<"������ ���ϸ��� : "<<hamburger->get_user()->get_mileage()<<endl;
		cout<<hamburger->get_message()<<endl;
		cout<<"-----------------------------------"<<endl;
		//if(make_burger_list.begin()->get_burger_count()==0)
		make_burger_list.erase(hamburger);
		//hamburger = make_burger_list.begin();
	}
}


// ���� �Լ�
//------------------------------------------------------------------------------------------
void HamburgerShop::save_user()	// ���� ����
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

void HamburgerShop::load_user()	// ���� �ε�
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

User* HamburgerShop::search_user(int _id)	// �Է¹��� ID�� array_user[10]���� Ž��
{
	for(int i=0; i<user_count; i++)
		if(array_user[i]->get_id() == _id)
			return array_user[i];
	return NULL;
}