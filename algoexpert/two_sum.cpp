#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
// My Approach T = O(nlogn) I Think! S = O(n)
vector<int> twoSum1(vector<int> &nums, int target)
{
    int inverted;
    vector<int> toSort = nums;
    sort(toSort.begin(), toSort.end());
    for (int i = 0; i < nums.size(); i++)
    {
        inverted = target - nums[i];
        if (binary_search(toSort.begin(), toSort.end(), inverted))
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == inverted)
                {
                    return vector<int>{i, j};
                }
            }
        }
        else
        {
            continue;
        }
    }
    return vector<int>{0, 0};
}

// Another solution with only sorting can be done where
// we don't want index but directly two sum numbers

// T = O(n) S = O(n) using HashMaps
vector<int> twoSum2(vector<int> &nums, int target)
{
    map<int, int> found;
    int inverted;
    for (int i = 0; i < nums.size(); i++)
    {
        inverted = target - nums[i];
        if (found.find(inverted) != found.end())
        {
            // element found
            return vector<int>{i, found[inverted]};
        }
        else
        {
            // element not present
            found[nums[i]] = i;
        }
    }

    return vector<int>{0, 0};
}

void print(vector<int> &vec)
{
    cout << "[ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec.at(i) << ", ";
    }
    cout << "]" << endl;
}

int main(void)
{
    vector<int> ans;
    vector<int> test1{-3, 4, 3, 90};
    int tar1 = 0;
    vector<int> test2{3, 2, 4};
    int tar2 = 6;
    vector<int> test3{3, 3};
    int tar3 = 6;
    //twoSum(test1, tar1);
    ans = twoSum2(test1, tar1);
    print(ans);
    ans = twoSum2(test2, tar2);
    print(ans);
    ans = twoSum2(test3, tar3);
    print(ans);
    return 0;
}
