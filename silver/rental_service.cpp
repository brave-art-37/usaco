#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  ll n,m,r;cin>>n>>m>>r;

  vector<ll> cows(n);
  for(int i=0;i<n;i++) cin>>cows[i];
  sort(cows.begin(),cows.end(),greater<ll>());

  vector<pair<ll,ll>> milk(m);
  for(int i=0;i<m;i++){
    ll qty,price;cin>>qty>>price;
    milk[i]={price,qty};
  }
  sort(milk.begin(),milk.end(),greater<pair<ll,ll>>());

  vector<ll> rent(r);
  for(int i=0;i<r;i++) cin>>rent[i];
  sort(rent.begin(),rent.end(),greater<ll>());

  int total_money=0, milk_ptr=0, right=n-1, rent_ptr=0;
  for(int left=0;left<=right;left++){
    ll milk_money=0;
    while(cows[left]>0 && milk_ptr<m){
      ll used=min(milk[milk_ptr].second,cows[left]);
      milk_money+=milk[milk_ptr].first*used;
      milk[milk_ptr].second-=used;
      cows[left]-=used;
      if(milk[milk_ptr].second<=0) milk_ptr++;
    }
    ll rent_money=((rent_ptr<r)?rent[rent_ptr]:0);
    while(rent_money>milk_money){
      total_money+=rent_money;
      right--;rent_ptr++;
      rent_money=((rent_ptr<r)?rent[rent_ptr]:0);
      if(right<left) break;
    }
    if(left<=right) total_money+=milk_money;
  }
  cout<<total_money<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("rental");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
