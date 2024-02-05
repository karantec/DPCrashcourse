// Given a string s=s_{1}s_{2}...s_{|s|} of length |s|, consisting of lowercase English letters.
//  There are q queries, each described by two integers l_{i},r_{i}(1\le l_{i}\le r_{i}\le|s|). 
//  The answer to each query is the number of palindromic substrings in the string s[l_{i}...r_{i}].

// A substring s[l...r]=s_{l}s_{l+1}...s_{r}(1\le l\le r\le|s|) of string s=s_{1}s_{2}...s_{\sqrt{s}} defined as the sequence of characters from index I to index r, inclusive.

// A string t is considered a palindrome if it reads the same from left to right and from right to left. Formally, t=t_{1}t_{2}...t_{|t|}=t_{|t|}t_{|t|}...t_{1}

// TechNews

// Work Life Balan

// Interview-Expe

// CTC (compensa

// Tutorials Roadr

// Input:

// The first line contains a string s (1≤8 ≤5000).

// The second line contains a single integer q(1\le q<10^{6}), representing the number of queries.

// Each of the next q lines contains two integers l_{i},r_{i}(1\le l_{i}\le r_{i}\le|s|).
//Small case to solve it

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll ; 
// 1 letter is also called as palindrome
int dp[5000][5000]; 
int dp1[5000][5000];
int main() {
    string s ; 
    cin>>s ; 
    int n = s.size();
    int i,j,k ; 
    
    //length 1 string
    i = 0 ; int g = 0 ; 
    while(i<n){
        dp[i][i] = 1 ; //true-->1 
        dp1[i][i] = 1 ;  
        i++;
    }
    
    //length 2 string 
    i = 0 ; 
    while(i<n-1){
        
        if(s[i]==s[i+1]){
            dp[i][i+1] = 1 ; 
        }
        
        dp1[i][i+1] = dp1[i][i] + dp1[i+1][i+1] + dp[i][i+1];
        
        i++;
    }
    
    //length 3 ; length 4 ; length 5...length n 
    cout<<dp1[0][1];
    cout<<'\n';
    
    ll length = 3 ; 
    while(length<=n){
        i = 0 ; 
        while(i<n-length+1){
            ll j = i + length - 1 ; 
            
            if(s[i]==s[j] && dp[i+1][j-1]==1){
                dp[i][j] = 1 ; 
                //j-i+1..... 
            }
            dp1[i][j] = dp1[i][j-1] + dp1[i+1][j] - dp1[i+1][j-1] + dp[i][j] ; 
            
            i++;
        }
        length++;
    }
    //cout<<dp[1][2];
    //cout<<'\n';
    int q ; 
    cin>>q ; 
    for(int i=0;i<q;i++){
    	int l,r ; 
    	cin>>l>>r ; 
    	
    	cout<<dp1[l][r];
    	cout<<'\n';
    }
    
    //cout<<g ; 
    
    
    return 0 ; 
}