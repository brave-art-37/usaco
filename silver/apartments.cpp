#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m,k;cin>>n>>m>>k;
  vector<int> a(n),b(m);
  for(int &x:a) cin>>x;
  for(int &x:b) cin>>x;
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  auto it=lower_bound(b.begin(),b.end(),a[0]-k);
  int j=(it-b.begin());
  int count=0;
  for(int i=0;i<n;i++){
    while(j<m && b[j]<a[i]-k) j++;
    if(j<m && b[j]<=a[i]+k) count++, j++;
  }
  cout<<count<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
