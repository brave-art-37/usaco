#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=1000;
vector<int> x(MAXN);
vector<int> y(MAXN);
vector<int> visited(MAXN);

int dist_sq(int u, int v){
  return (x[v]-x[u])*(x[v]-x[u])+(y[v]-y[u])*(y[v]-y[u]);
}

int dfs(int u, int n, int X){
  visited[u]=1;
  int count=1;
  for(int v=0;v<n;v++){
    if(visited[v] || dist_sq(u,v)>X) continue;
    count+=dfs(v,n,X);
  }
  return count;
}

int first_true(int lo, int hi, function<bool(int)>f){
  int ans=hi;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid, hi=mid-1;
    else lo=mid+1;
  }
  return ans;
}

void solve(){
  int n;cin>>n;
  for(int i=0;i<n;i++){
    cin>>x[i]>>y[i];
  }

  cout<< first_true(0,625000000, [&](int X){
      fill(visited.begin(),visited.end(),0);
      int count=dfs(0,n,X);
      return (count==n);
      }) <<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("moocast");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

