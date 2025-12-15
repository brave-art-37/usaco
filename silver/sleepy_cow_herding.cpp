#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> nos(n);
  for(int &x:nos){
    cin>>x;
  }
  sort(nos.begin(),nos.end());
  
  int ans_mini=0;
  if((nos[n-2]-nos[0]==n-2 && nos[n-1]-nos[n-2]>2) || (nos[n-1]-nos[1]==n-2 && nos[1]-nos[0]>2)) ans_mini=2;
  else{
    for(int i=0;i<n;i++){
      auto it=upper_bound(nos.begin()+i,nos.end(),nos[i]+n-1);
      int dist=(it-nos.begin())-i;
      ans_mini=max(ans_mini,dist);
    }
    ans_mini=n-ans_mini;
  }
  cout<<ans_mini<<"\n";
  
  int ans_max=0;
  for(int i=2;i<n-1;i++){
    ans_max+=(nos[i]-nos[i-1]-1);
  }
  ans_max+=max(nos[1]-nos[0]-1, nos[n-1]-nos[n-2]-1);
  cout<<ans_max<<"\n";
}


void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("herding");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

