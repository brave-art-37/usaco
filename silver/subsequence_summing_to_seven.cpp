#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> pf(n+1);
  for(int i=1;i<=n;i++){
    int tmp;cin>>tmp;
    pf[i]=pf[i-1]+tmp;
    pf[i]=pf[i]%7;
  }
  vector<int> mini(7,n);
  vector<int> maxi(7);
  int ans=0;
  for(int i=0;i<=n;i++){
    mini[pf[i]]=min(mini[pf[i]],i);
    maxi[pf[i]]=max(maxi[pf[i]],i);
  }
  for(int i=0;i<7;i++){
    ans=max(ans,maxi[i]-mini[i]);
  }
  cout<<ans<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("div7");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
