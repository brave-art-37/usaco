#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n,k;cin>>n>>k;
  vector<ll> nos(n);
  for(ll &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  vector<ll> sz(n);
  for(int i=0;i<n;i++){
    auto it = upper_bound(nos.begin()+i, nos.end(), nos[i]+k);
    it=prev(it,1);
    sz[i]=(it-nos.begin())-i;
  }
  vector<ll> sf(n+1);
  for(int i=n-1;i>-1;i--){
    sf[i]=max(sf[i+1],sz[i]);
  }
  ll maxi=0;
  for(int i=0;i<n;i++){
    maxi=max(maxi,sz[i]+sf[i+1+sz[i]]);
  }
  cout<<maxi+2LL<<"\n";
  /*for(int num:nos) cout<<num<<' ';cout<<"\n";
  for(int num:sz) cout<<num<<' ';cout<<"\n";
  for(int num:sf) cout<<num<<' ';cout<<"\n";*/
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("diamond");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

