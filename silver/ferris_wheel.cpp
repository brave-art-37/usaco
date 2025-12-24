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
  ll x;cin>>x;
  vector<ll> wt;
  for(int i=0;i<n;i++){
    ll tmp;cin>>tmp;
    if(tmp>x) continue;
    wt.push_back(tmp);
  }
  n=wt.size();
  sort(wt.begin(),wt.end());
  int j=n-1, count=0;
  for(int i=0;i<n;i++){
    while(i<=j && wt[i]+wt[j]>x) count++, j--;
    if(i>j) break;
    if(wt[i]+wt[j]<=x) count++, j--;
  }
  cout<<count<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

