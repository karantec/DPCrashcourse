// Find the minimum cost to do this  : In one operation ; you must select two adjacent numbers ; 
// and merge them to 1 number ; the cost of doing so is the sum of both numbers ; do this till
//  the array has only 1 number left. Find the min cost to do please. 

// [5,5,8] = [10,8] = [18] = cost = 10 + 18 
// [5,5,8] = [5,13] = [18] = cost = 13 + 18 
#include <bits/stdc++.h>

using namespace std;
int b[200005];
int prefix[200005];

int sum(int i,int j){
    
    int TopG = prefix[j]-prefix[i-1]; 
    return (TopG);
    
}


int main() {
    
    
    int n ; 
    cin>>n ; //size of array 
  
    int i = 1 ; 
    while(i<=n){
        cin>>b[i] ; //taking input of array 
        prefix[i] = prefix[i-1] + b[i];
        i++;
    }
    
    //prefixsum array to quickly find out sum of numbers in range [i...j] in O(1)
    
    
    
    
    int dp[n+5][n+5];
    
    //calculating answers of all subarrays of length 1 
    
    i = 1 ; 
    while(i<=n){
        dp[i][i] = 0;
        i++;
    }
    
    //calculating answers of all subarrays of length 2 
    
    i = 1 ;
    while(i<=n-1){
        dp[i][i+1] = b[i] + b[i+1] ; 
        i++;
    }
    
    int length = 3 ; 
    while(length<=n){
        
        i = 1 ; 
        int j = i + length - 1 ; 
        
        while(j<=n){
            
            //dp[i][j]...calculate answer for subarray from i to j [i...j]
            
            int ii = INT_MAX ; 
            int k = i ; 
            while(k<=j-1){
                
                
                int possibility = dp[i][k] + dp[k+1][j] + sum(i,j);
                ii = min(possibility,ii);
                k++;
            }
            
            
            dp[i][j] = ii ; 
            
            
            i++;j++;
        }
        
        
        length++;
    }
    
    
    
    
    cout<<dp[1][n] ; 
    
    
    
    
    
    return 0 ; 
}
// t.C-0(n3)

/*
[1 2 3 4 5]

dp[1][5] = dp[1][1] +dp[2][5] + sum(1 to 5)
= dp[1][2]+dp[3][5] +sum(1 to 5)
= Dp(1-3)+dp(4-5)+sum(1-2-3-4-5)
= dp[1][4]+dp[5][5]+sum(1 to 5)


= min of all 4 ways .... 
*/

/*

4
5 8 2 10 


*/

/*
[1 2 3 4 5]

dp[1][5] = dp[1][1] +dp[2][5] + sum(1 to 5)
= dp[1][2]+dp[3][5] +sum(1 to 5)
= Dp(1-3)+dp(4-5)+sum(1-2-3-4-5)
= dp[1][4]+dp[5][5]+sum(1 to 5)


= min of all 4 ways .... 
*/

/*

4
5 8 2 10 


*/