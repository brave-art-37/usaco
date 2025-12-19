#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

ll last_true(ll lo, ll hi, function<bool(int)> f){
  ll ans=0;
  while(lo<=hi){
    ll mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid,lo=mid+1;
    else hi=mid-1;
  }
  return ans;
}

void solve(){
  ll n,m;cin>>n>>m;
  vector<pair<ll,ll>> data(m);
  ll mini=LLONG_MAX,maxi=0;
  for(int i=0;i<m;i++){
    ll a,b;cin>>a>>b;
    data[i]={a,b};
    mini=min(mini,a);
    maxi=max(maxi,b);
  }
  sort(data.begin(),data.end());
  vector<ll> st(m),nd(m);
  for(int i=0;i<m;i++){
    st[i]=data[i].first;
    nd[i]=data[i].second;
  }
  cout<<last_true(1,(maxi-mini)/(n-1),[&](int d){
      //cout<<"d= "<<d<<"\n";

      ll total_used=1;
      ll last_place=st[0];
      int idx=0;

      /*cout<<"st= ";
      for(int num:st) cout<<num<<' ';cout<<"\n";
      cout<<"nd= ";
      for(int num:nd) cout<<num<<' ';cout<<"\n\n";*/

      while(last_place<nd.back() && total_used<n){
        while(idx<m && last_place+d>=st[idx]) idx++;
        if(idx>0 && last_place+d<=nd[idx-1]) last_place+=d;
        else if(idx<m) last_place=st[idx];
        else break;
        total_used++;

        //cout<<"total_used= "<<total_used<<"\n";
        //cout<<"last_place= "<<last_place<<"\n\n";

      }
      return (total_used>=n);
      })<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("socdist");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

