#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int x,y,m;cin>>x>>y>>m;
  int maxi=0,i=0;
  while(y*i<=m){
    maxi=max(maxi,m-(m-y*i)%x);
    i++;
  }
  cout<<maxi<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("pails");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

