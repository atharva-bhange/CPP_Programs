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

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(nums[i]);
        ans.push_back(nums[i + n]);
    }
    return ans;
}

int main(void)
{
    vector<int> vals = {1, 1, 2, 2};
    int len = 2;
    shuffle(vals, len);
    return 0;
}