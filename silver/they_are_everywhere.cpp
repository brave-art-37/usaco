#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  string s;cin>>s;
  set<char> found;
  for(int i=0;i<n;i++){
    found.insert(s[i]);
  }
  int distinct_chars=found.size();
  found.clear();
  int ans=n;
  map<char,int> last_index;
  for(int i=0;i<n;i++){
    last_index[s[i]]=i;
    found.insert(s[i]);
    if(found.size()<distinct_chars) continue;
    int mini=i;
    for(auto p:last_index) mini=min(mini,p.second);
    ans=min(ans,i-mini+1);
  }
  cout<<ans<<"\n";
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

