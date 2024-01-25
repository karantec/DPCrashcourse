#include<bits/stdc++.h>
#include<vector>
using namespace std;
typedef long long int ll;

int main(){
  ll n;
  cout<<"Enter the number";
  cin>>n;
  ll a[n+1];
  cout<<"Enter the array elements";
  ll i=1;
  
  //array input
  while(i<=n){
    cin>>a[i];
    i++;
  }
  //dp apprpach 
  //create a dp array with all the values zeroes
   ll dp[n+1]={0};
   
   ll k=0;//max value to which it will be compared

   //base case
   dp[1]=max(a[1],k);
   dp[2]=max(a[2],max(a[1],k));

//calculating dp 
 i=3;
  while(i<=n){
    dp[i]=max(dp[i-1],a[i]+dp[i-2]);
    i++;
  }
  //calculating q queries
   cout<<dp[n];

}