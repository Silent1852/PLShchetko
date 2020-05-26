#include <iostream>
using namespace std;

void word(char* symb, char* result)
{
    int i = 0;
    while (symb[i] != ' ' && symb[i] != ',' && symb[i] != '.' && symb[i] != 0)
        result[i] = symb[i++];
    result[i] = 0;
}

int main()
{
    char res[50], s[50];
    cin >> s;
    word(s, res);
    cout << res;
    return 0;
}