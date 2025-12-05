#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int x1,x2,x3,x4,x5,x6;
  int y1,y2,y3,y4,y5,y6;
  cin>>x1>>y1>>x2>>y2;
  cin>>x3>>y3>>x4>>y4;
  cin>>x5>>y5>>x6>>y6;
  int area1=(x2-x1)*(y2-y1)-max(0,min(x2,x6)-max(x1,x5))*max(0,min(y2,y6)-max(y1,y5));
  int area2=(x4-x3)*(y4-y3)-max(0,(min(x4,x6)-max(x3,x5)))*max(0,min(y4,y6)-max(y3,y5));
  cout<<area1+area2<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("billboard");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
