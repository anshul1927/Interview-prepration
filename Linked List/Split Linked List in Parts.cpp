
// https://leetcode.com/problems/split-linked-list-in-parts/
// lc725

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
    vector<ListNode *> splitListToParts(ListNode *root, int k)
    {

        int len = 0;
        ListNode *p = root;

        while (p != nullptr)
        {
            p = p->next;
            len++;
        }

        int total_nodes = len / k;
        int first = len % k;
        cout << first << endl;
        ListNode *curr = root;
        vector<ListNode *> ans;
        while (first--)
        {
            ans.push_back(curr);
            int t = total_nodes;
            while (t--)
            {
                curr = curr->next;
            }
            ListNode *temp = curr;
            curr = curr->next;
            temp->next = nullptr;
        }

        int rem = k - len % k;
        if (curr == nullptr && rem > 0)
        {
            while (rem--)
            {
                ans.push_back(nullptr);
            }
            return ans;
        }
        else
        {
            cout << rem << endl;
            while (rem--)
            {
                ans.push_back(curr);
                int t = total_nodes - 1;
                while (t--)
                {
                    curr = curr->next;
                }
                if (curr->next == nullptr)
                {
                    break;
                }
                ListNode *temp = curr;
                curr = curr->next;
                temp->next = nullptr;
            }

            return ans;
        }
    }
};