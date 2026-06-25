#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

const int MAXN=101;
int n,k,r;
vector<vector<int>> vis(MAXN,vector<int>(MAXN));
vector<vector<int>> comp(MAXN,vector<int>(MAXN,-1));

int diff(pair<int,int> q, pair<int,int> p){
  int x=q.first-p.first;
  int y=q.second-p.second;
  return (abs(x)+2*abs(y)+2*(x<0)+2*(y<0)-1);
}

void solve(){
  cin>>n>>k>>r;
  map<pair<int,int>,bitset<4>> roads;
  for(int i=0;i<r;i++){
    pair<int,int> p,q;cin>>p.first>>p.second>>q.first>>q.second;
    p.first--, p.second--, q.first--, q.second--;
    roads[p].set(diff(q,p));
    roads[q].set(diff(p,q));
  }
  int compNum=0;
  vector<pair<int,int>> dir={ 
    {1,0}, {0,1}, {-1,0}, {0,-1}
  };
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(vis[i][j]) continue;
      stack<pair<int,int>> st;
      st.push({i,j});
      while(!st.empty()){
        auto p=st.top();st.pop();


        //cerr<<1<<"\n";
        //cerr<<"p= "<<p.first<<", "<<p.second<<"\n";
        comp[p.first][p.second]=compNum;;
        vis[p.first][p.second]=1;

        //cerr<<"("<<p.first<<", "<<p.second<<")\n";
        bitset<4> tmp(0);

        //cerr<<2<<"\n";
        if(roads.count(p)) tmp=roads[p];

        for(int b=0;b<4;b++){
          if(tmp[b]==1) continue;
          int x=p.first+dir[b].first;
          int y=p.second+dir[b].second;
          //cerr<<3<<" "<<b<<"\n";
          //cerr<<"x="<<x<<", y="<<y<<"\n";
          if(x<0 || x>=n || y<0 || y>=n || vis[x][y]==1) continue;
          st.push({x,y});
        }
      }
      compNum++;
    }
  }
  vector<int> cnt(compNum);
  for(int i=0;i<k;i++){
    pair<int,int> cow;cin>>cow.first>>cow.second;
    cow.first--,cow.second--;
    cnt[comp[cow.first][cow.second]]++;
  }
  int sum=0, sqsum=0;
  for(int i=0;i<compNum;i++){
    sum+=cnt[i];
    sqsum+=cnt[i]*cnt[i];
  }
  cout<<(sum*sum-sqsum)/2<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("countcross");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

