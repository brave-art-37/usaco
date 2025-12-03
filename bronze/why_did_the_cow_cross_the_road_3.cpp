#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<pair<int,int>> data;
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    data.push_back({a,b});
  }
  sort(data.begin(),data.end());
  int tm=0;
  for(int i=0;i<n;i++){
    tm=max(tm,data[i].first);
    tm+=data[i].second;
  }
  cout<<tm<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("cowqueue");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

