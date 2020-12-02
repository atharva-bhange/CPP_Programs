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

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    void insert(vector<int> &values, int i = 0)
    {
        TreeNode *current;
        if (i >= values.size())
        {
            return;
        }
        queue<TreeNode *> queue;
        queue.push(this);
        while (!queue.empty())
        {
            current = queue.front();
            queue.pop();
            if (current->left == NULL)
            {
                current->left = new TreeNode(values[i]);
                break;
            }
            queue.push(current->left);
            if (current->right == NULL)
            {
                current->right = new TreeNode(values[i]);
                break;
            }
            queue.push(current->right);
        }
        this->insert(values, i + 1);
        return;
    }
};

void findDepth(TreeNode *current, int currentDepth, int &maxDepth)
{
    //cout << "Going  in depth and current dept is " << currentDepth << endl;
    if (current == NULL)
    {
        //cout << "Leaving" << endl;
        return;
    }
    if (maxDepth < currentDepth)
    {
        //cout << "Max depth changed" << endl;
        maxDepth = currentDepth;
    }

    findDepth(current->left, currentDepth + 1, maxDepth);
    findDepth(current->right, currentDepth + 1, maxDepth);
}

int maxDepth(TreeNode *root)
{
    int maxDepth = 1;
    if (root == NULL)
        return 0;
    findDepth(root, 1, maxDepth);
    return maxDepth;
}

int main(void)
{
    TreeNode tree(1);
    //cout << tree.val << endl;
    vector<int> child{9, 20, NULL, NULL, 15, 7};
    tree.insert(child);
    // cout << tree.left->val << endl;
    // cout << tree.right->val << endl;

    // cout << tree.left->left->val << endl;
    // cout << tree.left->right->val << endl;

    // cout << tree.right->left->val << endl;
    // cout << tree.right->right->val << endl;

    int depth = maxDepth(&tree);
    cout << depth << endl;
    return 0;
}

/*


*/