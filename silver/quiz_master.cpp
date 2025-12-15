#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int MAXN=1e5;
int INF=1e9;
vector<vector<int>> factor(MAXN+1,vector<int>());


void solve(){
  int n,m;cin>>n>>m;
  vector<int> nos(n);
  vector<int> freq(m+1);
  int ones=0;
  for(int &x:nos) cin>>x;
  sort(nos.begin(),nos.end());
  int l=0,mini=INF;
  for(int r=0;r<n;r++){
    for(int f:factor[nos[r]]){
      if(f>m) break;
      ones+=(freq[f]==0);
      freq[f]++;
    }

    //cout<<"r= "<<r<<' '<<ones<<"\n\n";

    while(l<=r && ones==m){
      mini=min(mini,nos[r]-nos[l]);
      for(int f:factor[nos[l]]){
        if(f>m) break;
        ones-=(freq[f]==1);
        freq[f]--;
      }
      l++;
      //cout<<"l= "<<l<<' '<<ones<<"\n";
    }
  }
  cout<<((mini==INF)?-1:mini)<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  for(int i=1;i<MAXN+1;i++){
    for(int j=i;j<MAXN+1;j+=i){
      factor[j].push_back(i);
    }
  }

  /*for(auto v:factor){
    for(int x:v){
      cout<<x<<' ';
    }
    cout<<"\n";
  }
  cout<<"\n";*/

  //setIO("filename");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

