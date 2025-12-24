#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<pair<ll,ll>> data(n);
  for(int i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    data[i]={x-y,x+y};
  }
  sort(data.begin(),data.end());
  ll right=data[0].second;
  ll count=0;
  for(int i=1;i<n;i++){
    count+=(data[i].second<=right);
    right=max(right,data[i].second);
  }
  cout<<(n-count)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("mountains");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

