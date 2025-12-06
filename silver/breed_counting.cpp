#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,q;cin>>n>>q;
  vector<int> a(n+1);
  vector<int> b(n+1);
  vector<int> c(n+1);
  for(int i=1;i<=n;i++){
    int tmp;cin>>tmp;
    a[i]=a[i-1]+(tmp==1);
    b[i]=b[i-1]+(tmp==2);
    c[i]=c[i-1]+(tmp==3);
  }
  while(q--){
    int l,r;cin>>l>>r;
    cout<<a[r]-a[l-1]<<' '<<b[r]-b[l-1]<<' '<<c[r]-c[l-1]<<"\n";
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("bcount");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

