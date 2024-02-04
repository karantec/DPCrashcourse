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
 cin>>n;
 // declareing array with 1 based indexing 
    ll a[n+1] = {0};
    ll b[n+1]={0};
    for(int i=1;i<=n;i++ ){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    
    //intiatlizing dp array with 0
    dp[1][0]=a[1];
    dp[1][1]=b[1];
    // loop to calculate the maximum earning and since we find the value of  previous elem,ent so we start from value 2 index
    //0 means a and 1 means b
    for( ll i=2;i<=n;i++){
        dp[i][0]=max(dp[i-1][0] +a[i],dp[i-2][1]+a[i]);
        dp[i][1]=max(dp[i-1][1]+b[i],dp[i-2][0]+b[i]);
    }
    cout<<dp[n][0]<<" "<<dp[n][1]<<endl;
    }
    

    // Output
//     25 10 15 10 70
// 5 5 50 5 30
// 145 110