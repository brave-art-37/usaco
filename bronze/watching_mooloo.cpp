#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  long long n,k;cin>>n>>k;
  vector<long long> nos(n);
  for(long long &x:nos){cin>>x;}
  long long cost=k+1;
  for(int i=1;i<n;i++){
    cost+=min(nos[i]-nos[i-1],k+1);
  }
  cout<<cost<<"\n";
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

