#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printV(vector<T> &vec)
{
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << ", ";
    }
    cout << "]" << endl;
}

vector<int> thirdMax(vector<int> &nums)
{
    long int fl = LONG_MIN;
    long int sl = LONG_MIN;
    long int tl = LONG_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] >= fl)
        {
            if (nums[i] != fl)
            {
                tl = sl;
                sl = fl;
            }
            fl = nums[i];
        }
        else if (nums[i] >= sl)
        {
            if (nums[i] != sl)
                tl = sl;
            sl = nums[i];
        }
        else if (nums[i] >= tl)
        {
            tl = nums[i];
        }
    }
    vector<int> ans;
    if (tl != LONG_MIN)
    {
        ans.push_back((int)tl);
    }
    if (sl != LONG_MIN)
    {
        ans.push_back((int)sl);
    }
    if (fl != LONG_MIN)
    {
        ans.push_back((int)fl);
    }
    return ans;
}

int main(void)
{
    vector<vector<int>> question{
        vector<int>{3, 2, 1},
        vector<int>{1, 2},
        vector<int>{2, 2, 3, 1},
    };
    vector<vector<int>> ans{
        vector<int>{1, 2, 3},
        vector<int>{1, 2},
        vector<int>{1, 2, 3}};

    for (int i = 0; i < question.size(); i++)
    {
        cout << "Testing case " << i << endl;
        if (thirdMax(question[i]) == ans[i])
        {
            cout << "Pass" << endl;
        }
        else
        {
            cout << "Fail" << endl;
        }
    }
    return 0;
}