

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int freq[27] = {0};
    queue<char> q;

    for (auto ch : s)
    {
        q.push(ch);
        freq[ch - 'a']++;
        while (!q.empty())
        {
            int idx = q.front() - 'a';
            if (freq[idx] > 1)
            {
                q.pop();
            }
            else
            {
                cout << q.front() << endl;
                break;
            }
        }
        if (q.empty())
        {
            cout << "-1" << endl;
        }
    }
}