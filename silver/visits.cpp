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
  vector<ll> next(n+1),wt(n+1);
  for(int i=1;i<n+1;i++){
    cin>>next[i]>>wt[i];
  }
  vector<int> comp(n+1,-1), vis(n+1,-1), entry(n+1,-1);
  ll compNum=0, total=0;
  for(int i=1;i<n+1;i++){
    if(vis[i]==1) continue;
    stack<int> st;
    ll cycle_sum=0, chain_sum=0, chain=0;
    st.push(i);
    while(!st.empty()){
      int u=st.top();st.pop();
      if(vis[u]==-1){ //first time
        vis[u]=0;
        st.push(u);
        st.push(next[u]);
      }
      else if(vis[u]==0){ //process
        vis[u]=1;
        cycle_sum+=(chain==0)*wt[u]; //if in cycle
        chain_sum+=(chain==1)*wt[u]; //else

        if(chain) entry[u]=entry[next[u]]; //if in chain
        else entry[u]=u; //else

        if(comp[next[u]]==-1) comp[u]=compNum; //new comp
        else comp[u]=comp[next[u]]; //else
      }
      else{ //finish
        chain=1;
      }
    }
    total+=cycle_sum+chain_sum;
    if(comp[i]==compNum) compNum++; //i was in new comp
  }
  vector<ll> mini(compNum,LLONG_MAX);
  for(int i=1;i<n+1;i++){
    if(entry[i]!=i) continue; //not in cycle

    mini[comp[i]]=min(mini[comp[i]],wt[i]);
  }
  ll ans=total;
  for(ll num:mini) ans-=num;
  cout<<ans<<"\n";

  /*
  cerr<<"comp ";for(int i=1;i<n+1;i++) cerr<<comp[i]<<' ';cerr<<"\n";
  cerr<<"entry ";for(int i=1;i<n+1;i++) cerr<<entry[i]<<' ';cerr<<"\n";
  cerr<<"mini ";for(int i=0;i<compNum;i++) cerr<<mini[i]<<' ';cerr<<"\n";
  */
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

