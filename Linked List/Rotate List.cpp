
// https://leetcode.com/problems/rotate-list/
// lc 61

// ----------------------------------------------------------------

// length of linked list % B use this

// ----------------------------------------------------------------
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
    ListNode *rotateRight(ListNode *A, int B)
    {
        if (A == nullptr)
        {
            return A;
        }

        ListNode *t, *newHead;
        t = newHead = A;
        int len = 1;
        while (t->next != nullptr)
        {
            len++;
            t = t->next;
        }

        t->next = A;
        if (B %= len)
        {
            for (int i = 0; i < len - B; i++)
            {
                t = t->next;
            }
        }
        newHead = t->next;
        t->next = nullptr;
        return newHead;

        //     // cout<<len;
        //     B%=len;
        //     if(B==0){
        //         return A;
        //     }

        //     ListNode* rev = reverse(A);
        //     ListNode* first = rev;
        //     int count = 1;

        //     while(rev && count!=B){
        //         rev = rev->next;
        //         count++;
        //     }

        //     ListNode* second = rev->next;
        //     rev->next = nullptr;

        //     ListNode* first1 = reverse(first);
        //     second = reverse(second);

        //     // ListNode* itr = first;

        //     first->next = second;
        //     return first1;
    }
};