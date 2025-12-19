#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n,m,q;cin>>n>>m>>q;
  vector<ll> a(n),b(m);
  for(ll &x:a) cin>>x;
  for(ll &x:b) cin>>x;
  ll A=0;
  vector<ll> B(m-n+1);
  for(int i=0;i<n;i++){
    if(i&1) A-=a[i],B[0]-=b[i];
    else A+=a[i],B[0]+=b[i];
  }
  //cout<<A<<"\n";
  for(int i=n;i<m;i++){
    B[i-n+1]-=B[i-n];
    B[i-n+1]+=b[i-n];
    if(n&1) B[i-n+1]+=b[i];
    else B[i-n+1]-=b[i];
  }
  sort(B.begin(),B.end());
  //for(int x:B) cout<<x<<' ';cout<<"\n";
  auto it=lower_bound(B.begin(),B.end(),A);
  ll ans=LLONG_MAX;
  if(it!=B.end()) ans=min(ans,abs(*it-A));
  if(it!=B.begin()) it=prev(it,1);
  ans=min(ans,abs(*it-A));
  cout<<ans<<"\n";
  while(q--){
    ll l,r,x;cin>>l>>r>>x;
    if((r-l+1)&1){
      A+=x;
      it=lower_bound(B.begin(),B.end(),A);
      ans=LLONG_MAX;
      if(it!=B.end()) ans=min(ans,abs(*it-A));
      if(it!=B.begin()) it=prev(it,1);
      ans=min(ans,abs(*it-A));
    }
    cout<<ans<<"\n";
  }
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

