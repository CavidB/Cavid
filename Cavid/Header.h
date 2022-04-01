#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>
#include<time.h>
#include <conio.h>
#include <iomanip>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <fstream>
#include <list>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#define color SetConsoleTextAttribute

using namespace std;

struct choice
{
	string choose;
	string _dxl;
	int _check = 0;
	char _c;
};

void FirstPage()
{

	system("Color B4");
	Sleep(500);
	cout << "\n\nPresent Cavid" << endl;
	Sleep(500);
	cout << "Thank you for your support!" << endl;
	Sleep(500);
	cout << "\n\n\n\n\n\n\n\n\n";
	cout << "\t\t\t\t\tWelcome ELOVSET DAYI Restaurant\n\n";
	Sleep(1568);
	cout << "\t\t\t\t\Menu Is Coming ";
	char ld = 178;
	for (int i = 0; i < 25; i++)
	{
		cout << ld;
		if (i < 10)
			Sleep(450);
		if (i >= 10)
			Sleep(100);
	}
	system("cls");

}

#pragma region Loading
void Loading()
{
	int count;
	cout << "\n\n\n\n\n\n\n\t\t\tLoading....\n\t\t\t";

	for (int count = 0; count < 40; count++)
	{
		cout << char(219);
		if (count < 15)
		{
			system("color f7");
			Sleep(100);
		}
		else if (count < 30)
		{
			system("color f0");
			Sleep(50);
		}
		else if (count < 40)
		{
			system("color f4");
			Sleep(200);
		}
	}
	system("color f0");
	system("cls");
	cout << "\n\n\t\t\tloadýng completed \n";
	system("cls");
}
#pragma endregion

#pragma region Tem Menu Write
void TheMenuWrite()
{
	cout << "			     .----------------.  .----------------.  .-----------------. .----------------." << endl;
	cout << "			    | .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
	cout << "			    | | ____    ____ | || |  _________   | || | ____  _____  | || | _____  _____ | |" << endl;
	cout << "			    | ||_   \\  /   _|| || | |_   ___ |   | || ||_   \\|_   _| | || ||_   _||_   _|| |" << endl;
	cout << "			    | |  |   \\/   |  | || |   | |_  \_|   | || |  |   \\ | |   | || |  | |    | |  | |" << endl;
	cout << "			    | |  | |\\  /| |  | || |   |  _|  _   | || |  | |\\ \\| |   | || |  | '    ' |  | |" << endl;
	cout << "			    | | _| |_\\/_| |_ | || |  _| |___/ |  | || | _| |_\\   |_  | || |   \\ `--' /   | |" << endl;
	cout << "			    | ||_____||_____|| || | |_________|  | || ||_____|\\____| | || |    `.__.'    | |" << endl;
	cout << "			    | |              | || |              | || |              | || |              | |" << endl;
	cout << "			    | '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
	cout << "			     '----------------'  '----------------'  '----------------'  '----------------' " << endl;
}
#pragma endregion

#pragma region Ingredients
void Ingredients()
{
	cout << "			     _____                          _ _            _       " << endl;
	cout << "			    |_   _|                        | (_)          | |      " << endl;
	cout << "			      | |  _ __   __ _ _ __ ___  __| |_  ___ _ __ | |_ ___ " << endl;
	cout << "			      | | | '_ \\ / _` | '__/ _ \\/ _` | |/ _ \\ '_ \\| __/ __|" << endl;
	cout << "			     _| |_| | | | (_| | |  | __/ (_| | |  __/ | | | |_\\__ \\" << endl;
	cout << "			    |_____|_| |_|\\__, |_|  \\___|\\__,_|_|\\___|_| |_|\\__|___/" << endl;
	cout << "			                  __/ |                                    " << endl;
	cout << "			                 |___/                                     " << endl;
}
#pragma endregion

#pragma region Search
void Search()
{
	cout << "			      _____                     _     " << endl;
	cout << "			     / ____|                   | |    " << endl;
	cout << "			    | (___   ___  __ _ _ __ ___| |__  " << endl;
	cout << "			     \\___ \\ / _ \\/ _` | '__/ __| '_ \\ " << endl;
	cout << "			     ____) |  __/ (_| | | | (__| | | |" << endl;
	cout << "			    |_____/ \\___|\\__,_|_|  \\___|_| |_|" << endl;
}
#pragma endregion

#pragma region Update
void Update()
{
	cout << "			     _    _           _       _   " << endl;
	cout << "			    | |  | |         | |     | |      " << endl;
	cout << "			    | |  | |_ __   __| | __ _| |_ ___ " << endl;
	cout << "			    | |  | | '_ \\ / _` |/ _` | __/ _ \\" << endl;
	cout << "			    | |__| | |_) | (_| | (_| | ||  __/" << endl;
	cout << "			     \\____/| .__/ \\__,_|\\__,_|\\__\\___|" << endl;
	cout << "				   | |                        " << endl;
	cout << "				   |_|                        " << endl;
}
#pragma endregion

#pragma region Product
void Product()
{
	cout << "			      _____               _            _   " << endl;
	cout << "			     |  __ \\             | |          | |  " << endl;
	cout << "			     | |__) | __ ___   __| |_   _  ___| |_ " << endl;
	cout << "			     |  ___/ '__/ _ \\ / _` | | | |/ __| __|" << endl;
	cout << "			     | |   | | | (_) | (_| | |_| | (__| |_ " << endl;
	cout << "			     |_|   |_|  \\___/ \\__,_|\\__,_|\\___|\\__|" << endl;
}
#pragma endregion

#pragma region Statics
void Statics()
{
	cout << "			       _____ _        _   _      " << endl;
	cout << "			      / ____| |      | | (_)         " << endl;
	cout << "			     | (___ | |_ __ _| |_ _  ___ ___ " << endl;
	cout << "			      \\___ \\| __/ _` | __| |/ __/ __|" << endl;
	cout << "			      ____) | || (_| | |_| | (__\\__ \\" << endl;
	cout << "			     |_____/ \\__\\__,_|\\__|_|\\___|___/" << endl;
}
#pragma endregion

#pragma region Panel
void Panel()
{
	cout << "			      _____                 _ " << endl;
	cout << "			     |  __ \\               | |" << endl;
	cout << "			     | |__) |_ _ _ __   ___| |" << endl;
	cout << "			     |  ___/ _` | '_ \\ / _ \\ |" << endl;
	cout << "			     | |  | (_| | | | |  __/ |" << endl;
	cout << "			     |_|   \\__,_|_| |_|\\___|_|" << endl;
}
#pragma endregion