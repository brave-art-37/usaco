#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  int n;cin>>n;
  vector<int> nos(n+1);
  for(int i=1;i<n+1;i++) {
    cin>>nos[i];
    nos[i]=(12-nos[i]);
  }
  vector<vector<int>> adj(n+1);
  for(int i=0;i<n-1;i++){
    int u,v;cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  vector<int> color(n+1,-1);
  color[0]=0;
  queue<pair<int,int>> q;
  q.push({1,0});
  while(!q.empty()){
    int node=q.front().first, par=q.front().second; q.pop();
    if(color[node]!=-1) continue;
    color[node]=1-color[par];
    for(int kid:adj[node]){
      if(kid==par) continue;
      q.push({kid,node});
    }
  }
  ll g1=0,g2=0,c1=0,c2=0;
  for(int i=1;i<n+1;i++){
    g1+=(color[i]==0)*nos[i];
    g2+=(color[i]==1)*nos[i];
    c1+=(color[i]==0);
    c2+=(color[i]==1);
  }
  ll diff=(12+(g1-g2)%12)%12;
  if(diff==0) cout<<n<<"\n";
  else if(diff==1) cout<<c2<<"\n";
  else if(diff==11) cout<<c1<<"\n";
  else cout<<0<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("clocktree");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

