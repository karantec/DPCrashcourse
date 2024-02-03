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
    int v[1001] = {0};
    cout<<"Enter the array elements\n";
    for(int i=1;i<=n;i++){
    	cin>>b[i];
    }
 
 
 
    dp[1] = 0;
    v[1] = dp[1] - b[1];
    int mxv = v[1];
 
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i],b[i] + mxv);
        v[i] = dp[i] - b[i];
        mxv = max(mxv, v[i]);
    }
 
    int r = 0;
    for (int i = 1; i <= n; i++) {
        r = max(r, dp[i]);
    }
 
    cout << r << endl;
 
    return 0;
}
// Output:
// 5
// 5 10 1 5 100
// 99


// T.C- O(N);
// S.C-(N+N).  

