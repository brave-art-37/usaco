#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  map<string,int> cows;
  cows["Beatrice"]=0;cows["Belinda"]=1;
  cows["Bella"]=2;cows["Bessie"]=3;
  cows["Betsy"]=4;cows["Blue"]=5;
  cows["Buttercup"]=6;cows["Sue"]=7;
  vector<string> names={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};

  int n;cin>>n;
  vector<pair<int,int>> cdn(n);
  for(int i=0;i<n;i++){
    string a,tmp,b;cin>>a>>tmp>>tmp>>tmp>>tmp>>b;
    //cout<<cows[a]<<' '<<cows[b]<<"\n\n";
    //cdn[i]={1,2};
    cdn[i]={cows[a],cows[b]};
  }
  vector<string> ans;
  string perm="01234567";
  do{
    int isit=1;
    for(int i=0;i<n;i++){
      isit&=(abs((perm[cdn[i].first]-'0')-(perm[cdn[i].second]-'0'))==1);
    }
    if(!isit) continue;
    string tmp="99999999";
    for(int i=0;i<8;i++){
      tmp[perm[i]-'0']=(char)(i+'0');
    }
    ans.push_back(tmp);
  }
  while(next_permutation(perm.begin(),perm.end()));
  sort(ans.begin(),ans.end());
  string print=ans[0];
  for(char c:print){
    cout<<names[c-'0']<<"\n";
  }
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("lineup");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}

