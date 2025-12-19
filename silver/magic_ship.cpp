#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll x1,y1;cin>>x1>>y1;
  ll x2,y2;cin>>x2>>y2;
  ll n;cin>>n;
  string s;cin>>s;s=' '+s;
  vector<ll> pfx(n+1),pfy(n+1);
  for(int i=1;i<n+1;i++){
    pfx[i]+=pfx[i-1], pfy[i]+=pfy[i-1];
    pfx[i]+=1LL*(s[i]=='L')-1LL*(s[i]=='R');
    pfy[i]+=1LL*(s[i]=='U')-1LL*(s[i]=='D');
  }
  ll maxi=abs(y2-y1)+abs(x2-x1)+4LL*n;

  ll lo=1,hi=5LL*1e11,ans=LLONG_MAX;
  while(lo<=hi){
    int d=lo+(hi-lo)/2;
    ll x3=x1+(d/n)*pfx.back()+pfx[d%n];
    ll y3=y1+(d/n)*pfy.back()+pfy[d%n];
    if(abs(x3-x2)+abs(y3-y2)<=d) ans=d,hi=d-1;
    else lo=d+1;
  }
  if(ans>=LLONG_MAX) cout<<-1<<"\n";
  else cout<<ans<<"\n";
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
