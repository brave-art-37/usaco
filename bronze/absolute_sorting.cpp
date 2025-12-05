#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  int mini=0,maxi=1e9;
  vector<int> nos(n);
  for(int &x:nos){cin>>x;}
  for(int i=0;i<n-1;i++){
    if(nos[i]<nos[i+1]) maxi=min(maxi,(nos[i]+nos[i+1])/2);
    else if(nos[i]>nos[i+1]) mini=max(mini,(nos[i]+nos[i+1]+1)/2);
  }
  if(mini>maxi) cout<<-1<<"\n";
  else cout<<mini<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  cin >> t;

  while (t--){solve();}
}

