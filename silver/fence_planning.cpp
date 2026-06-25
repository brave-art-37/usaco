#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1e5;
vector<vector<int>> adj(MAXN);
vector<int> visited(MAXN);
vector<int> x(MAXN);
vector<int> y(MAXN);

void dfs(int u, vector<int>& ans){
  visited[u]=1;
  ans[0]=max(ans[0],x[u]);
  ans[1]=min(ans[1],x[u]);
  ans[2]=max(ans[2],y[u]);
  ans[3]=min(ans[3],y[u]);
  for(int v:adj[u]){
    if(visited[v]) continue;
    dfs(v,ans);
  }
}

void solve(){
  int n,m;cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> ans={0,INT_MAX,0,INT_MAX};
  int mini=INT_MAX;
  for(int i=0;i<n;i++){
    if(visited[i]) continue;
    dfs(i,ans);
    mini=min(mini,2*(ans[0]+ans[2]-ans[1]-ans[3]));
    //cerr<<i<<"\n";
    //cerr<<"ans: ";for(int num:ans) cout<<num<<' ';cerr<<"\n";
    ans={0,INT_MAX,0,INT_MAX};
  }
  cout<<mini<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("fenceplan");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
