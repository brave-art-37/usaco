#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> adj(n,vector<int>());
  vector< pair<char,pair<int,int>> > cnt(m);
  vector<int> vis(n,-1);
  vector<int> col(n,-1);
  for(int i=0;i<m;i++){
    cin>>cnt[i].first>>cnt[i].second.first>>cnt[i].second.second;
    int u=cnt[i].second.first;
    int v=cnt[i].second.second;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int compNum=0;
  for(int i=0;i<n;i++){
    if(vis[i]!=-1) continue;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
      int u=st.top();st.pop();
      vis[u]=compNum;
      for(int v:adj[u]){
        if(vis[v]!=-1) continue;
        st.push(v);
      }
    }
    compNum++;
  }

  cerr<<"vis= ";for(int num:vis) cerr<<num<<' ';cerr<<"\n";
  cout<<1;
  while(compNum--){
    cout<<0;
  }
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

