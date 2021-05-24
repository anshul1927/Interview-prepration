#include <bits/stdc++.h>
using namespace std;

string multiple(int A)
{

    if (A == 1)
        return "1";
    vector<int> p(A, -1);
    vector<int> s(A, -1);

    int step[2] = {0, 1};

    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == 0)
            break;
        for (auto el : step)
        {
            int next = (curr * 10 + el) % A;
            if (p[next] == -1)
            {
                p[next] = curr;
                s[next] = el;
                q.push(next);
            }
        }
    }

    string ans;

    for (int i = 0; i != 1; i = p[i])
    {
        ans.push_back('0' + s[i]);
    }
    ans.push_back('1');

    return string(ans.rbegin(), ans.rend());
}

int main()
{
    int n;

    cin >> n;
    string ans = "";
    ans = multiple(n);
    cout << ans << endl;
    return 0;
}