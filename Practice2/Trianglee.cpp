// Trianglee.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;
class triangle {
private:
    float a, b, c;
public:
    bool exst_tr() {
        return ((a + b > c) && (b + c > a) && (a + c > b));
    }
    void set(float a1, float b1, float c1) {
        a = a1;
        b = b1;
        c = c1;
    }
    void show() {
        cout << "1 сторона: " << a << endl;
        cout << "2 сторона: " << b << endl;
        cout << "3 сторона: " << c << endl;
    }
    float perimetr() {
        float p = a + b + c;
        return p;
    }
    float square() {
        float minip = (a + b + c) / 2;
        float s = sqrt(minip * (minip - a) * (minip - b) * (minip - c));
        return s;
    }
};
int main()
{
    setlocale(LC_ALL, "Russian");
    triangle tr[3];
    float a, b, c;
    int i = 0;
    while (i < 3)
    {
        cout << "стороны треугольника" << endl;
        cin >> a >> b >> c;
        tr[i].set(a, b, c);
        if (tr[i].exst_tr())
        {
            i++;
        }
        else
        {
            cout << "не существует";
        }
    }
    for (int i = 0; i < 3; i++) {
        tr[i].show();
        cout << "периметр " << tr[i].perimetr() << endl;
        cout << "площадь " << tr[i].square() << endl;
    }
    return 0;
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
