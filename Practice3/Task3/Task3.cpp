// Task3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "rational.h" 
#include <iostream>
using namespace std;
void rational::set(int a1, int b1) {
	if (b1 == 0) { a = 0; b = 0; }
	else if (a1 % b1 == 0) { a = a1 / b1; b = 1; }
	else {
		a1 = a1 % b1;
		double d = nod(a1, b1);
		a = a1 / d;
		b = b1 / d;
	}
}
void rational::show() { cout << a << "/" << b << endl; }
rational operator + (rational d1, rational d2) {
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);
	int ok = d1.nok(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;
	int a, b;
	b = ok;
	a = a1 * k1 + a2 * k2;
	rational ans(a, b);
	return ans;
}
rational operator - (rational d1, rational d2) {
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);
	int ok = d1.nok(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;
	int a, b;
	b = ok;
	a = a1 * k1 - a2 * k2;
	rational ans(a, b);
	return ans;
}
rational& rational::operator ++ () {
	a = a + 1;
	set(a, b);
	return *this;
}
bool operator == (rational d1, rational d2) {
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);
	int ok = d1.nok(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;
	return (a1 * k1 == a2 * k2);
}
bool operator > (rational d1, rational d2) {
	int a1, b1, a2, b2;
	d1.get(a1, b1);
	d2.get(a2, b2);
	int ok = d1.nok(b1, b2);
	int k1 = ok / b1;
	int k2 = ok / b2;
	return (a1 * k1 > a2 * k2);
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
