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
  vector<ll> par(n+1), diff(n+1), joy(n+1), total_joy(n+1);
  for(int i=2;i<n+1;i++){
    cin>>par[i]>>diff[i]>>joy[i];
  }

  vector<multiset<ll>> most_diff(n+1);

  for(int i=2;i<n+1;i++){
    total_joy[i]=joy[i]+total_joy[par[i]];
    most_diff[i]=most_diff[par[i]];
    most_diff[i].insert(diff[i]);
    if(most_diff[i].size()>11) most_diff[i].erase(most_diff[i].begin());
  }
  vector<vector<ll>> most(n+1,vector<ll>(12));
  for(int i=2;i<n+1;i++){
    ll iter=0;
    for(auto it=most_diff[i].rbegin();it!=most_diff[i].rend();it++){
      most[i][iter]=*it;iter++;
    }
  }

  vector<vector<pair<ll,ll>>> c_thres_enjoy(11);
  vector<vector<ll>> pfmax(11);
  for(int c=0;c<11;c++){
    for(int i=2;i<n+1;i++){
      c_thres_enjoy[c].push_back({most[i][c],total_joy[i]});
    }
    sort(c_thres_enjoy[c].begin(),c_thres_enjoy[c].end());
    pfmax[c].push_back(c_thres_enjoy[c][0].second);
    for(int i=1;i<c_thres_enjoy[c].size();i++){
      ll tmp=max(pfmax[c][i-1],c_thres_enjoy[c][i].second);
      pfmax[c].push_back(tmp);
    }
  }

  ll m;cin>>m;
  while(m--){
    ll s,c;cin>>s>>c;
    auto it=upper_bound(c_thres_enjoy[c].begin(),c_thres_enjoy[c].end(),make_pair(s,LLONG_MAX));
    if(it==c_thres_enjoy[c].begin()) cout<<0<<"\n";
    else {
      it=prev(it,1);
      cout<<pfmax[c][it-c_thres_enjoy[c].begin()]<<"\n";
    }
  }

  /*
  cerr<<"par ";for(ll num:par) cerr<<num<<' ';cerr<<"\n";
  cerr<<"diff ";for(ll num:diff) cerr<<num<<' ';cerr<<"\n";
  cerr<<"joy ";for(ll num:joy) cerr<<num<<' ';cerr<<"\n";
  cerr<<"total ";for(ll num:total_joy) cerr<<num<<' ';cerr<<"\n";
  */
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

