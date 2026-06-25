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
  vector<int> down1(n);
  vector<int> down2(n);
  vector<int> down_child(n,-1);
  vector<int> up(n);

  //dfs1
  stack<pair<int,int>> st;
  vector<int> vis(n);
  st.push({0,-1});
  while(!st.empty()){
    int node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]==2) continue;
    else if(vis[node]==1){
      vis[node]=2;
      for(int child:adj[node]){
        if(child==par) continue;
        if(down1[child]+1>=down1[node]){
          down2[node]=down1[node];
          down1[node]=down1[child]+1;
          down_child[node]=child;
        }
        else if(down1[child]+1>=down2[node]) down2[node]=down1[child]+1;
      }
    }
    else{
      vis[node]=1;
      st.push({node,par});
      for(int child:adj[node]) {
        if(child==par) continue;
        st.push({child,node});
      }
    }
  }

  //df2
  fill(vis.begin(),vis.end(),0);
  st.push({0,-1});
  while(!st.empty()){
    int node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]==1) continue;
    vis[node]=1;
    for(int child:adj[node]){
      if(child==par) continue;
      up[child]=max(up[child],up[node]+1);
      if(down_child[node]!=child) up[child]=max(up[child],down1[node]+1);
      else up[child]=max(up[child],down2[node]+1);
      st.push({child,node});
    }
  }

  vector<int> path_begin(n);
  for(int i=0;i<n;i++){
    path_begin[i]=max(down1[i],up[i]);
  }
  for(int num:path_begin) cout<<num<<' ';
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

