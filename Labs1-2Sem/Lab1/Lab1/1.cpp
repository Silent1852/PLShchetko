#include <iostream> 
#include <fstream> 
#include <string> 
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int k, count = 0, size = 10;
	int* arr = new int[size];
	string path = "array.txt";
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Файл не открыт\n";
		return 0;
	}
	cout << "Файл открыт\n";
	string str;
	while (!fin.eof())
	{
		str = "";
		fin >> str;
		count++;
	}
	size = count;
	fin.clear();
	fin.seekg(0, ios::beg);
	for (int i = 0; i < size; i++)
		fin >> arr[i];
	cout << "Введите значение k: ";
	cin >> k;
	for (int i = 0; i < size; i++)
		if (arr[i] > k)
		{
			cout << arr[i] << "\n";
}
	delete[] arr;
	return 0;
}