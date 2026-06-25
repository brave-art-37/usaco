#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

int XOR(int OR, int AND){
  int bitOR = sizeof(int)*8-__builtin_clz(OR);
  int bitAND = sizeof(int)*8-__builtin_clz(AND);
  int maxi=max(bitOR,bitAND);
  return (OR & (((1<<maxi)-1)^AND ) );
}

void solve(){
  int n,k;cin>>n>>k;
  vector<int> nums={1,6,4,2,3,5,4};
  vector<pair<int,int>> sum(n-1);
  for(int i=2;i<n+1;i++){
    int a,b;
    cout<<"and 1 "<<i<<endl;
    cin>>a;
    if(a==-1) exit(0);
    cin>>b;
    if(b==-1) exit(0);
    sum[i-2]=make_pair(2*a+XOR(b,a),i);
  }
  sort(sum.begin(),sum.end());


  int i,j,a,b; i=sum[0].second, j=sum[1].second;
  cout<<"and "<<i<<" "<<j<<endl;
  cin>>a;
  if(a==-1) exit(0);
  cout<<"or "<<i<<" "<<j<<endl;
  cin>>b;
  if(b==-1) exit(0);
  int tmp=2*a+XOR(b,a);
  int x=(sum[0].first+sum[1].first-tmp)/2;
  vector<int> nos(n);
  for(int i=0;i<n-1;i++){
    nos[i]=sum[i].first-x;
  }
  nos[n-1]=x;
  sort(nos.begin(),nos.end());
  cout<<"finish "<<nos[k-1]<<endl;
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){//ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

