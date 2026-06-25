#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n,m;cin>>n>>m;
  vector<string> grid(n);
  vector<vector<int>> comp(n,vector<int>(m));
  vector<vector<int>> isgood(n,vector<int>(m));
  vector<vector<int>> isbad(n,vector<int>(m));
  for(int i=0;i<n;i++){
    cin>>grid[i];
    for(int j=0;j<m;j++){
      isgood[i][j]=(grid[i][j]=='G');
      isbad[i][j]=(grid[i][j]=='B');
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!isbad[i][j]) continue;
      if(i>0 && !isgood[i-1][j] && !isbad[i-1][j]) grid[i-1][j]='#';
      if(i<n-1 && !isgood[i+1][j] && !isbad[i+1][j]) grid[i+1][j]='#';
      if(j>0 && !isgood[i][j-1] && !isbad[i][j-1]) grid[i][j-1]='#';
      if(j<m-1 && !isgood[i][j+1] && !isbad[i][j+1]) grid[i][j+1]='#';
    }
  }
  stack<pair<int,int>> st;
  st.push({n-1,m-1});
  while(!st.empty()){
    int i=st.top().first, j=st.top().second;st.pop();
    if(i<0 || i>=n || j<0 || j>=m || comp[i][j]!=0 || grid[i][j]=='#') continue;
    comp[i][j]=1;
    st.push({i+1,j});
    st.push({i-1,j});
    st.push({i,j+1});
    st.push({i,j-1});
  }
  int valid=1;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!isgood[i][j]) continue;
      valid&=comp[i][j];
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(!isbad[i][j]) continue;
      valid&=(!comp[i][j]);
    }
  }
  if(valid) cout<<"YES\n";
  else cout<<"NO\n";
  
  cerr<<"grid=\n";
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cerr<<grid[i][j]<<" ";
    }
    cerr<<"\n";
  }
  cerr<<"comp=\n";
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cerr<<comp[i][j]<<" ";
    }
    cerr<<"\n";
  }
  
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  cin >> _;
  while (_--){solve();}}

