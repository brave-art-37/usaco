#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ld=long double;

void solve(){
  ld E=1e-8;
  int n;cin>>n;
  vector<ld> x(n),v(n);
  for(ld &p:x) cin>>p;
  for(ld &p:v) cin>>p;
  ld lo=E,hi=LLONG_MAX,ans=LLONG_MAX;
  while((hi-lo)>E){
    ld mid=lo+(hi-lo)/2;
    ld st=(x[0]-mid*v[0]),nd=(x[0]+mid*v[0]);
    for(int i=1;i<n;i++){
      st=max(st,x[i]-mid*v[i]);
      nd=min(nd,x[i]+mid*v[i]);
    }
    if(st<=nd) ans=lo, hi=mid;
    else lo=mid;
    //cout<<mid<<"\n";
  }
  cout<<setprecision(12)<<ans<<"\n";
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

