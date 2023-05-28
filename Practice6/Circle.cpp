// Circle.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "cone.h"
void cone::setCoordinate(double a, double b, double c) { x = a; y = b; z = c; }
void cone::setRadius(double r) { radius = r; }
void cone::setHeight(double h) { height = h; }
double cone::getRadius() { return radius; }
double cone::getHeight() { return height; }
double cone::area() {
    double l = sqrt(height * height + radius * radius);
    return pi * radius * (radius + l);
}
double cone::volume() { return pi * radius * radius * height / 3; }
ostream& operator<<(ostream& stream, cone obj) {
    stream << "(" << obj.x << "; ";
    stream << obj.y << "; ";
    stream << obj.z << ") ";
    stream << "r=" << obj.radius << " ";
    stream << "h=" << obj.height << "\n";
    return stream;
};

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
