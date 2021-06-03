// https://leetcode.com/problems/maximum-depth-of-binary-tree/
// lc 104

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
class Solution {
public:

    int solve(TreeNode* root){
        
        if(root==NULL){
            return 0;
        }
        
        int left = 0;
        int right = 0;
        
        // if(root->left!=NULL)
            left = solve(root->left);
        
        // if(root->right!=NULL)
            right = solve(root->right);
        return max(left, right)+1;
    }
    
    int maxDepth(TreeNode* root) {
        
        
        if(root==NULL){
            return 0;
        }
        // if(root->left==NULL && root->right==NULL){
        //     return 1;
        // }
        return solve(root);
    }
};