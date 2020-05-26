#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

int main()
{
	int mass[N], max;

	cout << "Array: ";
	srand(time(NULL));
	for (int r = 0; r < N; r++)
	{
		mass[r] = 2; //Ввод рандомных значений элементам массива
		cout << mass[r] << " "; //Вывод массива на экран 
	}
	cout << endl;
	if (mass[0] % 2 != 0) 
		max = mass[0];
	else max = mass[1];

	for (int r = 1; r < N; r++)
	{
		if (max < mass[r] && mass[r]%2!=0) //Проверка элемента на нечётность
			max = mass[r];

	}
	if (max % 2 != 0)
		cout << "Max: " << max << endl; // Вывод максимального элемента массива на экран
	else cout << "Error";
	return 0;
}