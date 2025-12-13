#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  int n,m;cin>>n>>m;
  vector<ll> a(n),b(m);
  for(ll &x:a){cin>>x;}
  for(ll &x:b){cin>>x;}
  ll INF=1e10;
  vector<ll> left(n,-1*INF),right(n,INF);
  for(int i=0;i<n;i++){
    auto r=lower_bound(b.begin(),b.end(),a[i]);
    if(r!=b.end()) right[i]=min(right[i],*r-a[i]);
    if(r!=b.begin()) left[i]=max(left[i],a[i]-*prev(r,1));
  }
  ll ans=0;
  for(int i=0;i<n;i++){
    ans=max(ans,min(abs(left[i]),abs(right[i])));
  }
  cout<<ans<<"\n";
  /*
  for(int x:a){cout<<x<<' ';}cout<<"\n";
  for(int x:b){cout<<x<<' ';}cout<<"\n";
  for(int x:left){cout<<x<<' ';}cout<<"\n";
  for(int x:right){cout<<x<<' ';}cout<<"\n";
  */
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

