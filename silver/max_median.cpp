#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

bool check(ll mid, vector<ll> nos, vector<ll> pf, ll k, ll n){
  auto it=lower_bound(nos.begin(),nos.end(),mid);
  int idx=it-nos.begin();
  ll to_inc=(idx-n/2)*mid-(pf[idx-1]-pf[n/2-1]);
  return (to_inc<=k);
}

void solve(){
  ll n,k;cin>>n>>k;
  vector<ll> nos(n);
  for(ll &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  if(n==1){
    cout<<nos[0]+k<<"\n";
    return;
  }
  vector<ll> pf(n);
  for(int i=0;i<n;i++){
    pf[i]=nos[i];
    if(i>0) pf[i]+=pf[i-1];
  }
  sort(nos.begin(),nos.end());
  ll lo=nos[n/2],hi=2*1e10,ans=nos[n/2];
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(check(mid,nos,pf,k,n)) ans=mid,lo=mid+1;
    else hi=mid-1;
    //cout<<"mid="<<mid<<" ans="<<ans<<"\n";
  }
  cout<<ans<<"\n";
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

