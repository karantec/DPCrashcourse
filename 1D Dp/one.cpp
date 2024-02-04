#include<bits/stdc++.h>
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
   //base case
   dp[1]=a[i];
   dp[2]=a[1]+a[2];
//calculating dp 
 i=3;
  while(i<=n){
    dp[i]=dp[i-1]+a[i];
    i++;
  }
  //calculating q queries
  ll q;
  cout<<"Taking Query of number";
  cin>>q;
  i=1;
  while(i<=q){
    
    ll index;
    cout<<"Calculating till index";
    cin>> index;
    cout<<dp[index];
    cout<<"\n";
    i++;
  }



}