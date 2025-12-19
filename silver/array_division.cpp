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
  ll n,k;cin>>n>>k;
  vector<ll> nos(n);
  ll maxi=0,sum=0;
  for(ll &x:nos) cin>>x,sum+=x,maxi=max(maxi,x);
  cout<<first_true(maxi,sum, [&](ll mid){
      ll count=1,curr=0;
      for(ll num:nos){
        if(curr+num>mid) curr=num,count++;
        else curr+=num;
      }
      return (count<=k);
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

