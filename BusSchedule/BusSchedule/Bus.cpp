#pragma once
#include "Header.h"
using namespace std;

struct Bus
{

	int number; // ����� �����
	string type; // ��� ��������
	string destination; // ����� ����������
	int start_hour; // ����� ����������� ����
	int start_minute; // ����� ����������� ������
	int finish_minute;
	int finish_hour;
	string Information = "information.txt";

	void add_bus()
	{
		cout << "������� ����� �����: ";                    cin >> number;
		cout << "������� ��� ��������: ";                   cin >> type;
		cout << "������� ����� ����������: ";               cin >> destination;

		bool check = true;
		while (check) {
			cout << "������� ����� ����������� (���): ";	cin >> start_hour;
			if (start_hour < 24 && start_hour >= 0)
				check = false;
		}

		bool check2 = true;
		while (check2) {
			cout << "������� ����� ����������� (������): "; cin >> start_minute;
			if (start_minute < 60 && start_minute >= 0)
				check2 = false;
		}

		bool check3 = true;
		while (check3) {
			cout << "������� ����� �������� (���): ";           cin >> finish_hour;
			if (finish_hour < 24 && finish_hour >= 0)
				check3 = false;
		}

		bool check4 = true;
		while (check4) {
			cout << "������� ����� �������� (������): ";        cin >> finish_minute;
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
		cout << "������� ����� �������� ������� ������ �������: "; cin >> tmp;
		for (int j = 0; j < BusArray.size(); j++) {
			if (BusArray[j].number == tmp)
				n = j;
		}
		if (n == -1)
			cout << "�������� � ����� ��������� ���!" << endl;
		else {

			for (int j = n; j < size - 1; j++)
				BusArray[j] = BusArray[j + 1];
			size--;
		}

		// ���������� � ����
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
		cout << "������� " << "[" << tmp << "] " << "������" << endl;
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
		cout << "������� �������� ����� ������� ������ �������������: "; cin >> tmp;
		for (int j = 0; j < size; j++) {
			if (BusArray[j].number == tmp) {
				n = j;
				cout << endl;
				cout << "����� ��������: " << BusArray[j].number << "\n";
				cout << "��� ��������: " << BusArray[j].type << "\n";
				cout << "����� ����������: " << BusArray[j].destination << "\n";
				cout << "����� ��������: " << BusArray[j].start_hour << ":" << BusArray[j].start_minute << "\n";
				cout << "����� ��������: " << BusArray[j].finish_hour << ":" << BusArray[j].finish_minute << "\n";
				system("pause");
				cout << endl;
			}

		}
		if (n == -1)
			cout << "����� � ����� ��������� ���!" << endl;
		else {
			cout << "1. �������� ����� ��������" << endl;
			cout << "2. �������� ��� ��������" << endl;
			cout << "3. �������� ����� ����������" << endl;
			cout << "4. �������� ����� ��������" << endl;
			cout << "5. �������� ����� ��������" << endl;
			int change; cin >> change;
			int NewNumber, NewStartMinute, NewStartHour, NewFinishMinute, NewFinishHour;
			string NewType, NewDestination;
			switch (change)
			{
			case 1:
				cout << "������� ����� ����� ��������: "; cin >> NewNumber;
				BusArray[n].number = NewNumber; break;
			case 2:
				cout << "������� ����� ��� ��������: "; cin >> NewType;
				BusArray[n].type = NewType; break;
			case 3:
				cout << "������� ����� ����� ����������: "; cin >> NewDestination;
				BusArray[n].destination = NewDestination; break;
			case 4: {
				bool check = true;
				while (check) {
					cout << "������� ����� ����� ����������� (���): ";	cin >> NewStartHour;
					if (NewStartHour < 24 && NewStartHour >= 0)
						check = false;
				}

				bool check2 = true;
				while (check2) {
					cout << "������� ����� ����� ����������� (������): "; cin >> NewStartMinute;
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
					cout << "������� ����� ����� �������� (���): ";           cin >> NewFinishHour;
					if (NewFinishHour < 24 && NewFinishHour >= 0)
						check3 = false;
				}

				bool check4 = true;
				while (check4) {
					cout << "������� ����� ����� �������� (������): ";        cin >> NewFinishMinute;
					if (NewFinishMinute < 60 && NewFinishMinute >= 0)
						check4 = false;
				}
				BusArray[n].finish_hour = NewFinishHour;
				BusArray[n].finish_minute = NewFinishMinute;
			}break;
			default:
				cout << "����� ������� ���!" << endl;
				break;
			}
			cout << "���� " << "[" << tmp << "] " << "������������!" << endl;
		}
		// ���������� � ����
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
			cout << "����� �����: " << B.number << "\n";
			cout << "��� ��������: " << B.type << "\n";
			cout << "����� ����������: " << B.destination << "\n";
			cout << "����� �����������: " << B.start_hour << ":" << B.start_minute << "\n";
			cout << "����� ��������: " << B.finish_hour << ":" << B.finish_minute << "\n";
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
		cout << "������� ����� �����: "; cin >> NewNumber;
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
			cout << "����� �����: " << Search.number << "\n";
			cout << "��� ��������: " << Search.type << "\n";
			cout << "����� ����������: " << Search.destination << "\n";
			cout << "����� ��������: " << Search.start_hour << ":" << Search.start_minute << "\n";
			cout << "����� ��������: " << Search.finish_hour << ":" << Search.finish_minute << "\n";
			system("pause");
			cout << endl;
		}
		else {
			cout << "���� �� ������!" << endl;
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

		cout << "1. ���������� �� ������ ���������� " << endl;
		cout << "2. ���������� �� ������ " << endl;
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
				cout << "����� �����: " << BusArray[i].number << endl;
				cout << "��� ��������: " << BusArray[i].type << endl;
				cout << "����� ����������: " << BusArray[i].destination << endl;
				cout << "����� �����������: " << BusArray[i].start_hour << ":" << BusArray[i].start_minute << endl;
				cout << "����� ��������: " << BusArray[i].finish_hour << ":" << BusArray[i].finish_minute << endl;
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
						// ������ �������� �������
						temp = BusArray[j];
						BusArray[j] = BusArray[j + 1];
						BusArray[j + 1] = temp;
					}
				}
			}
			for (int i = 0; i < size; i++) {
				cout << "����� �����: " << BusArray[i].number << endl;
				cout << "��� ��������: " << BusArray[i].type << endl;
				cout << "����� ����������: " << BusArray[i].destination << endl;
				cout << "����� �����������: " << BusArray[i].start_hour << ":" << BusArray[i].start_minute << endl;
				cout << "����� ��������: " << BusArray[i].finish_hour << ":" << BusArray[i].finish_minute << endl;
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
		cout << "������� ����� ����������: "; cin >> DESTINATION;
		int ThisHour, ThisMinute;

		bool check = true;
		while (check) {
			cout << "������� ������� ����� (���): ";	cin >> ThisHour;
			if (ThisHour < 24 && ThisHour >= 0)
				check = false;
		}

		bool check2 = true;
		while (check2) {
			cout << "������� ������� �����  (������): "; cin >> ThisMinute;
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
			cout << "����� �����: " << arr2[i].number << "\n";
			cout << "��� ��������: " << arr2[i].type << "\n";
			cout << "����� ����������: " << arr2[i].destination << "\n";
			cout << "����� �����������: " << arr2[i].start_hour << ":" << arr2[i].start_minute << "\n";
			cout << "����� ��������: " << arr2[i].finish_hour << ":" << arr2[i].finish_minute << "\n";
			cout << "==========================================" << endl;
		}
	}

};

