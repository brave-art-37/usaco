#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int k,n;cin>>k>>n;
  vector<int> a(k);
  for(int i=0;i<k;i++){
    int tmp;cin>>tmp;
    if(i>0) a[i]=a[i-1]+tmp;
    else a[i]=tmp;
  }
  set<int> b;
  int b1;cin>>b1;
  for(int i=1;i<n;i++){
    int tmp;cin>>tmp;
    b.insert(tmp);
  }
  set<int> possible;
  for(int i=0;i<k;i++){
    set<int> score;
    int start=b1-a[i];
    for(int j=0;j<k;j++){
      score.insert(start+a[j]);
    }
    int isit=1;
    for(int x:b){
      isit&=(score.find(x)!=score.end());
    }
    if(isit) possible.insert(start);
  }
  cout<<possible.size()<<"\n";
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

