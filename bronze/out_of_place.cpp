#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  vector<int> place(n);
  vector<int> sorted(n);
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;
    place[i]=tmp;
    sorted[i]=tmp;
  }
  sort(sorted.begin(),sorted.end());
  int first=0,last=n-1,same=0;
  while(first<n && place[first]==sorted[first]){first++;}
  while(last>-1 && place[last]==sorted[last]){last--;}
  for(int i=first;i<=last;i++){
    same+=(place[i]==sorted[i]);
  }
  cout<<last-first-same<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("outofplace");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

