#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;

void gotoxy(short x, short y);
void show_menu();

class Drob
{
protected:
	int ch;
	int zn;

public:
	Drob(){	ch = zn = 0;}
	Drob(int x, int y);
	void print(){ cout << ch << "/" << zn; }
	Drob operator+(Drob n);
	Drob operator-(Drob n);
	Drob operator*(int num);
	Drob operator*(Drob n);
	friend Drob operator*(int num, Drob n);
	Drob operator/(Drob n);
	int operator%(Drob n);
	Drob operator ++(int n);
	Drob operator --(int n);
	bool operator > (Drob n);
	bool operator < (Drob n);
	bool operator == (Drob n);
	bool operator != (Drob n);
};
void Show(int num1, int num2, int num3, int num4);