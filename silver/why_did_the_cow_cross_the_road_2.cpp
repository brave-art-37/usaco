#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,k,b;cin>>n>>k>>b;
  vector<int> nos(n);
  for(int i=0;i<b;i++){
    int tmp;cin>>tmp;
    nos[tmp-1]=1;
  }
  int count=0,mini=n;
  for(int i=0;i<k;i++){
    count+=nos[i];
  }
  mini=min(mini,count);
  for(int i=k;i<n;i++){
    count+=(nos[i]-nos[i-k]);
    mini=min(mini,count);
  }
  cout<<mini<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("maxcross");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

