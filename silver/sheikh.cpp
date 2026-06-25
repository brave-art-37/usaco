#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

ll first_true(ll lo, ll hi, function<bool(int)> f){
  ll ans=hi;
  while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid, hi=mid-1;
    else lo=mid+1;
  }
  return ans;
}

void solve(){
  ll n,q;cin>>n>>q;
  vector<ll> a(n), pfsum(n+1), pfxor(n+1);
  for(int i=0;i<n;i++){
    cin>>a[i];
    pfsum[i+1]=pfsum[i]+a[i];
    pfxor[i+1]=pfxor[i]^a[i];
  }
  if(n==1){
    ll _;
    cin>>_>>_;
    cout<<1<<' '<<1<<"\n";
    return;
  }
  vector<ll> inc(n-1);
  for(int i=0;i<n-1;i++){
    inc[i]=first_true(i,n-1,[&](ll mid){
          return ( (pfsum[mid+1]-pfsum[i]-(pfxor[mid+1]^pfxor[i])) >= (pfsum[n]-pfxor[n]) );
        });
    inc[i]-=i;
    if((pfsum[i+inc[i]+1]-(pfxor[i+inc[i]+1]^pfxor[i])-pfsum[i])!=(pfsum[n]-pfxor[n])) inc[i]=INT_MAX;
  }
  while(q--){
    ll L,R;cin>>L>>R;
  }
  ll mini_idx=0, mini=inc[0];
  for(int i=0;i<n-1;i++){
    if(mini<=inc[i] || (pfsum[i+inc[i]+1]-(pfxor[i+inc[i]+1]^pfxor[i])-pfsum[i])!=(pfsum[n]-pfxor[n]) ) continue;
    mini_idx=i, mini=inc[i];
  }
  cout<<(mini_idx+1)<<' '<<(mini_idx+inc[mini_idx]+1)<<"\n";

  /*
  cerr<<"sum: ";for(int num:pfsum) cerr<<num<<" ";cerr<<"\n";
  cerr<<"xor: ";for(int num:pfxor) cerr<<num<<" ";cerr<<"\n";
  cerr<<"diff: ";for(int i=1;i<n+1;i++) cerr<<(pfsum[i]-pfxor[i])<<" ";cerr<<"\n";
  cerr<<"valid: ";for(int i=0;i<n-1;i++) cerr<<(inc[i]==INT_MAX?-1:(pfsum[n]-pfxor[n]-pfsum[i+inc[i]+1]+(pfxor[i+inc[i]+1]^pfxor[i])+pfsum[i]))<<" ";cerr<<"\n";
  cerr<<"inc: ";for(int num:inc) cerr<<num<<" ";cerr<<"\n";
  */
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}
