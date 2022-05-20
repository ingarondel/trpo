#pragma once
#include "Header.h"

using namespace std;

struct Registration {
	string LoginUser, PasswordUser;
	string LoginAdmin = "Admin", PasswordAdmin = "111";
	string RegDATA = "RegDATA.txt";
	string LoginUser1, PasswordUser1; // ����� ��� �������� ������������

	int Access, Role; // ������ � ����

	void RegistrationFunction()
	{
		ifstream file("RegDATA.txt"); // ������� ���� � �������
		string s, find;
		char c;
		while (!file.eof()) {  // ��������� ��� � ��������� �� ������
			file.get(c);
			s.push_back(c);
		}
		file.close(); // ����������� �������






		int pos = 0;

		while (pos != -1)
		{

		
			cout << "\t\t\t\t�����������\n";

			cout << "������� �����: ";
			cin >> LoginUser;

			pos = s.find(LoginUser); // �����	

			if (pos == -1) {
				cout << "������� ������:";
				cin >> PasswordUser;
			}

			else {
				cout << "����� ����� ��� ����������\n";
				system("pause");
				system("cls");



			}
		}

		ofstream RegFile;
		RegFile.open(RegDATA, ofstream::app);
		RegFile << LoginUser << endl;
		RegFile << PasswordUser << endl;
		RegFile.close();
		system("pause");
		system("cls");
	}

	void EnterToProgram()
	{
		int exit1 = true;
		while (exit1)
		{
			cout << "0. ����� � ����� ������������\n" << "1. ����� � ����� ��������������\n" << "2. �����\n";
			int change;
			cin >> change;
			system("cls");
			string log, log1, pass, pass1;
			ifstream fileIN;
			char c = 0;
			switch (change)
			{
			case 0:
				cout << "�����: ";
				cin >> log;
				cout << "������: ";
				cin >> pass;


				//ifstream fileIN;
				fileIN.open(RegDATA);
				if (!fileIN.is_open()) {
					cout << "������ �������� ����� � ������� � �������!\n";
					Access = 0;
				}
				else {
					ifstream fileIN;
					fileIN.open(RegDATA);
					while (fileIN.peek() != EOF)
					{
						fileIN >> LoginUser; fileIN.get();
						fileIN >> PasswordUser; fileIN.get();
						//fileIN.get();
						if (log == LoginUser && pass == PasswordUser) {
							Access = 1;
							Role = 0;
							break;
						}
						else { Access = 0; Role = 0; }
					}
				}
				fileIN.close();
				system("cls");
				exit1 = false; break;
			case 1:
				cout << "�����: "; cin >> log;
				cout << "������: "; cin >> pass;
				system("cls");
				if (log == LoginAdmin && pass == PasswordAdmin) {
					Access = 1; Role = 1;
				}; exit1 = false; break;
			case 2:
				exit1 = false; break;
			default:
				cout << "������! ������ ������ ���� �� ����������\n";
				break;
			}
		}
	}
};


