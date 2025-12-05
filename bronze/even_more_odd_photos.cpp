#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve(){
  int n;cin>>n;
  int a=0,b=0;
  for(int i=0;i<n;i++){
    int tmp;cin>>tmp;
    a+=(tmp&1);
    b+=(tmp%2==0);
  }
  int tmp;
  if(a<=b){
    tmp=2*a+1;
  }
  else{
    tmp=2*(b+(a-b)/3);
    if((a-b)%3==1) tmp-=1;
    else if((a-b)%3==2) tmp+=1;
  }
  cout<<tmp<<"\n";
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

