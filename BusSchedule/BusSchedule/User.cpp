#pragma once
#include "Bus.cpp"
#include "Registration.cpp"
struct User //: public Bus, public Registration
{
	void User_Menu()
	{
		User U;
		Bus BusFunc;
		bool exitUM = true;
		while (exitUM)
		{
			cout << "\t\t\t\t\tМЕНЮ" << endl;
			cout << "1. Просмотр информации о рейсах" << endl;
			cout << "2. Поиск рейса" << endl;
			cout << "3. Сортировка рейсов" << endl;
			cout << "4. Индивидуальное задание" << endl;
			cout << "0. Назад" << endl;
			int change0;
			cin >> change0;
			system("cls");
			switch (change0)
			{
			case 1:
				BusFunc.view_bus();
				break;

			case 2:
				BusFunc.search_bus();
				break;

			case 3:

				BusFunc.sort_bus(); 
				break;

			case 4:

				BusFunc.task();
				break;

			case 0:
				exitUM = false;
				system("cls");
				break;
			default:
				cout << "Неверно выбран пункт меню" << endl;
				break;
			}
		}
	}
};


