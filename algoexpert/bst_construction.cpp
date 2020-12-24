/*
Write a Binary Search Tree (BST) class. 
The class should have a "value" property set to be an integer, 
as well as "left" and "right" properties, both of which should 
point to either the None (null) value or to another BST. A node 
is said to be a BST node if and only if it satisfies the 
BST property: 
its value is strictly greater than the values of every node to its left; 
its value is less than or equal to the values of every node to its right; 
and both of its children nodes are either BST nodes 
themselves or None (null) values. 
The BST class should support insertion, searching, and removal of values. 
The removal method should only remove the first instance of the target value.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BST
{
public:
    int value;
    BST *left;
    BST *right;

    BST(int put_value)
    {
        value = put_value;
        left = NULL;
        right = NULL;
    }

    BST &insert(int insert_val)
    {
        if (insert_val < value)
        {
            if (left == NULL)
                left = new BST(insert_val);
            else
                left->insert(insert_val);
        }
        else
        {
            if (right == NULL)
                right = new BST(insert_val);
            else
                right->insert(insert_val);
        }
        return *this;
    }

    BST &remove(int remove_val, BST *parentNode = NULL)
    {
        BST *currentNode = this;
        while (currentNode != NULL)
        {
            if (remove_val < value)
            {
                parentNode = currentNode;
                currentNode = currentNode->left;
            }
            else if (remove_val > value)
            {
                parentNode = currentNode;
                currentNode = currentNode->right;
            }
            else
            {
                if (currentNode->left != NULL && currentNode->right != NULL)
                {
                    currentNode->value = currentNode->right->getMinValue();
                    currentNode->right->remove(currentNode->value, currentNode);
                }
                else if (parentNode == NULL)
                {
                    if (currentNode->left != NULL)
                    {
                        currentNode->value = currentNode->left->value;
                        currentNode->right = currentNode->left->right;
                        currentNode->left = currentNode->left->left;
                    }
                    else if (currentNode->right != NULL)
                    {
                        currentNode->value = currentNode->right->value;
                        currentNode->left = currentNode->right->left;
                        currentNode->right = currentNode->right->right;
                    }
                }
                else if (parentNode->left == currentNode)
                {
                    parentNode->left = currentNode->left == NULL ? currentNode->right : currentNode->left;
                }
                else if (parentNode->right == currentNode)
                {
                    parentNode->right = currentNode->left == NULL ? currentNode->right : currentNode->left;
                }
            }
            break;
        }
        return *this;
    }

    bool contains(int val)
    {
        BST *currentNode = this;
        while (currentNode != NULL)
        {
            if (currentNode->value == val)
            {
                return true;
            }
            else if (val < currentNode->value)
            {
                currentNode = currentNode->left;
            }
            else
            {
                currentNode = currentNode->right;
            }
        }
        return false;
    }

    int getMinValue()
    {
        BST *currentNode = this;
        while (currentNode->left != NULL)
        {
            currentNode = currentNode->left;
        }
        return currentNode->value;
    }

    // BST &remove(int remove_val, BST *parentNode = NULL)
    // {
    //     if (value == remove_val)
    //     {
    //         BST *current = right;

    //         if (current == NULL && parentNode != NULL)
    //         {
    //             if (parentNode->left == this)
    //                 parentNode->left = left;
    //             else
    //                 parentNode->right = left;
    //         }
    //         else
    //         {
    //             int new_val;
    //             while (current != NULL)
    //             {
    //                 if (current->left == NULL)
    //                 {
    //                     if (parentNode->left == this)
    //                         parentNode->left = right;
    //                     else
    //                         parentNode->right = right;
    //                     new_val = current->value;
    //                 }
    //                 else
    //                 {
    //                     if (current->left->left == NULL)
    //                     {
    //                         new_val = current->left->value;
    //                         current->left = NULL;
    //                         break;
    //                     }
    //                 }
    //                 current = current->left;
    //             }
    //             value = new_val;
    //         }
    //     }
    //     else if (remove_val < value)
    //     {
    //         if (left->value == remove_val && left->left == NULL && left->right == NULL)
    //         {
    //             left = NULL;
    //             return *this;
    //         }
    //         left->remove(remove_val, this);
    //     }
    //     else
    //     {
    //         if (right->value == remove_val && right->left == NULL && right->right == NULL)
    //         {
    //             right = NULL;
    //             return *this;
    //         }
    //         right->remove(remove_val, this);
    //     }
    //     return *this;
    // }
};

vector<int> inOrderTraverse(BST *tree, vector<int> &arr)
{
    if (tree != NULL)
    {
        inOrderTraverse(tree->left, arr);
        arr.push_back(tree->value);
        inOrderTraverse(tree->right, arr);
    }
    return arr;
}

int main(void)
{

    return 0;
}