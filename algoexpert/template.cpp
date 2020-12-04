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

// #include <iostream>
// int main()
// {
//     if (__cplusplus == 201703L)
//         std::cout << "C++17"
//                   << "\n";
//     else if (__cplusplus == 201402L)
//         std::cout << "C++14"
//                   << "\n";
//     else if (__cplusplus == 201103L)
//         std::cout << "C++11"
//                   << "\n";
//     else if (__cplusplus == 199711L)
//         std::cout << "C++98"
//                   << "\n";
//     else
//         std::cout << "pre-standard C++"
//                   << "\n";
//     return 0;
// }