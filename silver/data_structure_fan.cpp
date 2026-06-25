#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  int totalxor=0, zeroxor=0;
  vector<int> a(n);
  vector<int> pf(n+1);
  for(int i=0;i<n;i++) {
    cin>>a[i];
    totalxor^=a[i];
    pf[i+1] = pf[i]^a[i];
  }
  string s;cin>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='0') zeroxor^=a[i];
  }
  /*
  cerr<<"zero "<<zeroxor<<"\n";
  cerr<<"total "<<totalxor<<"\n";
  cerr<<"pf ";for(int i=0;i<n;i++) cerr<<pf[i]<<' ';cerr<<"\n";
  */
  int q;cin>>q;
  while(q--){
    int tp;cin>>tp;
    if(tp==1){
      int l,r;cin>>l>>r;l--,r--;
      zeroxor^=(pf[l]^pf[r+1]);
    }
    else if(tp==2){
      int g;cin>>g;
      if(g==0) cout<<zeroxor<<" ";
      else cout<<(totalxor^zeroxor)<<" ";
    }
  }
  cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

