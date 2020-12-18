// LR5_OOP.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h> 
using namespace std;



int main() {
	system("COLOR F0");
	setlocale(LC_ALL, "RUS");

	cout << "Приведение типов и проверка принадлежности классу\n" << endl;
	affiliation();//приведение типов и проверка принадлежности классу
	cout << endl << endl << endl;

	cout << "Передача объектов как параметров в функцию\n" << endl;
	objecttransfer();// про передачу объекта как параметров в функцию
	cout << endl << endl << endl;

	cout << "Вызов виртуальных методов\n" << endl;
	virtualmethods();//вызов виртуальных методов
	cout << endl << endl << endl;
	_getch();

}

