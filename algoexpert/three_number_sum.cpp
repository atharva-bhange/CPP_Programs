/*
Write a function that takes in a non-empty array of 
distinct integers and an integer representing a target sum. 
The function should find all triplets in the array that sum 
up to the target sum and return a two-dimensional array 
of all these triplets. The numbers in each triplet should be ordered in ascending order, 
and the triplets themselves should be ordered in ascending order with respect to the numbers they hold. 
If no three numbers sum up to the target sum, the function should return an empty array.
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

// [1,2,3]

// 5

// {1: true, 2: true , 3: true}

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

void print_2d_vec(vector<vector<int>> &vec)
{
    cout << "{ ";
    for (int i = 0; i < vec.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < vec[i].size(); j++)
        {

            cout << to_string(vec[i][j]) << ", ";
        }
        cout << " }";
    }
    cout << " }" << endl;
}

// This approach has idea that we can use two number sum two times to find three number sum but it may skip some cases
// vector<vector<int>> twoNumberSum(vector<int> &arr, int total, map<int, bool> &dic)
// {
//     vector<vector<int>> ans;
//     vector<int> pair;
//     int inverted;
//     for (int i = 0; i < arr.size(); i++)
//     {
//         inverted = total - arr[i];
//         if (dic.find(inverted) != dic.end())
//         {
//             // found
//             if (dic[inverted])
//             {
//                 pair = {arr[i], inverted};
//                 ans.push_back(pair);
//                 dic[inverted] = false;
//             }
//             dic[arr[i]] = false;
//         }
//         else
//         {
//             // not found
//             dic[arr[i]] = true;
//         }
//     }
//     return ans;
// }

// vector<vector<int>> threeNumberSum(vector<int> &arr, int total)
// {
//     vector<vector<int>> newPairs;
//     vector<vector<int>> finalAnswer;
//     map<int, bool> history;
//     vector<vector<int>> pairs = twoNumberSum(arr, total, history);
//     print_2d_vec(pairs);
//     for (int i = 0; i < pairs.size(); i++)
//     {
//         // for 0
//         for (int j = 0; j < arr.size(); j++)
//         {
//             history[arr[j]] = true;
//         }
//         history[pairs[i][0]] = false;
//         newPairs = twoNumberSum(arr, pairs[i][1], history);
//         for (int k = 0; k < newPairs.size(); k++)
//         {
//             vector<int> triplet = {pairs[i][0]};
//             for (int l = 0; l < newPairs[k].size(); l++)
//             {
//                 triplet.push_back(newPairs[k][l]);
//             }
//             finalAnswer.push_back(triplet);
//         }
//         // for 1
//         for (int j = 0; j < arr.size(); j++)
//         {
//             history[arr[j]] = true;
//         }
//         history[pairs[i][1]] = false;
//         newPairs = twoNumberSum(arr, pairs[i][0], history);
//         for (int k = 0; k < newPairs.size(); k++)
//         {
//             vector<int> triplet = {pairs[i][0]};
//             for (int l = 0; l < newPairs[k].size(); l++)
//             {
//                 triplet.push_back(newPairs[k][l]);
//             }
//             finalAnswer.push_back(triplet);
//         }
//     }
//     int count = 0;
//     if (finalAnswer.size() == 0)
//     {
//         for (int i = 0; i < arr.size(); i++)
//         {
//             count += arr[i];
//         }
//         if (count == total)
//             finalAnswer.push_back(arr);
//     }
//     return finalAnswer;
// }

vector<vector<int>> threeNumberSum(vector<int> &arr, int total)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    int current;
    int left;
    int right;
    int addition;
    for (int i = 0; i < arr.size(); i++)
    {
        current = i;
        left = current + 1;
        right = arr.size() - 1;
        while (left < right)
        {
            addition = arr[current] + arr[left] + arr[right];
            if (addition == total)
            {
                ans.push_back(vector<int>{arr[current], arr[left], arr[right]});
                left++;
                right--;
            }
            else if (addition < total)
                left++;
            else
                right--;
        }
    }
    return ans;
}

class Test
{
public:
    int no_cases;
    Test()
    {
        no_cases = 11;
    }
    void Run(int c = -1)
    {
        if (c == -1)
        {
            for (int i = 0; i < no_cases; i++)
            {
                cout << "---- Test Case " << i + 1 << " ----" << endl;
                if (testCase(i))
                    cout << "PASS" << endl;
                else
                    cout << "FAIL" << endl;
            }
        }
        else if (c <= no_cases && c > 0)
        {
            cout << "---- Test Case " << c << " ----" << endl;
            if (testCase(c - 1))
                cout << "PASS" << endl;
            else
                cout << "FAIL" << endl;
        }
        else
        {
            cout << "Invalid Input" << endl;
        }
    }
    bool testCase(int num)
    {
        switch (num)
        {
        case 0:
        {
            vector<int> given = {1, 2, 3};
            vector<vector<int>> expected = {{1, 2, 3}};
            vector<vector<int>> ans = ::threeNumberSum(given, 6);
            print_2d_vec(ans);
            return ::threeNumberSum(given, 6) == expected ? true : false;
        }
        case 1:
        {
            vector<int> given = {1, 2, 3};
            vector<vector<int>> expected = {};
            vector<vector<int>> ans = ::threeNumberSum(given, 7);
            print_2d_vec(ans);
            return ::threeNumberSum(given, 7) == expected ? true : false;
        }
        case 2:
        {
            vector<int> given = {8, 10, -2, 49, 14};
            vector<vector<int>> expected = {{-2, 10, 49}};
            vector<vector<int>> ans = ::threeNumberSum(given, 57);
            print_2d_vec(ans);
            return ::threeNumberSum(given, 57) == expected ? true : false;
        }
        case 3:
        {
            vector<int> given = {12, 3, 1, 2, -6, 5, -8, 6};
            vector<vector<int>> expected = {{-8, 2, 6}, {-8, 3, 5}, {-6, 1, 5}};
            vector<vector<int>> ans = ::threeNumberSum(given, 0);
            print_2d_vec(ans);
            return ::threeNumberSum(given, 0) == expected ? true : false;
        }
        case 4:
        {
            vector<int> given = {12, 3, 1, 2, -6, 5, 0, -8, -1};
            vector<vector<int>> expected = {{-8, 3, 5}, {-6, 1, 5}, {-1, 0, 1}};
            vector<vector<int>> ans = ::threeNumberSum(given, 0);
            print_2d_vec(ans);
            return ::threeNumberSum(given, 0) == expected ? true : false;
        }
        case 5:
        {
            vector<int> given = {12, 3, 1, 2, -6, 5, 0, -8, -1, 6};
            vector<vector<int>> expected = {{-8, 2, 6}, {-8, 3, 5}, {-6, 0, 6}, {-6, 1, 5}, {-1, 0, 1}};
            vector<vector<int>> ans = ::threeNumberSum(given, 0);
            print_2d_vec(ans);
            return ::threeNumberSum(given, 0) == expected ? true : false;
        }
        case 6:
        {
            vector<int> given = {12, 3, 1, 2, -6, 5, 0, -8, -1, 6, -5};
            vector<vector<int>> expected = {
                {-8, 2, 6},
                {-8, 3, 5},
                {-6, 0, 6},
                {-6, 1, 5},
                {-5, -1, 6},
                {-5, 0, 5},
                {-5, 2, 3},
                {-1, 0, 1},
            };
            return ::threeNumberSum(given, 0) == expected ? true : false;
        }
        case 7:
        {
            vector<int> given = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
            vector<vector<int>> expected = {
                {1, 2, 15},
                {1, 8, 9},
                {2, 7, 9},
                {3, 6, 9},
                {3, 7, 8},
                {4, 5, 9},
                {4, 6, 8},
                {5, 6, 7},
            };
            return ::threeNumberSum(given, 18) == expected ? true : false;
        }
        case 8:
        {
            vector<int> given = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
            vector<vector<int>> expected = {{8, 9, 15}};
            return ::threeNumberSum(given, 32) == expected ? true : false;
        }
        case 9:
        {
            vector<int> given = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
            vector<vector<int>> expected = {};
            return ::threeNumberSum(given, 33) == expected ? true : false;
        }
        case 10:
        {
            vector<int> given = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
            vector<vector<int>> expected = {};
            return ::threeNumberSum(given, 5) == expected ? true : false;
        }
        default:
        {
            return false;
        }
        }
    }
};

int main(void)
{
    Test T;
    T.Run();
    return 0;
}