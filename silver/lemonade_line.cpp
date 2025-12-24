#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  sort(nos.begin(),nos.end(),greater<int>());
  vector<int> ans;
  for(int i=0;i<n;i++){
    if(ans.size()>nos[i]) continue;
    ans.push_back(nos[i]);
  }
  cout<<ans.size()<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("lemonade");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

