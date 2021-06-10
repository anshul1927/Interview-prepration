
// https://leetcode.com/problems/merge-in-between-linked-lists/
// lc 1669

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {

        ListNode *p = list1;

        int c = 1;
        for (int i = 1; i < a; i++)
        {
            p = p->next;
        }
        ListNode *q = p;
        for (int i = 0; i <= b - a; i++)
        {
            q = q->next;
        }

        p->next = list2;
        while (p->next != nullptr)
        {
            p = p->next;
        }

        p->next = q->next;
        q->next = nullptr;
        return list1;
    }
};