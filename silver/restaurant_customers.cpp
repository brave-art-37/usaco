#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


void solve(){
  int n;cin>>n;
  vector<pair<int,int>> data(n);
  set<int> indices;
  for(int i=0;i<n;i++){
    int a,b;cin>>a>>b;
    data[i]={a,b};
    indices.insert(a);
    indices.insert(b);
  }
  map<int,int> compress;
  int i=1;
  for(int num:indices){
    compress[num]=i;
    i++;
  }
  int m=indices.size();
  vector<int> diff(m+1);
  for(int i=0;i<n;i++){
    int a=data[i].first, b=data[i].second;
    diff[compress[a]]++, diff[compress[b]]--;
  }
  vector<int> arr(m+1);
  int maxi=0;
  for(int i=1;i<m+1;i++){
    arr[i]=arr[i-1]+diff[i];
    maxi=max(maxi,arr[i]);
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
  //cin >> t;

  while (t--){solve();}
}

