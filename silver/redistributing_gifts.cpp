#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> adj(n,vector<int>());
  vector<vector<int>> rev(n,vector<int>());
  for(int i=0;i<n;i++){
    int on=0;
    for(int j=0;j<n;j++){
      int tmp;cin>>tmp;tmp--;
      if(!on) adj[i].push_back(tmp);
      on|=(tmp==i);
    }
    for(int j:adj[i]){
      rev[j].push_back(i);
    }
  }

  vector<int> topo_sort;
  vector<int> rev_vis(n);
  for(int i=0;i<n;i++){
    if(rev_vis[i]) continue;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
      int u=st.top();st.pop();
      if(rev_vis[u]==0){
        rev_vis[u]=1;
        st.push(u);
        for(int v:rev[u]){
          if(rev_vis[v]) continue;
          st.push(v);
        }
      }
      else if(rev_vis[u]==1){
        topo_sort.push_back(u);
        rev_vis[u]=2;
      }
    }
  }


  reverse(topo_sort.begin(),topo_sort.end());

  vector<int> vis(n);
  vector<int> iscomp(n);
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    int w=topo_sort[i];
    if(vis[w]) continue;
    stack<int> st;
    st.push(w);
    while(!st.empty()){
      int u=st.top();st.pop();
      iscomp[u]=1;
      vis[u]=1;
      for(int v:adj[u]){
        if(vis[v]) continue;
        st.push(v);
      }
    }
    for(int j=0;j<n;j++){
      if(!iscomp[j]) continue;
      for(int k:adj[j]){
        if(!iscomp[k]) continue;
        ans[j]=k;
        break;
      }
    }
    fill(iscomp.begin(),iscomp.end(),0);
  }

  for(int i=0;i<n;i++){
    cout<<ans[i]+1<<"\n";
  }

  
  /*
  cerr<<"topo=\n";
  for(int num:topo_sort) cerr<<num<<' ';
  cerr<<"\n";
  */
  

}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

