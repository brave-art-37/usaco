#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  string s;cin>>s;
  int lo=1,hi=n,ans=0;
  while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    set<string> tmp;
    string c="";
    for(int i=0;i<mid;i++){
      c+=s[i];
    }
    tmp.insert(c);
    for(int j=mid;j<n;j++){
      c.erase(c.begin());c+=s[j];
      tmp.insert(c);
    }
    if(tmp.size()+mid==n+1){
      ans=mid;
      hi=mid-1;
    }
    else{
      lo=mid+1;
    }
  }
  cout<<ans<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("whereami");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

