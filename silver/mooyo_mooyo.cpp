#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void print(vector<vector<int>> grid, int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<10;j++){
      cout<<grid[i][j];
    }
    cout<<"\n";
  }
  cerr<<"\n";
}

void solve(){
  int n,k;cin>>n>>k;
  vector<vector<int>> grid(n,vector<int>(10));
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<10;j++){
      grid[i][j]=(s[j]-'0');
    }
  }
  vector<pair<int,int>> dir={
    {1,0},{0,1},{-1,0},{0,-1}
  };
  int change=1;
  int iter=0;
  while(change>0){
    //cerr<<"iter= "<<iter<<"\n";iter++;

    vector<vector<int>> tmp1(n,vector<int>(10));
    for(int j=0;j<10;j++){
      int gptr=n-1;
      for(int i=n-1;i>-1;i--){
        while(gptr>-1 && grid[gptr][j]==0) gptr--;
        if(gptr==-1) break;
        tmp1[i][j]=grid[gptr][j];gptr--;
      }
    }
    //print(tmp1,n);

    for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
        change+=(grid[i][j]!=tmp1[i][j]);
        grid[i][j]=tmp1[i][j];
      }
    }

    vector<vector<int>> comp(n,vector<int>(10,-1));
    change=0;
    vector<int> compsz;
    int compNum=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
        if(comp[i][j]!=-1 || grid[i][j]==0) continue;
        int sz=0;
        stack<pair<int,int>> st;
        st.push({i,j});
        while(!st.empty()){
          auto p=st.top();st.pop();
          comp[p.first][p.second]=compNum;
          sz++;
          for(int b=0;b<4;b++){
            int x=p.first+dir[b].first;
            int y=p.second+dir[b].second;
            if(x<0 || x>=n || y<0 || y>=10 || comp[x][y]!=-1 || grid[x][y]!=grid[p.first][p.second]) continue;
            st.push({x,y});
          }
        }
        compNum++;
        compsz.push_back(sz);
      }
    }
    set<int> rem;
    for(int i=0;i<compNum;i++){
      if(compsz[i]<k) continue;
      rem.insert(i);
    }
    for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
        if(grid[i][j]==0 || rem.count(comp[i][j])==0) continue;
        grid[i][j]=0;
      }
    }
    //print(grid,n);

    vector<vector<int>> tmp(n,vector<int>(10));
    for(int j=0;j<10;j++){
      int gptr=n-1;
      for(int i=n-1;i>-1;i--){
        while(gptr>-1 && grid[gptr][j]==0) gptr--;
        if(gptr==-1) break;
        tmp[i][j]=grid[gptr][j];gptr--;
      }
    }
    //print(tmp,n);

    for(int i=0;i<n;i++){
      for(int j=0;j<10;j++){
        change+=(grid[i][j]!=tmp[i][j]);
        grid[i][j]=tmp[i][j];
      }
    }

    //print(grid,n);
    //print(comp,n);
  }
  print(grid,n);
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("mooyomooyo");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

