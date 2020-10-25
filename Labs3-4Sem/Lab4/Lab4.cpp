#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
	int a;
	setlocale(LC_ALL, "RU");
	double b[] = { 3,7,9 };

	Matrix m1(3, 3), m2;

	m2.setSize(3, 3);
	cout << "Введие матрицу 1 размером 3x3" << endl;
	cin >> m1;
	cout << "Введие матрицу 2 размером 3x3" << endl;
	cin >> m2;

	cout << "Матрица 1" << m1 << endl << "Матрица 2"  << m2 << endl;

	cout << "Сумма матриц: ";
	cout << m1 + m2 << endl;

	cout << "Умножение матрицы на заданное число a: " << endl << "a = ";
	cin >> a;
	cout << m1 * a << endl;

	cout << "Умножение матриц:";
	cout << m1 * m2 << endl;

}