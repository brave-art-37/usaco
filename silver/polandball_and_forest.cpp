#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> adj(n);
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;tmp--;
    adj[tmp].push_back(i);
    adj[i].push_back(tmp);
  }
  int compNum=0;
  vector<int> vis(n);
  for(int i=0;i<n;i++){
    if(vis[i]) continue;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
      int u=st.top();st.pop();
      if(vis[u]) continue;
      vis[u]=1;
      for(int v:adj[u]) st.push(v);
    }
    compNum++;
  }
  cout<<compNum<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

