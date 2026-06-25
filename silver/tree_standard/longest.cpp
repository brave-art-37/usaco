#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=10;
vector<vector<int>> adj(MAXN);

vector<int> down1(MAXN);
vector<int> down2(MAXN);
vector<int> down_child(MAXN,-1);
vector<int> up(MAXN);

//path thru child, bottom up dp
void dfs1(int node, int par){
  for(int child:adj[node]){
    if(child==par) continue;
    dfs1(child,node);
    if(down1[child]+1>=down1[node]){
      down2[node]=down1[node];
      down1[node]=down1[child]+1;
      down_child[node]=child;
    }
    else if(down1[child]+1>=down2[node]){
      down2[node]=down1[child]+1;
    }
  }
}

//path thru par, top down dp
void dfs2(int node, int par){
  for(int child:adj[node]){
    up[child]=max(up[child],1+up[node]); //thru par of par
    if(down_child[node]!=child){
      up[child]=max(up[child],down1[node]+1); //if longest path of par not thru node
    }
    else up[child]=max(up[child],down2[node]+1); //else
                                                 
    dfs2(child,node);
  }
}

void solve(){
  int n;cin>>n;
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs1(0,-1);
  dfs2(0,-1);
  vector<int> path_thru(n);
  vector<int> path_begin(n);
  for(int i=0;i<n;i++){
    path_thru[i]=max({down1[i]+down2[i], down1[i]+up[i]});
    path_begin[i]=max(down1[i],up[i]);
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

