
// https://leetcode.com/problems/reverse-linked-list-ii/
// lc 92

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
    ListNode *reverseBetween(ListNode *A, int B, int C)
    {
        if (C == B)
        {
            return A;
        }
        ListNode *p = A, *last = p;
        for (int i = 1; i < B; i++)
        {
            last = p;
            p = p->next;
        }
        // cout<<last->val<<endl;
        // cout<<p->val;
        // cout<<endl<<p->next->val<<endl;
        ListNode *prev = NULL, *curr = p, *nxt, *head;
        int t = C - B + 1;
        for (int i = 0; i < t; i++)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // cout<<p->val<<" "<<last->val<<endl;
        if (last->next == NULL && curr == NULL)
        {
            return prev;
        }
        else if (last->next == NULL && curr != NULL)
        {
            last->next = curr;
            return prev;
        }
        p->next = curr;
        last->next = prev;
        // cout<<endl<<" ## ";
        // cout<<last->val;
        // cout<<endl<<" ##";
        return A;
    }
};