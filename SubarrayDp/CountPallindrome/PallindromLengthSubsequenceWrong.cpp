// Recursive APproacha
// #include <iostream>
// #include <string>

// using namespace std;

// // Function to return the total palindromic subsequence
// int Solve(string str, int i, int j) {
// 	if (i == j) // Base case: when the indices are the same, there is one palindrome
// 		return 1;

// 	if (i > j) // Base case: when the first index is greater than the second, there are no palindromes
// 		return 0;

// 	if (str[i] == str[j]) {
// 		// If the characters at indices i and j are the same, we can form palindromic subsequences
// 		// by including or excluding both characters, so we add 1 and make recursive calls.
// 		return 1 + Solve(str, i + 1, j) + Solve(str, i, j - 1);
// 	} else {
// 		// If the characters at indices i and j are different, we exclude one of them and make recursive calls.
// 		return Solve(str, i + 1, j) + Solve(str, i, j - 1) - Solve(str, i + 1, j - 1);
// 	}
// }

// // Driver program
// int main() {
// 	string str = "abbaxyz";
// 	cout << "Total palindromic subsequence are: " << Solve(str, 0, str.length() - 1) << endl;
// 	return 0;
// }
// C++ program to counts Palindromic Subsequence
// in a given String using recursion

// Dp approach
// #include <bits/stdc++.h>
// using namespace std;

// int n, dp[1000][1000];
// string str = "abcb";

// // Function return the total
// // palindromic subsequence
// int countPS(int i, int j)
// {

// 	if (i > j)
// 		return 0;

// 	if (dp[i][j] != -1)
// 		return dp[i][j];

// 	if (i == j)
// 		return dp[i][j] = 1;

// 	else if (str[i] == str[j])
// 		return dp[i][j]
// 			= countPS(i + 1, j) + 
// 				countPS(i, j - 1) + 1;

// 	else
// 		return dp[i][j] = countPS(i + 1, j) +
// 						countPS(i, j - 1) -
// 						countPS(i + 1, j - 1);
// }

// // Driver code
// int main()
// {
// 	memset(dp, -1, sizeof(dp));
// 	n = str.size();
// 	cout << "Total palindromic subsequence are : "
// 		<< countPS(0, n - 1) << endl;
// 	return 0;
// }

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string s;
    cout << "Enter the string:";
    cin >> s;
    int n = s.size();
    
    // Initializing dp array with 0 for max value of string
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Single characters are always palindromes
    for (int i = 0; i < n; ++i) {
        dp[i][i] = 1;
    }

    // Checking palindromes of length 2
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 3;
        } else {
            dp[i][i + 1] = 2;
        }
    }

    // Checking palindromes of length greater than 2
    for (int length = 3; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1] + dp[i + 1][j] -dp[i+1][j-1];
            } else {
                dp[i][j] = 1+ dp[i][j-1]+dp[i+1][j];
            }
        }
    }

    cout << dp[0][n - 1] << endl;

    return 0;
}
