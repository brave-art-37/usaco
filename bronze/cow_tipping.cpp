#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<string> grid(n);
  for(string &s:grid){cin>>s;}
  vector<vector<int>> flips(n,vector<int>(n));
  int count=0;
  for(int i=n-1;i>-1;i--){
    for(int j=n-1;j>-1;j--){
      if(i<n-1) flips[i][j]+=flips[i+1][j];
      if(j<n-1) flips[i][j]+=flips[i][j+1];
      if(i<n-1 && j<n-1) flips[i][j]-=flips[i+1][j+1];
      if((flips[i][j]+(grid[i][j]-'0'))%2==1){
        count++;
        flips[i][j]++;
      }
    }
  }
  cout<<count<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("cowtip");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

