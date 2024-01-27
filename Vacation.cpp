// Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.
// The vacation consists of N days. For each i (1≤i≤N), Taro will choose one of the following activities and do it on the 
// i-th day:
// A: Swim in the sea. Gain ai points of happiness.
// B: Catch bugs in the mountains. Gain bi points of happiness.
// C: Do homework at home. Gain ci points of happiness.
// As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

// Find the maximum possible total points of happiness that Taro gains.


#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int n;
    cin >> n;
    cout<<"Enter the array elements";
     ll a[n+1];
     ll b[n+1];
     ll c[n+1];

 
    for (int i = 1; i <= n; ++i) {
        cin >>a[i]>>b[i]>>c[i];
    }                  
    //taken array input as
  //dp apprpach 
   //base case
  ll dpa[n+1]={0};
  ll dpb[n+2]={0};
  ll dpc[n+3]={0};

  dpa[1]=a[1];
  dpb[1]=b[1];
  dpc[1]=c[1];

  for(int i=2;i<=n;i++){
    dpa[i]=a[i]+max(dpb[i-1],dpc[i-1]);
    dpb[i]=b[i]+max(dpa[i-1],dpc[i-1]);
    dpc[i]=c[i]+max(dpa[i-1],dpb[i-1]);
  }

   cout<<max(dpa[n],max(dpb[n],dpc[n]))<<endl;

}
