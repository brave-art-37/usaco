#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,k;cin>>n>>k;
  vector<int> nos(n+1);
  for(int i=1;i<n+1;i++) cin>>nos[i];
  int maxi=0,r=1,sum=0;
  for(int l=0;l<n;l++){
    sum-=nos[l];
    while(r<n+1 && sum+nos[r]<=k){
      maxi=max(maxi,r-l);
      sum+=nos[r];
      r++;
    }
  }
  cout<<maxi<<"\n";
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

