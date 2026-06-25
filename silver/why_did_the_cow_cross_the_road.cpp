#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  //Attempt 1
  /*int c,n;cin>>c>>n;
  vector<int> cken(c);
  for(int &x:cken) cin>>x;
  vector<pair<int,int>> cows(n);
  for(int i=0;i<n;i++) cin>>cows[i].first>>cows[i].second;
  sort(cken.begin(),cken.end());
  sort(cows.begin(),cows.end());
  int count=0, j=0;
  for(int i=0;i<n;i++){
    if(j>=c) break;
    
    while(j<c && cken[j]<cows[i].first) j++;
    if(j<c && cows[i].first<=cken[j] && cken[j]<=cows[i].second) count++, j++;

  }
  cout<<count<<"\n";

  cerr<<"cken=";for(int num:cken) cerr<<num<<' ';cerr<<"\n";
  cerr<<"cows=";for(auto p:cows) cerr<<"("<<p.first<<","<<p.second<<") ";cerr<<"\n";*/

  //Attempt 2
 /* int c,n;cin>>c>>n;
  multiset<int> cken;
  for(int i=0;i<c;i++) { int tmp;cin>>tmp; cken.insert(tmp); }
  vector<pair<int,int>> cows(n);
  for(int i=0;i<n;i++) { cin>>cows[i].first>>cows[i].second; }
  sort(cows.begin(),cows.end());
  int count=0;
  for(int i=0;i<n;i++){
    auto it=cken.lower_bound(cows[i].first);
    if(it==cken.end()) continue;
    else if(*it<=cows[i].second) count++, cken.erase(it);
  }
  cout<<count<<"\n";*/

  //Attempt 3
  int c,n;cin>>c>>n;
  vector<int> cken(c);
  for(int &x:cken) cin>>x;
  sort(cken.begin(),cken.end());
  vector<pair<int,int>> cows(n);
  for(int i=0;i<n;i++){cin>>cows[i].second>>cows[i].first;}
  sort(cows.begin(),cows.end());
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  int count=0;
  int j=0;
  for(int i=0;i<c;i++){
    while(j<n && cows[j].first>=cken[i]) pq.push(cows[j]), j++;
    if(!pq.empty() && pq.top().second<=cken[i]) count++, pq.pop();
  }
  cout<<count<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("helpcross");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
