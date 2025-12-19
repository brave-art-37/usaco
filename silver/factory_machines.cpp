#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

ll first_true(ll lo, ll hi, function<bool(int)> f){
  ll ans=hi;
  while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    //cout<<"mid= "<<mid<<"\n";
    if(f(mid)) ans=mid,hi=mid-1LL;
    else lo=mid+1LL;
  }
  //cout<<"ans= "<<ans<<"\n";
  return ans;
}

void solve(){
  ll n,T;cin>>n>>T;
  vector<ll> freq(n);
  for(ll &x:freq) cin>>x;
  sort(freq.begin(),freq.end());
  //cout<<freq[0]<<' '<<(freq.back()*T)<<"\n";
  cout<<first_true(freq[0],freq[n-1]*T, [&](ll r){
      ll count=0LL;
      for(ll num:freq){
        count+=(r/num);
      }
      //cout<<"r= "<<r<<" count= "<<count<<"\n";
      return (count>=T);
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

