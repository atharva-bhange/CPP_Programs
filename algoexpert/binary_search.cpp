#include <iostream>
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

int search(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int mid;
    while (l <= r)
    {
        mid = l + ((r - l) / 2);
        if (nums[mid] > target)
        {
            r = mid - 1;
        }
        else if (nums[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main(void)
{
    vector<vector<int>> tests{
        vector<int>{-1, 0, 3, 5, 9, 12},
        vector<int>{-1, 0, 3, 5, 9, 12},
        vector<int>{5}};

    vector<int> targets{
        9,
        2,
        5};

    for (int i = 0; i < tests.size(); i++)
    {
        cout << search(tests[i], targets[i]) << endl;
    }

    return 0;
}