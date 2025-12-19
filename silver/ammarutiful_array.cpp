#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<ll> vals(n),cols(n);
  for(ll &x:vals) cin>>x;
  for(ll &x:cols) cin>>x;
  map<ll,vector<ll>> cols_arr;
  map<ll,ll> dec;
  ll inc=0;
  for(int i=0;i<n;i++){
    if(!cols_arr.count(cols[i])) cols_arr[cols[i]]={0}, dec[cols[i]]=0;
    vector<ll> &tmp=cols_arr[cols[i]];
    tmp.push_back(tmp.back()+vals[i]);
  }

  /*for(auto p:cols_arr){
    cout<<p.first<<": ";
    for(auto tmp:p.second){
      cout<<tmp<<' ';
    }
    cout<<"\n";
  }*/

  ll q;cin>>q;
  while(q--){
    ll ops,col,y;cin>>ops>>col>>y;
    if(ops==1) inc+=y,dec[col]+=y;
    else{
      ll add=inc-dec[col];
      vector<ll> pf=cols_arr[col];
      ll lo=0,hi=pf.size()-1,ans=0;
      while(lo<=hi){
        int idx=lo+(hi-lo)/2;
        ll sum=pf[idx]+add*idx;
        if(sum<=y) ans=idx,lo=idx+1LL;
        else hi=idx-1LL;
      }
      cout<<ans<<"\n";
    }

    //cerr<<"inc="<<inc<<" dec="<<dec[col]<<"\n";

  }
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
