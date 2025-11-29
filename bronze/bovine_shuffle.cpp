#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> perm(n+1);
  for(int i=1;i<=n;i++){
    int tmp;cin>>tmp;
    perm[tmp]=i;
  }

  /* for(int i=1;i<=n;i++){
    cout<<perm[i]<<' ';
  }
  cout<<"\n"; */

  map<int,int> nos;
  for(int i=1;i<=n;i++){
    int tmp;cin>>tmp;
    nos[i]=tmp;
  }

  vector<int> ans(n+1);
  for(int i=1;i<=n;i++){
    ans[i]=i;
  }
  for(int j=0;j<3;j++){
    vector<int> tmp(n+1);
    for(int i=1;i<=n;i++){
      tmp[perm[i]]=ans[i];
    }
    for(int i=1;i<=n;i++){
      ans[i]=tmp[i];
    }

    /*for(int i=1;i<=n;i++){
      cout<<ans[i]<<' ';
    }
    cout<<"\n";*/

  }
  for(int i=1;i<=n;i++){
    cout<<nos[ans[i]]<<"\n";
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("shuffle");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

