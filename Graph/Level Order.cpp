#include <bits/stdc++.h>
using namespace std;

void dfs(TreeNode *A, vector<vector<int>> &ans, int level)
{
    if (A == NULL)
    {
        return;
    }
    if (ans.size() == level)
    {
        ans.push_back(vector<int>());
    }

    ans[level].push_back(A->val);

    dfs(A->left, ans, level + 1);
    dfs(A->right, ans, level + 1);
}

vector<vector<int>> Solution::levelOrder(TreeNode *A)
{

    vector<vector<int>> ans;

    dfs(A, ans, 0);
    return ans;
}