#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

vector<vector<int>> adj[2];
vector<int> down1[2];
vector<int> down2[2];
vector<int> down_child[2];
vector<int> up[2];

//thru child, bottom up dp
void dfs1(int node, int par, int tree){
  for(int child:adj[tree][node]){
    if(child==par) continue;
    dfs1(child,node,tree);
    if(down1[tree][child]+1>=down1[tree][node]){
      down2[tree][node]=down1[tree][node];
      down1[tree][node]=down1[tree][child]+1;
      down_child[tree][node]=child;
    }
    else if(down1[tree][child]+1>=down2[tree][node]){
      down2[tree][node]=down1[tree][child]+1;
    }
  }
}

//thru par, top down dp
void dfs2(int node, int par, int tree){
  for(int child:adj[tree][node]){
    if(child==par) continue;
    up[tree][child]=max(up[tree][child],up[tree][node]+1); //thru par of par

    if(down_child[tree][node]!=child) up[tree][child]=max(up[tree][child],1+down1[tree][node]); //longest path of node not thru this child
    else up[tree][child]=max(up[tree][child],1+down2[tree][node]);

    dfs2(child,node,tree);
  }
}

void solve(){
  int n;cin>>n;
  adj[0].assign(n,{});
  down1[0].assign(n,0);
  down2[0].assign(n,0);
  down_child[0].assign(n,-1);
  up[0].assign(n,0);
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[0][u].push_back(v);
    adj[0][v].push_back(u);
  }
  dfs1(0,-1,0);dfs2(0,-1,0);

  int m;cin>>m;
  adj[1].assign(m,{});
  down1[1].assign(m,0);
  down2[1].assign(m,0);
  down_child[1].assign(m,-1);
  up[1].assign(m,0);
  for(int i=0;i<m-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[1][u].push_back(v);
    adj[1][v].push_back(u);
  }
  dfs1(0,-1,1);dfs2(0,-1,1);

  int mini1=INT_MAX,mini2=INT_MAX;
  vector<vector<int>> path_begin(2);
  path_begin[0].assign(n,0);
  for(int i=0;i<n;i++){
    path_begin[0][i]=max(down1[0][i], up[0][i]);
    mini1=min(mini1,path_begin[0][i]);
  }
  path_begin[1].assign(m,0);
  for(int i=0;i<m;i++){
    path_begin[1][i]=max(down1[1][i], up[1][i]);
    mini2=min(mini2,path_begin[1][i]);
  }

  int diam1=0;
  for(int i=0;i<n;i++){
    diam1=max({diam1,down1[0][i]+down2[0][i],down1[0][i]+up[0][i]});
  }
  int diam2=0;
  for(int i=0;i<m;i++){
    diam2=max({diam2,down1[1][i]+down2[1][i],down1[1][i]+up[1][i]});
  }

  cerr<<"tree 1\n";
  for(int i=0;i<n;i++){
    cerr<<path_begin[0][i]<<' ';
  }
  cerr<<"\n";
  cerr<<"tree 2\n";
  for(int i=0;i<m;i++){
    cerr<<path_begin[1][i]<<' ';
  }
  cerr<<"\n";

  cout<<max({diam1,diam2,mini1+mini2+1})<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
