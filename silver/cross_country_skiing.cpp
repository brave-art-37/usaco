#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif


int first_true(int lo, int hi, function<bool(int)> f){
  int ans=hi;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid, hi=mid-1;
    else lo=mid+1;
  }
  return ans;
}

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> grid(n,vector<int>(m));
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>grid[i][j];
    }
  }
  vector<pair<int,int>> wps;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      int tmp;cin>>tmp;
      if(tmp==0) continue;
      wps.push_back({i,j});
    }
  }
  cout<<first_true(0,INT_MAX,[&](int d){
      //cerr<<"d= "<<d<<"\n";

      vector<vector<int>> comp(n,vector<int>(m));
      vector<vector<int>> vis(n,vector<int>(m));
      vector<pair<int,int>> topo_sort;
      stack<pair<int,int>> st;
      st.push(wps[0]);
      while(!st.empty()){
        int x=st.top().first, y=st.top().second; st.pop();
        if(vis[x][y]==1){
          topo_sort.push_back({x,y});
          vis[x][y]=2;
        }
        else if(vis[x][y]==0){
          vis[x][y]=1;
          comp[x][y]=1;
          st.push({x,y});
          if(x>0 && abs(grid[x-1][y]-grid[x][y])<=d) st.push({x-1,y});
          if(x<n-1 && abs(grid[x+1][y]-grid[x][y])<=d) st.push({x+1,y});
          if(y>0 && abs(grid[x][y-1]-grid[x][y])<=d) st.push({x,y-1});
          if(y<m-1 && abs(grid[x][y+1]-grid[x][y])<=d) st.push({x,y+1});
        }
      }
      int valid=1;
      for(int i=0;i<wps.size();i++){
        valid&=(comp[wps[i].first][wps[i].second]==1);
      }

      /*
      cerr<<"wps=\n";
      for(auto p:wps) cerr<<"("<<p.first<<", "<<p.second<<"), ";
      cerr<<"\n";

      cerr<<"comp=\n";
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          cerr<<comp[i][j]<<' ';
        }
        cerr<<"\n";
      }

      cerr<<"valid= "<<valid<<"\n";
      cerr<<"\n";
      */

      return valid;

      })<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("ccski");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

