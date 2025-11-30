#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void subset_sum(vector<long long> &wt, set<long long> &sums, long long curr, int n, long long total){
  if(n==0){
    sums.insert(abs(total-2LL*curr));
    return;
  }
  subset_sum(wt,sums,curr,n-1,total);
  subset_sum(wt,sums,curr+wt[n-1],n-1,total);
}

void solve(){
  int n;cin>>n;
  vector<long long> wt(n);
  long long total=0LL;
  for(long long &x:wt){
    cin>>x;
    total+=x;
  }
  set<long long> sums;
  subset_sum(wt,sums,0LL,n,total);
  cout<<(*min_element(sums.begin(),sums.end()))<<"\n";
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

