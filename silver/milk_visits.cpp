#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1e3;
int n,m; string st;
vector<vector<int>> adj(MAXN);

bool cant(int s, int e, int t, char c, int step){
  //cerr<<s+1<<' '<<t+1<<"\n";
  if(st[s]==c || st[t]==c) return 0;
  else if(s==t) return 1;
  bool ans=0;
  for(int v:adj[s]){
    if(v==e || st[v]==c) continue;
    ans|=cant(v,s,t,c,step+1);
  }
  return ans;
}

void solve(){
  cin>>n>>m>>st;
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  string ans="";
  for(int i=0;i<m;i++){
    int a,b;char c;cin>>a>>b>>c;a--,b--;
    if(cant(a,-1,b,c,1)) ans+='0';
    else ans+='1';
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("milkvisits");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
