#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> nos(n);
  for(int i=0;i<n;i++) {
    cin>>nos[i];
  }
  for(int i=0;i<n;i++){
    if(nos[i]>=0) continue;
    ans = max(ans, __builtin_clz(abs(nos[i])) );
  }
  int ans=0;
  for(int b=31;b>-1;b--){
    bool issort=1;
    //cerr<<"b="<<b<<"\n";
    for(int i=1;i<n;i++){
      issort&=( (nos[i]>>b) >= (nos[i-1]>>b) );
      //cerr<<(nos[i]>>b)<<">="<<(nos[i-1]>>b)<<"\n";
    }
    if(!issort){
      ans=(b+1);
      //cerr<<b+1<<"\n";
      break;
    }
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

