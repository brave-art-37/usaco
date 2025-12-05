#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  string s;cin>>s;
  int count=0;
  for(char c:s){
    count+=(c=='A');
  }
  int isit=0;
  for(int i=0;i<s.size()-1;i++){
    isit|=(s[i]=='B' && s[i+1]=='B');
  }
  if(s[0]=='B' || s.back()=='B' || isit){
    cout<<count<<"\n";
    return;
  }
  int mini=s.size();
  int curr=1;
  for(int i=1;i<s.size();i++){
    if(s[i]==s[i-1]) curr++;
    else{
      if(s[i-1]=='A') mini=min(mini,curr);
      curr=1;
    }
  }
  if(s[s.size()-1]=='A') mini=min(mini,curr);
  cout<<count-mini<<"\n";
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

