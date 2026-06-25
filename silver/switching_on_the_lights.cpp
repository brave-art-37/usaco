#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif


const int MAXN=100;
int n,m;
vector<vector<int>> vis(MAXN,vector<int>(MAXN));
vector<vector<int>> lit(MAXN,vector<int>(MAXN));
map<pair<int,int>,set<pair<int,int>>> on;
queue<pair<int,int>> q;


int bfs(int n, int cnt){
  set<pair<int,int>> restart;
  while(!q.empty()){
    int x=q.front().first, y=q.front().second;q.pop();
    if(vis[x][y]==1) continue;
    vis[x][y]=1;
    auto it=on.find({x,y});
    if(it!=on.end()){
      auto &v=*it;
      for(auto &p:v.second){
        if(lit[p.first][p.second]) continue;
        cnt++;
        lit[p.first][p.second]=1;
        restart.insert(p);
      }
    }
    if(x>0 && lit[x-1][y]) q.push({x-1,y});
    if(x<n-1 && lit[x+1][y]) q.push({x+1,y});
    if(y>0 && lit[x][y-1]) q.push({x,y-1});
    if(y<n-1 && lit[x][y+1]) q.push({x,y+1});
  }

  for(auto &p:restart){
    int x=p.first, y=p.second;
    if(vis[x][y]) continue;
    int valid=0;
    if(x>0) valid|=vis[x-1][y];
    if(x<n-1) valid|=vis[x+1][y];
    if(y>0) valid|=vis[x][y-1];
    if(y<n-1) valid|=vis[x][y+1];
    if(!valid) continue;
    q.push(p);
    cnt=bfs(n,cnt);
  }
  return cnt;
}

void solve(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int x,y,a,b;cin>>x>>y>>a>>b;x--,y--,a--,b--;
    on[make_pair(x,y)].insert({a,b});
  }
  
  lit[0][0]=1;
  q.push({0,0});
  cout<<bfs(n,1)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("lightson");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
