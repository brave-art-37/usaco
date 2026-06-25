#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

bool dfs(int u, vector<vector<int>> &adj, vector<int> &color){
  bool error=0;
  for(int v:adj[u]){
    if(color[v]==color[u]) return 1;
    else if(color[v]!=-1) continue;
    color[v]=(3-color[u]);
    error|=dfs(v,adj,color);
  }
  return error;
}

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> color(n,-1);
  bool error=0;
  for(int i=0;i<n;i++){
    if(color[i]!=-1) continue;
    color[i]=1;
    error|=dfs(i,adj,color);
  }
  if(error) cout<<"IMPOSSIBLE";
  else for(int c:color) cout<<c<<' ';
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

