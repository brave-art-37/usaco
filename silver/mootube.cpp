#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=5000;
vector<vector<pair<int,int>>> adj(MAXN);
vector<vector<int>> dist(MAXN,vector<int>(MAXN,INT_MAX));

void dfs(int r, int s, int e){
  for(auto p:adj[s]){
    int v=p.first, w=p.second;
    if(v==e) continue;
    dist[r][v]=min(dist[r][s],w);
    dfs(r,v,s);
  }
}

void solve(){
  int n,q;cin>>n>>q;
  for(int i=0;i<n-1;i++){
    int u,v,w;cin>>u>>v>>w;u--,v--;
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  for(int i=0;i<n;i++){
    dfs(i,i,-1);
  }
  while(q--){
    int r,k;cin>>k>>r;r--;
    int cnt=0;
    for(int i=0;i<n;i++){
      if(i==r) continue;
      cnt+=(dist[r][i]>=k);
    }
    cout<<cnt<<"\n";
  }

  /*
  cerr<<"dist\n";
  for(int i=0;i<n;i++){
    cerr<<i<<"= ";
    for(int j=0;j<n;j++){
      cerr<<dist[i][j]<<' ';
    }
    cerr<<"\n";
  }
  */
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("mootube");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

