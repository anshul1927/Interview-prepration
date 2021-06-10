
// https://leetcode.com/problems/partition-list/
// lc 86

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
    ListNode *partition(ListNode *A, int B)
    {
        ListNode *s = new ListNode(0), *smaller = s, *g = new ListNode(0), *greater = g, *curr = A;
        int count = 0;
        while (A != nullptr)
        {
            if (A->val < B)
            {
                smaller->next = A;
                smaller = smaller->next;
            }
            else
            {
                greater->next = A;
                greater = greater->next;
            }
            A = A->next;
        }
        smaller->next = g->next;
        greater->next = nullptr;
        return s->next;
    }
};