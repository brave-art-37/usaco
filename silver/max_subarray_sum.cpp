#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<ll> nos(n+1);
  vector<ll> pf(n+1);
  vector<ll> mini(n+1);
  for(int i=1;i<=n;i++){
    cin>>nos[i];
    pf[i]=pf[i-1]+nos[i];
    mini[i]=min(mini[i-1],pf[i-1]);
  }
  ll ans=nos[1];
  for(int i=1;i<=n;i++){
    ans=max(ans,pf[i]-mini[i]);
  }
  cout<<ans<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
