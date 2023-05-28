// Figure.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "figure.h"
#include <vector>
#include <algorithm>
using namespace std;
figure::figure(float X1, float X2, float X3, float X4, float Y1, float Y2, float Y3, float Y4)
{
	vector<pair<float, float>> kord;
	kord.resize(4);
	kord[0] = { X1, Y1 };
	kord[1] = { X2, Y2 };
	kord[2] = { X3, Y3 };
	kord[3] = { X4, Y4 };
	x1 = kord[0].first;
	y1 = kord[0].second;
	x2 = kord[1].first;
	y2 = kord[1].second;
	x3 = kord[2].first;
	y3 = kord[2].second;
	x4 = kord[3].first;
	y4 = kord[3].second;
	si1 = ca_side(x1, x2, y1, y2);
	si2 = ca_side(x2, x3, y2, y3);
	si3 = ca_side(x3, x4, y3, y4);
	si4 = ca_side(x1, x4, y1, y4);
	float diag1 = ca_side(x1, x3, y1, y3);
	float diag2 = ca_side(x2, x4, y2, y4);
	p = si1 + si2 + si3 + si4;
	si1 = ca_side(x1, x2, y1, y2);
	float co_sum = (x1 + x3) * (x2 + x4) + (y1 * y3) * (y2 * y4);
	float co_def = sqrt(pow(x1 + x3, 2) + pow(y1 + y3, 2)) * sqrt(pow(x2 + x4, 2) + pow(y2 + y4, 2));
	float cos = co_sum / co_def;
	float sin = sqrt(abs(1 - pow(cos, 2)));
	s = diag1 * diag2 * sin * 0.5;
}
void figure::show() {
	cout << "сторона " << si1 << ", " << si2 << ", " << si3 << ", " << si4 << ";" << endl;
	cout << "площадь " << s << endl;
	cout << "периметр " << p << endl;
}
bool figure::is_prug() {
	return (s / (si1 * si2) >= 0.95 && s / (si1 * si2) <= 1.05);
}
bool figure::is_square() {
	bool is_pr = is_prug();
	return (si1 == si2 == si3 == si4 && is_pr);
}
bool figure::is_romb() {
	bool is_pr = is_prug();
	if (si1 == si2 == si3 == si4 && is_pr == false) {
		return true;
	}
	else {
		return false;
	}
}
bool figure::is_in_circle() {
	float P1 = p / 2;
	float S1 = sqrt((P1 - si1) * (P1 - si2) * (P1 - si3) * (P1 - si4));
	return (S1 == s);
}
bool figure::is_out_circle() {
	return (si1 + si3 == si2 + si4);
}
Footer
© 2023 GitHub, Inc

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
