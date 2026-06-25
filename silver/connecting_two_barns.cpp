#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;


ll sq_dist(ll a, ll b){
  return (a*a+b*b);
}

void solve(){
  ll n,m;cin>>n>>m;
  vector<vector<ll>> adj(n,vector<ll>());
  for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;u--,v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  vector<ll> comp(n,-1);
  ll compNum=0;
  for(int i=0;i<n;i++){
    if(comp[i]!=-1) continue;
    stack<ll> st;
    st.push(i);
    while(!st.empty()){
      ll u=st.top();st.pop();
      comp[u]=compNum;
      for(ll v:adj[u]){
        if(comp[v]!=-1) continue;
        st.push(v);
      }
    }
    compNum++;
  }
  vector<vector<ll>> scc(compNum,vector<ll>());
  for(int i=0;i<n;i++){
    scc[comp[i]].push_back(i);
  }
  int st=comp[0], end=comp[n-1];
  vector<ll> min_dist_st(compNum,INT_MAX);
  vector<ll> min_dist_end(compNum,INT_MAX);
  int a=0;
  for(int i=0;i<n;i++){
    ll dist=abs(i-scc[st][a]);
    while(a<scc[st].size()-1 && abs(scc[st][a+1]-i)<dist){
      a++;
      dist=abs(i-scc[st][a]);
    }
    min_dist_st[comp[i]]=min(min_dist_st[comp[i]], dist);
  }
  int b=0;
  for(int i=0;i<n;i++){
    ll dist=abs(i-scc[end][b]);
    while(b<scc[end].size()-1 && abs(scc[end][b+1]-i)<dist){
      b++;
      dist=abs(i-scc[end][b]);
    }
    min_dist_end[comp[i]]=min(min_dist_end[comp[i]], dist);
  }
  ll min_ans=LLONG_MAX;
  for(int i=0;i<compNum;i++){
    min_ans=min(min_ans, sq_dist(min_dist_st[i],min_dist_end[i]));
  }
  cout<<min_ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

