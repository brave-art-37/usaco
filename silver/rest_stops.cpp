#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll l,n,a,b;cin>>l>>n>>a>>b;
  ll speed=(a-b);
  vector<pair<ll,ll>> nos(n);
  vector<int> msf(n);
  for(int i=0;i<n;i++) cin>>nos[i].first>>nos[i].second;
  for(int i=n-1;i>-1;i--){
    msf[i]=nos[i].second;
    if(i<n-1) msf[i]=max(msf[i],msf[i+1]);
  }
  ll curr=0, total=0;
  for(int i=0;i<n;i++){
    curr+=nos[i].first*speed;
    if(i>0) curr-=nos[i-1].first*speed;
    if(nos[i].second<msf[i]) continue;
    total+=curr*nos[i].second;
    curr=0;
  }
  cout<<total<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("reststops");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

