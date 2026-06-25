#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  string s;cin>>s;
  map<ll,set<ll>> freq_parity_cnt_to_idx;
  ll freq_parity_cnt=0;
  ll n=s.size();
  freq_parity_cnt_to_idx[0].insert(0);
  for(int i=0;i<n;i++){
    freq_parity_cnt^=(1<<(s[i]-'0'));
    freq_parity_cnt_to_idx[freq_parity_cnt].insert(i+1); //one more idx with this parity_freq_cnt value
  }
  ll ans=0;
  for(auto p:freq_parity_cnt_to_idx){
    /*
    cerr<<p.first<<": ";
    for(auto tmp:p.second) cerr<<tmp<<' ';
    cerr<<"\n";
    */
    ll m = p.second.size();
    ans+=(m*(m-1))/2;
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
