#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<pair<ll,ll>> pts(n);
  ll mini_x=LLONG_MAX,maxi_x=0;
  ll mini_y=LLONG_MAX,maxi_y=0;
  for(int i=0;i<n;i++){
    cin>>pts[i].first>>pts[i].second;
    mini_x=min(mini_x,pts[i].first);
    maxi_x=max(maxi_x,pts[i].first);
    mini_y=min(mini_y,pts[i].second);
    maxi_y=max(maxi_y,pts[i].second);
  }
  ll one_enclose=1LL*(maxi_y-mini_y)*(maxi_x-mini_x);
  sort(pts.begin(),pts.end());
  vector<ll> Mpfy(n);Mpfy[0]=pts[0].second;
  vector<ll> Msfy(n);Msfy[n-1]=pts[n-1].second;
  vector<ll> mpfy(n);mpfy[0]=pts[0].second;
  vector<ll> msfy(n);msfy[n-1]=pts[n-1].second;
  for(int i=1;i<n;i++){
    Mpfy[i]=max(Mpfy[i-1],pts[i].second);
    mpfy[i]=min(mpfy[i-1],pts[i].second);
  }
  for(int i=n-2;i>-1;i--){
    Msfy[i]=max(Msfy[i+1],pts[i].second);
    msfy[i]=min(msfy[i+1],pts[i].second);
  }
  ll two_enclose=one_enclose;
  for(int i=0;i<n-2;i++){
    if(pts[i].first==pts[i+1].first) continue;
    ll area=1LL*(pts[i].first-mini_x)*(Mpfy[i]-mpfy[i])+1LL*(maxi_x-pts[i+1].first)*(Msfy[i+1]-msfy[i+1]);
    two_enclose=min(two_enclose,area);
  }
  cout<<(one_enclose-two_enclose)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("split");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

