#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  for(int &x:a){cin>>x;} //cout<<x<<' ';}
  //cout<<"\n";
  for(int &y:b){cin>>y;} //cout<<y<<' ';}
  //cout<<"\n";
  vector<int> used(n+1);
  int j=0,count=0;
  for(int i=0;i<n;i++){
    while(j<n && i<n && (used[a[j]]==1 || a[j]==b[i])){
      //cout<<a[j]<<' '<<b[i]<<"\n";
      if(used[a[j]]==1){j++;}
      else if(a[j]==b[i]){used[b[i]]=1;i++;j++;}
    }
    if(j>=n || i>=n) break;
    count++;used[b[i]]=1;
  }
  cout<<count<<"\n";
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

