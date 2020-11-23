#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print(vector<T> &vec)
{
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << ", ";
    }
    cout << "]" << endl;
}

int compress(vector<char> &chars)
{
    vector<char> ans;
    char current = chars[0];
    int count = 0;
    for (int i = 0; i < chars.size(); i++)
    {
        if (chars[i] == current)
        {
            if (count == 0)
                ans.push_back(current);
            count++;
        }
        else
        {
            if (count > 1)
            {
                if (count > 9)
                    ans.push_back((count / 10) + 48);
                ans.push_back((count % 10) + 48);
            }
            current = chars[i];
            ans.push_back(chars[i]);
            count = 1;
        }
    }
    if (count > 1)
    {
        if (count > 9)
            ans.push_back((count / 10) + 48);
        ans.push_back((count % 10) + 48);
    }
    chars = ans;
    return ans.size();
}

int main(void)
{
    vector<vector<char>> tests = {
        {'a', 'a', 'b', 'b', 'c', 'c', 'c'},
        {'a'},
        {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'},
        {'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'}};
    for (int test = 0; test < tests.size(); test++)
    {
        cout << compress(tests[test]) << endl;
        print(tests[test]);
    }
    return 0;
}