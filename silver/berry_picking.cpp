#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n,k;cin>>n>>k;

/*  vector<ll> nos(n);
  for(ll &x:nos) cin>>x;
  sort(nos.begin(),nos.end());

  multiset<ll> q;
  for(int i=0;i<k-n;i++) q.insert(0);
  for(int i=max(0LL,n-k);i<n;i++) q.insert(nos[i]);

  cerr<<"q=";for(ll num:q) cerr<<num<<' ';cerr<<"\n";

  while(2*(*q.begin())<(*q.rbegin())){
    ll a=(*q.rbegin());
    q.erase(prev(q.end(),1));
    q.insert(a/2);q.insert((a+1)/2);
    q.erase(q.begin());

    cerr<<"q=";for(ll num:q) cerr<<num<<' ';cerr<<"\n";

  }
  ll ans=0, i=0;
  for(ll num:q){
    ans+=num; i++;
    if(i==k/2) break;
  }
  cout<<ans<<"\n";*/

  vector<ll> nos(n);
  ll maxi=0;
  for(ll &x:nos) cin>>x, maxi=max(maxi,x);
  ll ans=0;
  for(int i=1; i<=maxi; i++){
    ll full=0;
    for(ll num:nos) full+=num/i;
    if(full<k/2) continue;
    else if(full>=k) { ans=max(ans,(k/2)*i); continue; }
    ll rem=(full-k/2)*i;
    sort(nos.begin(),nos.end(), [&](ll a, ll b){
        return (a%i>b%i);
        });
    for(int j=0;j<min(n,k-full);j++) rem+=(nos[j]%i);
    ans=max(ans,rem);
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("berries");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
