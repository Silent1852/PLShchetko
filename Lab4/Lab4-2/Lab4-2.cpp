#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    int a, n, d, k = 0, p = 0;
    cout << "Введите первый член арифметической прогрессии: ";
    cin >> a;
    cout << "Введите разность членов: ";
    cin >> d;
    cout << "Введите номер последнего члена прогрессии: ";
    cin >> n;
    p = a;
    cout<<"1) "<< a << endl;
    while (k < (n - 1))
    {
        a = a + d; //
        p = p + a; //Сложение членов арифметической прогрессии
        cout<< k+2 << ") " << a << endl;
        k++;
    }
    cout << "Сумма членов арифметической прогрессии= " << p;
    return 0;
}