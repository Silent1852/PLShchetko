// Программа для проверки баланса скобок
#include <iostream> 
#include <stack>
using namespace std;


int main()
{
    setlocale(LC_ALL, "RU");
    stack<char> a;
    string s;
    cout << "Введите строку со скобками:";
    cin >> s;

    int flag = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(') {
            a.push(s[i]);
            flag = 1;
        }
        if (!a.empty()) {
            if (s[i] == '}') {
                if (a.top() == '{')
                {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ']') {
                if (a.top() == '[') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
            if (s[i] == ')') {
                if (a.top() == '(') {
                    a.pop();
                    continue;
                }
                else
                    break;
            }
        }
        else {
            break;
        }
    }
    if ((a.empty()) && (flag == 1))
        cout << "Все скобки сбалансированы" << endl;
    else
        cout << "Нет баланса скобок" << endl;
    return 0;
}