/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that 
it is possible to split the entire deck into 1 or more groups of cards, where:

Each group has exactly X cards.
All the cards in each group have the same integer.
*/

#include <iostream>
#include <vector>
#include <algorithm>
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
// T = O(nlog(n))
bool hasGroupsSizeX(vector<int> &deck)
{
    sort(deck.begin(), deck.end());
    //printV(deck);
    int current = deck[0];
    int groupSize = 1;
    for (int k = 1; k < deck.size(); k++)
    {
        if (deck[k] == current)
            groupSize++;
        else
        {
            if (groupSize < 2)
                return false;
            break;
        }
    }
    //cout << "Group Size: " << groupSize << endl;
    current = deck[groupSize];
    int counter = 1;
    for (int p = groupSize + 1; p < deck.size(); p++)
    {
        if (deck[p] == current)
            counter++;
        else
        {
            if (counter == groupSize)
            {
                current = deck[p];
                counter = 1;
            }
            else
                return false;
        }
    }
    if (counter != groupSize || groupSize == 1)
        return false;
    return true;
}

int main(void)
{
    vector<vector<int>> questions{
        vector<int>{1, 2, 3, 4, 4, 3, 2, 1},
        vector<int>{1, 1, 1, 2, 2, 2, 3, 3},
        vector<int>{1},
        vector<int>{1, 1},
        vector<int>{1, 1, 2, 2, 2, 2}};
    // cout << hasGroupsSizeX(questions[0]) << endl;
    for (int j = 0; j < questions.size(); j++)
    {
        cout << hasGroupsSizeX(questions[j]) << endl;
    }
    return 0;
}
// 11122233