#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1e5;
vector<vector<int>> adj(MAXN);
vector<vector<int>> adj_rev(MAXN);
vector<int> can_reach(MAXN);
vector<int> can_reach_rev(MAXN);

void dfs(int u){
  can_reach[u]=1;
  for(int v:adj[u]){
    if(can_reach[v]) continue;
    dfs(v);
  }
}

void dfs_rev(int u){
  can_reach_rev[u]=1;
  for(int v:adj_rev[u]){
    if(can_reach_rev[v]) continue;
    dfs_rev(v);
  }
}

void solve(){
  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj_rev[v].push_back(u);
  }
  dfs(0);
  dfs_rev(1);
  for(int i=0;i<n;i++){
    if(can_reach[i]) continue;
    cout<<"NO\n";
    cout<<1<<' '<<i+1<<"\n";
    exit(0);
  }
  for(int i=0;i<n;i++){
    if(can_reach_rev[i]) continue;
    cout<<"NO\n";
    cout<<i+1<<' '<<1<<"\n";
    exit(0);
  }
  cout<<"YES\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
