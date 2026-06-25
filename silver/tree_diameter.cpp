#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> adj(n);
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> dist(n);
  vector<int> vis(n);
  stack<pair<int,int>> st;
  st.push({0,-1});
  while(!st.empty()){
    int s=st.top().first, e=st.top().second;st.pop();
    if(vis[s]) continue;
    vis[s]=1;
    for(int v:adj[s]){
      if(v==e) continue;
      dist[v]=dist[s]+1;
      st.push({v,s});
    }
  }
  int diam1=0;
  for(int i=0;i<n;i++){
    if(dist[diam1]<dist[i]) diam1=i;
  }
  fill(vis.begin(),vis.end(),0);
  fill(dist.begin(),dist.end(),0);
  st.push({diam1,-1});
  while(!st.empty()){
    int s=st.top().first, e=st.top().second;st.pop();
    if(vis[s]) continue;
    vis[s]=1;
    for(int v:adj[s]){
      if(v==e) continue;
      dist[v]=dist[s]+1;
      st.push({v,s});
    }
  }
  int diam2=diam1;
  for(int i=0;i<n;i++){
    if(dist[diam2]<dist[i]) diam2=i;
  }
  cout<<dist[diam2]<<"\n";
  //cerr<<diam1<<' '<<diam2<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

