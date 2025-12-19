#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n,k;cin>>n>>k;
  vector<ll> nos(n);
  vector<ll> pf(n);
  for(ll &x:nos) cin>>x;
  sort(nos.begin(),nos.end());

  //cout<<"pf=";

  for(int i=0;i<n;i++){
    if(i>0) pf[i]+=pf[i-1];
    pf[i]+=nos[i];

    //cout<<pf[i]<<' ';
  }

  //cout<<"\n";

  if(nos.back()==nos[0]){
    cout<<0<<"\n";
    return;
  }
  ll lo=0,hi=nos.back()-nos[0],ans=hi;
  while(lo<=hi){
    ll diff=lo+(hi-lo)/2;

    //cout<<"diff="<<diff<<"\n";
    
    ll mini=LLONG_MAX;

    for(int i=0;i<n;i++){
      auto it=lower_bound(nos.begin()+i+1, nos.end(), nos[i]+diff);
      if(it==nos.end()) break;
      int idx=it-nos.begin();
      ll moves=(1LL*(i+1)*nos[i]-pf[i])+((pf.back()-pf[idx-1])-1LL*(n-idx)*(nos[i]+diff));

      //cout<<(i+1)*nos[i]-pf[i]<<' '<<(pf.back()-pf[idx-1])-(n-idx)*(nos[i]+diff)<<"\n";

      mini=min(mini,moves);

      //cout<<"i="<<i<<" idx="<<idx<<" moves="<<moves<<"\n";
    }

    //cout<<"\n";

    for(int i=n-1;i>0;i--){
      auto it=lower_bound(nos.begin(),nos.begin()+i, nos[i]-diff);
      if(it==nos.begin()) break;
      int idx=(it-nos.begin()-1);
      ll moves=(1LL*(idx+1)*(nos[i]-diff)-pf[idx])+((pf.back()-pf[i-1])-1LL*(n-i)*nos[i]);

     // cout<<(idx+1)*(nos[i]-diff)-pf[idx]<<' '<<(pf.back()-pf[i-1])-(n-i)*nos[i]<<"\n";

      mini=min(mini,moves);

     // cout<<"i="<<i<<" idx="<<idx<<" moves="<<moves<<"\n";
    }

   //cout<<"\n";

    if(mini<=k) ans=diff,hi=diff-1;
    else lo=diff+1;
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

