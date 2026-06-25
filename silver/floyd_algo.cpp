#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> next(n+1);
  for(int i=1;i<=n;i++){
    cin>>next[i];
  }

  int st;cin>>st;
  int slow=next[st], fast=next[next[st]];
  while(slow!=fast){
    slow=next[slow];
    fast=next[next[fast]];
  }
  slow=st;
  int entry=0;
  while(slow!=fast){
    entry++;
    slow=next[slow];
    fast=next[fast];
  }
  int len=1;
  fast=next[fast];
  while(slow!=fast){
    len++;
    fast=next[fast];
  }
  cout<<len<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}
