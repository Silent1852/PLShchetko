#include <iostream>

using namespace std;

const double PI = 3.14159;

class MyEx // класс исключений

{
    const char* m;
    float t;
public:
    MyEx(const char* message, float t1) // конструктор MyEx
    {
        m = message;
        t = t1;
    }
    int GetValue() { return t; } // возвращает переменную t из приватной части. метод обращается к закрытым полям
    const char* GetMessage() { return m; } // возвращает переменную m из приватной части. метод обращается к закрытым полям
};


class Cylinder
{
public:

    Cylinder();
    Cylinder(double r, double h);

    double getRadius();
    double getHeight();
    void setRadius(double r);
    void setHeight(double h);
    double SurfArea();
    double CalcVolume();

private:
    double radius;
    double height;
};

Cylinder::Cylinder()
{
    radius = 0;
    height = 0;
}
Cylinder::Cylinder(double r, double h)
{
    radius = r;
    if (r <= 0) // исключение для радиуса цилиндра
    {
        MyEx Ex("Ошибка! Неправильный радиус цилиндра:", r);
        throw Ex;
    }
    height = h;
    if (h <= 0) // исключение для высоты цилиндра
    {
        MyEx Ex("Ошибка! Неправильная высота цилиндра:", h);
        throw Ex;
    }
}

double Cylinder::getRadius()
{
    return radius;
}
double Cylinder::getHeight()
{
    return height;
}

void Cylinder::setRadius(double r)
{
    radius = r;
}
void Cylinder::setHeight(double h)
{
    height = h;
}

// Calculations
double Cylinder::SurfArea()
{
    return 2 * PI * radius * radius + 2 * PI * radius * height;
}
double Cylinder::CalcVolume()
{
    return PI * radius * radius * height;
}

int main()
{
    setlocale(LC_ALL, "Ru");
    float r = 0, h = 0;

    try // единожды создаёт. завершает программу не аварийно
    {
        cout << "Введите значение радиуса (м)" << endl;
        cout << "r = ";
        cin >> r;
        cout << "Введите значение высоты (м)" << endl;
        cout << "h = ";
        cin >> h;
        Cylinder CylinderOne(r, h);
        cout << "Площадь поверхности цилиндра: " << CylinderOne.SurfArea() << endl;
        cout << "Объём цилиндра: " << CylinderOne.CalcVolume() << endl;
    }
    catch (MyEx Ex) // если не правильно что-то задано try обращается к catch. Выводим саму ошибку (причину и неверный параметр)
    {
        cout << Ex.GetMessage() << " " << Ex.GetValue() << endl; // обращаемся к закрытому полю
    }
    cin.get();
    return 0;
}