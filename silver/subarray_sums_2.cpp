#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  long long n,x;cin>>n>>x;
  vector<long long> pf(n+1);
  long long ans=0LL;
  map<long long,long long> sum;
  sum[0]=1;
  for(int i=1;i<=n;i++){
    long long tmp;cin>>tmp;
    pf[i]=pf[i-1]+tmp;
    if(sum.count(pf[i]-x)){
      ans+=sum[pf[i]-x];
    }
    sum[pf[i]]++;
  }
  cout<<ans<<"\n";
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

