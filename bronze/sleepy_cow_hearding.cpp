#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  vector<int> nos(3);cin>>nos[0]>>nos[1]>>nos[2];
  sort(nos.begin(),nos.end());
  int a=nos[0],b=nos[1],c=nos[2];
  if(a==b-1 && c==b+1){
    cout<<0<<"\n";
    cout<<0<<"\n";
    return;
  }
  if(abs(a-b)==2 || abs(b-c)==2 || abs(c-a)==2) cout<<1<<"\n";
  else cout<<2<<"\n";
  cout<<max(abs(a-b),abs(b-c))-1<<"\n";
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

