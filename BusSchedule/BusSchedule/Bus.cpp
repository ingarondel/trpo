#pragma once
#include "Header.h"
using namespace std;

struct Bus
{

	int number; // номер рейса
	string type; // тип автобуса
	string destination; // пункт назначения
	int start_hour; // время отправления часы
	int start_minute; // время отправления минуты
	int finish_minute;
	int finish_hour;
	string Information = "information.txt";

	void add_bus()
	{
		cout << "Введите номер рейса: ";                    cin >> number;
		cout << "Введите тип автобуса: ";                   cin >> type;
		cout << "Введите пункт назначения: ";               cin >> destination;

		bool check = true;
		while (check) {
			cout << "Введите время отправления (час): ";	cin >> start_hour;
			if (start_hour < 24 && start_hour >= 0)
				check = false;
		}

		bool check2 = true;
		while (check2) {
			cout << "Введите время отправления (минута): "; cin >> start_minute;
			if (start_minute < 60 && start_minute >= 0)
				check2 = false;
		}

		bool check3 = true;
		while (check3) {
			cout << "Введите время прибытия (час): ";           cin >> finish_hour;
			if (finish_hour < 24 && finish_hour >= 0)
				check3 = false;
		}

		bool check4 = true;
		while (check4) {
			cout << "Введите время прибытия (минута): ";        cin >> finish_minute;
			if (finish_minute < 60 && finish_minute >= 0)
				check4 = false;
		}
		ofstream InfFile;
		InfFile.open(Information, ofstream::app);
		InfFile << number << endl;
		InfFile << type << endl;
		InfFile << destination << endl;
		InfFile << start_hour << endl;
		InfFile << start_minute << endl;
		InfFile << finish_hour << endl;
		InfFile << finish_minute << endl;
		InfFile.close();
		system("pause");
		system("cls");
	}

	void delete_bus()
	{
		vector<Bus> BusArray;
		Bus B;
		ifstream InfFile;
		InfFile.open(Information);
		while (InfFile.peek() != EOF)
		{
			InfFile >> B.number; InfFile.get();
			InfFile >> B.type; InfFile.get();
			InfFile >> B.destination; InfFile.get();
			InfFile >> B.start_hour; InfFile.get();
			InfFile >> B.start_minute; InfFile.get();
			InfFile >> B.finish_hour; InfFile.get();
			InfFile >> B.finish_minute; InfFile.get();
			BusArray.push_back(B);
			cout << "#" << B.number << endl;
		}
		InfFile.close();
		int size = BusArray.size();
		int n = -1;
		int tmp;
		cout << "Введите номер маршрута который хотите удалить: "; cin >> tmp;
		for (int j = 0; j < BusArray.size(); j++) {
			if (BusArray[j].number == tmp)
				n = j;
		}
		if (n == -1)
			cout << "Маршрута с таким названием нет!" << endl;
		else {

			for (int j = n; j < size - 1; j++)
				BusArray[j] = BusArray[j + 1];
			size--;
		}

		// перезапись в файл
		ofstream InfFile2;
		InfFile2.open(Information);
		for (int j = 0; j < size; j++) {
			InfFile2 << BusArray[j].number << endl;
			InfFile2 << BusArray[j].type << endl;
			InfFile2 << BusArray[j].destination << endl;
			InfFile2 << BusArray[j].start_hour << endl;
			InfFile2 << BusArray[j].start_minute << endl;
			InfFile2 << BusArray[j].finish_hour << endl;
			InfFile2 << BusArray[j].finish_minute << endl;
		}
		InfFile2.close();
		cout << "Маршрут " << "[" << tmp << "] " << "удален" << endl;
		system("pause");
		system("cls");
	}

	void edit_bus()
	{
		vector<Bus> BusArray;
		Bus B;
		ifstream InfFile;
		InfFile.open(Information);
		while (InfFile.peek() != EOF)
		{
			InfFile >> B.number; InfFile.get();
			InfFile >> B.type; InfFile.get();
			InfFile >> B.destination; InfFile.get();
			InfFile >> B.start_hour; InfFile.get();
			InfFile >> B.start_minute; InfFile.get();
			InfFile >> B.finish_hour; InfFile.get();
			InfFile >> B.finish_minute; InfFile.get();
			BusArray.push_back(B);
			cout << "#" << B.number << endl;
		}
		InfFile.close();
		int size = BusArray.size();
		int tmp;

		int n = -1;
		cout << "Введите название рейса который хотите редактировать: "; cin >> tmp;
		for (int j = 0; j < size; j++) {
			if (BusArray[j].number == tmp) {
				n = j;
				cout << endl;
				cout << "Номер маршрута: " << BusArray[j].number << "\n";
				cout << "Тип автобуса: " << BusArray[j].type << "\n";
				cout << "Пункт назначения: " << BusArray[j].destination << "\n";
				cout << "Время отправки: " << BusArray[j].start_hour << ":" << BusArray[j].start_minute << "\n";
				cout << "Время прибытия: " << BusArray[j].finish_hour << ":" << BusArray[j].finish_minute << "\n";
				system("pause");
				cout << endl;
			}

		}
		if (n == -1)
			cout << "рейса с таким названием нет!" << endl;
		else {
			cout << "1. Изменить номер маршрута" << endl;
			cout << "2. Изменить тип автобуса" << endl;
			cout << "3. Изменить пункт назначения" << endl;
			cout << "4. Изменить время отправки" << endl;
			cout << "5. Изменить время прибытия" << endl;
			int change; cin >> change;
			int NewNumber, NewStartMinute, NewStartHour, NewFinishMinute, NewFinishHour;
			string NewType, NewDestination;
			switch (change)
			{
			case 1:
				cout << "Введите новый номер маршрута: "; cin >> NewNumber;
				BusArray[n].number = NewNumber; break;
			case 2:
				cout << "Введите новый тип автобуса: "; cin >> NewType;
				BusArray[n].type = NewType; break;
			case 3:
				cout << "Введите новый пункт назначения: "; cin >> NewDestination;
				BusArray[n].destination = NewDestination; break;
			case 4: {
				bool check = true;
				while (check) {
					cout << "Введите новое время отправления (час): ";	cin >> NewStartHour;
					if (NewStartHour < 24 && NewStartHour >= 0)
						check = false;
				}

				bool check2 = true;
				while (check2) {
					cout << "Введите новое время отправления (минута): "; cin >> NewStartMinute;
					if (NewStartMinute < 60 && NewStartMinute >= 0)
						check2 = false;
				}
				BusArray[n].start_hour = NewStartHour;
				BusArray[n].start_minute = NewStartMinute;
			}

				  break;
			case 5: {
				bool check3 = true;
				while (check3) {
					cout << "Введите новое время прибытия (час): ";           cin >> NewFinishHour;
					if (NewFinishHour < 24 && NewFinishHour >= 0)
						check3 = false;
				}

				bool check4 = true;
				while (check4) {
					cout << "Введите новое время прибытия (минута): ";        cin >> NewFinishMinute;
					if (NewFinishMinute < 60 && NewFinishMinute >= 0)
						check4 = false;
				}
				BusArray[n].finish_hour = NewFinishHour;
				BusArray[n].finish_minute = NewFinishMinute;
			}break;
			default:
				cout << "Такой функции нет!" << endl;
				break;
			}
			cout << "Рейс " << "[" << tmp << "] " << "редактирован!" << endl;
		}
		// перезапись в файл
		ofstream InfFile2;
		InfFile2.open(Information);
		for (int j = 0; j < size; j++) {
			InfFile2 << BusArray[j].number << endl;
			InfFile2 << BusArray[j].type << endl;
			InfFile2 << BusArray[j].destination << endl;
			InfFile2 << BusArray[j].start_hour << endl;
			InfFile2 << BusArray[j].start_minute << endl;
			InfFile2 << BusArray[j].finish_hour << endl;
			InfFile2 << BusArray[j].finish_minute << endl;
		}
		InfFile2.close();
		system("pause");
		system("cls");
	}

	void view_bus()
	{
		Bus B;
		ifstream InfFile1;
		InfFile1.open(Information);
		while (InfFile1.peek() != EOF)
		{
			InfFile1 >> B.number; InfFile1.get();
			InfFile1 >> B.type; InfFile1.get();
			InfFile1 >> B.destination; InfFile1.get();
			InfFile1 >> B.start_hour; InfFile1.get();
			InfFile1 >> B.start_minute; InfFile1.get();
			InfFile1 >> B.finish_hour; InfFile1.get();
			InfFile1 >> B.finish_minute; InfFile1.get();
			cout << "Номер рейса: " << B.number << "\n";
			cout << "Тип автобуса: " << B.type << "\n";
			cout << "Пункт назначения: " << B.destination << "\n";
			cout << "Время отправления: " << B.start_hour << ":" << B.start_minute << "\n";
			cout << "Время прибытия: " << B.finish_hour << ":" << B.finish_minute << "\n";
			cout << "==========================================" << endl;
		}
		InfFile1.close();
		system("pause");
		system("cls");
	}

	void search_bus()
	{
		Bus B;
		int trueSearch = 0;
		int NewNumber;
		ifstream InfFile;
		InfFile.open(Information);
		cout << "Введите номер рейса: "; cin >> NewNumber;
		Bus Search;
		while (InfFile.peek() != EOF)
		{
			InfFile >> B.number; InfFile.get();
			InfFile >> B.type; InfFile.get();
			InfFile >> B.destination; InfFile.get();
			InfFile >> B.start_hour; InfFile.get();
			InfFile >> B.start_minute; InfFile.get();
			InfFile >> B.finish_hour; InfFile.get();
			InfFile >> B.finish_minute; InfFile.get();
			if (NewNumber == B.number)
			{
				NewNumber = B.number;
				Search = B;
				trueSearch = 1;
			}
		}
		if (trueSearch == 1) {
			cout << endl;
			cout << "Номер рейса: " << Search.number << "\n";
			cout << "Тип автобуса: " << Search.type << "\n";
			cout << "Пункт назначения: " << Search.destination << "\n";
			cout << "Время отправки: " << Search.start_hour << ":" << Search.start_minute << "\n";
			cout << "Время прибытия: " << Search.finish_hour << ":" << Search.finish_minute << "\n";
			system("pause");
			cout << endl;
		}
		else {
			cout << "рейс не найден!" << endl;
		}
		InfFile.close();
		system("pause");
		system("cls");
	}

	void sort_bus()
	{
		vector<Bus> BusArray;
		Bus B;
		ifstream InfFile;
		InfFile.open(Information);
		while (InfFile.peek() != EOF)
		{
			InfFile >> B.number; InfFile.get();
			InfFile >> B.type; InfFile.get();
			InfFile >> B.destination; InfFile.get();
			InfFile >> B.start_hour; InfFile.get();
			InfFile >> B.start_minute; InfFile.get();
			InfFile >> B.finish_hour; InfFile.get();
			InfFile >> B.finish_minute; InfFile.get();
			BusArray.push_back(B);
		}
		InfFile.close();

		cout << "1. сортировка по пункту назначения " << endl;
		cout << "2. сортировка по номеру " << endl;
		int searchMenu;
		cin >> searchMenu;
		switch (searchMenu)
		{
		case 1: {
			system("cls");
			Bus temp;
			int size = BusArray.size();
			for (int i = 0; i < size; i++)
			{
				for (int j = i + 1; j < size; j++) {
					if (BusArray[i].destination > BusArray[j].destination) {
						temp = BusArray[i];
						BusArray[i] = BusArray[j];
						BusArray[j] = temp;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				cout << "Номер рейса: " << BusArray[i].number << endl;
				cout << "Тип автобуса: " << BusArray[i].type << endl;
				cout << "Пункт назначения: " << BusArray[i].destination << endl;
				cout << "Время отправления: " << BusArray[i].start_hour << ":" << BusArray[i].start_minute << endl;
				cout << "Время прибытия: " << BusArray[i].finish_hour << ":" << BusArray[i].finish_minute << endl;
				cout << "\n";
			}
			system("pause");
			system("cls");
		}break;
		case 2: {
			system("cls");
			Bus temp;
			int size = BusArray.size();
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (BusArray[j].number > BusArray[j + 1].number) {
						// меняем элементы местами
						temp = BusArray[j];
						BusArray[j] = BusArray[j + 1];
						BusArray[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				cout << "Номер рейса: " << BusArray[i].number << endl;
				cout << "Тип автобуса: " << BusArray[i].type << endl;
				cout << "Пункт назначения: " << BusArray[i].destination << endl;
				cout << "Время отправления: " << BusArray[i].start_hour << ":" << BusArray[i].start_minute << endl;
				cout << "Время прибытия: " << BusArray[i].finish_hour << ":" << BusArray[i].finish_minute << endl;
				cout << "\n";
			}
			system("pause");
			system("cls");
		}break;
		default:
			break;
		}
	}

	void task()
	{
		vector<Bus> BusArray;
		vector<Bus> arr2;
		Bus B;
		string DESTINATION;
		cout << "Введите пункт назначения: "; cin >> DESTINATION;
		int ThisHour, ThisMinute;

		bool check = true;
		while (check) {
			cout << "Введите текущее время (час): ";	cin >> ThisHour;
			if (ThisHour < 24 && ThisHour >= 0)
				check = false;
		}

		bool check2 = true;
		while (check2) {
			cout << "Введите текущее время  (минута): "; cin >> ThisMinute;
			if (ThisMinute < 60 && ThisMinute >= 0)
				check2 = false;
		}

		ifstream InfFile;
		InfFile.open(Information);
		while (InfFile.peek() != EOF)
		{
			InfFile >> B.number; InfFile.get();
			InfFile >> B.type; InfFile.get();
			InfFile >> B.destination; InfFile.get();
			InfFile >> B.start_hour; InfFile.get();
			InfFile >> B.start_minute; InfFile.get();
			InfFile >> B.finish_hour; InfFile.get();
			InfFile >> B.finish_minute; InfFile.get();
			BusArray.push_back(B);
		}
		InfFile.close();

		int size = BusArray.size();

		for (int i = 0; i < size; i++) {
			if (ThisHour > BusArray[i].finish_hour) {
				int time = 0;
				time = 24 - ThisHour + BusArray[i].finish_hour;
				if (ThisMinute > BusArray[i].finish_minute) {
					time = time - 1;
				}
				if (time < 12)
					arr2.push_back(BusArray[i]);
			}
			if (ThisHour < BusArray[i].finish_hour) {
				int time = 0;
				time = BusArray[i].finish_hour - ThisHour;
				if (ThisMinute < BusArray[i].finish_minute) {
					time = time + 1;
				}
				if (time < 12 && DESTINATION == BusArray[i].destination)
					arr2.push_back(BusArray[i]);
			}
		}

		for (int i = 0; i < arr2.size(); i++) {
			cout << "Номер рейса: " << arr2[i].number << "\n";
			cout << "Тип автобуса: " << arr2[i].type << "\n";
			cout << "Пункт назначения: " << arr2[i].destination << "\n";
			cout << "Время отправления: " << arr2[i].start_hour << ":" << arr2[i].start_minute << "\n";
			cout << "Время прибытия: " << arr2[i].finish_hour << ":" << arr2[i].finish_minute << "\n";
			cout << "==========================================" << endl;
		}
	}

};

