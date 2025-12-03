#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  long long n;cin>>n;
  vector<long long> nos(n);
  for(long long &x:nos){cin>>x;}
  set<pair<long long,long long>> ans;
  sort(nos.begin(),nos.end());
  for(int i=n-1;i>-1;i--){
    ans.insert({-1LL*nos[i]*(n-i),nos[i]});
  }
  for(auto p:ans){
    cout<<-1LL*p.first<<' '<<p.second<<"\n";
    break;
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

