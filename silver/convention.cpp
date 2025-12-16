#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int first_true(int lo, int hi, function<bool(int)> f){
  int ans=hi;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid,hi=mid-1;
    else lo=mid+1;
  }
  return ans;
}

void solve(){
  int n,m,c;cin>>n>>m>>c;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  int maxi=0;
  for(int i=c-1;i<n;i++){
    maxi=max(maxi,nos[i]-nos[i-c+1]);
  }
  cout<<first_true(1,maxi,[&](int mid){
      int buses=0;
      int i=0;
      while(i<n){
        auto it=upper_bound(nos.begin()+i,nos.end(),nos[i]+mid);
        int j=(it-nos.begin());
        buses++;
        i=min(j,i+c);
      }
      return (buses<=m);
  })<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("convention");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
