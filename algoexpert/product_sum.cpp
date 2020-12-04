/*

A “special array” is a non-empty array that contains either 
integers or other “special arrays” (i.e. subarrays of integers). 
The product sum of a “special array” is the sum of its elements, 
where the inner “special arrays” are added themselves and then 
multiplied by how deep they are in the original array. 
For instance, the depth of [] is 1; the depth of the inner 
array in [[]] is 2; and the depth of the innermost array in [[[]]] is 3.
Taking in a “special array”, write a function that returns the product sum of a “special array”.

Sample Input: array=array = [5, 2, [7, -1], 3, [6, [-13, 8], 4]]
Sample Output: 12 (calculated as: 5 + 2 + 2*(7 + -1) + 3 + 2*(6 + 3 * (-13 + 8))
{5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}}
*/

#include <iostream>
#include <vector>
#include <any>
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

int productSum(vector<any> &arr, int level = 1)
{
    int ps = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].type().name() == typeid(ps).name())
        {
            // If it is int
            ps += level * (any_cast<int>(arr[i]));
        }
        else
        {
            vector<any> newArr = any_cast<vector<any>>(arr[i]);
            ps += level * productSum(newArr, level + 1);
        }
    }
    return ps;
}

int main(void)
{
    vector<any> question = {5, 2, vector<any>{7, -1}, 3, vector<any>{6, vector<any>{-13, 8}, 4}};
    int ans = productSum(question);
    cout << ans << endl;
    return 0;
}