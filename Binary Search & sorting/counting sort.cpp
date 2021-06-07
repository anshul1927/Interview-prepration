#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxelement = *max_element(arr.begin(), arr.end());
    cout << maxelement << endl;

    vector<int> count(maxelement + 1, 0);

    for (auto it : arr)
    {
        count[it]++;
    }

    for (int i = 0; i < count.size(); i++)
    {
        if (count[i] > 0)
        {
            while (count[i]--)
                cout << i << " ";
        }
    }
    return 0;
}