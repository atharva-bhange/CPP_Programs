/*
Question 
You are given a BST data structure consisting of BST nodes. 
Each BST node has an integer value stored in a property 
called "value" and two children nodes stored in properties 
called "left" and "right," respectively. A node is said to 
be a BST node if and only if it satisfies the BST property: 
    -> its value is strictly greater than the values of every node to its left; 
    -> its value is less than or equal to the values of every node to its right; 
    -> and both of its children nodes are either BST nodes themselves or None (null) values. 
You are also given a target integer value; 
Write a function that finds the current value to that target value contained in the BST. 
Assume that there will only be one current value.
*/

#include <iostream>
#include <vector>
#include <cmath>
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

class BST
{

public:
    int value;
    BST *left;
    BST *right;
    BST(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    BST &insert(int new_val)
    {
        if (new_val < value)
        {
            if (left == NULL)
            {
                left = new BST(new_val);
            }
            else
            {
                left->insert(new_val);
            }
        }
        else
        {
            if (right == NULL)
            {
                right = new BST(new_val);
            }
            else
            {
                right->insert(new_val);
            }
        }
        return *this;
    }

    // void printBST()
    // {
    //     cout << left->value << endl;
    //     cout << right->value << endl;
    //     cout << right->right->value << endl;
    // }
};

int find(BST &root, int target)
{
    BST *current = &root;
    int distance = abs(current->value - target);
    int temp_distance;
    int closest = current->value;

    while (true)
    {
        if (target == current->value)
        {
            return current->value;
        }
        if (target < current->value)
        {
            if (current->left == NULL)
                break;
            current = current->left;
        }
        else
        {
            if (current->right == NULL)
                break;
            current = current->right;
        }
        temp_distance = abs(current->value - target);
        if (temp_distance < distance)
        {
            distance = temp_distance;
            closest = current->value;
        }
    }
    return closest;
}

int main(void)
{
    BST root(100);
    root
        .insert(5)
        .insert(15)
        .insert(5)
        .insert(2)
        .insert(1)
        .insert(22)
        .insert(1)
        .insert(1)
        .insert(3)
        .insert(1)
        .insert(1)
        .insert(502)
        .insert(55000)
        .insert(204)
        .insert(205)
        .insert(207)
        .insert(206)
        .insert(208)
        .insert(203)
        .insert(-51)
        .insert(-403)
        .insert(1001)
        .insert(57)
        .insert(60)
        .insert(4500);

    vector<int> tests{100, 208, 4500, 4501, -70, 2000, 6, 30000, -1, 29751, 29749};
    vector<int> ans{100, 208, 4500, 4500, -51, 1001, 5, 55000, 1, 55000, 4500};
    int got;
    for (int i = 0; i < tests.size(); i++)
    {
        cout << "TEST " << i << endl;
        got = find(root, tests[i]);
        if (got == ans[i])
        {
            cout << "OK" << endl;
        }
        else
        {
            cout << "WRONG Expected : " << ans[i] << " Got : " << got << endl;
        }
    }
    return 0;
}