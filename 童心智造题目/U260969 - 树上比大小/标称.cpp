#include<iostream>
#include<cstring>
#include<algorithm>
#include<testlib.h>
using namespace std;
const int maxn = 2e5 + 5;
int n;
int head[maxn],to[maxn * 2],w[maxn * 2],last[maxn * 2],cnt;
void add(int x,int y){
    to[++cnt] = y;
    last[cnt] = head[x];
    head[x] = cnt;
}
int c[maxn],a[maxn],b[700];
unordered_map<int,int>mp;
unordered_map<int,int>mp2;

int tree[maxn][500];
int anss = 0,sum[maxn];
void dfs(int x,int pre){
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == pre) continue;
        dfs(j,x);
        for(int k = 1; k <= anss; k++){
            tree[x][k] += tree[j][k];
        }
    }

    tree[x][mp[a[x]]]++;
    return ;
}


long long pows(int x,int y){
    long long s = 1;
    for(int i = 1; i <=y; i++){
        s *= x;

    }
    return s;
}


int main(){
    for(int _ = 1; _ <= 10; _++){
        endTest(_);
        int n;
        cin >> n;
        memset(tree,0,sizeof tree);
        memset(head,-1,sizeof head);
        memset(sum,0,sizeof sum);
        mp.clear();
        cnt = 0;
        anss = 0;
        mp2.clear();
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);
        }

        for(int i = -32; i <= 32; i++){
            for(int j = -20; j <= 32; j++){
                long long x = a[1];
                if(i < 0){
                    if((x % (1ll << (-i))) != 0) break;
                    x >>= -i;
                }else x <<= i;
                if(j < 0){
                    //cout << i << " " <<j << " " << pows(3,-j) << "  " << x % pows(3,-j)<< endl;
                    if((x % (pows(3,-j))) != 0) continue;
                    x /= 1ll*pows(3,-j);
                }else x *= 1ll*pows(3,j);

                if(x > 1e9) break;
                if(!mp2[x]){
                       // cout << x << " " << i << " " << j <<endl;
                    mp2[x] = 1;
                    b[++anss] = x;
                }
            }
        }

        sort(b + 1,b + anss + 1);

        for(int i = 1; i <= anss; i++){
            mp[b[i]] = i;
        }

        for(int i = 1; i <= n - 1; i++){
            int x,y;
            scanf("%d %d",&x,&y);
            add(x,y);
            add(y,x);
        }

        dfs(1,0);

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= mp[a[i]]; j++){
                sum[i] += tree[i][j];
            }
        }

        int m;
        scanf("%d",&m);
        for(int i = 1; i <= m; i++){
            int x;
            scanf("%d",&x);
            printf("%d\n",sum[x] - 1);
        }


    }
    return 0;
}
