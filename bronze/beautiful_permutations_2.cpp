#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void calc(set<int> &nos, vector<int> &perm, int k, int n){
  if(k==n){
    for(int i=0;i<perm.size();i++){
      cout<<perm[i]<<" \n"[i==perm.size()-1];
    }
    exit(0);
  }
  for(int x:nos){
    if(perm.empty() || abs(x-perm.back())!=1){
      perm.push_back(x);
      nos.erase(x);
      calc(nos, perm, k+1, n);
      perm.pop_back();
      nos.insert(x);
    }
  }
}

void solve(){
  int n;cin>>n;
  if(n==2 || n==3){
    cout<<"NO SOLUTION\n";
  }
  set<int> nos;
  for(int i=1;i<=n;i++){
    nos.insert(i);
  }
  vector<int> perm;
  calc(nos, perm, 0, n);
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

