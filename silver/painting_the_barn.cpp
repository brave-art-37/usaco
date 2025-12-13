#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll N=1000;
  ll n,k;cin>>n>>k;
  //int diff[N+2][N+2];
  int grid[N+2][N+2];
  //vector<vector<ll>> diff(N+2,vector<ll>(N+2));
  while(n--){
    ll x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
    /*diff[x1][y1]++,diff[x2][y2]++;
    diff[x1][y2]--,diff[x2][y1]--;*/
    grid[x1][y1]++,grid[x2][y2]++;
    grid[x1][y2]--,grid[x2][y1]--;
  }
  /*for(int i=0;i<N+1;i++){
    for(int j=0;j<N+1;j++){
      if(diff[i][j]==-1) cout<<2<<' ';
      else cout<<diff[i][j]<<' ';
    }
    cout<<"\n";
  }
  cout<<"\n";*/
  //int grid[N+1][N+1];
  //vector<vector<ll>> grid(N+1,vector<ll>(N+1));
  ll count=0;
  for(int i=1;i<N+1;i++){
    for(int j=1;j<N+1;j++){
      //grid[i][j]=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1]+diff[i][j];
      grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
      //cout<<grid[i][j]<<' ';
      count+=(grid[i][j]==k);
    }
    //cout<<"\n";
  }
  cout<<count<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("paintbarn");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
