// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

 

// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 
 #include<bits/stdc++.h>
 typedef long long ll;
 using namespace std;
 int main(){

    string s;
    cout<<"Enter the string:";
    cin>>s;

    int n = s.size();
    
    int i, j,k;
    int count_pallindrome=0;

    i=0;
    while(i<n){
       int j=i;
        while(j<n){
          
          // i is the start point of substring 
          // j is the end point of substring
          int k=i;
          int c=0;
          int p=0;
          while(k<=j){
            if(s[k]==s[j-p]){
            }else{
              c=1;
            }
            p++;    
            k++;
             } 
            if(c==0){
                //t=yes pallindrome
                count_pallindrome++;
            }else{
                //no pallindrome
            }
            j++;
          }
          i++;
          
        }
    cout<<count_pallindrome<<endl;


    }

 