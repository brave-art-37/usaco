#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,q;cin>>n>>q;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  while(q--){
    int a,b;cin>>a>>b;
    auto it2=upper_bound(nos.begin(),nos.end(),b);
    auto it1=lower_bound(nos.begin(),nos.end(),a);
    int num=distance(it1,it2);
    cout<<num<<"\n";
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("haybales");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

