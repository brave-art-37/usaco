#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

ll first_true(ll lo, ll hi, function<bool(int)> f){
  ll ans=hi;
  while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid,hi=mid-1;
    else lo=mid+1;
  }
  return ans;
}

void solve(){
  ll n;cin>>n;
  cout<<first_true(1,n*n,[&](ll k){
      ll count=0;
      for(int i=1;i<=n;i++){
      count+=min(n,k/i);
      }
      return (count>=((n*n+1)/2));
      })<<"\n";
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

