/*
Given an integer n and an integer start.

Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.
*/

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
int xorOperation(int n, int start)
{
    int ans = 0;
    vector<int> arr;
    arr.reserve(n);
    for (int i = 0; i < n; i++)
    {
        arr.push_back(start + (2 * i));
    }
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int main(void)
{
    cout << xorOperation(5, 0) << endl;
    cout << xorOperation(4, 3) << endl;
    cout << xorOperation(1, 7) << endl;
    cout << xorOperation(10, 5) << endl;
    return 0;
}