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
  ll sum=0;
  vector<ll> nos(n);
  for(ll &x:nos) { cin>>x; sum+=x; }
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  int i=0;
  ll robot=0;
  while(i<n){
    pq.push(nos[i]);
    if(i&1) { robot+=pq.top(); pq.pop(); }
    i++;
  }
  cout<<sum-robot<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

