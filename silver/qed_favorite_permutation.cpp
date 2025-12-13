#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,q;cin>>n>>q;
  vector<int> nos(n+1);
  for(int i=1;i<n+1;i++){cin>>nos[i];}

  //for(int i:nos){cout<<i<<' ';}cout<<"\n";

  vector<int> pos(n+1);
  for(int i=1;i<n+1;i++){
    pos[nos[i]]=i;
  }

  //for(int i:pos){cout<<i<<' ';}cout<<"\n";

  vector<int> diff(n+2);
  for(int i=1;i<n+1;i++){
    int l=min(i,pos[i]);
    int r=max(i,pos[i]);
    if(l==r) continue;
    //cout<<l<<' '<<r<<"\n";
    diff[l]++,diff[r]--;
  }
  for(int i=1;i<n+2;i++){
    diff[i]+=diff[i-1];
  }

  //for(int i:diff){cout<<i<<' ';}cout<<"\n";
  

  string s;cin>>s;s=' '+s+' ';
  set<int> bad_indices;
  for(int i=1;i<n+1;i++){
    if(s[i]=='L' && s[i+1]=='R' && diff[i]>0) bad_indices.insert(i);
  }
  while(q--){
    int j;cin>>j;
    if(s[j]=='L'){
      s[j]='R';
      if(s[j-1]=='L' && diff[j-1]>0) bad_indices.insert(j-1);
      if(s[j+1]=='R') bad_indices.erase(j);
    }
    else if(s[j]=='R'){
      s[j]='L';
      if(s[j+1]=='R' && diff[j]>0) bad_indices.insert(j);
      if(s[j-1]=='L') bad_indices.erase(j-1);
    }
    if(bad_indices.empty()) cout<<"YES\n";
    else cout<<"NO\n";
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  //setIO("filename");

  int t = 1;
  cin >> t;

  while (t--){solve();}
}
