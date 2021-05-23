// https://www.interviewbit.com/problems/max-min-05542f2f-69aa-4253-9cc7-84eb7bf739c4/

#include <bits/stdc++.h>
using namespace std;

int Solution::solve(vector<int> &A)
{
    return *min_element(A.begin(), A.end()) + *max_element(A.begin(), A.end());
}