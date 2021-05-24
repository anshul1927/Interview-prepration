// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/
// lc 1379

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode *ans;
    void getNode(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        if (original != NULL)
        {
            getNode(original->left, cloned->left, target);
            if (original == target)
            {
                ans = cloned;
            }
            getNode(original->right, cloned->right, target);
        }
    }
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {

        getNode(original, cloned, target);
        return ans;
    }
};