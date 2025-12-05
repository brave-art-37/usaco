#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,k;cin>>n>>k;
  string s;cin>>s;
  vector<int> freq(26);
  for(char c:s){
    freq[c-'a']++;
  }
  int pairs=0,odd=0;
  for(int i=0;i<26;i++){
    pairs+=(freq[i])/2;
    odd+=(freq[i]&1);
  }
  int x=pairs/k;
  odd+=2*(pairs%k);
  cout<<2*x+(odd>=k)<<"\n";
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

