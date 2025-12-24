#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<int> first(n/2), second(n-n/2);
  set<int> used;
  for(int i=0;i<n/2;i++){
    cin>>first[i];
    used.insert(first[i]);
  }
  for(int i=0;i<n-n/2;i++){
    cin>>second[i];
    used.insert(second[i]);
  }
  set<int> have;
  for(int i=1;i<=2*n;i++){
    if(used.count(i)==1) continue;
    have.insert(i);
  }
  set<int> ff, ss;
  for(int num:have){
    if(ss.size()>=(n-n/2)) ff.insert(num);
    else ss.insert(-1*num);
  }
  vector<int> un(n/2), deux(n-n/2);
  for(int i=0;i<n/2;i++){
    auto it=ff.lower_bound(first[i]);
    if(it==ff.end()) it=ff.begin();
    un[i]=*it, ff.erase(it);
  }
  for(int i=0;i<n-n/2;i++){
    auto it=ss.lower_bound(-1*second[i]);
    if(it==ss.end()) it=ss.begin();
    deux[i]=-1*(*it), ss.erase(it);
  }
  int score=0;
  for(int i=0;i<n/2;i++) score+=(un[i]>first[i]);
  for(int i=0;i<n-n/2;i++) score+=(deux[i]<second[i]);
  cout<<score<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("cardgame");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

