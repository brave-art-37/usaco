#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,m;cin>>n>>m;
  vector<vector<bool>> rules(n,vector<bool>(n));
  for(int i=0;i<n;i++){
    for(int j=0;j<i+1;j++){
      char tmp;cin>>tmp;
      rules[i][j]=(tmp=='L');
      rules[j][i]=(tmp=='W');
    }
  }
  /*
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<rules[i][j]<<' ';
    }
    cout<<"\n";
  }*/
  while(m--){
    int a,b;cin>>a>>b;a--,b--;
    set<int> possible;
    for(int i=0;i<n;i++){
      if(!rules[a][i]) continue;
      if(rules[b][i]) possible.insert(i);
    }
    int len=possible.size();
    cout<<(2*n-len)*len<<"\n";
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

