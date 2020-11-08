// Программа для проверки строки на полиндром
#include<iostream>
#include <stack>
#include<queue>
#include<string>
using namespace std;

int main() 
{
    setlocale(LC_ALL, "RU");
    queue <char> q;
    stack <char> s;
    string characters;
    cout << "Введите строку " << endl;
    cin >> characters;
    for (int i = 0; i < characters.size(); i++) {
        q.push(characters[i]);
        s.push(characters[i]);
    }
    bool check = true;
    if (!q.empty() && !s.empty() && check) {
        if (s.top() == q.front()) {
            q.pop();
            s.pop();
            cout << " Это полиндром " << endl;
        }
        else
            cout << " Это не полиндром " << endl;
    }
    system("pause");
    return 0;
}