#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  string s;cin>>s;
  int q;cin>>q;
  while(q--){
    int m;cin>>m;
    char c;cin>>c;
    int maxi=0,r=0;
    for(int l=0;l<n-m+1;l++){
      while((r<n && s[r]==c)||(m>0)){
        if(r<n && s[r]!=c) m--;
        r++;
        //cout<<"r="<<r<<" m="<<m<<"\n";
        if(r>n) break;
      }
      maxi=max(maxi,min(n,r)-l);
      m+=(s[l]!=c);
    }
    cout<<maxi<<"\n";
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
