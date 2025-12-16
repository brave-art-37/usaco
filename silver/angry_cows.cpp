#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int first_true(int lo, int hi, function<bool(int)> f){
  int ans=0;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    if(f(mid)) ans=mid,hi=mid-1;
    else lo=mid+1;
  }
  return ans;
}

void solve(){
  int n,k;cin>>n>>k;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  cout<<first_true(1,(nos.back()-nos[0]+1)/2,[&](int r){
      int cows=0,i=0;
      while(i<n){
        auto it=upper_bound(nos.begin()+i,nos.end(),nos[i]+2*r);
        cows++;
        i=(it-nos.begin());
      }
      return (cows<=k);
  })<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("angry");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

