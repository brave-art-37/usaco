#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  set<int> nos;
  vector<pair<int,char>> data;
  for(int i=0;i<n;i++){
    char c;cin>>c;
    int num;cin>>num;
    data.push_back({num,c});
    nos.insert(num);
  }
  sort(data.begin(),data.end());
  int mini=1000;
  for(int num:nos){
    int count=0;
    for(int i=0;i<n;i++){
      auto tmp=data[i];
      if(tmp.second=='L' && num>tmp.first) count++;
      else if(tmp.second=='G' && num<tmp.first) count++;
    }
    mini=min(mini,count);
  }
  cout<<mini<<"\n";
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

