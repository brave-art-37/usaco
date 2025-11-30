#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,m;cin>>n>>m;
  vector<bitset<4>> data1(m);
  vector<bitset<4>> data2(m);
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<m;j++){
      if(s[j]=='A') data1[j].set(0);
      else if(s[j]=='T') data1[j].set(1);
      else if(s[j]=='C') data1[j].set(2);
      else if(s[j]=='G') data1[j].set(3);
    }
  }
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<m;j++){
      if(s[j]=='A') data2[j].set(0);
      else if(s[j]=='T') data2[j].set(1);
      else if(s[j]=='C') data2[j].set(2);
      else if(s[j]=='G') data2[j].set(3);
    }
  }
  int count=0;
  for(int i=0;i<m;i++){
    count+=((data1[i]&data2[i])==0);
  }
  cout<<count<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("cownomics");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
