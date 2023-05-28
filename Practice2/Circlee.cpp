// Circlee.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "circle.h"
using namespace std;
circle::circle(float r, float x, float y) {
    radius = r;
    x_center = x;
    y_center = y;
};
void circle::set_circle(float r, float x, float y)
{
    radius = r;
    x_center = x;
    y_center = y;
};
float circle::square()
{
    return pi * radius * radius;
}
bool circle::triangle_around(float a, float b, float c) {
    double minip = (a + b + c) * 0.5;
    double s = sqrt(minip * (minip - a) * (minip - b) * (minip - c));
    return (radius >= ((a + b + c) / (4 * s)));
}
bool circle::triangle_in(float a, float b, float c) {
    double minip = (a + b + c) * 0.5;
    double s = sqrt(minip * (minip - a) * (minip - b) * (minip - c));
    return (radius <= s / minip);
}
bool circle::check_circle(float r, float x_cntr, float y_cntr) {
    float rad2 = sqrt(pow((x_cntr - x_center), 2) + pow((y_cntr - y_center), 2));
    return (radius + r <= rad2);
}
void circle::show() {
    cout << "радиус " << radius << endl;
    cout << "Х круга " << x_center << endl;
    cout << "Y круга " << y_center << endl;
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
