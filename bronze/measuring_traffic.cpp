#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  long long n;cin>>n;
  vector<pair<string,pair<long long,long long>>> data;
  for(int i=0;i<n;i++){
    string s;cin>>s;
    long long a,b;cin>>a>>b;
    data.push_back({s,{a,b}});
  }
  long long st=0LL,nd=1000LL;
  for(int i=n-1;i>-1;i--){
    auto tmp=data[i];
    if(tmp.first=="none"){
      st=max(st,tmp.second.first);
      nd=min(nd, tmp.second.second);
    }
    else if(tmp.first=="off"){
      st=min(st+tmp.second.first,1000LL);
      nd=min(nd+tmp.second.second,1000LL);
    }
    else if(tmp.first=="on"){
      st=max(st-tmp.second.second,0LL);
      nd=max(nd-tmp.second.first,0LL);
    }
  }
  cout<<st<<' '<<nd<<"\n";

  st=0,nd=1000;
  for(int i=0;i<n;i++){
    auto tmp=data[i];
    if(tmp.first=="none"){
      st=max(st,tmp.second.first);
      nd=min(nd, tmp.second.second);
    }
    else if(tmp.first=="on"){
      st=min(st+tmp.second.first,1000LL);
      nd=min(nd+tmp.second.second,1000LL);
    }
    else if(tmp.first=="off"){
      st=max(st-tmp.second.second,0LL);
      nd=max(nd-tmp.second.first,0LL);
    }
  }
  cout<<st<<' '<<nd<<"\n";
}


void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("traffic");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

