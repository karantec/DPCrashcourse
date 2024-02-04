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
 
//  dp[i......j] =true if s[i]==s[j] is pallindrom
//   and dp[i+1......j-1] is false 
//   s[i------j] is not pallindrome
 #include<bits/stdc++.h>
 typedef long long ll;

 using namespace std;
 int main() {
    string s;
    cout << "Enter the string:";
    cin >> s;
    int n = s.size();
    int length_pallindrome = 0;

    // Initializing dp array with 0 for max value of string
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Single characters are always palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
        length_pallindrome=1;
    }

    // Checking palindromes of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            length_pallindrome=2;
        }
    }

    // Checking palindromes of length greater than 2
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                length_pallindrome=length;//j-i+1
            }
        }
    }

    cout << length_pallindrome << endl;

    return 0;
}
 