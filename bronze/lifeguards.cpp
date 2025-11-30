#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int z=1000;
  int n;cin>>n;
  vector<int> diff(z+1);
  vector<pair<int,int>> nos;
  for(int i=0;i<n;i++){
    int st,nd;cin>>st>>nd;
    nos.push_back({st,nd});
    diff[st]++;
    diff[nd]--;
  }
  int mini=z;
  for(int i=0;i<n;i++){
    int st=nos[i].first, nd=nos[i].second;
    diff[st]--;diff[nd]++;
    /*for(int k=0;k<z+1;k++){
      cout<<diff[k]<<' ';
    }
    cout<<"\n";*/
    int counter=0,empty=0;
    for(int j=0;j<z+1;j++){
      counter+=diff[j];
      empty+=(counter==0);
    }
    diff[st]++;diff[nd]--;
    //cout<<empty<<"\n";
    mini=min(mini,empty);
  }
  cout<<z+1-mini<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("lifeguards");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

