#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=2002;
vector<vector<int>> grid(MAXN,vector<int>(MAXN));

bool comfy(int a, int b){
  int cnt=0;
  if(a>0 && grid[a-1][b]==1) cnt++;
  if(b>0 && grid[a][b-1]==1) cnt++;
  if(a<MAXN-1 && grid[a+1][b]==1) cnt++;
  if(b<MAXN-1 && grid[a][b+1]==1) cnt++;
  return (cnt==3);
}

pair<int,int> to_fill(int a, int b){
  if(!comfy(a,b)) return {a,b};
  if(a>0 && grid[a-1][b]==0) return {a-1,b};
  if(b>0 && grid[a][b-1]==0) return {a,b-1};
  if(a<MAXN-1 && grid[a+1][b]==0) return {a+1,b};
  if(b<MAXN-1 && grid[a][b+1]==0) return {a,b+1};
  return {a,b};
}

void solve(){
  int n;cin>>n;
  int total=0;
  for(int i=0;i<n;i++){

    pair<int,int> cow;cin>>cow.first>>cow.second;cow.first+=501, cow.second+=501;

    //event: fill missing spot
    queue<pair<int,int>> q;
    q.push(cow);
    while(!q.empty()){
      auto p=q.front();q.pop();
      int a=p.first, b=p.second;
      if(a<0 || b<0 || a>=MAXN || b>=MAXN || grid[a][b]==1) continue;
      grid[a][b]=1;
      total++;
      if(comfy(a,b)) q.push(to_fill(a,b));
      else if(a>0 && grid[a-1][b]==1 && comfy(a-1,b)) q.push(to_fill(a-1,b));
      else if(b>0 && grid[a][b-1]==1 && comfy(a,b-1)) q.push(to_fill(a,b-1));
      else if(a<MAXN-1 && grid[a+1][b]==1 && comfy(a+1,b)) q.push(to_fill(a+1,b));
      else if(b<MAXN-1 && grid[a][b+1]==1 && comfy(a,b+1)) q.push(to_fill(a,b+1));
    }

    cout<<(total-i-1)<<"\n";
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

