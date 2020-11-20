#include <iostream>
#include <string>
using namespace std;

bool check(string s)
{
    int s_len = s.length();
    for (int i = 0; i < (s_len / 2); i++)
    {
        if (s[i] != s[s_len - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    string inp, ans;
    cin >> inp;
    ans = check(inp) ? "true" : "false";
    cout << ans;
    return 0;
}