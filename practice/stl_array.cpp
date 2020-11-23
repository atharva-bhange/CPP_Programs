#include <iostream>
#include <array>
using namespace std;

int main(void)
{

    array<int, 5> arr;
    arr = {1, 2, 3, 4, 5};

    cout << arr.front() << endl;
    cout << arr.back() << endl;
    cout << arr.at(2) << endl;
    cout << arr[4] << endl;
    cout << arr.size() << endl;
    arr.fill(10);
    cout << arr[4];

    return 0;
}