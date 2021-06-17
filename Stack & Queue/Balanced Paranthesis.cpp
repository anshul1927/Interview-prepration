

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string s)
{
    stack<char> st;

    for (auto ch : s)
    {
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            st.push(ch);
            break;
        case ')':
            if (!st.empty() and st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        case '}':
            if (!st.empty() and st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!st.empty() and st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
            break;
        }
    }
    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin >> s;

    if (isBalanced(s))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not Balanced" << endl;
    }

    return 0;
}