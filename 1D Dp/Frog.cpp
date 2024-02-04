// Time Limit: 2 sec/Memory Limit: 1024 MB

// Score: 100 points

// Problem Statement

// There are N stones, numbered 1, 2, N. For each i (1 ≤ i ≤N), the height of Stone i is hi

// There is a frog who is initially on Stone 1. He will repeat the following action some number of times to reach Stone N

// • If the frog is currently on Stone 2, jump to Stone i + 1 or Stone i + 2. Here, a cost of hij is incurred, where is the

// Find the minimum possible total cost incurred before the frog reaches Stone N.

// Constraints

// • All values in input are integers.

// • 2 ≤ N ≤105

// • 1 ≤ hi≤ 101


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 

int main() {
    ll n ; 
    cin>>n ; ll b[n+1] = {0};
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
        
        dp[i] = min(dp[i-1] + abs(b[i]-b[i-1]) ,dp[i-2] + abs(b[i]-b[i-2]));
        
        i++;
    }
    
    cout<<dp[n] ; 
    
    return 0 ; 
}