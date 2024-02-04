// You work as a consultant and have clients in cityA and cityB. On a given day,
// say i, you can either
// work in cityA and make Ai dollars or you can work in cityB and make Bi dollars. You can also spend
// the day traveling between cityA and cityB in which case your earnings that day are 0.

// Given Al,A2, ....An and B1, B2,....., Bn, return a schedule S of N days which maximizes your earnings,
// You can start either in cityA or cityB.

// You need to print the final maximum earning

// Example1: A = [23, 4,5 ,101] B = [21,1,10, 100] The optimal schedule S here would be ->"ATBB"
// Example 2:
// A[25,10,15,10,70] B = [5,5,50,5,30] The optimal schedule S here would be-> "ATBTA"

// Follow up :-> solve the problem for 3 cities A,B,C

// All dollars are positive!
//  understanding - you are given 2 array  travel from start to end;
// maximize the dollar whenever you try to jump from Array "A" 
// Array "B and" you can no money 
// you can jump from A to B or B to A

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll ;
ll dp[100005][2];
int main(){
  ll n;
    cin >> n;

    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(3, 0));
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
// dp[i][b] = max(b[i]+dp[i-1][b],b[i]+dp[i-2][a],b[i]+dp[i-2][c])

// dp[i][a] = max(DP[i-1][A], DP[i-2][B], DP[i-2][C]) + A[i])
// dp[i][c] = max(c[i]+dp[i-1][c],c[i]+dp[i-2][a],c[i]+dp[i-2][b])

    for (ll i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    ll max_earnings = max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]});
    cout << max_earnings << endl;
}

   