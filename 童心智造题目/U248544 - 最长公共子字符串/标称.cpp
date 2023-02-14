#include<bits/stdc++.h>
#include<testlib.h>
#include<map>
using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;
const int p = 1e9 + 7;
typedef unsigned long long ull;


char a[N],b[N];
ull cal[N];
vector<ull>v[N];

int n,m,k;
bool check(int x){
 map<ull,ull> ans,flag;
 for(int i = 1; i <= m; i++){
  bool ok=false;
  for(int j = x; j < v[i].size(); j++){
   ull xx = (v[i][j] - v[i][j - x] * cal[x]);
   if(!flag[xx]) {
   	if (++ans[xx] == i) ok=true;
    flag[xx] = 1;
   }
  }
  if (!ok) return false;
  flag.clear();
 }
 return true;
}
int main(){
 ios::sync_with_stdio(false);
 endTest(3);
 cin.tie(0);
 cout.tie(0);
 cin >> n >> m;
 cal[0] = 1;
 for(int i = 1; i <= 1000000; i++){
  cal[i] = cal[i - 1] * 131;
 }
 int l = 0,r = 1e6;
 for(int i = 1; i <= m; i++){
  string a;
  cin >> a;
  int sz=a.length();
  r=min(r,sz);
  v[i].push_back(0);
  for(int j = 0; j < a.length(); j++){
   v[i].push_back(v[i][j] * 131 + a[j]);
  }
 }

 while(l < r){
  int mid = l + r + 1 >> 1;
  if(check(mid)){
   l = mid;
  }else r = mid - 1;
 }

 cout << l << endl;

 return 0;
}
