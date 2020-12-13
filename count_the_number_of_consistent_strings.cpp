/*
You are given a string allowed consisting of distinct characters 
and an array of strings words. A string is consistent if all 
characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.
*/

#include <iostream>
#include <string>
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

int countConsistentStrings(string allowed, vector<string> &words)
{
    int count = 0;
    bool present = false;
    bool isConsistant = true;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = 0; j < words[i].length(); j++)
        {
            for (int k = 0; k < allowed.length(); k++)
            {
                if (allowed[k] == words[i][j])
                {
                    present = true;
                }
            }
            if (present)
                present = false;
            else
            {
                isConsistant = false;
                break;
            }
        }
        if (isConsistant)
            count++;
        isConsistant = true;
    }
    return count;
}

int main(void)
{
    vector<string> all{"cc", "acd", "b", "ba", "bac", "bad", "ac", "d"};
    string alld = "cad";
    cout << countConsistentStrings(alld, all) << endl;
    return 0;
}