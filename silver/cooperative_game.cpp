#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  vector<int> post(10);
  int stage=0, iter=0;
  while(stage==0){
    if(iter%2==0) cout<<"next 0 1"<<endl;
    else cout<<"next 1"<<endl;
    iter++;

    string s;cin>>s;
    if(s=="stop") exit(0);

    int grps=stoi(s);
    for(int i=0;i<grps;i++){
      string tmp;cin>>tmp;
      for(char c:tmp) post[c-'0']=i;
    }
    
    if(iter%2==0 && post[0]==post[1]) stage=1;
  }
  while(stage==1){
    if(post[0]==post[2]){
      cout<<"done"<<endl;
      break;
    }
    cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;

    string s;cin>>s;
    if(s=="stop") exit(0);

    int grps=stoi(s);
    for(int i=0;i<grps;i++){
      string tmp;cin>>tmp;
      for(char c:tmp) post[c-'0']=i;
    }
  }
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

