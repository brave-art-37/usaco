#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int x1,x2,x3,x4;
  int y1,y2,y3,y4;
  cin>>x1>>y1>>x2>>y2;
  cin>>x3>>y3>>x4>>y4;
  int tmp=max(max(x4,x2)-min(x3,x1),max(y4,y2)-min(y3,y1));
  cout<<tmp*tmp<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("square");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

