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
  vector<ll> d;
  map<ll,ll> freq;
  for(int i=0;i<2*n;i++){
    ll tmp;cin>>tmp;
    if(!freq.count(tmp)) d.push_back(tmp);
    freq[tmp]++;
  }
  bool isit=1;
  isit&=(d.size()==n);
  for(auto p:freq) isit&=(p.second%2==0);
  if(!isit){
    cout<<"NO\n";
    return;
  }
  sort(d.begin(),d.end(),greater<ll>());
  isit&=(d[0]%(2*n)==0);
  set<ll> elts;
  vector<ll> a(n);a[0]=d[0]/(2*n);
  elts.insert(a[0]);
  for(int i=1;i<n;i++){
    isit&=((d[i]-d[i-1])%(2*(n-i))==0);
    a[i]=a[i-1]+(d[i]-d[i-1])/(2*(n-i));
    isit&=(a[i]>0);
    if(a[i]!=0) elts.insert(a[i]);
  }
  isit&=(elts.size()==n);
  if(!isit) cout<<"NO\n";
  else cout<<"YES\n";
  cerr<<"d: ";for(ll num:d) cerr<<num<<' ';cerr<<"\n";
  cerr<<"a: ";for(ll num:a) cerr<<num<<' ';cerr<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  cin >> t;
  while (t--){solve();}}

