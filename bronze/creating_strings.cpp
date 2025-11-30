#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void perm(set<string> &words, string &s, vector<int> &used, string &curr){
  if(curr.size()==s.size()){
    words.insert(curr);
    return;
  }
  for(int i=0;i<s.size();i++){
    if(used[i]==1) continue;
    used[i]=1;
    perm(words,s,used,curr);
    curr+=s[i];
    perm(words,s,used,curr);
    curr.erase(curr.end()-curr.begin()-1);
    used[i]=0;
  }
}

void solve(){
  string s;cin>>s;
  set<string> words;
  vector<int> used(s.size());
  string curr="";
  perm(words, s, used, curr);
  cout<<words.size()<<"\n";
  for(string s:words){
    cout<<s<<"\n";
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

