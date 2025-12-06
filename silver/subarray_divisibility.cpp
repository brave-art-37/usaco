#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  long long n;cin>>n;
  vector<long long> pf(n+1);
  vector<long long> nos(n);
  nos[0]=1;
  for(int i=1;i<=n;i++){
    long long tmp;cin>>tmp;
    pf[i]=pf[i-1]+tmp;
    pf[i]=(n+(pf[i]%n))%n;
    nos[pf[i]]++;
  }
  long long ans=0;
  for(int i=0;i<n;i++){
    ans+=(nos[i]*(nos[i]-1))/2;
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

