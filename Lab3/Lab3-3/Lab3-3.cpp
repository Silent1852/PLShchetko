#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	char string_3[256];
	const char ch = '\n';
	const int len = 41, strings = 3;
	char arr[strings][len];
	ifstream fs("file.txt");

	if (!fs) return 1; //Если файл не открыт, то завершаем программу
	for (int r = 0; r < 3; r++)
	{
		fs.getline(arr[r], len - 1, ch); //Считываем строки в массив
	}
	strcpy_s(string_3, arr[2]); //копируем отедельно нужную строку
	cout << "Первоначальный вид строки: " << string_3 << endl;
	char* str = new char[300];
	str = string_3;
	int words[150];
	int num, i, j, temp, flag;
	for (num = 0, flag = 1, i = 0; str[i]; i++) //считаем слова
	{
		if (str[i] == ' ')
		{
			str[i] = 0;
			flag = 1;
		}
		else if (flag)
		{
			words[num++] = i;
			flag = 0;
		}
	}
	for (j = num - 1; j > 0; j--)
		for (i = 0; i < j; i++)
			if (strcmp(&str[words[i]], &str[words[i + 1]]) > 0)
			{
				temp = words[i];
				words[i] = words[i + 1];
				words[i + 1] = temp;
			}
	cout << endl << "После сортировки:\n";
	for (i = num - 1; i >= 0; i--)
	{
		cout << &str[words[i]] << " ";
	}
	fs.close(); //Закрываем файл
	return 0;
}