#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,T;cin>>n>>T;
  while(T--){
    int k;cin>>k;
    int lo=1,hi=n;
    cout<<"? "<<1<<' '<<n<<"\n";
    int zero;cin>>zero;
    if(zero==-1) exit(0);
    zero=(n-zero);
    while(lo<hi){
      int mid=lo+(hi-lo)/2;
      cout<<"? "<<lo<<' '<<mid<<"\n";
      int first;cin>>first;
      if(first==-1) exit(0);
      first=(mid-lo+1)-first;
      if(first>=k) zero=first,hi=mid;
      else zero=zero-first,k-=first,lo=mid+1;
    }
    cout<<"! "<<lo<<"\n";
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){//ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

