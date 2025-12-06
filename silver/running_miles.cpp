#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> nos(n+1);
  for(int i=1;i<=n;i++){
    cin>>nos[i];
  }
  vector<int> pf(n+1);
  vector<int> sf(n+1);
  pf[0]=nos[1];
  sf[n]=nos[n]-n;
  for(int i=1;i<=n;i++){
    pf[i]=max(pf[i-1],nos[i]+i);
  }
  for(int i=n-1;i>-1;i--){
    sf[i]=max(sf[i+1],nos[i+1]-(i+1));
  }
  int maxi;
  for(int i=2;i<n;i++){
    if(i==2) maxi=nos[i]+pf[i-1]+sf[i];
    else maxi=max(maxi,nos[i]+pf[i-1]+sf[i]);
  }
  cout<<maxi<<"\n";
  /*for(int num:pf){cout<<num<<' ';}cout<<"\n";
  for(int num:sf){cout<<num<<' ';}cout<<"\n";*/
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  cin >> t;

  while (t--){solve();}
}

