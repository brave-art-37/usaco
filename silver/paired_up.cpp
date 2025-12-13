#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  int n;cin>>n;
  vector<pair<int,int>> nos(n);
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    nos[i]={b,a};
  }
  sort(nos.begin(),nos.end());
  int ans=0,i=0,j=n-1;
  while(i<=j){
    ans=max(ans,nos[i].first+nos[j].first);
    int used=min(nos[i].second,nos[j].second);
    nos[i].second-=used;
    nos[j].second-=used;
    if(nos[i].second<=0) i++;
    if(nos[j].second<=0) j--;
  }
  cout<<ans<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("pairup");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

