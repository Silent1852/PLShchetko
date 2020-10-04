#include <iostream>
#include <cmath>

using namespace std;

class Complex         // класс "Комплексное число"
{
private:
    double real, imag;      // действительная и мнимая части

public:
    // конструкторы 

    Complex()
    {
    };

    Complex(double r)
    {
        real = r;
        imag = 0;
    }

    Complex(double r, double i)
    {
        real = r;
        imag = i;
    }

    Complex(const Complex& c)   // конструктор копирования
    {
        real = c.real;
        imag = c.imag;
    }

    // деструктор
    ~Complex()
    {
    }

    // остальные функции

    // Модуль комплексного числа
    double abs()
    {
        return sqrt(real * real + imag * imag);
    }

    // оператор присваивания
    Complex& operator = (Complex& c)
    {
        real = c.real;
        imag = c.imag;

        return (*this);
    }


    // оператор +=
    Complex& operator += (Complex& c)
    {
        real += c.real;
        imag += c.imag;
        return *this;
    }

    // оператор *=
    Complex& operator *= (Complex& c)
    {
        int q, w;
        q = (real * c.real) - (imag * c.imag);
        w = (real * c.imag) + (c.real * imag);
        real = q;
        imag = w;
        return *this;
    }

    // оператор сложения
    Complex operator + (const Complex& c)
    {
        return Complex(real + c.real, imag + c.imag);
    }

    // оператор вычитания
    Complex operator - (const Complex& c)
    {
        return Complex(real - c.real, imag - c.imag);
    }

    // оператор умножения
    Complex operator * (const Complex& c)
    {
        return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
    }

    // оператор деления
    Complex operator / (const Complex& c)
    {
        Complex temp;

        double r = c.real * c.real + c.imag * c.imag;
        temp.real = (real * c.real + imag * c.imag) / r;
        temp.imag = (imag * c.real - real * c.imag) / r;

        return temp;
    }

    // дружественные операторы к private данным
    friend ostream& operator<< (ostream&, const Complex&);
    friend istream& operator>> (istream&, Complex&);

};

// перегрузка оператора <<
ostream& operator<< (ostream& out, const Complex& c)
{
    out << "(" << c.real << ", " << c.imag << ")";
    return out;
}

// перегрузка оператора >>
istream& operator>> (istream& in, Complex& c)
{
    in >> c.real >> c.imag;
    return in;
}

int
main()
{
    setlocale(LC_ALL, "RU");
    Complex a(4, 2);
    Complex b(3, 5);



    cout << "a = " << a << "; b = " << b << endl;

    Complex c = a + b;

    cout << c << endl;
    cout << "Сложение: " << a + b << endl;
    cout << "Вычитание: " << a - b << endl;
    cout << "Умножение: " << a * b << endl;
    cout << "Деление: " << a / b << endl << endl;

    a += b;
    cout << "'a += b': "<< "a = " << a << "; b = " << b << endl;
    a *= b;
    cout << "'a *= b': " << "a = " << a << "; b = " << b << endl;

    return 0;
}