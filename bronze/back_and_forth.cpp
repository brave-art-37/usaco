#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void calc(set<int> &ans, vector<int> &a, vector<int> &b, int curr1, int curr2, int n){
  if(n==0){
    ans.insert(curr1);
    //cout<<"\n\n";
    return;
  }
  else if(n&1){
    //cout<<2<<"\n";
    for(int i=1;i<101;i++){
      if(b[i]<=0) continue;
      b[i]--;a[i]++;
      curr1+=i;curr2-=i;
      /*cout<<curr1<<' '<<curr2<<"\n";
      cout<<"a: ";
      for(int i=0;i<10;i++){
        cout<<a[i]<<' ';
      }
      cout<<"\nb: ";
      for(int i=0;i<10;i++){
        cout<<b[i]<<' ';
      }
      cout<<"\n\n";*/
      calc(ans,a,b,curr1,curr2,n-1);
      b[i]++;a[i]--;
      curr1-=i;curr2+=i;
    }
  }
  else{
    //cout<<1<<"\n";
    for(int i=1;i<101;i++){
      if(a[i]<=0) continue;
      a[i]--;b[i]++;
      curr2+=i;curr1-=i;
      /*cout<<curr1<<' '<<curr2<<"\n";
      cout<<"a: ";
      for(int i=0;i<10;i++){
        cout<<a[i]<<' ';
      }
      cout<<"\nb: ";
      for(int i=0;i<10;i++){
        cout<<b[i]<<' ';
      }
      cout<<"\n\n";*/
      calc(ans,a,b,curr1,curr2,n-1);
      a[i]++;b[i]--;
      curr2-=i;curr1+=i;
    }
  }
}

void solve(){
  vector<int> a(101);
  vector<int> b(101);
  for(int i=0;i<10;i++){
    int tmp;cin>>tmp;
    a[tmp]++;
  }
  for(int i=0;i<10;i++){
    int tmp;cin>>tmp;
    b[tmp]++;
  }
  /*cout<<"a: ";
  for(int i=0;i<10;i++){
    cout<<a[i]<<' ';
  }
  cout<<"\nb: ";
  for(int i=0;i<10;i++){
    cout<<b[i]<<' ';
  }
  cout<<"\n\n";*/
  set<int> ans;
  calc(ans, a, b, 1000, 1000, 4);
  /*for(int k:ans){
    cout<<k<<' ';
  }
  cout<<"\n";*/
  cout<<ans.size()<<"\n";
}

void setIO(string s){
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout); 
}

int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);

  setIO("backforth");

  int t = 1;
  //cin >> t;

  while (t--){solve();}
}
