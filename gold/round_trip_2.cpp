#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int N=5;
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
  vector<int> idx(N);
  for(int i=0;i<topo_sort.size();i++){
    idx[topo_sort[i]]=i;
  }
  int valid=1;
  vector<int> cycle;
  for(int u=0;u<n;u++){
    for(int v:adj[u]){
      valid&=(idx[u]<idx[v]);
      if(!valid){
        for(int j=idx[v];j<idx[u]+1;j++){
          cycle.push_back(topo_sort[j]);
        }
        //goto answer;
      }
    }
    if(!valid) break;
  }

//answer:;
   if(valid) cout<<"IMPOSSIBLE\n";
   else{
     cout<<cycle.size()<<"\n";
     for(int i=0;i<cycle.size()-1;i++) cout<<cycle[i]+1<<' ';
     cout<<cycle.back()+1<<"\n";
   }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
