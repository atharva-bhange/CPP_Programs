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

vector<int> riverSizes(vector<vector<int>> matrix)
{
    int count;
    int rows = matrix.size();
    int cols;
    vector<vector<bool>> isVisited;
    queue<vector<int>> neighbours;
    vector<int> ans;
    for (int i = 0; i < rows; i++)
    {
        vector<bool> row;
        cols = matrix[i].size();
        for (int j = 0; j < cols; j++)
        {
            row.push_back(false);
        }
        isVisited.push_back(row);
    }
    for (int i = 0; i < rows; i++)
    {
        cols = matrix[i].size();
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 1 && !isVisited[i][j])
            {
                //cout << "Going into if with " << i << j << endl;
                count = 0;
                neighbours.push(vector<int>{i, j});
                while (!neighbours.empty())
                {
                    //cout << "Going into while" << endl;
                    vector<int> current = neighbours.front();
                    neighbours.pop();
                    if (isVisited[current[0]][current[1]])
                        continue;
                    //cout << "Current " << current[0] << current[1] << endl;
                    if (current[0] - 1 >= 0)
                    {

                        if (!isVisited[current[0] - 1][current[1]] && matrix[current[0] - 1][current[1]] == 1)
                        {
                            //cout << "up" << endl;
                            neighbours.push(vector<int>{current[0] - 1, current[1]});
                        }
                    }
                    if (current[1] + 1 < cols)
                    {

                        if (!isVisited[current[0]][current[1] + 1] && matrix[current[0]][current[1] + 1] == 1)
                        {
                            //cout << "right" << endl;
                            neighbours.push(vector<int>{current[0], current[1] + 1});
                        }
                    }
                    if (current[0] + 1 < rows)
                    {

                        if (!isVisited[current[0] + 1][current[1]] && matrix[current[0] + 1][current[1]] == 1)
                        {
                            //cout << "down" << endl;
                            neighbours.push(vector<int>{current[0] + 1, current[1]});
                        }
                    }
                    if (current[1] - 1 >= 0)
                    {

                        if (!isVisited[current[0]][current[1] - 1] && matrix[current[0]][current[1] - 1] == 1)
                        {
                            //cout << "left" << endl;
                            neighbours.push(vector<int>{current[0], current[1] - 1});
                        }
                    }
                    isVisited[current[0]][current[1]] = true;
                    count++;
                }
                //cout << "Count " << count << endl;
                ans.push_back(count);
            }
        }
    }
    //printV(ans);
    return ans;
}

int main(void)
{
    vector<vector<int>> mat{
        {
            1,
            1,
        },
        {
            1,
            1,
        }};

    vector<int> a = riverSizes(mat);
    printV(a);
    return 0;
}