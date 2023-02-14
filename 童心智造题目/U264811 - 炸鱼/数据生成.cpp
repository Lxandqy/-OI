#include<iostream>
#include<cstring>
#include<cmath>
#include<testlib.h>
#define randoms(a,b) ((1ll * rand())%(b-a)+a)
#define random(a,b) (xorShift128Plus() % (b - a) + a)
#define endl "\n"

using namespace std;

const int N = 101000;

map<int,int>mp;
int fa[N],n;
int find(int x){
    if(fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int head[N],to[N * 2],last[N * 2],cnt;
void add(int a,int b){
    to[++cnt] = b;
    last[cnt] = head[a];
    head[a] = cnt;
}

struct node{
    int l,r;
}a[N];

int pe[N];
void dfs(int x,int pre){
    int ans = 0;
    for(int i = head[x]; i != -1; i = last[i]){
        int j = to[i];
        if(j == pre) continue;
        ans++;
        if(ans > 3) cout << "asdsad" << endl;
        int s = rnd.next(1,2);
        if(s == 1 && a[x].l == 0){
            a[x].l = j;
        }else if(s == 2 && a[x].r == 0){
            a[x].r = j;
        }else if(a[x].l == 0){
            a[x].l = j;
        }else a[x].r = j;
        dfs(j,x);
    }
}

int main(int argc,char *argv[]){
    registerGen(argc, argv, 1);

    int maxn = 0;
    for(int _ = 1; _ <= 10; _++){
        startTest(_);
        int t = rnd.next(1,12);
        cout << t << endl;
        while(t--){
            int s = rnd.next(1,1000);
            for(int i = 1; i <= s; i++){
                if(i == 1) cout << rnd.next(1,9);
                else cout << rnd.next(0,9);
            }
            cout << " "<< rnd.next(1,400) << " " << rnd.next(1,400) << endl;
        }


    }


    return 0;
}
