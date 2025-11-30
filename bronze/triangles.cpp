#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<pair<int,int>> pts;
  for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    pts.push_back({x,y});
  }
  int maxi=0;
  for(int i=0;i<n-2;i++){
    auto p=pts[i];
    for(int j=i;j<n-1;j++){
      auto q=pts[j];
      for(int k=j;k<n;k++){
        auto r=pts[k];
        if(p.second==q.second && p.first==r.first) maxi=max(maxi,abs((p.first-q.first)*(p.second-r.second)));
        else if(p.second==r.second && p.first==q.first) maxi=max(maxi,abs((p.first-r.first)*(p.second-q.second)));

        if(q.second==r.second && q.first==p.first) maxi=max(maxi,abs((q.first-r.first)*(q.second-p.second)));
        else if(q.second==p.second && q.first==r.first) maxi=max(maxi,abs((q.first-p.first)*(q.second-r.second)));

        if(r.second==p.second && r.first==q.first) maxi=max(maxi,abs((r.first-p.first)*(r.second-q.second)));
        else if(r.second==q.second && r.first==p.first) maxi=max(maxi,abs((r.first-q.first)*(r.second-p.second)));
      }
    }
  }
  cout<<maxi<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("triangles");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

