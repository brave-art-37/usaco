#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=10;
vector<vector<int>> adj(MAXN);

//Method 1
/*
vector<int> path(MAXN);
vector<int> maxlen(MAXN);

void dfs(int s,int e){
  path[s]=0;
  for(int v:adj[s]){
    if(v==e) continue;
    dfs(v,s);
    path[s]=max(path[s],path[v]+1);
  }
  priority_queue<int,vector<int>,greater<int>> pq;
  for(int v:adj[s]){
    if(v==e) continue;
    pq.push(path[v]+1);
    if(pq.size()>2) pq.pop();
  }
  maxlen[s]=0;
  while(!pq.empty()){
    maxlen[s]+=pq.top();pq.pop();
  }
}

void solve(){
  int n;cin>>n;
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0,-1);
  int diam=0;
  for(int i=0;i<n;i++){
    diam=max(diam,maxlen[i]);
  }
  cout<<diam<<"\n";

  cerr<<"path=";for(int num:path) cerr<<num<<' ';cerr<<"\n";
  cerr<<"maxlen=";for(int num:maxlen) cerr<<num<<' ';cerr<<"\n";
}
*/


//Method 2
vector<int> dist1(MAXN);
vector<int> dist2(MAXN);
void dfs(int s,int e, int pass){
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
  int diampt1=0;
  for(int i=0;i<n;i++){
    if(dist1[i]>dist1[diampt1]) diampt1=i;
  }
  dfs(diampt1,-1,2);
  int diampt2=diampt1;
  for(int i=0;i<n;i++){
    if(dist2[i]>dist2[diampt2]) diampt2=i;
  }
  int diam=dist2[diampt2];
  cout<<diam<<"\n";
  cout<<diampt1+1<<' '<<diampt2+1<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

