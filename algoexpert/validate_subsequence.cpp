#include <iostream>
#include <string>
using namespace std;

bool validate(string s, string t)
{
    int idx = 0;
    int t_len = t.length();
    for (int i = 0; i < t_len; i++)
    {
        if (s[idx] == t[i])
        {
            idx++;
        }
    }
    if (idx == s.length())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main(void)
{
    string s, t;
    cin >> s;
    cin >> t;
    string ans = validate(s, t) ? "true" : "false";
    cout << ans;
    return 0;
}