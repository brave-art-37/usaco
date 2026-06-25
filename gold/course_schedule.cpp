#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

// Method 1: DFS
/*
const int N=1e5+1;
vector<vector<int>> adj(N);
vector<int> visited(N);
vector<int> topo_sort;

void dfs(int u){
  visited[u]=1;
  for(int v:adj[u]){
    if(visited[v]) continue;
    dfs(v);
  }
  topo_sort.push_back(u);
}

void solve(){
  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
  }
  for(int i=0;i<n;i++){
    if(visited[i]) continue;
    dfs(i);
  }
  vector<int> idx(n);
  for(int i=0;i<n;i++){
    idx[topo_sort[i]]=i;
  }
  int valid=1;
  for(int u=0;u<n;u++){
    for(int v:adj[u]){
      valid&=(idx[v]<idx[u]);
      if(!valid) break;
    }
    if(!valid) break;
  }
  
  reverse(topo_sort.begin(),topo_sort.end());
  if(valid){
    for(int i=0;i<n-1;i++) cout<<topo_sort[i]+1<<' ';
    cout<<topo_sort.back()+1<<"\n";
  }
  else cout<<"IMPOSSIBLE\n";
}
*/


// Method 2: BFS(Kahn Algo)
const int N=1e5;
vector<vector<int>> adj(N);
vector<int> indegree(N);
vector<int> topo_sort;

void solve(){
  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    indegree[v]++;
  }
  queue<int> q;
  for(int i=0;i<n;i++){
    if(indegree[i]>0) continue;
    q.push(i);
  }

  while(!q.empty()){
    int u=q.front();q.pop();
    topo_sort.push_back(u);
    for(int v:adj[u]){
      if(--indegree[v]==0) q.push(v);
    }
  }

  if(topo_sort.size()!=n){
    cout<<"IMPOSSIBLE\n";
  }
  else{
    for(int i=0;i<n-1;i++) cout<<topo_sort[i]+1<<' ';
    cout<<topo_sort.back()+1<<"\n";
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
