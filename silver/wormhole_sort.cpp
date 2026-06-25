#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif


int last_true(int lo, int hi, function<bool(int)> f){
  int ans=lo;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid, lo=mid+1;
    else hi=mid-1;
  }
  return ans;
}

void dfs(int u, vector<int>& comp, vector<vector<int>>& adj, vector<int>& visited){
  visited[u]=1;
  for(int v:adj[u]){
    if(visited[v]) continue;
    comp[v]=comp[u];
    dfs(v,comp,adj,visited);
  }
}

void solve(){
  int n,m;cin>>n>>m;
  vector<pair<int,int>> check;
  for(int i=0;i<n;i++){
    int num;cin>>num;num--;
    if(num==i) continue;
    check.push_back(make_pair(num,i));
  }

  vector<pair<int,pair<int,int>>> data(m);
  for(int i=0;i<m;i++){
    cin>>data[i].second.first>>data[i].second.second>>data[i].first;
  }
  sort(data.begin(),data.end());

  vector<int> search(m);
  for(int i=0;i<m;i++) search[i]=data[i].first;

  //cerr<<"data: ";for(auto p:data) cerr<<p.first<<' ';cerr<<"\n";
  if(check.empty()) {
    cout<<-1<<"\n";
    return;
  }
  //cerr<<"check: ";for(auto p:check) cerr<<p.first<<","<<p.second<<' ';cerr<<"\n";

  int idx=last_true(search[0],search.back(), [&](int w){
      auto it=lower_bound(search.begin(),search.end(),w);
      int i=(it-search.begin());

      vector<vector<int>> adj(n);
      for(int j=i;j<n;j++){
        int a=data[j].second.first;a--;
        int b=data[j].second.second;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
      }

      vector<int> comp(n);
      vector<int> visited(n);
      int counter=1;
      for(int u=0;u<n;u++){
        if(visited[u]) continue;
        comp[u]=counter;
        dfs(u, comp, adj, visited);
        counter++;
      }

      int isit=1;
      for(auto p:check){
        isit&=(comp[p.first]==comp[p.second]);
      }

      return isit;

      });
  cout<<data[idx].first<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("wormsort");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

