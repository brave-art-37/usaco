#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m;cin>>n>>m;
  vector<int> nos(n+1);
  vector<int> orig(n+1);
  for(int i=1;i<=n;i++) { cin>>nos[i]; orig[i]=nos[i]; }
  sort(nos.begin(),nos.end());
  int x=1,prep=0;
  while(x<n+1){
    if(prep+nos[x]<=m) prep+=nos[x], x++;
    else break;
  }
  x--;
  if(prep-nos[x]+orig[x+1]<=m) cout<<max(n-x,1)<<"\n";
  else cout<<n-x+1<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  cin >> t;
  while (t--){solve();}}

