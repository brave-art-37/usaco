#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  long long n;cin>>n;
  map<long long, vector<long long>> data;
  for(long long i=0;i<n;i++){
    long long tmp;cin>>tmp;
    data[tmp-i].push_back(tmp);
  }
  long long sum=0;
  for(auto p:data){
    vector<long long> nos=p.second;
    sort(nos.begin(),nos.end());
    /*cout<<p.first<<": ";
    for(int i=0;i<nos.size();i++){
      cout<<nos[i]<<" \n"[i==nos.size()-1];
    }*/
    for(int i=nos.size()-1;i>0;i-=2){
      sum+=max(0LL,nos[i]+nos[i-1]);
    }
  }
  cout<<sum<<"\n";
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

