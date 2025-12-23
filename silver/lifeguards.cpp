#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<pair<int,int>> data(n);
  set<int> indices;
  int maxi=0,mini=INT_MAX;
  for(int i=0;i<n;i++){
    int l,r;cin>>l>>r;
    data[i]={l,r};
    indices.insert(l);
    indices.insert(r);
    maxi=max(maxi,r);
    mini=min(mini,l);
  }
  int m=indices.size();
  map<int,int> compress;
  vector<int> expand(m+1);
  int i=1;
  for(int num:indices){
    compress[num]=i;
    expand[i]=num;
    i++;
  }
  expand[0]=expand[1];
  vector<int> diff(m+1);
  for(int i=0;i<n;i++){
    int l=data[i].first,r=data[i].second;
    diff[compress[l]]++,diff[compress[r]]--;
  }
  int zeroes=0;
  vector<int> onespf(m+1);
  vector<int> arr(m+1);
  for(int i=1;i<m+1;i++){
    arr[i]=arr[i-1]+diff[i];
    if(arr[i-1]==0) zeroes+=expand[i]-expand[i-1];
    onespf[i]=onespf[i-1]+(arr[i-1]==1)*(expand[i]-expand[i-1]);
  }
  int ones=INT_MAX;
  for(int i=0;i<n;i++){
    int l=data[i].first, r=data[i].second;
    ones=min(ones,onespf[compress[r]]-onespf[compress[l]]);
  }
  cout<<(maxi-mini)-(zeroes+ones)<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("lifeguards");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

