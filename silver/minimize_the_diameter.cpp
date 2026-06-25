#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> adj1(n);
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj1[u].push_back(v);
    adj1[v].push_back(u);
  }
  int m;cin>>m;
  vector<vector<int>> adj2(m);
  for(int i=0;i<m-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj2[u].push_back(v);
    adj2[v].push_back(u);
  }

  stack<pair<int,int>> st;
  vector<int> vis(n);
  vector<int> dist(n);
  st.push({0,-1});
  while(!st.empty()){
    int node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]) continue;
    vis[node]=1;
    for(int child:adj1[node]){
      if(child==par) continue;
      dist[child]=dist[node]+1;
      st.push({child,node});
    }
  }
  int diam11=0;
  for(int i=0;i<n;i++){
    if(dist[diam11]<dist[i]) diam11=i;
  }
  fill(vis.begin(),vis.end(),0);
  fill(dist.begin(),dist.end(),0);
  st.push({diam11,-1});
  while(!st.empty()){
    int node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]) continue;
    vis[node]=1;
    for(int child:adj1[node]){
      if(child==par) continue;
      dist[child]=dist[node]+1;
      st.push({child,node});
    }
  }
  int diam12=diam11;
  for(int i=0;i<n;i++){
    if(dist[diam12]<dist[i]) diam12=i;
  }
  int diam1=dist[diam12];

  vis.resize(m);
  dist.resize(m);
  fill(vis.begin(),vis.end(),0);
  fill(dist.begin(),dist.end(),0);
  st.push({0,-1});
  while(!st.empty()){
    int node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]) continue;
    vis[node]=1;
    for(int child:adj2[node]){
      if(child==par) continue;
      dist[child]=dist[node]+1;
      st.push({child,node});
    }
  }
  int diam21=0;
  for(int i=0;i<m;i++){
    if(dist[diam21]<dist[i]) diam21=i;
  }
  fill(vis.begin(),vis.end(),0);
  fill(dist.begin(),dist.end(),0);
  st.push({diam21,-1});
  while(!st.empty()){
    int node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]) continue;
    vis[node]=1;
    for(int child:adj2[node]){
      if(child==par) continue;
      dist[child]=dist[node]+1;
      st.push({child,node});
    }
  }
  int diam22=diam21;
  for(int i=0;i<m;i++){
    if(dist[diam22]<dist[i]) diam22=i;
  }
  int diam2=dist[diam22];
  cout<<max({diam1, diam2, (diam1+1)/2+(diam2+1)/2+1})<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

