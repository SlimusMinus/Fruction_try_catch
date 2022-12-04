#include "Fruction.h"

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}

void show_menu()
{
	system("cls");
	cout << "Arithmetic operations" << endl;
	cout << "Logical operations" << endl;
	cout << "Unary operations" << endl;
	cout << "=====================" << endl;
	cout << "Press ESC to exit" << endl;

}

Drob operator*(int num, Drob n)
{
	Drob tmp1;
	tmp1.ch = num * n.ch;
	tmp1.zn = n.zn;
	return tmp1;
}

Drob::Drob(int x, int y)
{
	ch = x;
	zn = y;
}

Drob Drob::operator+(Drob n)
{
	Drob tmp1;
	tmp1.ch = ch * n.zn + zn * n.ch;
	tmp1.zn = zn * n.zn;
	return tmp1;
}

Drob Drob::operator-(Drob n)
{
	Drob tmp1;
	tmp1.ch = ch * n.zn - zn * n.ch;
	tmp1.zn = zn * n.zn;
	return tmp1;
}

Drob Drob::operator*(int num)
{
	Drob tmp1;
	tmp1.ch = ch * num;
	tmp1.zn = zn;
	return tmp1;
}

Drob Drob::operator*(Drob n)
{
	Drob tmp1;
	tmp1.ch = ch * n.ch;
	tmp1.zn = zn * n.zn;
	return tmp1;
}

Drob Drob::operator/(Drob n)
{
	Drob tmp1;
	tmp1.ch = ch * n.zn;
	tmp1.zn = zn * n.ch;
	return tmp1;
}

int Drob::operator%(Drob n)
{
	int res_1;
	ch = ch * n.zn;
	zn = zn * n.ch;
	res_1 = ch / zn;
	return res_1;
}

Drob Drob::operator++(int n)
{
	ch = ch + zn;
	zn = zn;
	try
	{
		if ((ch / zn) < 2)
			throw exception("\t   Error.\n\t Your first fraction < 2******* ");
		return *this;
	}
	catch (exception& str)
	{
		cout << str.what() << " because " << (double)ch/zn << " < " << 2 << endl;
		exit(0);
	}
	
}

Drob Drob::operator--(int n)
{
	ch = ch - zn;
	zn = zn;
	try
	{
		if ((ch/zn) < 1)
			throw exception("\t   Error.\n\tYour second fraction < 1*******\n");
		return *this;
	}
	catch (exception& str)
	{
		cout << str.what() << endl;
		exit(0);
	}
	
}

bool Drob::operator>(Drob n)
{
	cout << (double)ch / zn << "   " << (double)n.ch / n.zn << endl;
	return (double)ch / zn > n.ch / n.zn;
}

bool Drob::operator<(Drob n)
{
	cout << (double)n.ch / n.zn << "   " << (double)ch / zn << endl;
	return (double)ch / zn < n.ch / n.zn;
}

bool Drob::operator==(Drob n)
{
	cout << (double)ch / zn << "   " << (double)n.ch / n.zn << endl;
	return (double)ch / zn == n.ch / n.zn;
}

bool Drob::operator!=(Drob n)
{
	cout << (double)ch / zn << "   " << (double)n.ch / n.zn << endl;
	return (double)ch / zn != n.ch / n.zn;
}

void Show(int num1, int num2, int num3, int num4)
{
	cout << "First fraction - " << num1 << "/" << num2 << "\t" << "Second fraction - " << num3 << "/" << num4 << endl;
}