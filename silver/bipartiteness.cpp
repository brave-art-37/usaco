#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<vector<ll>> adj(n,vector<ll>());
  vector<ll> vis(n,-1);
  for(ll i=0;i<n-1;i++){
    ll u,v;cin>>u>>v;u--,v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  for(ll i=0;i<n;i++){
    if(vis[i]!=-1) continue;
    stack<ll> st;
    st.push(i);
    if(i==0) vis[i]=0;
    while(!st.empty()){
      ll u=st.top();st.pop();
      for(ll v:adj[u]){
        if(vis[v]!=-1) continue;
        vis[v]=1-vis[u];
        st.push(v);
      }
    }
  }
  ll zero=0,one=0;
  for(ll i=0;i<n;i++){
    zero+=(vis[i]==0);
    one+=(vis[i]==1);
  }
  cout<<one*zero-n+1LL<<"\n";
  //cerr<<"vis= ";for(int num:vis) cerr<<num<<" ";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

