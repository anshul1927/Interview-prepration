// https://www.interviewbit.com/problems/painters-partition-problem/

#include <bits/stdc++.h>
using namespace std;

int mod = 10000003;
int isValid(int A, vector<int> &board, long long int mid)
{

    int painter = 1;
    long long int currTime = 0;
    for (auto it : board)
    {

        // cout << "currTime " << currTime << " it " << it << " mid " << mid << endl;
        if (currTime + it > mid)
        {
            painter++;
            currTime = it;
            // cout << "currTime " << currTime << endl;

            if (it > mid)
            {
                return false;
            }
            if (painter > A)
            {
                return false;
            }
        }
        else
        {
            currTime += it;
        }
    }
    // cout << painter << endl;
    return true;
}

int main()
{
    int A, B;
    cin >> A >> B;
    int N;
    cin >> N;

    vector<int> board(N);
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
    }

    long long int start = INT_MAX;
    long long int end = 0;
    long long int ans = 0;
    for (auto it : board)
    {
        start = min(start, (long long)it);
        end += it;
    }

    while (start <= end)
    {
        long long int mid = (start + (end - start) / 2);
        if (isValid(A, board, mid))
        {
            cout << "mid " << mid << endl;
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << (ans * B) % mod;
    return 0;
}