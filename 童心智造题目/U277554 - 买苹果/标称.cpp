#include<stdio.h>
#include<vector>
#include<algorithm>
#include<testlib.h>
#include<bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;

int v[N],w[N];

int main(){
    for(int _ = 1; _ <= 11; _++){
        endTest(_);
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i = 1; i <= n; i++){
            scanf("%d %d",&v[i],&w[i]);
        }

        int maxn = 0;
        for(int i = 0; i < (1 << n) - 1; i++){
            int s = 0,y = 0;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    s += w[j];
                    y += v[j];
                }
            }
            if(s <= x){
                if(maxn < y) maxn = y;
            }
        }
        printf("%d\n",maxn);

    }


}
