#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m;cin>>n>>m;
  /* Wrong code
  int ops=0;
  if(n==m){
    cout<<ops<<"\n";
    return;
  }
  else if(n>m){
    while(n>m){ //need to get n below m as ++ ops
      //cerr<<n<<' '<<m<<"\n";
      if(n%2==0) n>>=1, ops++;
      else n++, ops++;
    }
    ops+=(m-n);
  }
  else{
    while(m/2>n){ // need to get m close to n but not below as ops--
      //cerr<<n<<' '<<m<<"\n";
      if(m%2==0) m>>=1, ops++;
      else m--, ops++;
    }
    ops+=(m-n);
  }
  cout<<ops<<"\n";
  */
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

