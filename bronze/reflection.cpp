#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n,u;cin>>n>>u;
  vector<string> data(n);
  for(string &s:data){cin>>s;}
  int count=0;
  for(int i=0;i<n/2;i++){
    for(int j=0;j<n/2;j++){
      int tmp=0;
      tmp+=(data[i][j]=='.');
      tmp+=(data[n-1-i][j]=='.');
      tmp+=(data[i][n-1-j]=='.');
      tmp+=(data[n-1-i][n-1-j]=='.');
      //cout<<i<<' '<<j<<' '<<tmp<<"\n";
      count+=min(tmp,4-tmp);
    }
  }
  cout<<count<<"\n";
  while(u--){
    int r,c;cin>>r>>c;
    r--;c--;
    int i=min(r,n-1-r);
    int j=min(c,n-1-c);
    int tmp=0;
    tmp+=(data[i][j]=='.');
    tmp+=(data[n-1-i][j]=='.');
    tmp+=(data[i][n-1-j]=='.');
    tmp+=(data[n-1-i][n-1-j]=='.');
    //cout<<min(tmp,4-tmp)<<"\n";
    count-=min(tmp,4-tmp);
    tmp=0;
    if(data[r][c]=='.') data[r][c]='#';
    else if(data[r][c]=='#') data[r][c]='.';
    tmp+=(data[i][j]=='.');
    tmp+=(data[n-1-i][j]=='.');
    tmp+=(data[i][n-1-j]=='.');
    tmp+=(data[n-1-i][n-1-j]=='.');
    //cout<<min(tmp,4-tmp)<<"\n";
    count+=min(tmp,4-tmp);
    cout<<count<<"\n";
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

