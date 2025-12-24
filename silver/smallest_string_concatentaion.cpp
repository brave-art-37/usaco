#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

bool compare(string a, string b){
  return (a+b)<(b+a);
}

void solve(){
  int n;cin>>n;
  /*priority_queue<string, vector<string>, greater<string>> pq;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    pq.push(s);
  }
  while(pq.size()>1){
    string a=pq.top();pq.pop();
    string b=pq.top();pq.pop();
    string c=((a+b)<(b+a)?(a+b):(b+a));
    pq.push(c);
  }
  cout<<pq.top()<<"\n";*/
  
  vector<string> data(n);
  for(string &s:data) cin>>s;
  sort(data.begin(),data.end(),compare);
  string ans="";
  for(string s:data) ans+=s;
  cout<<ans<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
