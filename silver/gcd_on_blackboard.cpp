#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<ll> nos(n);
  vector<ll> fwd(n+1);
  vector<ll> bwd(n+1);
  //ll prod=1LL;
  for(int i=0;i<n;i++){
    cin>>nos[i];
    //prod*=nos[i];
  }
  //ll gcd1=nos[0],gcd2=nos[];
  /*for(int i=0;i<n;i++){
    if(i!=0) gcd1=gcd(gcd1,nos[i]);
    if(i!=n-1) gcd2=gcd(gcd2,nos[i]);
  }*/
  //fwd[0]=gcd1;bwd[n]=gcd2;
  for(int i=0;i<n;i++){
    fwd[i+1]=gcd(fwd[i],nos[i]);
  }
  for(int i=n-1;i>-1;i--){
    bwd[i]=gcd(bwd[i+1],nos[i]);
  }
  ll maxi=1LL;
  for(int i=0;i<n;i++){
    //if(i==0) maxi=max(maxi,bwd[1]);
    //else if(i==n-1) maxi=max(maxi,fwd[n-1]);
    maxi=max(maxi,gcd(fwd[i],bwd[i+1]));
  }
  /*for(int num:nos){cout<<num<<' ';}cout<<"\n";
  for(int num:fwd){cout<<num<<' ';}cout<<"\n";
  for(int num:bwd){cout<<num<<' ';}cout<<"\n";*/
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

