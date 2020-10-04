#include "stdio.h"
#include <iostream>

using namespace std;

struct COMPLEX
{
    float real;
    float imag;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    COMPLEX a, b, c;
    int input;
    cout << "Введите действительную часть 1ого числа" << endl;
    cin>>a.real;
    cout << "Введите мнимую часть 1ого числа" << endl;
    cin>>a.imag;

    cout << "Введите действительную часть 2ого числа" << endl;
    cin >> b.real;
    cout << "Введите мнимую часть 2ого числа" << endl;
    cin >> b.imag;

    cout << "Выберите действие:" << endl;
    cout << "1. Сложение" << endl;
    cout << "2. Умножение" << endl;
    cin >> input;

    switch (input)
    {
    case 1: 
        c.real = a.real + b.real;
        c.imag = a.imag + b.imag;
        break;
    case 2: 
        c.real = a.real * b.real - a.imag * b.imag;
        c.imag = a.real * b.imag + a.imag * b.real;
        break;
    default:
        cout << "Ошибка" << endl;
        break;
    };

    cout << "Ответ:" << c.real + c.imag << endl;
    return 0;
}