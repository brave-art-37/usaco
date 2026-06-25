#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif

void solve(){
  int n;cin>>n;
  vector<vector<int>> grid(n,vector<int>(n));
  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(int j=0;j<n;j++){
      grid[i][j]=(s[j]=='#');
    }
  }
  vector<vector<int>> comp(n,vector<int>(n,-1));
  priority_queue<pair<int,int>> pq;
  int compNum=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(comp[i][j]!=-1 || grid[i][j]==0) continue;
      int curr_size=0;
      stack<pair<int,int>> st;
      st.push({i,j});
      while(!st.empty()){
        auto p=st.top();st.pop();
        int x=p.first, y=p.second;
        if(x<0 || x>=n || y<0 || y>=n || comp[x][y]!=-1 || grid[x][y]==0) continue;
        comp[x][y]=compNum;
        curr_size++;
        st.push({x+1,y});
        st.push({x-1,y});
        st.push({x,y+1});
        st.push({x,y-1});
      }
      pq.push({curr_size,compNum});
      compNum++;
    }
  }
  vector<int> peri(compNum);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(comp[i][j]!=-1) continue;
      if(i>0 && comp[i-1][j]!=-1) peri[comp[i-1][j]]++;
      if(i<n-1 && comp[i+1][j]!=-1) peri[comp[i+1][j]]++;
      if(j>0 && comp[i][j-1]!=-1) peri[comp[i][j-1]]++;
      if(j<n-1 && comp[i][j+1]!=-1) peri[comp[i][j+1]]++;
    }
  }
  for(int i=0;i<n;i++){
    if(comp[i][0]!=-1) peri[comp[i][0]]++;
    if(comp[i][n-1]!=-1) peri[comp[i][n-1]]++;
    if(comp[0][i]!=-1) peri[comp[0][i]]++;
    if(comp[n-1][i]!=-1) peri[comp[n-1][i]]++;
  }
  int max_area=pq.top().first;
  int min_peri=INT_MAX;
  while(!pq.empty() && pq.top().first==max_area){
    int cmp=pq.top().second;pq.pop();
    min_peri=min(min_peri,peri[cmp]);
  }
  /*
  while(!pq.empty() && pq.top().first==max_area){
    int cmp=pq.top().second;pq.pop();
    int maxix=1,maxiy=1;
    for(int i=0;i<n;i++){
      int j=0,k=n-1;
      while(j<=k && comp[i][j]!=cmp) j++;
      while(j<=k && comp[i][k]!=cmp) k--;
      maxix=max(maxix,k-j+1);
    }
    for(int i=0;i<n;i++){
      int j=0,k=n-1;
      while(j<=k && comp[j][i]!=cmp) j++;
      while(j<=k && comp[k][i]!=cmp) k--;
      maxiy=max(maxiy,k-j+1);
    }
    min_peri=min(min_peri,2*(maxix+maxiy));
    cout<<maxix<<' '<<maxiy<<"\n";
  }
  */
  cout<<max_area<<' '<<min_peri<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  setIO("perimeter");
  int _ = 1;
  //cin >> _;
  while (_--){solve();}}

