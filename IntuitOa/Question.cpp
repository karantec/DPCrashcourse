#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    // Assuming 'b' is a 2D array representing the input values for each position
    int b[1001][1001];
    cout << "Enter the values for array b:" << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
        }
    }

    // Initialize dp array
    int dp[1001][1001];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int id = i - 1;
            int v = 0;

            while (id >= 1) {
                v = max(v, dp[id][j] + b[i][j] - b[id][j]);
                id--;
            }

            id = j - 1;
            while (id >= 1) {
                v = max(v, dp[i][id] + b[i][j] - b[i][id]);
                id--;
            }

            dp[i][j] = v;
        }
    }

    // Find the maximum value in dp array
    int answer = dp[1][1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer << endl;

    return 0;
}
// 4 4 
// 1 2 13 0 
// 15 26 7 48
// 99 86 11 12
// 92 89 0 99 
// Enter the values for array b:
// 99