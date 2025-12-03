#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  string a,b;cin>>a>>b;
  int count=0;
  a+='H';b+='H';
  for(int i=1;i<=n;i++){
    count+=(a[i]==b[i] && a[i-1]!=b[i-1]);
    //if(a[i]==b[i] && a[i-1]!=b[i-1]) cout<<i<<' ';
  }
  cout<<count<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("breedflip");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
