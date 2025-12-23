#include<bits/stdc++.h>
using namespace std;

/*#ifndef ONLINE_JUDGE
#define debug(x) cerr << x
#else
#define debug(x)
#endif*/

#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif


#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll=long long;

void solve(){
  ll n;cin>>n;
  vector<pair<ll,ll>> data(n);
  set<ll> indices;
  for(int i=0;i<n;i++){
    ll l,r;cin>>l>>r;
    data[i]={l,r+1};
    indices.insert(l);
    indices.insert(r+1);
  }

  cerr<<"data: ";for(auto p:data) cerr<<"("<<p.first<<", "<<p.second<<") ";cerr<<"\n";
  //debug("indices: ";for(int num:indices) cout<<num<<' ';cout<<"\n");

  ll m=indices.size();
  map<ll,ll> compress;
  vector<ll> expand(m+1);
  ll i=1;
  for(ll num:indices){
    compress[num]=i;
    expand[i]=num;
    i++;
  }

  //debug("compress: ";for(auto p:compress) cout<<"("<<p.first<<", "<<p.second<<") ";cout<<"\n");
  //debug("expand: ";for(int num:expand) cout<<num<<' ';cout<<"\n");

  vector<ll> diff(m+1);
  for(int i=0;i<n;i++){
    ll l=data[i].first, r=data[i].second;
    diff[compress[l]]++, diff[compress[r]]--;
  }
  vector<ll> arr(m+1);
  vector<ll> count(n+1);
  for(int i=1;i<m+1;i++){
    arr[i]=arr[i-1]+diff[i];
    count[arr[i-1]]+=expand[i]-expand[i-1];
  }
  for(int i=1;i<n+1;i++){
    cout<<count[i]<<" \n"[i==n];
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

