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
  vector<ll> pf(n+1);
  vector< pair<pair<ll,ll>,ll> > cnt(m);
  for(int i=0;i<m;i++){
    cin>>cnt[i].first.first>>cnt[i].first.second>>cnt[i].second;
    pf[cnt[i].first.second]=pf[cnt[i].first.first-1]+cnt[i].second;
  }
  int valid=1;
  for(int i=0;i<m;i++){
    valid&=( (pf[cnt[i].first.second]-pf[cnt[i].first.first-1]-cnt[i].second)==0LL  );
  }
  if(valid){
    cout<<"YES\n";
    for(int i=0;i<n;i++){
      cout<<pf[i+1]-pf[i]<<" ";
    }
  }
  else{
    cout<<"NO\n";
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

