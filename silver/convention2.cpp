#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif
using ll=long long;

void print(priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > q){
  cerr<<"q=";
  while(!q.empty()){
    auto p=q.top();q.pop();
    cerr<<"("<<p.first<<", "<<p.second<<") ";
  }
  cerr<<"\n";
}

void solve(){
  ll n;cin>>n;
  vector<pair<ll,pair<ll,ll>>> nos(n), orig(n);
  for(int i=0;i<n;i++){
    ll a,b;cin>>a>>b;
    nos[i]={a,{1LL*i,b}};
    orig[i]=nos[i];
  }
  sort(nos.begin(),nos.end());

  cerr<<"nos=";for(auto p:nos) cerr<<p.first<<":("<<p.second.first<<", "<<p.second.second<<") ";cerr<<"\n";

  ll wait=0;
  priority_queue< pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>> > q;
  ll time=0;
  ll i=0;
  while(1){
    if(i<n && (nos[i].first<=time || q.empty())){
      if(q.empty()) time=max(nos[i].first,time);
      q.push(nos[i].second), i++;
    }
    else if(i>=n && q.empty()) break;
    else{
      auto p=q.top();q.pop();
      wait=max(wait,time-orig[p.first].first);
      time+=p.second;
    }
    cerr<<"time="<<time<<"\n";
    //print(q);cerr<<"\n";
  }
  cout<<wait<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("convention2");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}

