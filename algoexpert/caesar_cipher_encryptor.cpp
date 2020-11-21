#include <iostream>
#include <string>
using namespace std;

string encrypt(string s, int k)
{
    string new_string = "";
    k = k % 26;
    int newCharCode;
    for (int i = 0; i < s.length(); i++)
    {
        int charCode = (int)s[i];
        if (charCode >= 65 && charCode <= 90)
        {
            newCharCode = ((charCode + k) % 90);
            if (newCharCode < 64 && newCharCode > 0)
                newCharCode = newCharCode + 64;
            else if (newCharCode == 0)
                newCharCode = 90;
            new_string = new_string + (char)newCharCode;
        }
        else if (charCode >= 97 && charCode <= 122)
        {
            newCharCode = ((charCode + k) % 122);
            if (newCharCode < 96 && newCharCode > 0)
                newCharCode = newCharCode + 96;
            else if (newCharCode == 0)
                newCharCode = 122;

            new_string = new_string + (char)newCharCode;
        }
        else
        {
            new_string = new_string + s[i];
        }
    }
    return new_string;
}

int main(void)
{
    int n, k;
    string s, ans;
    cin >> n;
    cin >> s;
    cin >> k;
    cout << encrypt(s, k);
    return 0;
}