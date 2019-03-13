﻿// Dynamic_Add_DLL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

//	Определение указателя на вызываемую функцию
typedef void(__stdcall *PName)(),
(__stdcall *PGroup)();

int main()
{
	//	Динамическое подключение DLL (загрузка)
	HINSTANCE hDll = LoadLibrary(L"two_func.dll");

	//	Обработка случая отсутствия библиотеки
	if (hDll == NULL)
	{
		cout << "Error!" << endl;
		return 1;
	}
	//	Определение переменных, которые будут указателями на вызываемые функции
	PName Name;
	PGroup Group;

	//	Присвоение значений переменным
	Name = (PName)GetProcAddress(hDll, "_name");
	Group = (PGroup)GetProcAddress(hDll, "_group");

	//	Использование функций
	cout << "Nice to meet you! My name is ";
	(*Name)();
	cout << "I`m study in group ";
	(*Group)();

	//	Выгружаем библиотеку
	FreeLibrary(hDll);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
