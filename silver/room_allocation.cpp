#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<pair<pair<int,int>,int>> data(n);
  for(int i=0;i<n;i++) { cin>>data[i].first.first>>data[i].first.second; data[i].second=i;}
  sort(data.begin(),data.end());
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
  int rooms=0;
  vector<int> ans(n);
  for(int i=0;i<n;i++){
    if(!pq.empty() && pq.top().first<data[i].first.first){
      pair<int,int> tmp={data[i].first.second,pq.top().second};
      ans[data[i].second]=pq.top().second;
      pq.pop();
      pq.push(tmp);
    }
    else rooms++, pq.push({data[i].first.second,rooms}), ans[data[i].second]=rooms;
  }
  cout<<rooms<<"\n";
  for(int num:ans) cout<<num<<' ';cout<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

