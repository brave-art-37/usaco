#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

int MAXN=200;
vector<int> visited(MAXN);
vector<vector<int>> adj(MAXN);

int dfs(int u){
  visited[u]=1;
  int count=1;
  for(int v:adj[u]){
    if(visited[v]) continue;
    count+=dfs(v);
  }
  return count;
}

void solve(){
  int n;cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  vector<int> dist(n);
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i]>>dist[i];
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(j==i) continue;
      int tmp=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if(tmp>dist[i]*dist[i]) continue;
      adj[i].push_back(j);
    }
  }
  int maxi=0;
  for(int i=0;i<n;i++){
    fill(visited.begin(),visited.end(),0);
    maxi=max(maxi,dfs(i));
  }
  cout<<maxi<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("moocast");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

