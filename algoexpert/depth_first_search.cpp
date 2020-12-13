/* 

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

vector<int> allNodes(BinaryTree tree)
{
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
            BinaryTree tree(1);
            vector<int> sums = ::allNodes(tree);
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
            vector<int> sums = ::allNodes(tree);
            //::printV(sums);
            if (sums == vector<int>{2})
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
            BinaryTree tree(1);
            vector<int> vec{2, 3};
            tree.insert(vec);
            vector<int> sums = ::allNodes(tree);
            if (sums == vector<int>{1, 2, 3})
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
            vector<int> sums = ::allNodes(tree);
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
            vector<int> sums = ::allNodes(tree);
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
            vector<int> sums = ::allNodes(tree);
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
            vector<int> sums = ::allNodes(tree);
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
            vector<int> sums = ::allNodes(tree);
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
            vector<int> sums = ::allNodes(tree);
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
    return 0;
}