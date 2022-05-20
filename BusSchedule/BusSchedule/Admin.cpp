#pragma once
#include "User.cpp"
struct Admin //public User
{
	void MenuAmin()
	{
		Bus B;
		Registration R;
		bool exitAM = true;
		Admin A;
		while (exitAM)
		{
			cout << "Меню Администратора" << endl;
			cout << "1. Добавить автобус в расписание" << endl;
			cout << "2. Просмотр информации рейсах" << endl;
			cout << "3. Удалить информацию о всех рейсах" << endl;
			cout << "4. Удалить информацию об определенном рейсе" << endl;
			cout << "5. Поиск рейса" << endl;
			cout << "6. Удалить определенного пользователя" << endl;
			cout << "7. Удалить всех пользователей" << endl;
			cout << "8. Просмотр аккаунтов всех пользователей" << endl;
			cout << "9. Зарегистрировать пользователя" << endl;
			cout << "10. Редактировать информацию о рейсе" << endl;
			cout << "11. Сортировка" << endl;
			cout << "12. Индивидуальное задание" << endl;
			cout << "0. Назад" << endl;
			int change1; cin >> change1; system("cls");
			switch (change1)
			{
			case 1:
				B.add_bus(); break;
			case 2:
				B.view_bus(); break;
			case 3:
				A.Delete_information_about_Bus(); break;
			case 4:
				B.delete_bus(); break;
			case 5:
				B.search_bus(); break;
			case 6:
				A.DeteteUser(); break;
			case 7:
				A.Delete_All_Users(); break;
			case 8:
				A.View_Users_Accounts(); break;
			case 9:
				R.RegistrationFunction(); break;
			case 10:
				B.edit_bus(); break;
			case 11:
				B.sort_bus(); break;
			case 12: { // индивидуальное задание
				B.task(); break;
			}
			case 0:
				exitAM = false; break;
			default:
				cout << "Error" << endl;
				break;
			}
		}
	}

	void Delete_information_about_Bus()
	{
		Bus B;
		ofstream InfFile;
		InfFile.open(B.Information, ofstream::trunc);
		cout << "Информация о рейсах удалена" << endl;
		system("pause");
		system("cls");
		InfFile.close();
	}

	void Delete_All_Users()
	{
		Registration R1;
		ofstream UFile;
		string path = R1.RegDATA;
		UFile.open(path, ofstream::trunc);
		cout << "Аккаунты всех пользователей удалены" << endl;
		system("pause");
		system("cls");
		UFile.close();
	}

	void View_Users_Accounts()
	{
		Registration R1;
		ifstream UserFile;
		string path = R1.RegDATA;
		UserFile.open(path);
		if (!UserFile.is_open())
		{
			cout << "Ошибка открытия файла!" << endl;
		}
		else
		{
			char ch;
			cout << "\t\t\t\tАккаунты всех пользователей" << endl;
			while (UserFile.get(ch))
			{
				cout << ch;
			}
		}
		UserFile.close();
		system("pause");
		system("cls");
	}

	void DeteteUser()
	{
		int size = 0;
		ifstream InfFile;
		Registration R;
		InfFile.open(R.RegDATA);
		while (InfFile.peek() != EOF)
		{
			InfFile >> R.LoginUser1; InfFile.get();
			InfFile >> R.PasswordUser1; InfFile.get();
			size++;
		}
		InfFile.close();

		int i = 0;
		Registration* arr = new Registration[size];
		ifstream InfFile1;
		InfFile1.open(R.RegDATA);
		while (InfFile1.peek() != EOF)
		{
			InfFile1 >> arr[i].LoginUser1; InfFile1.get();
			InfFile1 >> arr[i].PasswordUser1; InfFile1.get();
			i++;
		}
		InfFile1.close();

		string tmp;
		int n = -1;
		cout << "Введите логин пользователя которого хотите удалить: "; cin >> tmp;
		for (int j = 0; j < size; j++) {
			if (arr[j].LoginUser1 == tmp)
				n = j;
		}
		if (n == -1)
			cout << "Пользователя с таким логином нет!" << endl;
		else {
			for (int j = n; j < size - 1; j++)
				arr[j] = arr[j + 1];
			size--;
		}
		ofstream InfFile2;
		InfFile2.open(R.RegDATA);
		for (int j = 0; j < size; j++) {
			InfFile2 << arr[j].LoginUser1 << endl;
			InfFile2 << arr[j].PasswordUser1 << endl;
		}
		InfFile2.close();
		cout << "Пользователь " << "[" << tmp << "] " << "удален" << endl;
		delete[] arr;
		system("pause");
		system("cls");
	}

};

