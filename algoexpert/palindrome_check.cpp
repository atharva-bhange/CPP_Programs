#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
    string newString = "";
    string reverseNewString = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((int)s[i] > 64 && (int)s[i] < 91)
        {
            newString += (char)((int)s[i] + 32);
        }
        else if ((int)s[i] > 96 && (int)s[i] < 123)
        {
            newString += s[i];
        }
        else if ((int)s[i] > 47 && (int)s[i] < 58)
        {
            newString += s[i];
        }
    }
    for (int i = newString.length() - 1; i >= 0; i--)
    {
        reverseNewString += newString[i];
    }
    return newString == reverseNewString;
}

int main(void)
{
    string inp, ans;
    cin >> inp;
    check(inp);
    ans = check(inp) ? "true" : "false";
    cout << ans;
    return 0;
}