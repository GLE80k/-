// Bay.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
class Ocean {
private:
    string name;
    double size;
    double depth;
public:
    Ocean() : name(""), size(0), depth(0) {}
    Ocean(string name, double size, double depth)
        : name(name), size(size), depth(depth) {}
    friend ostream& operator<<(ostream& out, const Ocean& ocean);
    friend istream& operator>>(istream& in, Ocean& ocean);
    bool operator==(const Ocean& other) const {
        return name == other.name && size == other.size && depth == other.depth;
    }
};
class Sea : public Ocean {
private:
    string name;
    double size;
    double depth;
public:
    Sea() : Ocean() {}
    Sea(string name, double size, double depth)
        : Ocean(name, size, depth) {}
};
class Bay : public Ocean {
private:
    string name;
    double size;
    double depth;
public:
    Bay() : Ocean() {}
    Bay(string name, double size, double depth)
        : Ocean(name, size, depth) {}
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
