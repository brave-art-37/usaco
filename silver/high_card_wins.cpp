#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> opp(n);
  set<int> used;
  set<int> have;
  for(int &x:opp) cin>>x, used.insert(x);
  for(int i=1;i<=2*n;i++){
    if(used.count(i)==1) continue;
    have.insert(i);
  }
  vector<int> me(n);
  for(int i=0;i<n;i++){
    auto it=have.lower_bound(opp[i]);
    if(it==have.end()) it=have.begin();
    me[i]=*it;
    have.erase(it);
  }
  int score=0;
  for(int i=0;i<n;i++) score+=(me[i]>opp[i]);
  cout<<score<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("highcard");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

