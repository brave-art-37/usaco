#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> next(n+1);
  for(int i=1;i<n+1;i++){
    cin>>next[i];
  }
  vector<int> ans(n+1,-1);
  vector<int> vis(n+1,-1); //-1 not visit, 0 process, 1 done

  //if reach a node that is in process => cycle
  //if reach a node that is done => entry point
  for(int i=1;i<n+1;i++){
    if(vis[i]==1) continue;
    stack<int> st;
    st.push(i);
    int tmp=-1;
    int on=0;
    while(!st.empty()){
      int u=st.top();st.pop();
      if(vis[u]==1){
        on=1;
        tmp=ans[u];
      }
      else if(vis[u]==0){
        vis[u]=1;
        if(on) ans[u]=tmp;
        else ans[u]=u;
      }
      else{
        vis[u]=0;
        st.push(u);
        st.push(next[u]);
      }
    }
  }
  for(int i=1;i<n+1;i++){
    cout<<ans[i]<<' ';
  }
  cout<<"\n";
  //cerr<<"ans ";for(int num:ans) cerr<<num<<" ";cerr<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

