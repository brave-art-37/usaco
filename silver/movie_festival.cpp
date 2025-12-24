#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<pair<int,int>> data(n);
  for(int i=0;i<n;i++){
    cin>>data[i].second>>data[i].first;
  }
  sort(data.begin(),data.end());
  int t=0, curr=0, count=0;
  while(curr<n){
    if(data[curr].second>=t) t=data[curr].first, count++;
    curr++;
  }
  cout<<count<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

