#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

ll square(ll num){
  return num*num;
}

bool check(pair<ll,ll> p1, ll t1, pair<ll,ll> p2, ll t2){
  return (square(p1.first-p2.first)+square(p1.second-p2.second)>square(t2-t1));
}

void solve(){
  int g,n;cin>>g>>n;
  vector<pair<ll,pair<ll,ll>>> data(g);
  for(int i=0;i<g;i++){
    ll x,y,t;cin>>x>>y>>t;
    data[i]={t,{x,y}};
  }
  sort(data.begin(),data.end());
  vector<ll> time(g);
  vector<pair<ll,ll>> loc(g);
  for(int i=0;i<g;i++){
    time[i]=data[i].first;
    loc[i]=data[i].second;
  }
  int count=0;
  for(int i=0;i<n;i++){
    ll x,y,t;cin>>x>>y>>t;
    auto it=lower_bound(time.begin(),time.end(),t);
    //if(it==time.end()) continue;
    int free=0;
    int idx=(it-time.begin());
    if(idx<g && check(loc[idx],time[idx],{x,y},t)) free=1;
    else if(idx>0 && check(loc[idx-1],time[idx-1],{x,y},t)) free=1;
    count+=free;
  }
  cout<<count<<"\n";
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

