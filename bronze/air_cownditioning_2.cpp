#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,m;cin>>n>>m;
  vector<int> temp(100);
  vector<pair<pair<int,int>,pair<int,int>>> coolers(m);
  for(int i=0;i<n;i++){
    int s,t,c;cin>>s>>t>>c;
    for(int j=s-1;j<t;j++){
      temp[j]+=c;
    }
  }
  for(int i=0;i<m;i++){
    int a,b,p,m;cin>>a>>b>>p>>m;
    coolers[i]={{a-1,b},{p,m}};
  }
  int mini=10000;
  string choice="";
  for(int i=0;i<(1<<m);i++){
    //cout<<i<<"\n";
    int cost=0;
    string what="";
    vector<int> tmp(100);
    for(int j=0;j<m;j++){
      //cout<<((i>>j)&1)<<"\n";
      if(((i>>j)&1)==0) continue;
      //cout<<j<<"\n";
      auto data=coolers[j];
      cost+=data.second.second;
      what+=(char)(j+'0');what+=' ';
      //cout<<cost<<' '<<what<<"\n";
      for(int k=data.first.first;k<data.first.second;k++){
        tmp[k]+=data.second.first;
      }
    }
    int isit=1;
    for(int j=0;j<100;j++){
      isit&=(tmp[j]>=temp[j]);
    }
    //cout<<what<<' '<<cost<<' '<<isit<<"\n";
    if(isit && cost<=mini){
      mini=cost;
      choice=what;
    }
  }
  cout<<mini<<"\n";
  //cout<<choice<<"\n";
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

