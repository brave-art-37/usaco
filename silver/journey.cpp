#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1e5;
vector<vector<int>> adj(MAXN);
vector<int> cnnt(MAXN);

void cnt(int s,int e){
  cnnt[s]=0;
  for(int v:adj[s]){
    if(v==e) continue;
    cnnt[s]++;
    cnt(v,s);
  }
}

double dfs(int s,int e){
  double ans=0;
  for(int v:adj[s]){
    if(v==e) continue;
    ans+=(1+dfs(v,s))/cnnt[s];
  }
  return ans;
}

void solve(){
  int n;cin>>n;
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cnt(0,-1);
  cout<<fixed<<setprecision(10)<<dfs(0,-1)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

