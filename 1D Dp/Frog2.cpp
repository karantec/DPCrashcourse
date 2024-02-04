// B-Frog 2

// Editorial

// Time Limit: 2 sec/Memory Limit: 1024 MB

// Score: 100 points

// Problem Statement

// There are N stones, numbered 1, 2,..., N. For each i (1\le i\le N) the height of Stone i is h_{i}

// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N:

// • If the frog is currently on Stone i, jump to one of the following: Stone i+1,i+2,...,i+K Here, a cost of |h_{i}-h_{j}|| incurred, where j is t stone to land on.

// Find the minimum possible total cost incurred before the frog reaches Stone N.

// Constraints

// • All values in input are integers.

// 2<N<10^{5}

// 1\le K\le100

// • 1<h<10^{4}



#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ; 

int main() {
    ll n ; 
    ll k ;
    
    cin>>n>>k ; ll b[n+1] = {0};
    ll i = 1 ; 
    while(i<=n){
        cin>>b[i] ; 
        i++;
    }
    
    
    ll dp[n+1] = {0};
    
    dp[1] = 0 ; 
    dp[2] = abs(b[1]-b[2]);
    i = 3 ; 
    while(i<=n){
         ll answer = 1e18 ; 
        ll j = 1 ; 
        while(j<=k && i-j>=1){
            ll yy = dp[i-j] + abs(b[i]-b[i-j]);
            //cout<<yy<<"\n";
            answer = min(answer,yy);
            j++;
        }
        dp[i] = answer ; 
        //cout<<dp[i]<<" ";cout<<'\n';
        i++;
    }
    
    cout<<dp[n] ; 
    
    return 0 ; 
}