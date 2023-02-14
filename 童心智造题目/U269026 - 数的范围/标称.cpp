#include<iostream>
#include<testlib.h>
using namespace std;
const int maxn = 100010;
int a[maxn];
int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            scanf("%d",&a[i]);
        }
        int k;
        for(int i = 1; i <= m; i++){
            scanf("%d",&k);
            int l = 0,r = n - 1;
            while(l < r){
                int m = l + r >> 1;
                if(a[m] >= k){
                    r = m;
                }else l = m + 1;
            }
            if(a[l] != k){
                cout << -1 << " " << -1 << endl;
                continue;
            }
            cout << l << " ";
            l = 0,r = n - 1;
            while(l < r){
                int m = l + r + 1>> 1;
                if(a[m] <= k){
                    l = m;
                }else r = m - 1;
            }
            cout << l << endl;
        }

    }



    return 0;
}
