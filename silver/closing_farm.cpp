#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=3000;
vector<vector<int>> adj(MAXN);
vector<int> closed(MAXN);
vector<int> visited(MAXN);

int dfs(int u){
  visited[u]=1;
  int count=1;
  for(int v:adj[u]){
    if(visited[v]||closed[v]) continue;
    count+=dfs(v);
  }
  return count;
}

void print_status(int n, int last){
  int count=dfs(last);
  cout<< ((count==n)?"YES":"NO") <<"\n";
}

void solve(){
  int n,m;cin>>n>>m;
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> order(n);
  for(int i=0;i<n;i++){
    cin>>order[i];
    order[i]--;
  }
  int last=order.back();

  print_status(n,last);
  for(int i=0;i<n-1;i++){
    closed[order[i]]=1;
    //memset(visit,0,sizeof(visit));
    fill(visited.begin(),visited.end(),0);
    print_status(n-1-i,last);
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("closing");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

