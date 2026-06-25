#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> list(n,vector<int>());
  vector<int> nbs(n);
  vector<int> vis(n,-1);
  for(int i=0;i<n;i++){
    int u;cin>>u;u--;
    if(find(list[i].begin(),list[i].end(),u)!=list[i].end()) continue;
    nbs[i]++, nbs[u]++;
    list[u].push_back(i);
    list[i].push_back(u);
  }
  int compNum=0;
  for(int i=0;i<n;i++){
    //cerr<<"i= "<<i<<"\n\n";
    if(vis[i]!=-1) continue;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
      int u=st.top();st.pop();
      //cerr<<u<<"\n";
      vis[u]=compNum;
      for(int v:list[u]){
        if(vis[v]==-1) st.push(v);
      }
    }
    compNum++;
    //cerr<<"\n";
  }
  /*
  cerr<<"nbs= ";for(int num:nbs) cerr<<num<<" ";cerr<<"\n";
  cerr<<"vis= ";for(int num:vis) cerr<<num<<" ";cerr<<"\n";
  cerr<<"list=\n";
  for(int i=0;i<n;i++){
    cerr<<"i="<<i<<": ";
    vector<int> tmp=list[i];
    for(int num:tmp) cerr<<num<<", ";
    cerr<<"\n";
  }
  */

  vector<int> mnbs(n,INT_MAX);
  for(int i=0;i<n;i++){
    mnbs[vis[i]]=min(mnbs[vis[i]],nbs[i]);
  }
  int iso=0;
  for(int i=0;i<compNum+1;i++){
    iso+=(mnbs[i]==2);
  }
  //cerr<<"compNum="<<compNum<<", iso="<<iso<<"\n";
  cout<<min(iso+1,compNum)<<' '<<compNum<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}
