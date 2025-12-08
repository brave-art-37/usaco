#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int N=200000;
  int n,k,q;cin>>n>>k>>q;
  vector<int> diff(N+2);
  while(n--){
    int l,r;cin>>l>>r;
    diff[l]++,diff[r+1]--;
  }
  for(int i=1;i<N+2;i++){
    diff[i]+=diff[i-1];
  }
  vector<int> isit(N+2);
  for(int i=0;i<N+2;i++){
    isit[i]=(diff[i]>=k);
  }
  vector<int> pf(N+2);
  for(int i=1;i<N+2;i++){
    pf[i]=pf[i-1]+isit[i];
  }
  while(q--){
    int a,b;cin>>a>>b;
    cout<<pf[b]-pf[a-1]<<"\n";
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

