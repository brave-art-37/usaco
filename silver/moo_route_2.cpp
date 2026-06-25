#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

int n,m;
const int MAXN=2e5;
vector<int> a(MAXN);
map< pair<int,int>, set<pair<int,int>> > adj;
vector<int> ans(MAXN,INT_MAX);
map<int,set<int>> tmp;

void dfs(int u,int t){
  ans[u]=min(ans[u],t);
  cerr<<"("<<u<<", "<<t<<") --> \n";
  auto it=tmp[u].lower_bound(t+a[u]);
  if(it==tmp[u].end()) return;
  int T=*it;
  pair<int,int> v={u,T};
  for(auto p:adj[v]){
    dfs(p.first,p.second);
  }
  cerr<<"---> ("<<u<<", "<<t<<")\n";
}

void solve(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int c,r,d,s;
    cin>>c>>r>>d>>s;
    adj[make_pair(c,r)].insert({d,s});
    tmp[c].insert(r);
  }
  for(int i=1;i<n+1;i++){
    cin>>a[i];
  }
  tmp[1].insert(0);
  ans[1]=0;
  for(auto p:adj[make_pair(1,0)]){
    dfs(p.first,p.second);
  }
  for(int i=1;i<n+1;i++){
    if(ans[i]==INT_MAX) cout<<-1<<"\n";
    else cout<<ans[i]<<"\n";
  }

  cerr<<"a= ";for(int i=1;i<n+1;i++) cerr<<a[i]<<" ";cerr<<"\n";
  cerr<<"adj= ";for(auto p:adj){
    cerr<<"("<<p.first.first<<","<<p.first.second<<"): ";
    for(auto q:p.second){
      cerr<<"("<<q.first<<","<<q.second<<"), ";
    }
    cerr<<"\n";
  }
  cerr<<"tmp= ";for(auto p:tmp){
    cerr<<p.first<<": ";
    for(int num:p.second) cerr<<num<<", ";
    cerr<<"\n";
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
