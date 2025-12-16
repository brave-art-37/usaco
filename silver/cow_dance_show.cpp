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
  int n,T;cin>>n>>T;
  vector<int> nos(n);
  for(int &x:nos) cin>>x;
  cout<<first_true(1,n,[&](int mid){
      multiset<int> onstage;
      for(int i=0;i<mid;i++){
        onstage.insert(nos[i]);
      }
      int j=mid;
      //cout<<"\n mid= "<<mid<<"\n";
      while(j<n){
        int mini=*(onstage.begin());
        onstage.erase(onstage.begin());
        onstage.insert(mini+nos[j]);
        j++;

        /*cout<<j<<" : ";
        for(int num:onstage) cout<<num<<' ';
        cout<<"\n";*/
      }
      return (*(onstage.rbegin())<=T);
  })<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("cowdance");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

