#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  string s;cin>>s;
  int N=0,E=0,W=0,S=0;
  pair<int,int> curr={0,0};
  for(int i=0;i<n;i++){
    curr.first+=(s[i]=='E')-(s[i]=='W');
    curr.second+=(s[i]=='N')-(s[i]=='S');
    N=max(N,curr.second);
    S=max(S,-curr.second);
    E=max(E,curr.first);
    W=max(W,-curr.first);
  }
  //cerr<<N<<' '<<E<<' '<<W<<' '<<S<<"\n";
  int x=3+2*E+2*W, y=3+2*N+2*S;
  vector<vector<char>> grid(x,vector<char>(y,'.'));
  map<char,pair<int,int>> dir;
  dir['N']={0,1};
  dir['S']={0,-1};
  dir['E']={1,0};
  dir['W']={-1,0};
  curr={2*W+1,2*S+1};
  grid[curr.first][curr.second]='#';
  for(int i=0;i<n;i++){
    auto p=dir[s[i]];
    for(int j=0;j<2;j++){
      curr.first+=p.first;
      curr.second+=p.second;
      grid[curr.first][curr.second]='#';
      //cerr<<"curr= "<<curr.first<<' '<<curr.second<<"\n";
    }
  }
  /*
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      cerr<<grid[i][j];
    }
    cerr<<"\n";
  }
  */

  int compNum=0;
  vector<vector<int>> comp(x,vector<int>(y,-1));
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if(comp[i][j]!=-1 || grid[i][j]=='#') continue;
      stack<pair<int,int>> st;
      st.push({i,j});
      while(!st.empty()){
        int u=st.top().first, v=st.top().second; st.pop();
        comp[u][v]=compNum;
        if(u>0 && comp[u-1][v]==-1 && grid[u-1][v]!='#') st.push({u-1,v});
        if(u<x-1 && comp[u+1][v]==-1 && grid[u+1][v]!='#') st.push({u+1,v});
        if(v>0 && comp[u][v-1]==-1 && grid[u][v-1]!='#') st.push({u,v-1});
        if(v<y-1 && comp[u][v+1]==-1 && grid[u][v+1]!='#') st.push({u,v+1});
      }
      compNum++;
    }
  }
  /*
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      if(comp[i][j]==-1) cerr<<'.';
      else cerr<<comp[i][j];
    }
    cerr<<"\n";
  }
  */
  cout<<compNum-1<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("gates");
  int _ = 1;
 //cin >> _;
  while (_--){solve();}}

