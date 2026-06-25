#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n,g;cin>>n>>g;
  map<ll,ll> cow_to_amt;
  vector<pair<ll,pair<ll,ll>>> data(n);
  for(int i=0;i<n;i++) { cin>>data[i].first>>data[i].second.first>>data[i].second.second; cow_to_amt[data[i].second.first]=g; }
  sort(data.begin(),data.end());
  map<ll,ll> amt_to_cowsNumber;
  amt_to_cowsNumber[n+1]=g;
  ll display_change=0;
  for(int i=0;i<n;i++){
    ll cow=data[i].second.first;
    ll delta=data[i].second.second;
    ll curr_amt=cow_to_amt[cow];
    ll most_amt=(amt_to_cowsNumber.rbegin()->first);
    ll most_amt_cowsNumber=(amt_to_cowsNumber.rbegin()->second);
    amt_to_cowsNumber[curr_amt]--;
    if(amt_to_cowsNumber[curr_amt]==0) amt_to_cowsNumber.erase(curr_amt);
    cow_to_amt[cow]=(curr_amt+delta);
    amt_to_cowsNumber[curr_amt+delta]++;
    display_change+=((most_amt!=amt_to_cowsNumber.rbegin()->first)||(most_amt_cowsNumber!=amt_to_cowsNumber.rbegin()->second));
  }
  cout<<display_change<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("measurement");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

