#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
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

int main(void)
{
    return 0;
}