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
  vector<int> cycle;
  vector<int> vis(n+1,-1);
  for(int i=1;i<n+1;i++){
    if(vis[i]==1) continue;
    stack<int> st;
    st.push(i);
    int chain=0, len=0;
    while(!st.empty()){
      int u=st.top();st.pop();
      if(vis[u]==1) chain=1;
      else if(vis[u]==0){
        vis[u]=1;
        len+=(chain==0);
      }
      else{
        vis[u]=0;
        st.push(u);
        st.push(next[u]);
      }
    }
    if(len>0) cycle.push_back(len);
  }
  int sum=0;
  cerr<<"cycle ";for(int num:cycle) cerr<<num<<' ';cerr<<"\n";
  for(int i=0;i<cycle.size();i++) sum+=cycle[i];
  cout<<sum<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("shuffle");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

