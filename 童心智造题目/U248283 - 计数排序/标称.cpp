#include<iostream>
#include<testlib.h>
#include<unordered_map>
const int mod = 1e9 + 7;
using namespace std;


const int N = 1e7 + 10;
int cnt[N],a[N],b[N];

int n,w;
void counting_sort() {
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];
  for (int i = 1; i <= w; ++i) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; --i) b[cnt[a[i]]--] = a[i];
}
int main(){
    for(int _ = 1; _ <= 1; _++){
        endTest(_);
        cin >> n;
        w = 0;
        for(int i = 1; i <=  n; i++){
            scanf("%d",&a[i]);
            w = max(w,a[i]);
        }
        counting_sort();
        for(int i = 1; i <= n; i++) printf("%d\n",b[i]);
    }







    return 0;
}
