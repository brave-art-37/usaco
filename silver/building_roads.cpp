#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void dfs(int u, int n, vector<vector<int>> &adj, vector<int> &visited){
  for(int v:adj[u]){
    if(visited[v]) continue;
    visited[v]=1;
    dfs(v, n, adj, visited);
  }
}

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int count=0;
  int last=(-1);
  vector<int> visited(n);
  vector<pair<int,int>> ans;
  for(int i=0;i<n;i++){
    if(visited[i]) continue;
    count++;
    if(last!=-1) ans.push_back({last+1,i+1});
    last=i;
    visited[i]=1;
    dfs(i, n, adj, visited);
  }
  cout<<count-1<<"\n";
  for(auto p:ans) cout<<p.first<<' '<<p.second<<"\n";
}


void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

