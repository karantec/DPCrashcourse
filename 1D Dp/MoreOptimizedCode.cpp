
//given an array pick any subset of number (minimum size 2);
// such that their goodness is maximized
//To go from x->y you need to pay |a[x]-a[y]|
// number can be positive as well as negative
//Optimized Code
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int b[1001];
    int dp[1001] = {0};
    cout << "Enter the array elements\n";
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    dp[1] = 0;
    int mxv = dp[1] - b[1];

    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i], b[i] + mxv);
        mxv = max(mxv, dp[i] - b[i]);
    }

    int r = 0;
    for (int i = 1; i <= n; i++) {
        r = max(r, dp[i]);
    }

    cout << r << endl;

    return 0;
}
