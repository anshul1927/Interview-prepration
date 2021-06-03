#include <bits/stdc++.h>
using namespace std;



int main() {

    int n;
    cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cow;
    cin >> cow;

    sort(a,a+n);

    int low = 0;
    int high = a[n - 1];

    int gap = 0;
    int mid = 0;
    while (low <= high) {
        mid = (low+high+1)/2;
        int t=0;
        int c = 1;
        for (int j = 1; j < n && c<cow; j++) {
            if ((a[j] - a[t]) >= mid) {
                c++;
                t = j;
            }
        }
        if (cow <= c) {
            gap = mid;
            low = mid+1;
        } else {
            high = mid - 1;
        }
    }

    cout<<gap;
    return 0;
}