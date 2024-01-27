#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    cout<<"Enter the array elements";
    vector<int> cost(n + 1);
    //initialize dp array with all zeroes
    vector<int> dp(n + 1, 0);
 
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }                    //1  2  3  4  5 6
                         //4 12 13 18 10 12
    //taken array input as
  //dp apprpach 
   //base case
   dp[1]=0; //as we are starting from 1
   dp[2]=abs(cost[2]-cost[1]); // 12 -4=8
   dp[3]=dp[2] + abs(cost[3]-cost[2]);//8+(13-12)=8+1=9
   

for(int i=4;i<=n;i++){
            // min // 18-13+9 =14, 18-4+0=14)
            //calculating till we can fine minimum cost
    dp[i] = min(abs(cost[i] - cost[i - 1]) + dp[i - 1], abs(cost[i] - cost[i - 3]) + dp[i - 3]);
    cout<<dp[i]<<" ";
}
//calculating dp 

  //calculating q queries
   cout<<dp[n]<<endl;

}