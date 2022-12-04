#include "Fruction.h"

int main()
{
	system("color F0");
	const int num_menu = 3;
	int ch = 0, active_menu = 0;
	bool q;

	do
	{
		int num1, num2, num3, num4;
		do
		{
			cout << "Enter fraction number 1" << endl;
			cin >> num1 >> num2;
			cout << "Enter fraction number 2" << endl;
			cin >> num3 >> num4;
			try
			{
				if (num2 == 0 && num4 == 0)
					throw exception("Error all fraction - you can't divide by zero, try again\n");
				else if (num2 == 0)
					throw exception ("Error first fraction - you can't divide by zero, try again\n");
				else if (num4 == 0)
					throw exception ("Error second fraction - you can't divide by zero, try again\n");
			}
			catch (exception& str)
			{
				system("cls");
				cout << str.what() << endl;
			}
		} while (num2 == 0 || num4 == 0);
		
		Drob d1(num1, num2);
		Drob d2(num3, num4);
		Drob res;
		bool exit = false;
		while (!exit)
		{
			show_menu();
			gotoxy(0, active_menu);
			ch = _getch();
			if (ch == 224) ch = _getch();
			switch (ch)
			{

			case 27: exit = true; break;
			case 72: active_menu--; break;
			case 80: active_menu++; break;
			case 13:

				if (active_menu == 0)
				{
					system("cls");
					Show(num1, num2, num3, num4);
					cout << "**********************************************" << endl;
					res = d1 + d2;
					cout << "addition of fractions + " << endl;
					res.print();
					cout << endl;
					res = d2 - d1;
					cout << "fraction subtraction - " << endl;
					res.print();
					cout << endl;
					res = d1 * d2;
					cout << "multiplication of fractions * " << endl;
					res.print();
					cout << endl;
					cout << "division of fractions / " << endl;
					res = d1 / d2;
					res.print();
					cout << endl;
					cout << "multiplication of number * num" << endl;
					res = d1 * 7;
					res.print();
					cout << endl;
					res = d2 * 7;
					res.print();
					cout << endl;
					cout << "multiplication a number (7) by a fraction" << endl;
					res = 7 * d1;
					res.print();
					cout << endl;
					res = 7 * d2;
					res.print();
					cout << endl;
					cout << "division without remainder %" << endl;
					cout << (d1 % d2) << endl;
					system("pause");
				}
				else if (active_menu == 1)
				{
					system("cls");
					Show(num1, num2, num3, num4);
					cout << "*****************************************" << endl;
					cout << "first fraction > second fraction?" << endl;
					cout << (d1 > d2) << endl;
					cout << "second fraction > first fraction?" << endl;
					cout << (d1 < d2) << endl;
					cout << "fractions are equal ?" << endl;
					cout << (d1 == d2) << endl;
					cout << "fractions are not equal ?" << endl;
					cout << (d1 != d2) << endl;
					system("pause");
				}
				else if (active_menu == 2)
				{
					system("cls");
					Show(num1, num2, num3, num4);
					cout << "*****************************************" << endl;
					cout << "increment first fraction\n" << endl;
					res = d1++;
					res.print();
					cout << endl;
					cout << "decrement second fraction\n" << endl;
					res = d2--;
					res.print();
					cout << endl;
					system("pause");
				}
				break;
			}
			if (active_menu < 0) active_menu = num_menu - 1;
			if (active_menu > num_menu - 1) active_menu = 0;
		}
		system("cls");
		cout << "If you wanna continue press 1, no 0" << endl;
		cin >> q;
		system("cls");
	} while (q == 1);
	system("cls");

	return 0;
}