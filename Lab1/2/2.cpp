#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int a, b,c, k, size;
	cout << "Введите размер массива: ";
	cin >> size;
	int* arr = new int[size];
	cout << "Введите интервал [a,b]:" << endl;
	cout << "a= ";
	cin >> a;
	cout << "b= ";
	cin >> b;
	for (int i = 0; i < size; i++)
	{
		arr[i] =a+rand() % (b-a+1);
		cout << arr[i] << endl;
	}
	cout << "Введите значение k: ";
	cin >> k;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			c = abs(arr[i]);
			int p = 1;
			while (c > 0)
			{
				p = p * 10;
				c = abs(c) / 10;
			}
			arr[i] = -1*(k * p - arr[i]);
		}
		cout << arr[i] << endl;
	}
	delete[] arr;
	return 0;
}