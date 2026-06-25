#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,k;cin>>n>>k;
  vector<pair<int,int>> a(n);
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;
    a[i]=make_pair(tmp,i+1);
  }
  sort(a.begin(),a.end());
  int mini=0;
  for(int i=0;i<n-1;i++){
    if( (a[i].first^a[i+1].first)<(a[mini].first^a[mini+1].first) ) mini=i;
  }
  int x=0;
  for(int b=0;b<k;b++){
    bool bit1 = (a[mini].first>>b)&1;
    bool bit2 = (a[mini+1].first>>b)&1;
    if(bit1^bit2) continue;
    x+=((!bit1)<<b);
  }
  cout<<a[mini].second<<" "<<a[mini+1].second<<" "<<x<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

