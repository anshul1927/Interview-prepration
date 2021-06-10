
// https://leetcode.com/problems/next-greater-node-in-linked-list/
// lc 1019

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {

        vector<int> ans, s;
        while (head != nullptr)
        {
            ans.push_back(head->val);
            head = head->next;
        }

        for (int i = ans.size() - 1; i >= 0; i--)
        {
            int val = ans[i];
            while (!s.empty() && s.back() <= val)
                s.pop_back();
            ans[i] = s.empty() ? 0 : s.back();
            s.push_back(val);
        }

        return ans;
    }
};