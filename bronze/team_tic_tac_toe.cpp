#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  vector<string> data(3);
  cin>>data[0]>>data[1]>>data[2];
  set<set<char>> win;
  for(int i=0;i<3;i++){
    set<char> tmp;
    tmp.insert(data[i][0]);
    tmp.insert(data[i][1]);
    tmp.insert(data[i][2]);
    if(tmp.size()>2) continue;
    win.insert(tmp);
  }
  for(int i=0;i<3;i++){
    set<char> tmp;
    tmp.insert(data[0][i]);
    tmp.insert(data[1][i]);
    tmp.insert(data[2][i]);
    if(tmp.size()>2) continue;
    win.insert(tmp);
  }
  set<char> tmp1;
  tmp1.insert(data[0][0]);
  tmp1.insert(data[1][1]);
  tmp1.insert(data[2][2]);
  if(tmp1.size()<=2) win.insert(tmp1);
  set<char> tmp2;
  tmp2.insert(data[0][2]);
  tmp2.insert(data[1][1]);
  tmp2.insert(data[2][0]);
  if(tmp2.size()<=2) win.insert(tmp2);
  int one=0,two=0;
  for(auto s:win){
    if(s.size()==1) one++;
    else two++;
  }
  cout<<one<<"\n";
  cout<<two<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("tttt");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

