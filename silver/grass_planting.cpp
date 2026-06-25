#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
const int MAXN=1e5;
vector<vector<int>> adj(MAXN);

vector<int> dist1(MAXN);
vector<int> dist2(MAXN);

void dfs(int s,int e,int pass){
  for(int v:adj[s]){
    if(v==e) continue;
    if(pass==1) dist1[v]=dist1[s]+1;
    else if(pass==2) dist2[v]=dist2[s]+1;
    dfs(v,s,pass);
  }
}

void solve(){
  int n;cin>>n;
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0,-1,1);
  int diam1=0;
  for(int i=0;i<n;i++){
    if(dist1[i]>dist1[diam1]) diam1=i;
  }
  dfs(diam1,-1,2);
  int diam2=diam1;
  for(int i=0;i<n;i++){
    if(dist2[i]>dist2[diam2]) diam2=i;
  }
  int diam=dist2[diam2];
  if(n<4) cout<<n<<"\n";
  else{
    if(diam==n-1) cout<<3<<"\n";
    else cout<<4<<"\n";
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("planting");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
