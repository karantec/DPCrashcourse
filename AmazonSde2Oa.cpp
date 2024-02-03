//given an array pick any subset of number (minimum size 2);
// such that their goodness is maximized
//To go from x->y you need to pay |a[x]-a[y]|
// number can be positive as well as negative
//Brute force code
#include<bits/stdc++.h>
using namespace std;
// typedef long long int ll ;
int main(){
    int n;
    cin>>n;
    cout<<"Enter the array elements\n";
    int a[n+1] = {0};
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    //initialize the dp array with 0
    int dp[n+1]={0};
    // calculate the maximum goodness
    dp[1]=0;
    for(int i=0;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            int possibility=a[i]-a[j]+dp[j];
            dp[i]=max(possibility,dp[i]);
        }
    }
    // print the maximum goodness
    int r=0;
    for(int i=0;i<=n;i++){
        r=max(r,dp[i]);
    }
    cout<<r<<endl;

     
}

// Input:
// 5
// 5 10 1 5 100
//Output:
// 99