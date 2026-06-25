#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  int n;cin>>n;
  vector<ll> nos(n+1);
  for(int i=1;i<=n;i++){
    cin>>nos[i];
  }
  ll mod = 998244353;
  ll ans=0;
  for(int b=0;b<3;b++){
    int curr=0;
    vector<int> odd, even;
    odd.push_back(1);
    for(int i=1;i<=n;i++){
      if(((nos[i]>>b)&1)==0) continue;
      curr++;
      if(curr&1) odd.push_back(i);
      else even.push_back(i);
    }
    
    cerr<<"odd: ";for(int num:odd) cerr<<num<<' ';cerr<<"\n";
    cerr<<"even: ";for(int num:even) cerr<<num<<' ';cerr<<"\n";
    
    int o=odd.size(), e=even.size();
    ll sum=0;
    for(int i=1;i<=o;i++){
      sum=(sum+((2*i-o-1)*odd[i-1])%mod)%mod;
    }
    for(int i=1;i<=e;i++){
      sum=(sum+((2*i-e-1)*even[i-1]))%mod;
    }
    sum=(sum+o*(o-1)/2+e*(e-1)/2)%mod;
    ans=(ans+(sum<<b)%mod)%mod;
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

