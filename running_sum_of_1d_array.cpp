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

vector<int> runningSum(vector<int> &nums)
{
    int sum = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        ans.push_back(sum);
    }
    return ans;
}

int main(void)
{
    return 0;
}