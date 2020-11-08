#include <iostream> 
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

bool great(int a, int b);

int main()
{
    setlocale(LC_ALL, "RU");
    int t = 0;
    int f;
    vector<int>vect;
    ifstream file("data.txt");
    cout << "Набор данных из файла: " << endl;
    while (!file.eof())
    {
        file >> f;
        vect.push_back(f);
        cout << f << " ";
    }
    cout << endl;
    file.close();
    
    sort(vect.begin(), vect.end(), great);
    cout << "Отсортированные данные из вектора: " << endl;
    for (int i = 0; i < (int)vect.size(); i++)
        cout << vect.at(i) << " ";
    cout << endl;
    system("pause");
    return 0;
}
bool great(int a, int b)
{
    return (a < b);
}