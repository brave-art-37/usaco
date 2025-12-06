#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> a(n+1),b(n+1),c(n+1);
  for(int i=1;i<=n;i++){
    char tmp;cin>>tmp;
    a[i]=a[i-1]+(tmp=='P');
    b[i]=b[i-1]+(tmp=='H');
    c[i]=c[i-1]+(tmp=='S');
  }
  vector<int> fwd(n+1),bwd(n+1);
  int maxi=0;
  for(int i=0;i<n+1;i++){
    fwd[i]=max({a[i],b[i],c[i]});
    bwd[i]=max({a[n]-a[i],b[n]-b[i],c[n]-c[i]});
    maxi=max(fwd[i]+bwd[i],maxi);
  }
  cout<<maxi<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("hps");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

