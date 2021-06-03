#include <bits/stdc++.h>
using namespace std;



int main() {

    int r, c;
    cin >> r >> c;

    int a[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }


    // int r1 = 0;
    // int c1 = c - 1;
    // int currmid = -1;
    // for (int i = c - 1; i >= 0; i--) {
    //     // cout << "i is " << i << endl;
    //     // cout << "c1 is " << c1 << endl;
    //     r1 = 0;
    //     while (r1 <= c1) {
    //         int mid = (r1 + c1) / 2;
    //         // cout << "mid is " << mid << " " << currmid << endl;
    //         if (a[i][mid] == 1) {
    //             currmid = mid;
    //             // cout <<"currmid "<< currmid << endl;
    //             c1 = mid - 1;
    //         } else if (a[i][mid] == 0) {
    //             r1 = mid + 1;
    //         }
    //     }
    //     if (currmid == -1) {
    //         // cout << "##\n";
    //         continue;
    //     }
    //     c1 = currmid-1;
    // }



    // another approach

    int j = r-1;
    int result = -1;
    for(int i = c-1; i>=0; i--){

        for(j ; j>=0; j--){
            if(a[i][j]==0){
                j = j;
                break;
            }
            else if(a[i][j]==1){
                result = j;
            }
        }
    }


    cout << result << endl;
    return 0;
}