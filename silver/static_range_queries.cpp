#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,q;cin>>n>>q;
  vector<pair<pair<int,int>,int>> updates(n);
  vector<pair<int,int>> queries(q);
  set<int> indices;
  for(int i=0;i<n;i++){
    int l,r,x;cin>>l>>r>>x;
    updates[i]={{l,r},x};
    indices.insert(l);indices.insert(r);
  }
  for(int i=0;i<q;i++){
    int l,r;cin>>l>>r;
    queries[i]={l,r};
    indices.insert(l);indices.insert(r);
  }
  int m=indices.size();
  map<int,int> compress;
  vector<int> val(m+1);
  int j=1;
  for(int i:indices){
    compress[i]=j;
    val[j]=i;
    j++;
  }
  val[0]=val[1]-1;
  vector<int> diff(m+1);
  for(int i=0;i<n;i++){
    auto data=updates[i];
    int idx1=compress[data.first.first];
    int idx2=compress[data.first.second];
    diff[idx2]-=data.second;
    diff[idx1]+=data.second;
  }

  cout<<"diff: ";for(int i:diff) cout<<i<<" ";cout<<"\n";

  for(int i=1;i<diff.size();i++){
    diff[i]+=diff[i-1];
  }

  cout<<"arr: ";for(int i:diff) cout<<i<<" ";cout<<"\n";

  vector<int> pf(m+2);
  for(int i=1;i<m+1;i++){
    pf[i]=pf[i-1]+diff[i]*(val[i]-val[i-1]);
  }
  
  cout<<"pf: ";for(int i:pf) cout<<i<<" ";cout<<"\n";

  for(int i=0;i<q;i++){
    auto data=queries[i];
    int idx1=compress[data.first];
    int idx2=compress[data.second];
    cout<<(pf[idx2]-diff[idx2])-(pf[idx1]-diff[idx1])<<"\n";
  }

  cout<<"indices: ";for(int i:indices) cout<<i<<' ';cout<<"\n";
  cout<<"val: ";for(int i:val) cout<<i<<' ';cout<<"\n";
  cout<<"compress: ";for(auto p:compress) cout<<"("<<p.first<<", "<<p.second<<") ";cout<<"\n";

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

