
// https://leetcode.com/problems/swap-nodes-in-pairs/
// lc 24

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
    ListNode *swapPairs(ListNode *A)
    {

        if (A == nullptr)
        {
            return nullptr;
        }

        ListNode *prev = nullptr, *curr = A, *nxt;
        int t = 2;

        while (curr != nullptr && t--)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        if (nxt != nullptr)
        {
            A->next = swapPairs(nxt);
        }

        return prev;
    }
};