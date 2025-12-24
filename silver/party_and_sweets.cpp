#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n,m;cin>>n>>m;
  ll sb=0, sg=0;
  ll maxi_b=0, second_maxi_b=0, mini_g=INT_MAX;
  set<ll> g;
  for(int i=0;i<n;i++){
    ll tmp;cin>>tmp;
    sb+=tmp;
    if(tmp>maxi_b){
      second_maxi_b=maxi_b;
      maxi_b=tmp;
    }
    else if(tmp>second_maxi_b){
      second_maxi_b=tmp;
    }
  }
  for(int i=0;i<m;i++){
    ll tmp;cin>>tmp;
    sg+=tmp;
    mini_g=min(mini_g,tmp);
    g.insert(tmp);
  }
  if(maxi_b>mini_g){
    cout<<"-1\n";
    return;
  }
  ll ans=m*(sb-maxi_b)+sg;
  if(!g.count(maxi_b)) ans+=(maxi_b-second_maxi_b);
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

