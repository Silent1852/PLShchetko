#include <iostream>

using namespace std;

const double PI = 3.14159;

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
    height = h;
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
    int r = 0, h = 0;
    cout << "Введите значение радиуса (м)" << endl;
    cin >> r;
    cout << "Введите значение высоты (м)" << endl;
    cin >> h;
    if (r > 0 && h > 0)
    {
        Cylinder CylinderOne(r, h);
        cout << "Площадь поверхности цилиндра: " << CylinderOne.SurfArea() << endl;
        cout << "Объём цилиндра: " << CylinderOne.CalcVolume() << endl;
    }
    else cout << "Некорректные данные" << endl;
    cin.get();
    return 0;
}