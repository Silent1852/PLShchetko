#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RU");
    int t = 0;
    int f;
    vector<int>vect;
    ifstream file("data.txt");
    cout << "Набор данных из файла: ";
    while (!file.eof())
    {
        file >> f;
        vect.push_back(f);
        cout << f << " ";
    }
    cout << endl;
    file.close();
    int n;
    cout << "Введите число n:" << endl;
    cin >> n;
    cout << "Количество чисел " << n << ": " << count(vect.begin(), vect.end(), n) << endl;
    system("pause");
    return 0;
}