#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  string s;cin>>s;
  vector<vector<int>> pf(s.size(),vector<int>(26));
  for(int i=0;i<s.size();i++){
    pf[i][s[i]-'a']++;
    if(i==0) continue;
    for(int j=0;j<26;j++){
      pf[i][j]+=pf[i-1][j];
    }
  }
  int q;cin>>q;
  while(q--){
    int l,r;cin>>l>>r;l--,r--;
    int count=0;
    for(int i=0;i<26;i++){
      count+=((pf[r][i]-pf[l][i])>0);
    }
    if(l==r || s[l]!=s[r] || count>2) cout<<"Yes\n";
    else cout<<"No\n";
  }
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
