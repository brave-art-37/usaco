#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> adj(n,vector<int>());
  vector<int> vis(n,-1);
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int compNum=0;
  for(int i=0;i<n;i++){
    if(vis[i]!=-1) continue;
    queue<int> q;
    q.push(i);
    vis[i]=0;
    while(!q.empty()){
      int u=q.front();q.pop();
      for(int v:adj[u]){
        if(vis[v]!=-1) continue;
        vis[v]=1-vis[u];
        q.push(v);
      }
    }
    compNum++;
  }
  int zero=0;
  for(int i=0;i<n;i++){
    zero+=(vis[i]==0);
  }
  int col=(zero>n/2);
  int cnt=0;
  for(int i=0;i<n;i++){
    cnt+=(vis[i]==col);
  }
  cout<<cnt<<"\n";
  for(int i=0;i<n;i++){
    if(vis[i]==col) cout<<i+1<<' ';
  }
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

