/* 
Write a function that takes in a Binary Tree and 
returns a list of its branch sums (ordered from leftmost branch sum to rightmost branch sum).
A branch sum is the sum of all values in a Binary Tree branch. 
A Binary Tree branch is a path of nodes in a tree that starts at the root 
node and ends at any leaf node. Each Binary Tree node has a value stored in a property 
called "value" and two children nodes stored in properties called "left" and "right," respectively. 
Children nodes can either be Binary Tree nodes themselves or the None (null) value.
*/
#include <iostream>
#include <vector>
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

class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int val)
    {
        value = val;
        left = NULL;
        right = NULL;
    }

    BinaryTree &insert(vector<int> &values, int i = 0)
    {
        BinaryTree *current;
        //cout << "Size is" << values.size() << " and i is " << i << endl;
        if (i >= values.size())
        {
            //cout << "inside if" << endl;
            return *this;
        }
        queue<BinaryTree *> queue;
        queue.push(this);
        while (!queue.empty())
        {
            //cout << "inside while loop" << endl;
            current = queue.front();
            queue.pop();
            if (current->left == NULL)
            {
                //cout << "left is null" << endl;
                current->left = new BinaryTree(values[i]);
                break;
            }
            queue.push(current->left);
            if (current->right == NULL)
            {
                current->right = new BinaryTree(values[i]);
                break;
            }
            queue.push(current->right);
        }
        this->insert(values, i + 1);
        return *this;
    }
};

// vector<int> branchSums(BinaryTree *tree, int sum = 0)
// {
//     vector<int> ans;
//     if (tree->value == NULL)
//     {
//         ans.push_back(sum);
//     }
//     int new_sum = tree->value + sum;
//     vector<int> ans1 = branchSums(tree->left, new_sum);
//     vector<int> ans2 = branchSums(tree->right, new_sum);
//     for (int i = 0; i < ans1.size(); i++)
//     {
//         ans.push_back(ans1[i]);
//     }
//     for (int i = 0; i < ans2.size(); i++)
//     {
//         ans.push_back(ans2[i]);
//     }
//     return ans;
// }

void CalculateSums(BinaryTree *tree, int runningSum, vector<int> &sums)
{
    //cout << "New Called" << endl;
    if (tree == NULL)
    {
        return;
    }
    int newRunningSum = runningSum + tree->value;
    if (tree->left == NULL && tree->right == NULL)
    {
        //cout << "pushing stuff" << endl;
        sums.push_back(newRunningSum);
        //::printV(sums);
        return;
    }

    CalculateSums(tree->left, newRunningSum, sums);
    CalculateSums(tree->right, newRunningSum, sums);
}

vector<int> branchSums(BinaryTree *tree)
{
    //cout << "Called" << endl;
    vector<int> sums;
    CalculateSums(tree, 0, sums);
    //::printV(sums);
    //cout << "sums sixe" << sums.size() << endl;
    //cout << "lol" << endl;
    return sums;
}

class Test
{
public:
    int no_of_tests = 9;
    void Run(int i = -1)
    {
        if (i < 0)
        {
            for (int t = 0; t < no_of_tests; t++)
            {
                cout << "Runnig Test " << t << endl;
                if (Switch(t))
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
            if (Switch(i))
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

    bool Switch(int j)
    {

        switch (j)
        {
        case 0:
        {
            //cout << "case 0" << endl;
            BinaryTree tree(1);
            //cout << tree.value << endl;
            vector<int> sums = ::branchSums(&tree);

            //::printV(sums);
            if (sums == vector<int>{1})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 1:
        {
            BinaryTree tree(1);
            vector<int> vec{2};
            tree.insert(vec);
            vector<int> sums = ::branchSums(&tree);
            //::printV(sums);
            if (sums == vector<int>{3})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 2:
        {
            //cout << "case 2" << endl;
            BinaryTree tree(1);
            vector<int> vec{2, 3};
            tree.insert(vec);
            vector<int> sums = ::branchSums(&tree);
            //cout << "Size is" << sums.size() << endl;
            //::printV(sums);
            if (sums == vector<int>{3, 4})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 3:
        {
            BinaryTree tree(1);
            vector<int> vec{2, 3, 4, 5};
            tree.insert(vec);
            vector<int> sums = ::branchSums(&tree);
            if (sums == vector<int>{7, 8, 4})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 4:
        {
            BinaryTree tree(1);
            vector<int> vec{2, 3, 4, 5, 6, 7, 8, 9, 10};
            tree.insert(vec);
            vector<int> sums = ::branchSums(&tree);
            //::printV(sums);
            if (sums == vector<int>{15, 16, 18, 10, 11})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 5:
        {
            BinaryTree tree(1);
            vector<int> vec{2, 3, 4, 5, 6, 7, 8, 9, 10, 1, 1, 1};
            tree.insert(vec);
            vector<int> sums = ::branchSums(&tree);
            if (sums == vector<int>{15, 16, 18, 9, 11, 11, 11})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 6:
        {
            BinaryTree tree(0);
            tree.left = new BinaryTree(1);
            tree.left->left = new BinaryTree(10);
            tree.left->left->left = new BinaryTree(100);
            vector<int> sums = ::branchSums(&tree);
            if (sums == vector<int>{111})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 7:
        {
            BinaryTree tree(0);
            tree.right = new BinaryTree(1);
            tree.right->right = new BinaryTree(10);
            tree.right->right->right = new BinaryTree(100);
            vector<int> sums = ::branchSums(&tree);
            if (sums == vector<int>{111})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        case 8:
        {
            BinaryTree tree(0);
            tree.left = new BinaryTree(9);
            tree.right = new BinaryTree(1);
            tree.right->left = new BinaryTree(15);
            tree.right->right = new BinaryTree(10);
            tree.right->right->left = new BinaryTree(100);
            tree.right->right->right = new BinaryTree(200);
            vector<int> sums = ::branchSums(&tree);
            if (sums == vector<int>{9, 16, 111, 211})
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        default:
        {
            break;
        }
        }
        return false;
    }
};

int main(void)
{
    Test test;
    test.Run();
    // BinaryTree tree(1);
    // cout << tree.value << endl;
    // cout << tree.left << endl;
    // cout << tree.right << endl;
    // vector<int> vec{2, 3};
    // tree.insert(vec);
    // cout << tree.value << endl;
    // cout << tree.left->value << endl;
    // cout << tree.right->value << endl;
    return 0;
}