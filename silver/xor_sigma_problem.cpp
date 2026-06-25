#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  int n;cin>>n;
  vector<ll> pf(n+1);
  for(int i=1;i<=n;i++){
    ll tmp;cin>>tmp;
    pf[i] = pf[i-1]^tmp;
  }
  //cerr<<"pf ";for(int num:pf) cerr<<num<<' ';
  ll ans=0;
  vector<ll> ones(32);
  for(int b=0;b<32;b++){
    for(int i=0;i<=n;i++){
      ones[b] += (pf[i]>>b)&1;
    }
    //cerr<<"b="<<b<<" ones="<<ones[b]<<"\n";
    ans += ones[b]*(n+1-ones[b])*(1<<b);
  }
  for(int i=1;i<=n;i++){
    ans-=(pf[i]^pf[i-1]);
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

