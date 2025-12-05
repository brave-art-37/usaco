#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,m;cin>>n>>m;
  vector<set<int>> graph(n);
  vector<int> colors(n);
  vector<int> label(n);
  for(int i=0;i<m;i++){
    int u,v;cin>>u>>v;u--,v--;
    graph[u].insert(v);
    graph[v].insert(u);
  }
  for(int u=0;u<n;u++){
    for(int j=0;j<4;j++){
      if(colors[u]&(1<<j)) continue;
      label[u]=j+1;
      for(int v:graph[u]){
        if(v<u) continue;
        colors[v]|=(1<<j);
      }
      /*for(int i=0;i<n;i++){
        cout<<colors[i]<<" \n"[i==n-1];
      }*/
      break;
    }
  }
  for(int l:label){
    cout<<l;
  }
  cout<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("revegetate");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

