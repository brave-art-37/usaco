#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

vector<vector<int>> dist(101,vector<int>(101,INT_MAX/2));
queue<pair<int,int>> q;
int x,y,k,m;

void next(int i, int j){
  vector<pair<int,int>> v={ {0,j}, {i,0}, {x,j}, {i,y}, {i+min(x-i,j), j-min(x-i,j)}, {i-min(y-j,i), j+min(y-j,i)} };
  for(auto p:v){
    if(dist[p.first][p.second]<=dist[i][j]) continue;
    dist[p.first][p.second]=dist[i][j]+1;
    q.push(p);
    //cerr<<"("<<p.first<<", "<<p.second<<")\n";
  }
  //cerr<<"("<<i<<", "<<j<<")\n";
}

void solve(){
  cin>>x>>y>>k>>m;
  q.push({0,0});
  dist[0][0]=0;
  while(!q.empty()){
    int i=q.front().first, j=q.front().second;q.pop();
    next(i,j);
    //cerr<<"("<<i<<", "<<j<<")\n";
  }
  int ans=m;
  for(int i=0;i<101;i++){
    for(int j=0;j<101;j++){
      if(dist[i][j]>k) continue;
      ans=min(ans,abs(m-i-j));
    }
  }
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("pails");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

