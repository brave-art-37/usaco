#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,q;cin>>n>>q;
  vector<vector<int>> grid(n+1,vector<int>(n+1));
  for(int i=1;i<=n;i++){
    string s;cin>>s;
    s=' '+s;
    for(int j=1;j<=n;j++){
      grid[i][j]=(s[j]=='*')+grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
    }
  }
  while(q--){
    int y1,x1,y2,x2;cin>>x1>>y1>>x2>>y2;
    x1--,y1--;
    cout<<grid[x2][y2]-grid[x2][y1]-grid[x1][y2]+grid[x1][y1]<<"\n";
    //cout<<grid[x2][y2]<<' '<<grid[x2][y1]<<' '<<grid[x1][y2]<<' '<<grid[x1][y1]<<"\n\n";
  }
  /*for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      cout<<grid[i][j]<<" \n"[j==n];
    }
  }*/
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
