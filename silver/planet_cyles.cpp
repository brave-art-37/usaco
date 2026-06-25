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
  vector<int> entry(n+1,-1);
  vector<int> t(n+1,-1);
  vector<int> vis1(n+1,-1); //for entry
  vector<int> vis2(n+1,-1); //for time
  for(int i=1;i<n+1;i++){
    if(vis1[i]==1) continue;
    stack<int> st;
    st.push(i);
    int chain=0, len=0;
    //finding first entry in cycle
    while(!st.empty()){
      int u=st.top();st.pop();
      if(vis1[u]==1){ //finish
        chain=1;
      }
      else if(vis1[u]==0){ //process
        vis1[u]=1;
        if(chain) entry[u]=entry[next[u]];
        else entry[u]=u;
        len+=(chain==0);
      }
      else{ //first time
        vis1[u]=0;
        st.push(u);
        st.push(next[u]);
      }
    }
    //finding first repeat time
    st.push(i);
    while(!st.empty()){
      int u=st.top();st.pop();
      if(vis2[u]==1) continue;
      else if(vis2[u]==0){
        vis2[u]=1;
        if(entry[u]==u) t[u]=len;
        else t[u]=t[next[u]]+1;
      }
      else{
        vis2[u]=0;
        st.push(u);
        st.push(next[u]);
      }
    }
  }
  for(int i=1;i<n+1;i++){
    cout<<t[i]<<' ';
  }
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

