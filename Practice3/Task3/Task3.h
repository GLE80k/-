// Task3.h.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class rational {
private:
	int a, b;
public:
	void set(int a1, int b1);
	void get(int& a1, int& b1) { a1 = a; b1 = b; }
	void show();
	int nod(int a1, int b1) {
		if (a1 == b1) return a1;
		else {
			if (a1 > b1) return nod(a1 - b1, b1);
			else return nod(a1, b1 - a1);
		}
	}
	int nok(int a1, int b1) { return a1 * b1 * nod(a1, b1); }
	rational() { a = 0; b = 0; }
	rational(int a1, int b1) {
		if (b1 == 0) { a = 0; b = 0; }
		else if (a1 % b1 == 0) { a = a1 / b1; b = 1; }
		else {
			a1 = a1 % b1;
			double d = nod(a1, b1);
			a = a1 / d;
			b = b1 / d;
		}
	}
	friend rational operator - (rational d1, rational d2);
	rational& operator++();
};
rational operator + (rational d1, rational d2);
bool operator == (rational d1, rational d2);
bool operator > (rational d1, rational d2);

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
