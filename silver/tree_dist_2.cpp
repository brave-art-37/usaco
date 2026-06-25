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
  vector<vector<ll>> adj(n);
  for(ll i=0;i<n-1;i++){
    ll u,v;cin>>u>>v;u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  //num of elts in subtree bottom up
  vector<ll> vis(n);
  stack<pair<ll,ll>> st;
  vector<ll> subtree(n);
  st.push({0,-1});
  while(!st.empty()){
    ll node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]==2) continue;
    else if(vis[node]==1){
      vis[node]=2;
      for(ll child:adj[node]){
        if(child==par) continue;
        subtree[node]+=subtree[child];
      }
      subtree[node]++;
    }
    else{
      vis[node]=1;
      st.push({node,par});
      for(ll child:adj[node]){
        if(child==par) continue;
        st.push({child,node});
      }
    }
  }

  //sum of paths for root top down
  fill(vis.begin(),vis.end(),0);
  vector<ll> dp(n);
  st.push({0,-1});
  while(!st.empty()){
    ll node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]) continue;
    vis[node]=1;
    for(ll child:adj[node]){
      if(child==par) continue;
      dp[child]=dp[node]+1;
      st.push({child,node});
    }
  }
  vector<ll> sum(n);
  for(ll i=0;i<n;i++){
    sum[0]+=dp[i];
  }

  //sum for all nodes top down
  fill(vis.begin(),vis.end(),0);
  st.push({0,-1});
  while(!st.empty()){
    ll node=st.top().first, par=st.top().second;st.pop();
    if(vis[node]) continue;
    vis[node]=1;
    for(ll child:adj[node]){
      if(child==par) continue;
      sum[child]=sum[node]+n-2*subtree[child];
      st.push({child,node});
    }
  }

  for(ll num:sum) cout<<num<<' ';cout<<"\n";
  cerr<<"dp ";for(ll num:dp) cerr<<num<<' ';cerr<<"\n";
  cerr<<"sub ";for(ll num:subtree) cerr<<num<<' ';cerr<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

