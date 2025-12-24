#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void solve(){
  int a,b,c;cin>>a>>b>>c;
  int n;cin>>n;
  vector<ll> A,B;
  for(int i=0;i<n;i++){
    ll tmp;cin>>tmp;
    string s;cin>>s;
    if(s=="USB") A.push_back(tmp);
    else if(s=="PS/2") B.push_back(tmp);
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  int p=A.size(),q=B.size();
  ll cost=0, count=0;
  for(int i=0;i<min(a,p);i++) cost+=A[i], count++;
  for(int i=0;i<min(b,q);i++) cost+=B[i], count++;

  int i=min(a,p), j=min(b,q);
  while(c>0){
    if(i>=p && j>=q) break;
    else if(i>=p) cost+=B[j], j++;
    else if(j>=q) cost+=A[i], i++;
    else{
      if(A[i]<B[j]) cost+=A[i], i++;
      else cost+=B[j], j++;
    }
    c--, count++;
  }
  cout<<count<<' '<<cost<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

