#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

bool ycomp(pair<ll,ll> a, pair<ll,ll> b){
  return (a.second<b.second);
}

ll no_of_pts(ll x1, ll y1, ll x2, ll y2, vector<vector<ll>> &pref){
  return (pref[x2][y2]-pref[x1-1][y2]-pref[x2][y1-1]+pref[x1-1][y1-1]);
}

void solve(){
  ll n;cin>>n;
  vector<pair<ll,ll>> pts(n);
  for(int i=0;i<n;i++){
    ll x,y;cin>>x>>y;
    pts[i]={x,y};
  }
  sort(pts.begin(),pts.end());
  for(int i=0;i<n;i++){
    pts[i].first=i+1;
  }
  sort(pts.begin(),pts.end(),ycomp);
  for(int i=0;i<n;i++){
    pts[i].second=i+1;
  }

  /*for(auto p:pts){
    cout<<"("<<p.first<<", "<<p.second<<") ";
  }
  cout<<"\n";*/

  vector<vector<ll>> pref(n+1,vector<ll>(n+1));

  for(int i=0;i<n;i++){
    pref[pts[i].first][pts[i].second]=1;
  }
  for(int i=1;i<n+1;i++){
    for(int j=1;j<n+1;j++){
      pref[i][j]+=(pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1]);
    }
  }

  /*for(auto v:pref){
    for(auto e:v) cout<<e<<' ';cout<<"\n";
  }*/

  ll ans=0;
  for(int i=1;i<n+1;i++){
    for(int j=i;j<n+1;j++){
      ll left=min(pts[i-1].first,pts[j-1].first);
      ll right=max(pts[i-1].first,pts[j-1].first);
      ans+=(no_of_pts(1,i,left,j,pref))*(no_of_pts(right,i,n,j,pref));
    }
  }
  cout<<ans+1<<"\n";
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

