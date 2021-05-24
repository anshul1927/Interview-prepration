// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// lc 515

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{

public:
    void solve(TreeNode *root, int row, vector<int> &ans)
    {

        if (root == NULL)
        {
            return;
        }

        if (row < ans.size())
        {
            ans[row] = max(ans[row], root->val);
        }
        else
        {
            ans.push_back(root->val);
        }

        solve(root->left, row + 1, ans);
        solve(root->right, row + 1, ans);
    }

    vector<int> largestValues(TreeNode *root)
    {
        vector<int> ans;

        if (root == NULL)
        {
            return ans;
        }
        solve(root, 0, ans);
        return ans;
    }
    // private:
    //     vector<int> ans;
    // public:
    //     std::queue<TreeNode*> q;
    //     vector<int> largestValues(TreeNode* root) {

    //         if(root==NULL){
    //             return {};
    //         }
    //         q.push(root);

    //         int index = 0;
    //         while(!q.empty()){

    //             int m = INT_MIN;

    //             int s = q.size();
    //             while(s--){

    //                             TreeNode *node = q.front();
    //                             m = max(m, node->val);
    //             // int wt = q.front().second;
    //             q.pop();

    //             if(node->left!=NULL){
    //                 q.push(node->left);
    //             }
    //             if(node->right!=NULL){
    //                 q.push(node->right);
    //             }

    //             // ans[wt] = max(node->val,ans[wt]);
    //             }
    //                         ans.push_back(m);
    //         }

    // //         vector<int> final;

    // //         for(int i=0;i<=index;i++){
    // //                 final.push_back(ans[i]);
    // //         }
    //         return ans;
    //     }
};