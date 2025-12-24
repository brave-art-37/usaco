#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<pair<int,int>> data(n),tmp(n);
  map<pair<int,int>,int> init_idx;
  init_idx[make_pair(-1,-1)]=-2;
  for(int i=0;i<n;i++){
    int w,h;cin>>w>>h;
    data[i]={max(w,h),min(w,h)};
    tmp[i]=data[i];
    init_idx[data[i]]=i;
  }
  sort(tmp.begin(),tmp.end());
  vector<int> mwt(n),ind(n);
  mwt[0]=-1*tmp[0].second, ind[0]=0;
  for(int i=0;i<n;i++){
    if(i==0) continue;
    ind[i]=ind[i-1]; mwt[i]=mwt[i-1];
    if(mwt[i-1]<-1*tmp[i].second) mwt[i]=-1*tmp[i].second, ind[i]=i;
  }
  map<pair<int,int>,pair<int,int>> ans;
  ans[tmp[0]]={-1,-1};
  for(int i=1;i<n;i++){
    auto it=upper_bound(mwt.begin(),mwt.begin()+i,-1*tmp[i].second);
    if(it==mwt.begin()+i) ans[tmp[i]]={-1,-1};
    else{
      int j=ind[(it-mwt.begin())];
      if(tmp[j].first==tmp[i].first) ans[tmp[i]]={-1,-1};
      else ans[tmp[i]]=tmp[j];
    }
  }
  cerr<<"ans= ";for(auto p:ans) cerr<<"("<<p.first.first<<", "<<p.first.second<<"): ("<<p.second.first<<", "<<p.second.second<<"); ";cerr<<"\n";
  vector<int> to_print(n);
  for(int i=0;i<n;i++){
    to_print[i]=(1+init_idx[ans[data[i]]]);
  }
  for(int num:to_print) cout<<num<<' ';cout<<"\n";
  cerr<<"tmp= ";for(auto p:tmp) cerr<<"("<<p.first<<", "<<p.second<<") ";cerr<<"\n";
  cerr<<"mwt= ";for(auto p:mwt) cerr<<p<<" ";cerr<<"\n";
  cerr<<"ind= ";for(auto p:ind) cerr<<p<<" ";cerr<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  cin >> t;
  while (t--){solve();}}

