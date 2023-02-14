#include<bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;

int v[N],w[N],a[N],f[N][20],f2[N][20];

int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%d",&a[i]);
        f[i][0] = a[i];
        f2[i][0] = a[i];
    }

    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n; j++){
            if(j + (1 << (i - 1)) <= n){
                f[j][i] = max(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
                f2[j][i] = min(f2[j][i - 1] , f2[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int l,r;
    for(int i = 1; i <= m; i++){
        scanf("%d %d",&l,&r);
        int x = r - l + 1;
        int d = 0,sum1 = 0,sum2 = 1e9;
        while(x){
            if(x & 1) sum1 = max(sum1,f[l][d]),sum2 = min(sum2,f2[l][d]),l += 1 << d;
            d++;
            x >>= 1;
        }
        printf("%d\n",sum1 - sum2);
    }

}
