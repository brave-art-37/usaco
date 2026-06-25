#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> kids(n,vector<int>());
  for(int i=1;i<n;i++){
    int tmp;cin>>tmp;tmp--;
    kids[tmp].push_back(i);
  }
  vector<int> ans(n,-1);
  stack<int> st;
  st.push(0);
  vector<int> vis(n,0);
  while(!st.empty()){
    int u=st.top();st.pop();
    if(vis[u]==2) continue;
    else if(vis[u]==1){
      ans[u]=0;
      vis[u]=2;
      for(int v:kids[u]) ans[u]+=(1+ans[v]);
    }
    else{
      vis[u]=1;
      st.push(u);
      for(int v:kids[u]) st.push(v);
    }
  }
  for(int num:ans) cout<<num<<' ';
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

