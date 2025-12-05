#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,k;cin>>n>>k;
  vector<int> a(n);
  vector<int> b(n);
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;
    if(i==0) a[i]=tmp;
    else a[i]=a[i-1]+tmp;
  }
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;
    if(i==0) b[i]=tmp;
    else b[i]=max(b[i-1],tmp);
  }
  int maxi=0;
  for(int x=0;x<min(n,k);x++){
    maxi=max(maxi,a[x]+(k-1-x)*b[x]);
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
  cin >> t;

  while (t--){solve();}
}

