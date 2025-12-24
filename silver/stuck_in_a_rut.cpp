#include<bits/stdc++.h>
using namespace std;
#define uid(a,b) uniform_int_distribution<int>(a,b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef ONLINE_JUDGE
#define cerr if(false) cerr
#endif


struct Cow{
  char dir;
  int x,y,stop,blame;

  Cow(char dir, int x, int y):dir(dir),x(x),y(y),stop(0),blame(0){}
};

bool compare_ptr(Cow* cow1, Cow* cow2){
  if(cow1->dir=='N' && cow2->dir=='N'){
    if(cow1->x != cow2->x) return (cow1->x < cow2->x);
    return (cow1->y < cow2->y);
  }
  else{
    if(cow1->y != cow2->y) return (cow1->y < cow2->y);
    return (cow1->x < cow2->x);
  }
}

void solve(){
  int n;cin>>n;
  vector<Cow*> N;
  vector<Cow*> E;
  vector<Cow*> init;
  for(int i=1;i<n+1;i++){
    char dir;cin>>dir;
    int x,y;cin>>x>>y;
    Cow* data = new Cow(dir,x,y);
    if(dir=='N') N.push_back(data);
    else E.push_back(data);
    init.push_back(data);
  }
  sort(N.begin(),N.end(),compare_ptr);
  sort(E.begin(),E.end(),compare_ptr);

  //for(Cow* cow:init) cerr<<cow->dir<<' '<<cow.x<<' '<<cow.y<<"\n";cout<<"\n";

  //for(Cow* cow:N) cerr<<cow.dir<<' '<<cow->x<<' '<<cow->y<<"\n";cout<<"\n";

  //for(Cow* cow:E) cerr<<cow.dir<<' '<<cow->x<<' '<<cow->y<<"\n";cout<<"\n";

  for(int i=0;i<N.size();i++){
    for(int j=0;j<E.size();j++){
      if(E[j]->stop) continue;

      int dist_n=E[j]->y - N[i]->y;
      int dist_e=N[i]->x - E[j]->x;
      if(dist_n<=0 || dist_e<=0 || dist_n==dist_e) continue;
      else if(dist_n<dist_e){
        N[i]->blame += (1+E[j]->blame);
        //cerr<<N[i]->blame<<"\n";
        E[j]->stop=1;
      }
      else{
        E[j]->blame+=(1+N[i]->blame);
        //cerr<<E[j]->blame<<"\n";
        N[i]->stop=1;
        break;
      }
    }
  }
  for(Cow* cow:init) cout<<cow->blame<<"\n";
}

void setIO(string s){freopen((s+".in").c_str(), "r", stdin);freopen((s+".out").c_str(), "w", stdout);}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);
  //setIO("filename");
  int t = 1;
  //cin >> t;
  while (t--){solve();}}
