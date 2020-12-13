/*
Given the array candies and the integer extraCandies, where candies[i] 
represents the number of candies that the ith kid has.

For each kid check if there is a way to distribute extraCandies 
among the kids such that he or she can have the greatest number 
of candies among them. Notice that multiple kids can have the 
greatest number of candies.
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

vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
{
    int max = candies[0];
    for (int i = 1; i < candies.size(); i++)
    {
        if (candies[i] > max)
            max = candies[i];
    }
    vector<bool> ans;
    for (int i = 0; i < candies.size(); i++)
    {
        if (candies[i] + extraCandies >= max)
            ans.push_back(true);
        else
            ans.push_back(false);
    }
    return ans;
}

int main(void)
{
    return 0;
}