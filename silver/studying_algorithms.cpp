#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,k;cin>>n>>k;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  vector<int> pf(n);
  for(int i=0;i<n;i++){
    pf[i]+=nos[i];
    if(i==0) continue;
    pf[i]+=pf[i-1];
  }
  auto it=upper_bound(pf.begin(),pf.end(),k);
  cout<<(it-pf.begin())<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

