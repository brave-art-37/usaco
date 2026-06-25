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
  int po2;cin>>po2;
  vector<vector<int>> succ(po2,vector<int>(n+1)); //succ[b][i] = (1<<b)th succ of i
  for(int b=0;b<po2;b++){
    for(int i=1;i<n+1;i++){
      if(b==0) {
        succ[b][i]=next[i];
        continue;
      }
      succ[b][i]=succ[b-1][ succ[b-1][i] ];
    }
  }
  /*
  int q;cin>>q;
  while(q--){
    int u,k;cin>>u>>k;
    int curr=u;
    for(int b=0;b<po2;b++){
      if((k>>b)&1) curr=succ[b][curr];
    }
    cout<<curr<<"\n";
  }
  */
  cerr<<"succ\n";
  for(int b=0;b<po2;b++){
    for(int i=1;i<n+1;i++){
      cout<<succ[b][i]<<' ';
    }
    cout<<"\n";
  }
}


void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

