// LR5_OOP.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <windows.h> 
using namespace std;

class Base
{
public:
	int valuebase;
	Base() {//конструктор
		cout << "Вызов конструктора Base" << endl;
	}
	Base(Base* obj) {//конструктор, принимающий аргумент и преобразущий его к типу конструктора
		cout << "Вызов конструктора преобразования *Base" << endl;
	}
	Base(Base& obj) {//obj хранит адрес при передачи объекта по значению в качестве аргумента
		cout << "Вызов копирующего конструктора &Base" << endl;
	}
	virtual ~Base() {
		cout << "Виртуальный ~Base" << endl;
	}
	virtual string classname()
	{
		return "Базовый виртуальный метод string classname(), Base";
	}
	virtual bool isA(string classnm)//Базовый виртуальный метод string classname(), Base
	{
		if (classname() == classnm) {//проверка на принадлежность
			cout << "true" << endl;
			return true;
		}
		else {
			cout << "false" << endl;
			return false;
		}
	}
	void method1_1() {
		cout << "Метод method1_1 класса Base. Вызовется method 2_1: " << endl;
		method2_1();
	}
	void method1_2() {
		cout << "Метод method1_2 класса Base. Вызовется method 2_2:" << endl;
		method2_2();
	}
	void method2_1() {
		cout << "Метод method2_1 класса Base" << endl;
	}
	virtual void method2_2() {//виртуальный метод
		cout << "Виртуальный метод method2_2 класса Base" << endl;
	}
	void method3() {
		cout << "Метод method3 класса Base" << endl;
	}
	virtual void method4() {//виртуальный метод
		cout << "Виртуальный метод method4 класса Base" << endl;
	}
	virtual void redefinition(int d) {//виртуальный метод переопределения переменной класса
		valuebase = d;
		cout << "Виртуальный метод redefinition у Base " << endl;
	}
	//virtual ~Base() // примечание: Деструктор виртуальный
	//{
	//	cout << "Виртуальный деструктор Base" << endl;

	//}
};
class Desc : public Base
{
public:
	int valuedesc;
	Desc() {
		cout << "Вызов конструктора Desc" << endl;
	}
	Desc(Desc* obj) {
		cout << "Вызов конструктора преобразования *Desc" << endl;
	}
	Desc(Desc& obj) {
		cout << "Вызов копирующего конструктора &Desc" << endl;
	}
	~Desc() {
		cout << "~Desc" << endl;
	}
	string classname() {

		return "Desc";

	}
	bool isA(string classnm)
	{
		if (classname() == classnm) {
			cout << "true" << endl;
			return true;
		}
		else {
			cout << "false" << endl;
			return Base::isA(classnm);
		}
	}
	void method2_1() {//переопределенный метод 
		cout << "Метод method2_1 потомка Desc" << endl;
	}
	void method2_2() {//переопределенный метод 
		cout << "Метод method2_2 потомка Desc" << endl;
	}
	void method3() {
		cout << "Метод method3 потомка Desc" << endl;
	}
	void method4() {//переопределенный  метод 
		cout << "Виртуальный метод method4 потомка Desc" << endl;
	}
	void redefinition(int d) {
		valuedesc = d + 1;
		cout << "Метод redefinition у потомка Desc " << endl;
	}
	//virtual ~Desc() // примечание: Деструктор виртуальный
	//{
	//	cout << "Виртуальный деструктор Desk" << endl;
	//}
};

void func1(Base obj) {
	cout << " Функция func1 obj" << endl;
	obj.redefinition(1);//виртуальный метод Base
}
void func2(Base* obj) {
	cout << "Функция func2 *obj" << endl;
	obj->redefinition(2);
}
void func3(Base& obj) {
	cout << "Функция func3 &obj" << endl;
	obj.redefinition(3);
}


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

