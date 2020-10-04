#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct smth 
{
	long long nomer = 0;
	string fam = " ";
	string imya = " ";
	string otch = " ";
	string tarif = " ";
	int stoimost = 0;
};

bool cmpByFam(const smth& r1, const smth& r2)
{
	return r1.fam < r2.fam;
}

int main()
{
	setlocale(LC_ALL, "rus");
	string x;
	smth s;
	ifstream file;
	file.open("file.txt");
	int len(0);
	if (file.is_open()) {
		while (!file.eof()) {
			string s;
			getline(file, s);
			len++;
		}
	}
	smth* arr = new smth[len];
	file.seekg(0, ios_base::beg);
	for (size_t i = 0; i < len; i++)
	{
		getline(file, x);
		istringstream iss(x);
		iss >> s.nomer >> s.fam >> s.imya  >> s.otch >> s.tarif >> s.stoimost;
		arr[i] = s;
	}
	cout << "Информация о всех абонентах: \n" << endl;
	for (size_t n = 0; n < len; n++)
	{
		cout << "Номер телефона: " << setw(13) << left << arr[n].nomer
			 << "Фамилия: " << setw(10) << left <<  arr[n].fam
			 << "Имя: "<< setw(13) << left << arr[n].imya
			 << "Отчество: " << setw(13) << left << arr[n].otch 
			 << "Тариф: " << setw(10) << left << arr[n].tarif 
			 << "Абон.плата за месяц: "<< setw(5) << left << arr[n].stoimost<< endl;
	}
	cout << "\nИнформация о номерах, не закреплённых за фамилией Петров :\n" << endl;

	for (size_t n = 0; n < len; n++)
	{
		if (arr[n].fam != "Petrov")
		{
			cout << "Номер телефона: " << setw(13) << left << arr[n].nomer
				 << "Фамилия: " << setw(10) << left << arr[n].fam
				 << "Имя: " << setw(13) << left << arr[n].imya
				 << "Отчество: " << setw(13) << left << arr[n].otch
				 << "Тариф: " << setw(10) << left << arr[n].tarif
				 << "Абон.плата за месяц: " << setw(5) << left << arr[n].stoimost << endl;
		}
	}
	cout << "\nИнформация о абонентах, для которых абонентская плата в год превышает 5000 руб, отсортированная по алфавиту:\n" << endl;
	sort(arr, arr + len, cmpByFam);
	for (size_t n = 0; n < len; n++)
	{
		if ((arr[n].stoimost * 12) > 5000)
		{
			cout << "Номер телефона: " << setw(13) << left << arr[n].nomer
				 << "Фамилия: " << setw(10) << left << arr[n].fam
				 << "Имя: " << setw(13) << left << arr[n].imya
				 << "Отчество: " << setw(13) << left << arr[n].otch
				 << "Тариф: " << setw(10) << left << arr[n].tarif
				 << "Абон.плата за месяц: " << setw(5) << left << arr[n].stoimost << endl;
		}
	}
	file.close();
}