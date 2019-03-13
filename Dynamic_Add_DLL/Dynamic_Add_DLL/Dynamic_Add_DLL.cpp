// Dynamic_Add_DLL.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <stdio.h>
#include <windows.h>
#include <iostream>

using namespace std;

//	Определение указателя на вызываемую функцию
typedef void(__stdcall *PName)(),
(__stdcall *PGroup)();

int old();

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
	(*Name)();
	cout << "My age is " << old() << endl;
	(*Group)();

	//	Выгружаем библиотеку
	FreeLibrary(hDll);
}

// Вычисление возраста.
int old()
{
	int age;
	SYSTEMTIME st;
	GetSystemTime(&st);
	age = st.wYear - 1997;
	return age;
}
