#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<int>> grid(n,vector<int>(m));
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<m;j++){
      grid[i][j]=(s[j]=='.');
    }
  }

  vector<vector<int>> visited(n,vector<int>(m));

  int compNum=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(visited[i][j]) continue;
      stack<pair<int,int>> st;
      st.push({i,j});
      while(!st.empty()){
        auto p=st.top();st.pop();
        int x=p.first, y=p.second;
        if(x<0 || x>=n || y<0 || y>=m || visited[x][y] || grid[x][y]==0) continue;
        visited[x][y]=1;
        st.push({x+1,y});
        st.push({x-1,y});
        st.push({x,y+1});
        st.push({x,y-1});
      }
      compNum+=(grid[i][j]==1);
    }
  }
  cout<<compNum<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

