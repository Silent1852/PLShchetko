#include <iostream>
#include <conio.h>
#include <cmath>  //  + Математическая библиотека
using namespace std;

class Vector
{
private:
    int x;
    int y;
    int z;
public:
    Vector() : x(0), y(0), z(0)
    {}
    Vector(int vx, int vy, int vz) : x(vx), y(vy), z(vz)
    {}
    void showVector()
    {
        cout << x << ":" << y << ":" << z << "";
    }
    void showProizVector()
    {
        cout << x + y + z << "";
    }

    Vector operator+(Vector)const;
    Vector operator%(Vector)const;
    Vector operator*(Vector)const;
    double alpha();  //  метод угла
};

Vector Vector :: operator+ (Vector d2)const // Сложение векторов
{
    int vx = x + d2.x;
    int vy = y + d2.y;
    int vz = z + d2.z;
    return Vector(vx, vy, vz);
}

Vector Vector :: operator% (Vector d2)const // Скалярное произведение векторов
{
    int vx = x * d2.x;
    int vy = y * d2.y;
    int vz = z * d2.z;
    return Vector((vx + vy + vz), vx * 0, vy * 0);
}


Vector Vector :: operator* (Vector d2)const //Векторное произведение
{
    int vx = y * d2.z - z * d2.y;
    int vy = z * d2.x - x * d2.z;
    int vz = x * d2.y - y * d2.x;
    return Vector((vx + vy + vz), vx * 0, vy * 0);
}

double Vector::alpha()  //  Реализация метода угла
{
    return std::asin(y / (sqrt(double(x * x + y * y))));
}
int main()
{
    setlocale(0, "RU");
    int x, y, z, j, k, l;
    Vector a, b, c;
    cout << "Введите координаты вектора A: " << endl;
    cin >> x >> y >> z;
    cout << "Введите координаты вектора B: " << endl;
    cin >> j >> k >> l;
    a = Vector(x, y, z);
    b = Vector(j, k, l);
    c = a + b;
    cout << "Сложение a("; a.showVector(); cout << ") + b("; b.showVector(); cout << ") = c("; c.showVector(); cout << ")" << endl;
    c = a % b;
    cout << "Скалярное произведение a("; a.showVector(); cout << ") % b("; b.showVector(); cout << ") = "; c.showProizVector(); cout << endl;
    c = a * b;
    cout << "Векторное произведение a("; a.showVector(); cout << ") * b("; b.showVector(); cout << ") = "; c.showProizVector(); cout << endl;
    cout << "Угол вектора а =  " << a.alpha() << " радиан" << endl;

    cin.get();
    cin.get();
    return 0;
}