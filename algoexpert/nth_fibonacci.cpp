/*
The Fibonacci sequence is defined as follows: 
the first number of the sequence is 0, 
the second number is 1, 
and the nth number is the sum of the (n - 1)th and (n - 2)th numbers. 
Write a function that takes in an integer n and returns the nth Fibonacci number.
0,1,1,2,3,5,8
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

int getNthFib(int n, int n1 = 0, int n2 = 1, int counter = 3)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n == 2)
    {
        return 1;
    }

    if (n == counter)
    {
        return n1 + n2;
    }

    return getNthFib(n, n2, n1 + n2, counter + 1);
}

class Test
{
public:
    int no_of_tests;
    vector<int> ans;
    Test(vector<int> givenAns)
    {
        no_of_tests = givenAns.size();
        ans = givenAns;
    }
    void Run(int i = -1)
    {
        if (i < 0)
        {
            for (int t = 0; t < no_of_tests; t++)
            {
                cout << "Runnig Test " << t << endl;
                if (::getNthFib(t + 1) == ans[t])
                {
                    cout << "PASS" << endl;
                }
                else
                {
                    cout << "WRONG" << endl;
                }
            }
        }
        else if (i < no_of_tests)
        {
            cout << "Running Test " << i << endl;
            if (::getNthFib(i + 1) == ans[i])
            {
                cout << "PASS" << endl;
            }
            else
            {
                cout << "WRONG" << endl;
            }
        }
        else
        {
            cout << "Test Not Available" << endl;
        }
    }
};

int main(void)
{
    vector<int> answers{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597};
    Test test(answers);
    test.Run();
    return 0;
}
