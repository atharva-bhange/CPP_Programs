#include <iostream>
#include <vector>
using namespace std;

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
    vector<int> vec;

    vec.reserve(10);

    for (int i = 0; i < 15; i++)
    {
        vec.push_back(i);
    }
    print(vec);
    vector<int> vec2 = vec;
    vec2[0] = 99;
    print(vec);
    print(vec2);
    //cout << vec.size() << endl;

    return 0;
}