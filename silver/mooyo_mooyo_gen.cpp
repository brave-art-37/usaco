#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n=uid(0,10);
  int k=uid(0,10);
  cout<<n<<' '<<k<<"\n";
  for(int i=0;i<n;i++){
    string s="";
    for(int j=0;j<10;j++){
      int tmp=uid(1,2);
      s+=(char)(tmp+'0');
    }
    cout<<s<<"\n";
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

