

#include <bits/stdc++.h>
using namespace std;

bool isRedundent(string s)
{
    stack<char> st;
    for (auto ch : s)
    {
        if (ch == ')' /*|| ch == '}' || ch == ']'*/)
        {
            bool flag = false;

            while (!st.empty() && (st.top() != '(' /*|| st.top() != '{' || st.top() != '['*/))
            {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    flag = true;
                st.pop();
            }
            st.pop();
            if (flag == false)
            {
                return true;
            }
        }
        else
        {
            st.push(ch);
        }
    }
    return false;
}
int main()
{
    string s;
    cin >> s;

    if (isRedundent(s))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}