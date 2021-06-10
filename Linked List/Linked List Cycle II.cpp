
// https://leetcode.com/problems/linked-list-cycle-ii/
// lc 142

#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *A)
    {
        if (A == nullptr or A->next == nullptr)
        {
            return nullptr;
        }

        ListNode *slow = A;
        ListNode *fast = A;

        while (fast != nullptr and fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                break;
            }
        }
        // cout<<"##"<<endl;
        if (slow == fast)
        {

            slow = A;
            int id = 0;
            while (slow != fast)
            {
                id++;
                slow = slow->next;
                fast = fast->next;
            }
            //     cout<<"##"<<endl;
            // cout<<slow->val<<endl;
            cout << id;
            return slow;
        }
        else
        {
            return nullptr;
        }
    }
};