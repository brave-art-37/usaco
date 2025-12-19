#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  vector<int> last_elt;
  vector<vector<int>> lists;
  last_elt.push_back(-1*nos[0]);
  lists.push_back(vector<int>());
  lists[0].push_back(nos[0]);
  for(int i=1;i<n;i++){
    auto it=upper_bound(last_elt.begin(),last_elt.end(),-1*nos[i]);
    if(it==last_elt.end()){
      lists.push_back(vector<int>());
      lists.back().push_back(nos[i]);
      last_elt.push_back(-1*nos[i]);
    }
    else{
      int idx=(it-last_elt.begin());
      last_elt[idx]=(-1*nos[i]);
      lists[idx].push_back(nos[i]);
    }
  }
  for(vector<int> v:lists){
    for(int num:v){
      cout<<num<<' ';
    }
    cout<<"\n";
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

