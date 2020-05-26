#include <iostream>

using namespace std;

//Прототипы ф-ий

int F(int n);
int G(int n);

int main()
{
	setlocale(LC_ALL, "rus");
	//Выводим результаты работы функции F от аргументов 1,2,...,10
	cout << "Значения F(n):" << endl;
	for (int i = 1; i < 11; i++)
		cout << F(i) << " ";
	cout << endl;
	//Выводим результаты работы функции G от аргументов 1,2,...,10
	cout << endl << "Значения G(n)" << endl;
	for (int i = 1; i < 11; i++)
		cout << G(i) << " ";
	return 0;
}

int F(int n)
{
	if (n == 1) //Если n равно 1, возвращаем -5
		return -5;
	else //Иначе выражение с рекурсией
		return -4 * F(n - 1) + G(n - 1); 
}


int G(int n)

{
	if (n == 1) //Если n равно 1, возвращаем 1
		return 1; 
	else //Иначе выражение с рекурсией
		return -2 * F(n - 1) + G(n - 1); 
}