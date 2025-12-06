#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n;cin>>n;
  string s;cin>>s;
  vector<ll> pfl(n+1);
  map<ll,ll> id;
  id[0]++;
  for(int i=1;i<=n;i++){
    pfl[i]=pfl[i-1]+1LL*(s[i-1]-'0')-1LL;
    id[pfl[i]]++;
  }
  ll ans=0LL;
  for(auto p:id){
    ans+=(p.second*(p.second-1))/2;
  }
  //for(int num:pfl){cout<<num<<' ';}cout<<"\n";
  cout<<ans<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  cin >> t;

  while (t--){solve();}
}

