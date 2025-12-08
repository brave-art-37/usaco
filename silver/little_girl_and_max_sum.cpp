#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  int n,q;cin>>n>>q;
  vector<ll> nos(n+1);
  for(int i=1;i<n+1;i++){cin>>nos[i];}
  vector<ll> diff(n+2);
  while(q--){
    int l,r;cin>>l>>r;
    diff[l]++,diff[r+1]--;
  }
  for(int i=1;i<n+2;i++){
    diff[i]+=diff[i-1];
  }
  sort(nos.begin(),nos.end());
  sort(diff.begin(),diff.end());
  ll sum=0;
  for(int i=0;i<n+1;i++){
    sum+=(1LL*nos[i]*diff[i+1]);
  }
  cout<<sum<<"\n";
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

