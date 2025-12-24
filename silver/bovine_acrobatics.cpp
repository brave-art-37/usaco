#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

/*void print(deque<pair<ll,ll>> q){
  int n=q.size();
  cerr<<"towers: { ";
  while(n--){
    pair<ll,ll> p=q.front();q.pop_front();
    cerr<<"("<<p.first<<", "<<p.second<<") ";
    q.push_back(p);
  }
  cerr<<"}\n";
}*/

void solve(){
  ll n,m,k;cin>>n>>m>>k;
  vector<pair<ll,ll>> cows(n);
  for(int i=0;i<n;i++){
    cin>>cows[i].first>>cows[i].second;
    cows[i].second=min(cows[i].second,m);
  }
  sort(cows.begin(),cows.end(),greater<pair<ll,ll>>());

  //cerr<<"cows=";for(auto p:cows) cerr<<"("<<p.first<<", "<<p.second<<") ";cerr<<"\n";

  deque<pair<ll,ll>> towers;
  towers.push_back({LLONG_MAX,m});
  ll count=0;

 //print(towers);

  for(int i=0;i<n;i++){
    ll used=0;
    while(!towers.empty() && towers.front().first>=(cows[i].first+k)){

      pair<ll,ll>& curr=towers.front();

      if(curr.second>cows[i].second){
        curr.second-=cows[i].second;
        used=cows[i].second;
        break;
      }
      else{
        used+=curr.second;
        cows[i].second-=curr.second;
        towers.pop_front();
      }
    }
      pair<ll,ll> new_tower={cows[i].first,used};
      towers.push_back(new_tower);
      count+=used;

      //print(towers);

     //cerr<<"i="<<i<<" used="<<used<<"\n";
  }
  cout<<count<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

