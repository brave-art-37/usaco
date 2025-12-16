#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<ll> a(n+1);
  vector<set<ll>> idx(n+1,set<ll>());
  for(int i=1;i<n+1;i++){
    cin>>a[i];
  }
  for(ll i=1;i<n+1;i++){
    int tmp;cin>>tmp;
    idx[tmp].insert(i);
  }
  ll count=0LL;
  for(ll i=1;i<n+1;i++){
    set<ll> data=idx[a[i]];
    for(ll j:data){
      count++;
      if(j<i) count+=1LL*min(j-1,n-i);
      else count+=1LL*min(i-1,n-j);
      if(j==i){
        count+=1LL*((j-1)*j)/2;
        count+=1LL*((n-j)*(n-j+1))/2;
      }
    }
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

