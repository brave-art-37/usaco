#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m,k;cin>>n>>m>>k;
  vector<int> left(n+1), right(n+1), next(n+1);
  for(int i=1;i<n+1;i++){
    cin>>left[i]>>right[i];
  }

  string s;
  for(int i=0;i<m;i++){
    char c;cin>>c;
    s+=c;
  }

  for(int i=1;i<n+1;i++){
    int curr=i;
    for(char c:s){
      if(c=='L') curr=left[curr];
      else curr=right[curr];
    }
    next[i]=curr;
  }

  vector<vector<int>> succ(31,vector<int>(n+1));
  for(int b=0;b<31;b++){
    for(int i=1;i<n+1;i++){
      if(b==0) succ[b][i]=next[i];
      else succ[b][i]=succ[b-1][succ[b-1][i]];
    }
  }
  int curr=1;
  for(int b=0;b<31;b++){
    if((k>>b)&1) curr=succ[b][curr];
  }
  cout<<curr<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("cruise");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
